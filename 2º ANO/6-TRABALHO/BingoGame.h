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
    void start();
    void generateCards(int numCards);
    void drawNumber();
    void runAutoMode();
    void runManualMode();

private:
    NumberGenerator numberGenerator;
    vector<BingoCard> cards;
};

#endif