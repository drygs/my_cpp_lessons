#include "BingoGame.h"
#include <iostream>
#include <thread>
#include <chrono>

BingoGame::BingoGame() : numberGenerator(1, 100) {}

void BingoGame::start() {
    cout << "Bingo Game Started!\n";
}

void BingoGame::generateCards(int numCards) {
    for (int i = 0; i < numCards; ++i) {
        BingoCard card(i + 1);
        card.generate();
        card.printToFile("card_" + to_string(i + 1) + ".txt");
        cards.push_back(card);
        cout << "Card " << i + 1 << " generated and saved to file.\n";
    }
}

void BingoGame::drawNumber() {
    int number = numberGenerator.generate();
    if (number != -1) {
        cout << "Number drawn: " << number << "\n";
        Display::printTable(numberGenerator.getDrawnNumbers());
    } else {
        cout << "All numbers have been drawn.\n";
    }
}

void BingoGame::runAutoMode() {
    while (true) {
        drawNumber();
        if (numberGenerator.getDrawnNumbers().size() == 100) {
            cout << "All numbers have been drawn. Game over!\n";
            break;
        }
        this_thread::sleep_for(chrono::seconds(5)); // Espera 5 segundos
    }
}

void BingoGame::runManualMode() {
    while (true) {
        cout << "Press Enter to draw the next number...";
        cin.get(); // Espera o usuário pressionar Enter
        drawNumber();
        if (numberGenerator.getDrawnNumbers().size() == 100) {
            cout << "All numbers have been drawn. Game over!\n";
            break;
        }
    }
}