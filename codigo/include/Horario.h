
#ifndef PROJETOAED_HORARIO_H
#define PROJETOAED_HORARIO_H
#include <vector>
#include "Class.h"

class Horario{
public:

    vector<Class> getHorario();
    vector<Class> add_to_horario(Class x);
    vector<Class> remove_from_horario(Class x);
    vector<Class>::iterator begin();
    vector<Class>::iterator end();

    Horario();
    Horario(vector<Class> horario);

    /**
     * @brief ways to clear, insert, order and print the schedule
     */
    void clear();
    void push_back(Class x);
    void ordenar(int order);
    void print();

    /**
     * @brief order schedule in different ways
     * @param x
     * @param y
     * @return ordered schedule
     */
    int type_of_order();
    bool static decrescent_order(Class x,Class y);
    bool static teoricas_first(Class x,Class y);
    bool static uc_order(Class x,Class y);
    bool static duration_order(Class x,Class y);
    bool static crescent_order(Class x,Class y);

    /**
     * @brief transform default starthour (ex: 10.5) to normal hours and minutes (10:30)
     * @param hour
     * @return
     */
    string TransformHour(float hour);

    /**
     * @brief get the finalhour by adding the duration to the starthour
     * @param starthour
     * @param duration
     * @return finalhour
     */
    string SumHours(float starthour, float duration);

private:

    vector<Class> horario;

    void UcMap();
};

#endif //PROJETOAED_HORARIO_H
