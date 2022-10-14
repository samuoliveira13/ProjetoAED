//
// Created by samuel on 13/10/2022.
//

#include "include/Student.h"

Student::Student(int studentcode, string studentname) {
    setStudentcode(studentcode);
    setStudentname(studentname);

}

int Student::setStudentcode(int studentcode) {
    this -> studentcode = studentcode;
}
int Student::getStudentcode() {
    return this -> studentcode;
}

string Student::setStudentname(std::string studentname) {
    this -> studentname = studentname;
}
string Student::getStudentname() {
    return this -> studentname;
}