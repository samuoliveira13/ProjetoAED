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
    float setStarthour(float starthour);
    float getStarthour();
    float setDuration(float duration);
    float getDuration();
    string getClassType();
    string getWeekDay();
    string getClassCode();
    int orderWeekDay();
    int orderTypeClasses();
private:
    string classcode;
    string uccode;
    string weekday;
    float starthour;
    float duration;
    string classtype;

};


#endif //PROJETOAED_CLASS_H
