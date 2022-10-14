//
// Created by samuel on 13/10/2022.
//

#ifndef PROJETOAED_CLASS_H
#define PROJETOAED_CLASS_H
#include <string>
using namespace std;

class Class {
public:
    Class(string uccode, string classtype, float starthour, float duration);

    string setUccode(string uccode);
    string getUccode();

    string setClasstype(string classtype);
    string getClasstype();

    float setStarthour(float starthour);
    float getStarthour();

    float setDuration(float duration);
    float getDuration();

private:
    string uccode;
    string classtype;
    float starthour;
    float duration;

};


#endif //PROJETOAED_CLASS_H
