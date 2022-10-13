//
// Created by samuel on 13/10/2022.
//

#include "include/Student.h"

Student::Student(int studentcode, string studentname) {
    this -> studentcode = studentcode;
    this -> studentname = studentname;

}

int Student::setStudentcode(int studentcode) {
    this -> studentcode = studentcode;
}

string Student::setStudentname(std::string studentname) {
    this -> studentname = studentname;
}