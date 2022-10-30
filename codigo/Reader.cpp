#include "include/Reader.h"
#include "include/Class.h"
#include "include/Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void Reader() {

}

vector<Class> Reader::ReadClasses() {
    int firstLine = 0;
    bool fim = true;
    fstream fin;
    fin.open("../schedule/classes.csv", ios::in);
    vector<Class> classList = {};
    vector<string> row;
    string line, word, temp;

    while (fim) {
        row.clear();
        getline(fin, line);
        if(line== "") break;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        //para passar a primeira linha
        if (firstLine == 0){
            firstLine++;
            continue;
        }

        classList.push_back(Class(row[0], row[1], row[2], stof(row[3]), stof(row[4]), row[5]));
    }
    return classList;
}

vector <Student> Reader::ReadStudent() {
    int firstLine=0;
    bool fim = true;
    fstream fin;
    fin.open("../schedule/students_classes.csv", ios::in);
    vector<Student> studentList = {};
    vector<string> row;
    string line, word, temp;

    while (fim) {
        row.clear();
        getline(fin, line);
        if(line == "") break;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        //para passar a primeira linha
        if (firstLine == 0){
            firstLine++;
            continue;
        }
        studentList.push_back(Student(row[0], row[1], row[2], row[3]));
    }
    return studentList;
}