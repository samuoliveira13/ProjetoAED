#include "include/Menu.h"
#include "include/Reader.h"
#include <iostream>
#include <vector>
#include "include/Class.h"
#include "include/Horario.h"
#include<bits/stdc++.h>

using namespace std;
Reader reader = Reader();
vector<Class> classList = reader.ReadClasses();
vector<Student> studentList = reader.ReadStudent();
Horario horario;
int order;

Menu::Menu() {
    mainMenu();
}

/**
 * @brief main menu that executes in the beggining, asks what the users wants to do
 */
void Menu::mainMenu() {
    int input;
    cout << "==============================================================" << endl << endl;
    cout << "Bem Vindo" << endl << endl;
    cout << "1 -> Ver Horarios" << endl;
    cout << "2 -> Ver Estudantes" << endl;
    cout << "3 -> Efetuar Alteracoes" << endl;
    cout << "Outro -> Sair" << endl << endl;
    cout << "==============================================================" << endl;
    cin >> input;
    cout << endl;

    switch (input) {
        case 1:
            int input1;
            cout << "==============================================================" << endl << endl;
            cout << "1 -> Ver o Horario de um Estudante." << endl;
            cout << "2 -> Ver o Horario de uma Turma" << endl;
            cout << "3 -> Ver o Horario de uma Cadeira" << endl;
            cout << "4 -> Ver o Horario de uma Cadeira, numa determinada Turma" << endl;
            cout << "Outro -> Sair" << endl << endl;
            cout << "==============================================================" << endl;
            cin >> input1;

            switch (input1) {
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
                default:
                    exit(-1);

            }
        case 2:
            int input2;
            cout << "==============================================================" << endl << endl;
            cout << "1 -> ver os estudantes de uma turma." << endl;
            cout << "2 -> ver os estudantes de uma cadeira" << endl;
            cout << "3 -> ver os estudantes de uma cadeira, numa determinada turma" << endl;
            cout << "4 -> ver os estudantes com mais de n cadeias" << endl;
            cout << "Outro -> Sair" << endl << endl;
            cout << "==============================================================" << endl;
            cin >> input2;

            switch (input2) {
                case 1:
                    EstudanteTurma();
                    break;
                case 2:
                    EstudanteCadeira();
                    break;
                case 3:
                    EstudanteCadeiraTurma();
                    break;
                case 4:
                    MaisCadeiras();
                    break;
                default:
                    exit(-1);
            }
        case 3:
            int input3;
            cout << "==============================================================" << endl << endl;
            cout << "1 -> remover um estudante de uma cadeira." << endl;
            cout << "2 -> inserir um estudantes numa cadeira" << endl;
            cout << "Outro -> Sair" << endl << endl;
            cout << "==============================================================" << endl;
            cin >> input3;
            switch (input3) {
                case 1:
                    RemoveStudentUc();
                    break;
                case 2:
                    InsertStudentUc();
                    break;
                default:
                    exit(-1);
            }
            break;
        default:
            exit(-1);
    }
}


/**
 * @brief checks if the student exists, and pushes his schedule to a vector horario
 * @return the student's schedule
 */
void Menu::EstudanteHorario() {
    string aluno;
    cout << "Introduza o up do estudante:";
    cin >> aluno;
    cout << endl;
    horario.clear();

    if (StudentExists(aluno) == false) {                        //se o up nao existir
        cout << "O numero que introduziu nao e valido" << endl;
        EstudanteHorario();                                     //reiniciar funcao
    } else {
        for (int i = 0; i < studentList.size(); i++) {
            if (studentList[i].getStudentcode() == aluno) {     //se o aluno for igual
                for (int j = 0; j < classList.size(); j++) {
                    if (studentList[i].getClassCode() == classList[j].getClassCode() &&     //pesquisar a turma e as
                        studentList[i].getUccode() == classList[j].getUccode()) {           //cadeiras do aluno
                        horario.push_back(classList[j]);
                    }
                }
            }
        }
    }

    order = horario.type_of_order();            //perguntar a categoria de ordenacao

    switch (order) {
        case 2:
            sort(horario.begin(), horario.end(), horario.decrescent_order);       //ordem decrescente
            break;
        case 3:
            sort(horario.begin(), horario.end(), horario.teoricas_first);        //primeiro teoricas
            break;
        case 4:
            sort(horario.begin(), horario.end(), horario.uc_order);               //codigo uc
            break;
        case 5:
            sort(horario.begin(), horario.end(), horario.duration_order);        //duracao
            break;
        default:
            sort(horario.begin(), horario.end(), horario.crescent_order);      //ordem crescente
            break;
    }
    horario.print();
    AfterExec();        //perguntar se acabou ou nao
}


