#ifndef BINGOCARD_H
#define BINGOCARD_H

#include <vector>
#include <string>

using namespace std;

class BingoCard {
public:
    BingoCard(int id);
    void gerar();
    void imprimirParaFicheiro(const string& nomeFicheiro) const;

private:
    int id;
    vector<vector<int>> cartao;
};

#endif