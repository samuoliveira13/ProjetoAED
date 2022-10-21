//
// Created by samue on 20/10/2022.
//

#include "include/Reader.h"
#include "include/Class.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void Reader() {

}

vector<string> Reader::ReadClasses() {
    fstream fin;
    fin.open("../schedule/classes.csv", ios::in);
    vector<Class> classList = {};
    vector<string> row;
    string line, word, temp;

    while (fin >> temp) {
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        //Class(row[0], row[1], row[2], row[3], row[4], row[5]);
        cout << "ClassCode: " << row[0] << " : \n";
        cout << "UcCode: " << row[1] << "\n";
        cout << "Weekday: " << row[2] << "\n";
        cout << "StartHour: " << row[3] << "\n";
        cout << "Duration: " << row[4] << "\n";
        cout << "Type: " << row[5] << "\n";
        break;
    }
}

Reader::Reader() {


}



