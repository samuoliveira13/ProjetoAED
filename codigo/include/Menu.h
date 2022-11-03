
#ifndef PROJETOAED_MENU_H
#define PROJETOAED_MENU_H

#include <string>
#include <vector>

class Menu {

public:
    Menu();

private:
    void mainMenu();
    void EstudanteHorario();
    void TurmaHorario();
    void CadeiraHorario();
    void CadeirainTurmaHorario();
    void EstudanteTurma();
    void EstudanteCadeira();
    void EstudanteCadeiraTurma();
    void MaisCadeiras();
    void RemoveStudentUc();
    void AfterExec();

    bool StudentExists(std::string aluno);
    bool TurmaExists(std::string turma);
    bool CadeiraExists(std::string turma);
    bool AlunoinCadeiraExists(std::string aluno, std::string turma);
    bool CadeirainTurmaExists(std::string turma, std::string cadeira);

    void InsertStudentUc();
};


#endif //PROJETOAED_MENU_H
