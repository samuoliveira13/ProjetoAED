#include <iostream>
#include <algorithm>
#include "include/Horario.h"

Horario::Horario(){}

Horario::Horario(vector<Class> horario) {
    this->horario=horario;
}
void Horario::clear(){
    horario.clear();
}
void Horario::push_back(Class x) {
    horario.push_back(x);
}
vector<Class> Horario::getHorario() {
    return horario;
}
vector<Class>::iterator Horario::begin(){
    vector<Class>::iterator it;
    it=horario.begin();
    return it;
}
vector<Class>::iterator Horario::end(){
    vector<Class>::iterator itf;
    itf=horario.end();
    return itf;
}
void Horario::print() {
    for(auto x:horario) {
        cout << x.getWeekDay() << " | " << x.getUccode() << " "
             << x.getClassType() << " class from "
             << TransformHour(x.getStarthour()) << " to "
             << SumHours(x.getStarthour(), x.getDuration())
             << endl;
    }
}
int Horario::type_of_order() {
    int order;
    std::cout<<"Como deseja ordenar o horario?"<<endl;
    std::cout<<"1(default)-> ordem crescente"<<endl;
    std::cout<<"2-> ordem decrescente"<<endl;
    std::cout<<"3-> primeiro pelas aulas teoricas"<<endl;
    std::cout<<"4-> pelo codigo da UC"<<endl;
    std::cout<<"5-> pela duracao da aula"<<endl;
    cin>> order;
    return order;
}
bool Horario::decrescent_order(Class x, Class y) {
    if (x.orderWeekDay() == y.orderWeekDay()) {
        if (x.getStarthour() == y.getStarthour()) return x.getClassCode() > y.getClassCode();
        else return x.getStarthour() > y.getStarthour();
    }
    return x.orderWeekDay() > y.orderWeekDay();
}
bool Horario::teoricas_first(Class x, Class y) {
    if (x.orderTypeClasses() == y.orderTypeClasses()) {
        if (x.orderWeekDay() == y.orderWeekDay()) {
            if (x.getStarthour() == y.getStarthour()) return x.getClassCode() < y.getClassCode();
            else return x.getStarthour() < y.getStarthour();
        }
        return x.orderWeekDay() < y.orderWeekDay();
    }
    return x.orderTypeClasses() < y.orderTypeClasses();
}
bool Horario::uc_order(Class x,Class y){
    if (x.getUccode() == y.getUccode()) {
        if (x.orderTypeClasses() == y.orderTypeClasses()) {
            if (x.orderWeekDay() == y.orderWeekDay()) {
                if (x.getStarthour() == y.getStarthour()) return x.getClassCode() < y.getClassCode();
                else return x.getStarthour() < y.getStarthour();
            }
            return x.orderWeekDay() < y.orderWeekDay();
        }
        return x.orderTypeClasses() < y.orderTypeClasses();
    }
    return (x.getUccode() < y.getUccode());
}
bool Horario::duration_order(Class x, Class y) {
    if (x.getDuration() == y.getDuration()) {
        if (x.orderWeekDay() == y.orderWeekDay()) {
            if (x.orderWeekDay() == y.orderWeekDay()) return x.getClassCode() < y.getClassCode();
            else return x.getStarthour() < y.getStarthour();
        }
        return x.orderWeekDay() < y.orderWeekDay();
    }
    return x.getDuration() < y.getDuration();
}
bool Horario::crescent_order(Class x, Class y) {
    if (x.orderWeekDay() == y.orderWeekDay()) {
        if (x.getStarthour() == y.getStarthour()) return x.getClassCode() < y.getClassCode();
        else return x.getStarthour() < y.getStarthour();
    }
    return x.orderWeekDay() < y.orderWeekDay();
}

string Horario::TransformHour(float hour) {
    int hours = int(hour);
    int minutes = (hour - hours) * 6;
    string time = to_string(hours) + ":" + to_string(minutes) + "0";
    return time;
}

string Horario::SumHours(float starthour, float duration) {
    float finalhour = starthour + duration;
    return TransformHour(finalhour);
}
