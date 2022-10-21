#include <iostream>
#include "codigo/Student.cpp"
#include "codigo/Class.cpp"
#include "codigo/Turma.cpp"
#include <algorithm>
#include <fstream>

using namespace std;


int main() {
    int i;
    int studentcode;
    cout<< "Introduza o seu número mecanográfico (Ex: 202012345);\n";
    cin >> studentcode;
    while (true) {
        cout << "Pressione 1 se quiser sair da sua turma atual;\n";
        cout << "Pressione 2 se quiser ingressar numa turma,caso não esteja inscrito e caso esta não desiquilibre as turmas da UC;\n";
        cout << "Pressione 3 se quiser trocar uma turma de uma determinada UC;\n";
        cout << "Pressione 4 se quiser trocar várias turmas de várias UCs;\n";
        cout << "Pressione outra tecla se já tiver terminado;\n";
        cin >> i;
        switch (i) {
            case (1): {
                cout << add_to_class();
                break;
            }
            case (2): {
                cout << remove_from_class();
                break;
            }
            case (3): {
                cout << change_a_class();
                break;
            }
            case (4): {
                cout << change_some_classes();
                break;
            }
            default: {
                return 0;
            }
        }
        cout<<"\n";
    }
}
