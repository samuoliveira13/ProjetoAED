
#include <iostream>
#include "include/Class.h"
Class::Class(string classcode, string uccode, string weekday, float starthour, float duration, string classtype) {
    this -> classcode = classcode;
    this -> uccode = uccode;
    this -> weekday = weekday;
    this -> starthour = starthour;
    this -> duration = duration;
    this -> classtype = classtype;
}

string Class::setUccode(string uccode){
    this -> uccode = uccode;
}

string Class::setClasstype(string classtype){
    this -> classtype = classtype;
}

float Class::setStarthour(float starthour){
    this -> starthour = starthour;
}

float Class::setDuration(float duration){
    this -> duration = duration;
}

string Class::getUccode() {
    return uccode;
}

string Class::getClassCode() {
    return classcode;
}

string Class::getWeekDay() {
    return weekday;
}

float Class::getStarthour() {
    return starthour;
}

float Class::getDuration() {
    return duration;
}

string Class::getClassType() {
    return classtype;
}
int Class::orderWeekDay() {
    if(weekday=="Monday") return 1;
    else if(weekday=="Tuesday") return 2;
    else if(weekday=="Wednesday") return 3;
    else if(weekday=="Thursday") return 4;
    else if(weekday=="Friday") return 5;
}
int Class::orderTypeClasses(){
    if (classtype=="T") return 1;
    return 2;
}

/*
    int order;
    std::cout<<"Como deseja ordenar o horario?"<<endl;
    std::cout<<"1(default)-> ordem crescente"<<endl;
    std::cout<<"2-> ordem decrescente"<<endl;
    std::cout<<"3-> primeiro pelas aulas teoricas"<<endl;
    std::cout<<"4-> pelo codigo da UC"<<endl;
    std::cout<<"5-> pela duracao da aula"<<endl;
    cin>> order;
    while(true) {
        switch (order) {
            case 2:
                if (x.orderWeekDay() == y.orderWeekDay()) {
                    if (starthour == other.starthour) return classcode > other.classcode;
                    else return starthour > other.starthour;
                }
                return orderWeekDay() > other.orderWeekDay();
            case 3:
                if (orderTypeClasses() == other.orderTypeClasses()) {
                    if (orderWeekDay() == other.orderWeekDay()) {
                        if (starthour == other.starthour) return classcode < other.classcode;
                        else return starthour < other.starthour;
                    }
                    return orderWeekDay() < other.orderWeekDay();
                }
                return orderTypeClasses() < other.orderTypeClasses();
            case 4:
                if (uccode == other.uccode) {
                    if (orderTypeClasses() == other.orderTypeClasses()) {
                        if (orderWeekDay() == other.orderWeekDay()) {
                            if (starthour == other.starthour) return classcode < other.classcode;
                            else return starthour < other.starthour;
                        }
                        return orderWeekDay() < other.orderWeekDay();
                    }
                    return orderTypeClasses() < other.orderTypeClasses();
                }
                return (uccode < other.uccode);
            case 5:
                if (duration == other.duration) {
                    if (orderWeekDay() == other.orderWeekDay()) {
                        if (starthour == other.starthour) return classcode < other.classcode;
                        else return starthour < other.starthour;
                    }
                    return orderWeekDay() < other.orderWeekDay();
                }
                return duration < other.duration;
            default:
                if (orderWeekDay() == other.orderWeekDay()) {
                    if (starthour == other.starthour) return classcode < other.classcode;
                    else return starthour < other.starthour;
                }
                return orderWeekDay() < other.orderWeekDay();
        }
    }
}
 */