/**
 * @brief checks if the class exists, and pushes its schedule to a vector horario
 * @return the class's schedule
 */
void Menu::TurmaHorario() {
    string turma;
    cout << "Introduza o numero da turma: ";
    cin >> turma;
    cout << endl;
    horario.clear();

    if (TurmaExists(turma) == false) {                          //se a turma nao existir
        cout << "A turma que introduziu nao e valida" << endl;
        TurmaHorario();                                         //reiniciar funcao
    } else {
        for (int i = 0; i < classList.size(); i++) {
            if (classList[i].getClassCode() == turma) {         //se a turma for igual
                horario.push_back(classList[i]);
            }
        }
    }
    order = horario.type_of_order();
    switch (order) {
        case 2:
            sort(horario.begin(), horario.end(), horario.decrescent_order);
            break;
        case 3:
            sort(horario.begin(), horario.end(), horario.teoricas_first);
            break;
        case 4:
            sort(horario.begin(), horario.end(), horario.uc_order);
            break;
        case 5:
            sort(horario.begin(), horario.end(), horario.duration_order);
            break;
        default:
            sort(horario.begin(), horario.end(), horario.crescent_order);
            break;
    }
    horario.print();
    AfterExec();        //perguntar se acabou ou nao
}


/**
 * @brief checks if the uc exists, and pushes its schedule to a vector horario
 * @return the uc's schedule
 */
void Menu::CadeiraHorario() {
    string cadeira;
    cout << "Introduza o numero da cadeira: ";
    cin >> cadeira;
    cout << endl;
    horario.clear();

    if (CadeiraExists(cadeira) == false) {                  //se a cadeira nao existir
        cout << "A cadeira que introduziu nao e valida" << endl;
        CadeiraHorario();                                         //reiniciar funcao
    } else {
        for (int i = 0; i < classList.size(); i++) {
            if (classList[i].getUccode() == cadeira) {              //se a cadeira for igual
                horario.push_back(classList[i]);
            }
        }
    }
    order = horario.type_of_order();
    switch (order) {
        case 2:
            sort(horario.begin(), horario.end(), horario.decrescent_order);
            break;
        case 3:
            sort(horario.begin(), horario.end(), horario.teoricas_first);
            break;
        case 4:
            sort(horario.begin(), horario.end(), horario.uc_order);
            break;
        case 5:
            sort(horario.begin(), horario.end(), horario.duration_order);
            break;
        default:
            sort(horario.begin(), horario.end(), horario.crescent_order);
            break;
    }
    horario.print();
    AfterExec();        //perguntar se acabou ou nao
}


/**
 * @brief checks if the uc exists in the class, and pushes its schedule to a vector horario
 * @return the uc's schedule in the class
 */
void Menu::CadeirainTurmaHorario() {
    string turma;
    string cadeira;
    cout << "Introduza a turma: ";
    cin >> turma;
    cout << endl;
    horario.clear();

    if (TurmaExists(turma) == false) {                          //se a turma nao existir
        cout << "A turma que introduziu nao existe" << endl;
        CadeirainTurmaHorario();                                //reiniciar funcao
    } else {
        cout << "Introduza o codigo da cadeira: ";
        cin >> cadeira;
        cout << endl;
        if (CadeirainTurmaExists(turma, cadeira) == false) {    //se a cadeira nao existir na turma
            cout << "A cadeira nao e valida" << endl;
            CadeirainTurmaHorario();                            //reiniciar funcao
        } else {
            for (int i = 0; i < classList.size(); i++) {
                if (classList[i].getUccode() == cadeira &&                  //se a cadeira e a
                    classList[i].getClassCode() == turma) {                  //turma forem iguais
                    horario.push_back(classList[i]);
                }
            }
        }
    }
    order = horario.type_of_order();
    switch (order) {
        case 2:
            sort(horario.begin(), horario.end(), horario.decrescent_order);
            break;
        case 3:
            sort(horario.begin(), horario.end(), horario.teoricas_first);
            break;
        case 4:
            sort(horario.begin(), horario.end(), horario.uc_order);
            break;
        case 5:
            sort(horario.begin(), horario.end(), horario.duration_order);
            break;
        default:
            sort(horario.begin(), horario.end(), horario.crescent_order);
            break;
    }
    horario.print();
    AfterExec();        //perguntar se acabou ou nao
}


