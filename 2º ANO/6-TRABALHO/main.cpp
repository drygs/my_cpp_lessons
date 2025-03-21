#include "BingoGame.h"
#include <iostream>

using namespace std;

int main() {
    BingoGame jogo;
    jogo.iniciar();

    int numCartoes;
    cout << "Quantos cartões deseja gerar? ";
    cin >> numCartoes;
    jogo.gerarCartoes(numCartoes);

    char modo;
    cout << "Escolha o modo (a para automático, m para manual): ";
    cin >> modo;

    if (modo == 'a' || modo == 'A') {
        jogo.executarModoAutomatico();
    } else if (modo == 'm' || modo == 'M') {
        jogo.executarModoManual();
    } else {
        cout << "Modo inválido selecionado.\n";
    }

    return 0;
}