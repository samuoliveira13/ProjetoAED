//
// Created by samuel on 13/10/2022.
//

#include "include/Class.h"

Class::Class(string uccode, string classtype, float starthour, float duration) {
    this -> uccode = uccode;
    this -> classtype = classtype;
    this -> starthour = starthour;
    this -> duration = duration;
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