/**
 * @brief checks if the class exists, and pushes its students to a vector classStudents
 * @return the class's students
 */
void Menu::EstudanteTurma() {
    set<string> classStudents = {};
    string turma;
    cout << "Introduza a turma: ";
    cin >> turma;
    cout << endl;

    if (TurmaExists(turma) == false) {                          //se a turma nao existir
        cout << "A turma que introduziu nao e valida" << endl;
        EstudanteTurma();                                       //reiniciar funcao
    } else {
        for (int i = 0; i < studentList.size(); i++) {
            if (studentList[i].getClassCode() == turma) {                   //se a turma for igual
                classStudents.insert(studentList[i].getStudentname());
            }
        }

        cout << "A turma " << turma << " tem " << classStudents.size() << " alunos:" << endl;

        for (string student: classStudents) {
            cout << student << endl;            //print a cada aluno
        }
    }
    AfterExec();        //perguntar se acabou ou nao
}


/**
 * @brief checks if the uc exists, and pushes its students to a vector ucStudents
 * @return the uc's students
 */
void Menu::EstudanteCadeira() {
    set<string> ucStudents = {};
    string cadeira;
    cout << "Introduza a cadeira: ";
    cin >> cadeira;
    cout << endl;

    if (CadeiraExists(cadeira) == false) {                  //se a cadeira nao existir
        cout << "A cadeira que introduziu nao e valida" << endl;
        EstudanteCadeira();                                       //reiniciar funcao
    } else {
        for (int i = 0; i < studentList.size(); i++) {
            if (studentList[i].getUccode() == cadeira) {                    //se a cadeira for igual
                ucStudents.insert(studentList[i].getStudentname());
            }
        }

        cout << "A cadeira " << cadeira << " tem " << ucStudents.size() << " alunos:" << endl;

        for (string student: ucStudents) {
            cout << student << endl;            //print a cada aluno
        }
    }
    AfterExec();        //perguntar se acabou ou nao
}


/**
 * @brief checks if the uc exists in the class, and pushes its students to a vector classStudents
 * @return the uc's students in the class
 */
void Menu::EstudanteCadeiraTurma() {
    set<string> ucStudents = {};
    string turma;
    string cadeira;
    cout << "Introduza a turma: ";
    cin >> turma;
    cout << endl;

    if (TurmaExists(turma) == false) {                      //se a turma nao existir
        cout << "A turma que introduziu nao existe" << endl;
        EstudanteCadeiraTurma();                            //reiniciar funcao
    } else {
        cout << "Introduza o codigo da cadeira: ";
        cin >> cadeira;
        if (CadeirainTurmaExists(turma, cadeira) == false) {    //se a cadeira nao existir dentro da turma
            cout << "A cadeira nao e valida" << endl;
            EstudanteCadeiraTurma();                            //reiniciar funcao
        } else {
            cout << endl;
            for (int i = 0; i < studentList.size(); i++) {
                if (studentList[i].getClassCode() == turma &&                   //se a turma e a
                    studentList[i].getUccode() == cadeira) {                    //cadeira forem iguais
                    ucStudents.insert(studentList[i].getStudentname());
                }
            }

            cout << "A cadeira " << cadeira << " da turma " << turma << " tem " << ucStudents.size() << " alunos"
                 << endl;

            for (string student: ucStudents) {
                cout << student << endl;            //print a cada aluno
            }
        }
    }
    AfterExec();        //perguntar se acabou ou nao
}

/**
 * @brief asks the number of Ucs, and returns the number and name of the students that have more than the number
 * @return number and names of the students
 */
void Menu::MaisCadeiras() {
    int n;
    int count = 0;
    set<string> ucStudents = {};
    cout << "Introduza o numero de cadeias: ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < studentList.size() - 1; i++) {
        for (int j = 1; j < studentList.size(); j++) {
            if (studentList[i].getStudentcode() == studentList[j].getStudentcode() &&
                studentList[i].getClassCode() != studentList[j].getClassCode()) {
                count++;
            }
        }
        if (count > n) {
            ucStudents.insert(studentList[i].getStudentname());
        }
        count = 0;
    }

    if (ucStudents.size() == 0) {
        cout << "Nao ha nenhum aluno com mais de " << n << " cadeiras." << endl;
    } else {
        cout << "Ha " << ucStudents.size() << " alunos com mais de " << n << " cadeiras: " << endl;

        for (string student: ucStudents) {
            cout << student << endl;
        }
    }
    AfterExec();        //perguntar se acabou ou nao
}


