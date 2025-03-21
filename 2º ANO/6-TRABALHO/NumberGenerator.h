#ifndef NUMBERGENERATOR_H
#define NUMBERGENERATOR_H

#include <vector>
#include <random>

using namespace std;

class NumberGenerator {
public:
    NumberGenerator(int min, int max);
    int gerar();
    void reiniciar();
    const vector<int>& getNumerosSorteados() const;

private:
    vector<int> numeros;
    vector<int> numerosSorteados;
    mt19937 rng;
};

#endif