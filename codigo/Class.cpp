//
// Created by samuel on 13/10/2022.
//

#include "include/Class.h"

Class::Class(string uccode, string classtype, float starthour, float duration) {
    setUccode(uccode);
    setClasstype(classtype);
    setStarthour(starthour);
    setDuration(duration);
}

string Class::setUccode(string uccode){
    this -> uccode = uccode;
}
string Class::getUccode() {
    return this -> uccode;
}

string Class::setClasstype(string classtype){
    this -> classtype = classtype;
}
string Class::getClasstype() {
    return this -> classtype;
}

float Class::setStarthour(float starthour){
    this -> starthour = starthour;
}
float Class::getStarthour() {
    return this -> starthour;
}

float Class::setDuration(float duration){
    this -> duration = duration;
};
float Class::getDuration(){
    return this -> duration;
}