/**
 * @brief removes a student from a uc
 * @returns studentList without the student in the uc
 */
void Menu::RemoveStudentUc() {
    string aluno;
    string cadeira;
    cout << "Introduza o aluno que prentende remover: " << endl;
    cin >> aluno;
    if (StudentExists(aluno) == false) {
        cout << "O aluno que introduziu nao existe, introduza um aluno valido" << endl;
        RemoveStudentUc();
    } else {
        cout << "Introduza a cadeira: " << endl;
        cin >> cadeira;
        if (AlunoinCadeiraExists(aluno, cadeira)) {
            cout << "O aluno nao esta inscrito na cadeira que introduziu" << endl;
            RemoveStudentUc();
        } else {
            for (auto it = studentList.begin(); it != studentList.end(); it++) {
                if (it->getClassCode() == cadeira && it->getStudentcode() == aluno) {
                    studentList.erase(it);
                }
            }
            cout << "O aluno " << aluno << " foi removido da " << cadeira << endl;
        }
    }
    AfterExec();
}

void Menu::InsertStudentUc() {
    string nomeAluno;
    string classAluno;
    string aluno;
    string cadeira;
    string turma;
    cout << "Introduza o aluno: ";
    cin >> aluno;
    cout << endl;
    if (StudentExists(aluno) == false) {
        cout << "O aluno que introduziu nao existe, introduza um aluno valido" << endl;
        InsertStudentUc();
    } else {
        cout << "Introduza a unidade curricular: ";
        cin >> cadeira;
        if (AlunoinCadeiraExists(aluno, cadeira) == true) {
            cout << "O aluno ja esta inscrito na unidade curricular que introduziu" << endl;
            InsertStudentUc();
        } else {
            cout << "Introduza a turma em que o aluno vai ser inscrito: ";
            cin >> turma;
            if (TurmaExists(turma) == false) {
                cout << "A turma que introduziu nao existe, introduza uma turma valida" << endl;
                InsertStudentUc();
            } else {
                for (auto it = studentList.begin(); it != studentList.end(); it++) {
                    if (it->getStudentcode() == aluno) {
                        nomeAluno = it->getStudentname();
                    }
                }
                studentList.push_back(Student(aluno, nomeAluno, cadeira, turma));
                cout << "O aluno " << aluno << " foi inserido na uc " << cadeira << " na turma " << turma << endl;
            }
        }
    }
    AfterExec();
}

/**
 * @brief checks if the student exists
 * @return true or false
 */
bool Menu::StudentExists(string aluno) {
    bool res = false;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getStudentcode() == aluno) res = true;       //se o aluno existir
    }
    return res;
}


/**
 * @brief checks if the class exists
 * @return true or false
 */
bool Menu::TurmaExists(string turma) {
    bool res = false;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getClassCode() == turma) res = true;         //se a turma existir
    }
    return res;
}


/**
 * @brief checks if the uc exists
 * @return true or false
 */
bool Menu::CadeiraExists(string cadeira) {
    bool res = false;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getUccode() == cadeira) res = true;      //se a cadeira existir
    }
    return res;
}


/**
 * @brief checks if the uc exists in the class
 * @return true or false
 */
bool Menu::CadeirainTurmaExists(string turma, string cadeira) {
    bool res = false;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getClassCode() == turma) {                       //se a turma existir
            if (studentList[i].getUccode() == cadeira) res = true;          //se a cadeira existir na turma
        }
    }
    return res;
}

/**
 * @brief checks if the student has the uc
 * @return true or false
 */
bool Menu::AlunoinCadeiraExists(string aluno, string cadeira) {
    bool res = false;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getStudentcode() == aluno && studentList[i].getUccode() == cadeira) res = true;
    }
    return res;
}

/**
 * @brief executes after each process, asks if the user is done using the programm
 * @return 1) the user is not done (restarts) or 2) the user is done (exits programm)
 */
void Menu::AfterExec() {
    int num;
    cout << endl << "Pretende fazer mais alguma pesquisa?" << endl;
    cout << "1 -> Yes" << endl;
    cout << "2 -> No" << endl;
    cin >> num;
    switch (num) {
        case 1:
            mainMenu();             //voltar ao menu
            break;
        default:
            exit(-1);         //terminar execucao
    }
}