#ifndef NUMBERGENERATOR_H
#define NUMBERGENERATOR_H

#include <vector>
#include <random>

using namespace std;

class NumberGenerator {
public:
    NumberGenerator(int min, int max);
    int generate();
    void reset();
    const vector<int>& getDrawnNumbers() const;

private:
    vector<int> numbers;
    vector<int> drawnNumbers;
    mt19937 rng;
};

#endif