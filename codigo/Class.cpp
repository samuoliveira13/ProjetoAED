//
// Created by samuel on 13/10/2022.
//

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
};