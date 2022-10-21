//
// Created by samuel on 13/10/2022.
//

#ifndef PROJETOAED_TURMA_H
#define PROJETOAED_TURMA_H
#include <string>
using namespace std;

class Turma {
public:
    Turma(string classcode);

    string setClasscode(string classcode);
    string getClasscode();

private:
    string classcode;

};


#endif //PROJETOAED_TURMA_H
