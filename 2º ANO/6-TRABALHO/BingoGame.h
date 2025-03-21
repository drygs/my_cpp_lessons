#ifndef BINGOGAME_H
#define BINGOGAME_H

#include "NumberGenerator.h"
#include "BingoCard.h"
#include "Display.h"
#include <vector>

using namespace std;

class BingoGame {
public:
    BingoGame();
    void iniciar();
    void gerarCartoes(int numCartoes);
    void sortearNumero();
    void executarModoAutomatico();
    void executarModoManual();

private:
    NumberGenerator geradorNumeros;
    vector<BingoCard> cartoes;
};

#endif