#include "include/Student.h"

Student::Student(string studentcode, string studentname, string uccode, string classcode) {
    this -> studentcode = studentcode;
    this -> studentname = studentname;
    this -> uccode = uccode;
    this -> classcode = classcode;
}

string Student::setStudentcode(string studentcode) {
    this -> studentcode = studentcode;
}

string Student::getStudentcode() {
    return studentcode;
}

string Student::setStudentname(std::string studentname) {
    this -> studentname = studentname;
}

string Student::getStudentname() {
    return studentname;
}

string Student::setUccode(std::string uccode) {
    this -> uccode = uccode;
}

string Student::getUccode() {
    return uccode;
}

string Student::setClassCode(string classcode){
    this -> classcode = classcode;
}

string Student::getClassCode(){
    return classcode;
}
