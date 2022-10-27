#include "codigo/include/Menu.h"
#include "codigo/include/Reader.h"
#include <iostream>
using namespace std;
Reader reader = Reader();
vector <Class> classList = reader.ReadClasses();
vector <Student> studentList = reader.ReadStudent();

Menu::Menu() {
    mainMenu();
}

void Menu::mainMenu() {
    int input;
    cout << "Precione 1 para ver a turma do estudante." << endl;
    cout << "Precione 2 para ver o horário do estudante." << endl;
    cout << "Precione 3 para sair." << endl;
    cin >> input;

    switch (input) {
        case 1:
            EstudanteTurma();
            break;
        case 2:
            //EstudanteHorario();
            break;
        case 3:
            break;
    }
};

void Menu::EstudanteTurma() {
    string aluno;
    cout << "Introduza o up do estudante: " ;
    cin >> aluno;
    vector <Class> classList = reader.ReadClasses();
    vector <Student> studentList = reader.ReadStudent();
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getStudentcode() == aluno) {
            for (int j=0; j < classList.size(); j++) {

            }
        }

    }
}

void EstudanteHorario() {

}



