#include "NumberGenerator.h"
#include <algorithm>

NumberGenerator::NumberGenerator(int min, int max) : rng(random_device{}()) {
    for (int i = min; i <= max; ++i) {
        numbers.push_back(i);
    }
    shuffle(numbers.begin(), numbers.end(), rng);
}

int NumberGenerator::generate() {
    if (numbers.empty()) {
        return -1; // Todos os números foram sorteados
    }
    int number = numbers.back();
    numbers.pop_back();
    drawnNumbers.push_back(number);
    return number;
}

void NumberGenerator::reset() {
    drawnNumbers.clear();
    shuffle(numbers.begin(), numbers.end(), rng);
}

const vector<int>& NumberGenerator::getDrawnNumbers() const {
    return drawnNumbers;
}