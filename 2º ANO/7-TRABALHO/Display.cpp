#include "Display.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Códigos ANSI para cores
#define RESET   "\033[0m"
#define VERMELHO     "\033[31m"
#define VERDE   "\033[32m"

void Display::imprimirTabela(const vector<int>& numerosSorteados) {
    // Limpa o terminal antes de exibir a tabela
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Linux/Mac
    #endif

    cout << "\n=== Números do Bingo ===\n";
    for (int i = 1; i <= 100; ++i) {
        // Verifica se o número já foi sorteado
        bool foiSorteado = find(numerosSorteados.begin(), numerosSorteados.end(), i) != numerosSorteados.end();
        if (foiSorteado) {
            cout << VERMELHO << setw(3) << i << RESET << " ";
        } else {
            cout << VERDE << setw(3) << i << RESET << " ";
        }
        if (i % 10 == 0) {
            cout << "\n";
        }
    }
    cout << "\n";
}

void Display::imprimirUltimosCincoNumeros(const vector<int>& numerosSorteados) {
    if (numerosSorteados.size() > 0) {
        cout << "Últimos números sorteados: ";
        // Exibe apenas os últimos 5 números
        int inicio = (numerosSorteados.size() > 5) ? numerosSorteados.size() - 5 : 0;
        for (size_t i = inicio; i < numerosSorteados.size(); ++i) {
            cout << numerosSorteados[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "Nenhum número foi sorteado ainda.\n";
    }
}