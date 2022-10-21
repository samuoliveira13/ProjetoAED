//
// Created by samuel on 13/10/2022.
//

#ifndef PROJETOAED_CLASS_H
#define PROJETOAED_CLASS_H
#include <string>
using namespace std;

class Class {
public:
    Class(string classcode, string uccode, string weekday, float starthour, float duration, string classtype);

    string setUccode(string uccode);
    string getUccode();

    string setClasstype(string classtype);
    string getClasstype();

    float setStarthour(float starthour);
    float getStarthour();

    float setDuration(float duration);
    float setDuration();

private:
    string classcode;
    string uccode;
    string weekday;
    float starthour;
    float duration;
    string classtype;

};


#endif //PROJETOAED_CLASS_H
