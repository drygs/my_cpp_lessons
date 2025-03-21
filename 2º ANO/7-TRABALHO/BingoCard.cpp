#include "BingoCard.h"
#include <fstream>
#include <algorithm>
#include <random>

BingoCard::BingoCard(int id) : id(id) {
    cartao.resize(5, vector<int>(5));
}

void BingoCard::gerar() {
    vector<int> numeros;
    for (int i = 1; i <= 100; ++i) {
        numeros.push_back(i);
    }
    shuffle(numeros.begin(), numeros.end(), mt19937(random_device{}()));

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cartao[i][j] = numeros[i * 5 + j];
        }
    }
}

void BingoCard::imprimirParaFicheiro(const string& nomeFicheiro) const {
    ofstream ficheiro(nomeFicheiro);
    for (const auto& linha : cartao) {
        for (int numero : linha) {
            ficheiro << numero << "\t";
        }
        ficheiro << "\n";
    }
    ficheiro.close();
}