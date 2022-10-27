#ifndef PROJETOAED_STUDENT_H
#define PROJETOAED_STUDENT_H

#include <string>

using namespace std;

class Student {
public:
    Student(string studentcode, string studentname, string ucCode, string classCode);
    string setStudentcode(string studentcode);
    string getStudentcode();
    string setStudentname(string studentname);
    string getStudentname();
    string setUccode(string uccode);
    string getUccode();
    string setClassCode(string classcode);
    string getClassCode();

private:
    string studentcode;
    string studentname;
    string uccode;
    string classcode;
    };

#endif //PROJETOAED_STUDENT_H
