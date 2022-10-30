
#ifndef PROJETOAED_MENU_H
#define PROJETOAED_MENU_H

#include <string>

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

    bool TurmaExists(std::string turma);
    bool CadeirainTurmaExists(std::string turma, std::string cadeira);
    bool StudentExists(std::string aluno);
    bool CadeiraExists(std::string turma);

};


#endif //PROJETOAED_MENU_H
