#include "include/Menu.h"
#include "include/Reader.h"
#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
Reader reader = Reader();
vector<Class> classList = reader.ReadClasses();
vector<Student> studentList = reader.ReadStudent();

Menu::Menu() {
    mainMenu();
}

void Menu::mainMenu() {
    do {
        int input;
        cout << "1 -> ver o horario de um estudante." << endl;
        cout << "2 -> ver o horario de uma turma" << endl;
        cout << "3 -> ver o horario de uma cadeira" << endl;
        cout << "4 -> ver o horario de uma cadeira, numa determinada turma" << endl;
        cout << "5 -> ver os estudantes de uma turma." << endl;
        cout << "6 -> ver os estudantes de uma cadeira" << endl;
        cout << "7 -> ver os estudantes de uma cadeira, numa determinada turma." << endl;
        cout << "8 -> sair" << endl;
        cin >> input;

        switch (input) {
            case 1:
                EstudanteHorario();
                break;
            case 2:
                TurmaHorario();
                break;
            case 3:
                CadeiraHorario();
                break;
            case 4:
                CadeirainTurmaHorario();
                break;
            case 5:
                EstudanteTurma();
                break;
            case 6:
                EstudanteCadeira();
                break;
            case 7:
                EstudanteCadeiraTurma();
                break;
            default:
                exit(-1);
        }
    }while(true);
}


void Menu::EstudanteHorario() {
    string aluno;
    cout << "Introduza o up do estudante:";
    cin >> aluno;
    vector<Class> horario;

    if (StudentExists(aluno) == false) {
        cout << "O numero que introduziu nao e valido" << endl;
        EstudanteHorario();
    } else {
        for (int i = 0; i < studentList.size(); i++) {
            if (studentList[i].getStudentcode() == aluno) {
                for (int j = 0; j < classList.size(); j++) {
                    if (studentList[i].getClassCode() == classList[j].getClassCode() &&
                        studentList[i].getUccode() == classList[j].getUccode()) {
                        horario.push_back(classList[j]);
                    }
                }
            }
        }
    }
    sort(horario.begin(),horario.end());
    for(auto x:horario) {
        cout << x.getWeekDay() << " | Class: " << x.getClassCode()
             << " | Uc: " << x.getUccode() << " | ClassType: "
             << x.getClassType()
             << " | StartHour: " << x.getStarthour() << " | Duration: "
             << x.getDuration()
             << endl;
    }
}


void Menu::TurmaHorario() {
    string turma;
    cout << "Introduza o numero da turma: ";
    cin >> turma;
    cout << endl;
    if (TurmaExists(turma) == false) {
        cout << "A turma que introduziu nao e valida" << endl;
        TurmaHorario();
    } else {
        for (int i = 0; i < classList.size(); i++) {
            if (classList[i].getClassCode() == turma) {
                cout << classList[i].getWeekDay() << " | Uc: " << classList[i].getUccode()
                     << " | ClassType: " << classList[i].getClassType()
                     << " | StartHour: " << classList[i].getStarthour() << " | Duration: "
                     << classList[i].getDuration()
                     << endl;
            }
        }
    }
}


void Menu::CadeiraHorario() {
    string cadeira;
    cout << "Introduza o numero da cadeira: ";
    cin >> cadeira;
    cout << endl;
    if (CadeiraExists(cadeira) == false) {
        cout << "A cadeira que introduziu nao e valida" << endl;
        CadeiraHorario();
    } else {
        for (int i = 0; i < classList.size(); i++) {
            if (classList[i].getUccode() == cadeira) {
                cout << classList[i].getWeekDay() << " | Class: " << classList[i].getClassCode()
                     << " | ClassType: " << classList[i].getClassType()
                     << " | StartHour: " << classList[i].getStarthour() << " | Duration: "
                     << classList[i].getDuration()
                     << endl;
            }
        }
    }
}


