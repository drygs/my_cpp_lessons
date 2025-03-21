#include "NumberGenerator.h"
#include <algorithm>

NumberGenerator::NumberGenerator(int min, int max) : rng(random_device{}()) {
    for (int i = min; i <= max; ++i) {
        numeros.push_back(i);
    }
    shuffle(numeros.begin(), numeros.end(), rng);
}

int NumberGenerator::gerar() {
    if (numeros.empty()) {
        return -1; // Todos os números foram sorteados
    }
    int numero = numeros.back();
    numeros.pop_back();
    numerosSorteados.push_back(numero);
    return numero;
}

void NumberGenerator::reiniciar() {
    numerosSorteados.clear();
    shuffle(numeros.begin(), numeros.end(), rng);
}

const vector<int>& NumberGenerator::getNumerosSorteados() const {
    return numerosSorteados;
}