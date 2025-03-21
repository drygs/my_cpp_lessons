#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <string>

using namespace std;

class Display {
public:
    static void imprimirTabela(const vector<int>& numerosSorteados);
    static void imprimirUltimosCincoNumeros(const vector<int>& numerosSorteados);
};

#endif