void Menu::CadeirainTurmaHorario() {
    string turma;
    string cadeira;
    cout << "Introduza a turma: ";
    cin >> turma;
    if (TurmaExists(turma) == false) {
        cout << "A turma que introduziu nao existe" << endl;
        CadeirainTurmaHorario();
    } else {
        cout << "Introduza o codigo da cadeira: ";
        cin >> cadeira;
        cout << endl;
        if (CadeirainTurmaExists(turma, cadeira) == false) {
            cout << "A cadeira nao e valida" << endl;
            CadeirainTurmaHorario();
        } else {
            for (int i = 0; i < classList.size(); i++) {
                if (classList[i].getUccode() == cadeira && classList[i].getClassCode() == turma) {
                    cout << classList[i].getWeekDay() << " | Class: " << classList[i].getClassCode()
                         << " | Type: " << classList[i].getClassType()
                         << " | StartHour: " << classList[i].getStarthour() << " | Duration: "
                         << classList[i].getDuration()
                         << endl;
                }
            }
        }
    }
}

void Menu::EstudanteTurma() {
    set<string> classStudents = {};
    string turma;
    cout << "Introduza a turma: ";
    cin >> turma;

    if (TurmaExists(turma) == false) {
        cout << "A turma que introduziu nao e valida" << endl;
        EstudanteTurma();
    } else {
        for (int i = 0; i < studentList.size(); i++) {
            if (studentList[i].getClassCode() == turma) {
                classStudents.insert(studentList[i].getStudentname());
            }
        }

        cout << "A turma " << turma << " tem " << classStudents.size() << " alunos:" << endl;

        for (string student: classStudents) {
            cout << student << endl;
        }
    }
}

void Menu::EstudanteCadeira() {
    set<string> ucStudents = {};
    string cadeira;
    cout << "Introduza a cadeira: ";
    cin >> cadeira;

    if (CadeiraExists(cadeira) == false) {
        cout << "A cadeira que introduziu nao e valida" << endl;
        EstudanteCadeira();
    } else {
        for (int i = 0; i < studentList.size(); i++) {
            if (studentList[i].getUccode() == cadeira) {
                ucStudents.insert(studentList[i].getStudentname());
            }
        }

        cout << "A cadeira " << cadeira << " tem " << ucStudents.size() << " alunos:" << endl;

        for (string student: ucStudents) {
            cout << student << endl;
        }
    }
}

void Menu::EstudanteCadeiraTurma() {
    set<string> ucStudents = {};
    string turma;
    string cadeira;
    cout << "Introduza a turma: ";
    cin >> turma;
    if (TurmaExists(turma) == false) {
        cout << "A turma que introduziu nao existe" << endl;
        EstudanteCadeiraTurma();
    } else {
        cout << "Introduza o codigo da cadeira: ";
        cin >> cadeira;
        if (CadeirainTurmaExists(turma, cadeira) == false) {
            cout << "A cadeira nao e valida" << endl;
            EstudanteCadeiraTurma();
        } else {
            cout << endl;
            for (int i = 0; i < studentList.size(); i++) {
                if (studentList[i].getClassCode() == turma && studentList[i].getUccode() == cadeira) {
                    ucStudents.insert(studentList[i].getStudentname());
                }
            }

            cout << "A cadeira " << cadeira << " da turma " << turma << " tem " << ucStudents.size() << " alunos"
                 << endl;
            for (string student: ucStudents) {
                cout << student << endl;
            }
        }
    }
}


bool Menu::StudentExists(string aluno) {
    bool res = false;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getStudentcode() == aluno) res = true;
    }
    return res;
}

bool Menu::TurmaExists(string turma) {
    bool res = false;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getClassCode() == turma) res = true;
    }
    return res;
}

bool Menu::CadeiraExists(string cadeira) {
    bool res = false;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getUccode() == cadeira) res = true;
    }
    return res;
}

bool Menu::CadeirainTurmaExists(string turma, string cadeira) {
    bool res = false;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getClassCode() == turma) {
            if (studentList[i].getUccode() == cadeira) res = true;
        }
    }
    return res;
}
