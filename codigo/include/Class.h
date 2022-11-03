#ifndef PROJETOAED_CLASS_H
#define PROJETOAED_CLASS_H
#include <string>
using namespace std;

class Class {
public:
    Class(string classcode, string uccode, string weekday, float starthour, float duration, string classtype);

    /**
     * @brief Setter and Getter for the uccode
     * @param uccode
     * @return uccode
     */
    string setUccode(string uccode);
    string getUccode();

    /**
     * @brief Setter and Getter for the classtype
     * @param classtype
     * @return classtype
     */
    string setClasstype(string classtype);
    string getClassType();

    /**
     * @brief Setter and Getter for the starthour
     * @param starthour
     * @return starthour
     */
    float setStarthour(float starthour);
    float getStarthour();

    /**
     * @brief Setter and Getter for the duration
     * @param duration
     * @return duration
     */
    float setDuration(float duration);
    float getDuration();

    /**
     * @brief Setter and Getter for the weekday
     * @param weekday
     * @return weekday
     */
    string setWeekDay(string weekday);
    string getWeekDay();

    /**
     * @brief Setter and Getter for the classcode
     * @param classcode
     * @return classcode
     */
    string setClassCode();
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
