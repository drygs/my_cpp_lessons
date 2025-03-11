#include "BingoGame.h"
#include <iostream>

using namespace std;

int main() {
    BingoGame game;
    game.start();

    int numCards;
    cout << "How many cards do you want to generate? ";
    cin >> numCards;
    game.generateCards(numCards);

    char mode;
    cout << "Choose mode (a for auto, m for manual): ";
    cin >> mode;

    if (mode == 'a' || mode == 'A') {
        game.runAutoMode();
    } else if (mode == 'm' || mode == 'M') {
        game.runManualMode();
    } else {
        cout << "Invalid mode selected.\n";
    }

    return 0;
}