//
// Created by samuel on 13/10/2022.
//cd

#include "include/Turma.h"

Turma::Turma(string classcode) {
    setClasscode(classcode);
}

string Turma::setClasscode(std::string classcode) {
    this -> classcode = classcode;
}
string Turma::getClasscode() {
    return this -> classcode;
}
