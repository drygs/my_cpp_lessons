#include "BingoCard.h"
#include <fstream>
#include <algorithm>
#include <random>

BingoCard::BingoCard(int id) : id(id) {
    card.resize(5, vector<int>(5));
}

void BingoCard::generate() {
    vector<int> numbers;
    for (int i = 1; i <= 100; ++i) {
        numbers.push_back(i);
    }
    shuffle(numbers.begin(), numbers.end(), mt19937(random_device{}()));

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            card[i][j] = numbers[i * 5 + j];
        }
    }
}

void BingoCard::printToFile(const string& filename) const {
    ofstream file(filename);
    for (const auto& row : card) {
        for (int number : row) {
            file << number << "\t";
        }
        file << "\n";
    }
    file.close();
}