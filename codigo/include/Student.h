//
// Created by samuel on 13/10/2022.
//

#ifndef PROJETOAED_STUDENT_H
#define PROJETOAED_STUDENT_H
#include <string>
using namespace std;

class Student {
public:
    Student(int studentcode, string studentname);

    int setStudentcode(int studentcode);
    int getStudentcode();

    string setStudentname(string studentname);
    string getStudentname();

private:
    int studentcode;
    string studentname;

};

#endif //PROJETOAED_STUDENT_H
