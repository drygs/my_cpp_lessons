#include <iostream>

using namespace std;


int RodarDado() {
    return rand() % 6 + 1; 
}


void mostrarDado(int numDado) {
    switch (numDado) {
        case 1:
            cout << "\n\t\t\t\t\t    *\n\n\n\n";
            break;
        case 2:
            cout << "\t\t\t\t\t  *\n\n\t\t\t\t\t      *\n\n\n";
            break;
        case 3:
            cout << "\t\t\t\t\t  *\n\t\t\t\t\t    *\n\t\t\t\t\t      *\n\n\n";
            break;
        case 4:
            cout << "\t\t\t\t\t  *   *\n\n\t\t\t\t\t  *   *\n\n\n";
            break;
        case 5:
            cout << "\t\t\t\t\t  *   *\n\t\t\t\t\t    *\n\t\t\t\t\t  *   *\n\n\n";
            break;
        case 6:
            cout << "\t\t\t\t\t  *   *\n\t\t\t\t\t  *   *\n\t\t\t\t\t  *   *\n\n\n";
            break;
        default:
            cout << "Erro: Valor inválido.\n";
    }
}


int main() {
   
    srand(time(NULL));
    int tentativas = 0;

    while (true) {
        system("cls");
        cout << "\f";
        cout << "\t\t\t  Dados Eletronicos - No Ambito do modulo\n";
        cout << "\t\t Programacaoo c/c++ Estruturas basicas e Conceitos Fundamentais\n";
        cout << "\t\t\t\t       ENTA - 2024\n";
        cout << "\n\n";
        int numDado = RodarDado();
        mostrarDado(numDado);

        cout << "\n\n";
        cout << "\t\t\t\t      Tentativas: " << tentativas << endl;
        cout << "\t\t        Pressione Enter para rolar o dado novamente.";
        cin.get();
        system("cls");

        tentativas++;
    }

    return 0;
}
