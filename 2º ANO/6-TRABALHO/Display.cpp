#include "Display.h"
#include <iostream>
#include <iomanip>
#include <algorithm> // Adicionei o cabeçalho <algorithm> para usar o find

using namespace std;

// Códigos ANSI para cores
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

void Display::printTable(const vector<int>& drawnNumbers) {
    // Limpa o terminal antes de exibir a tabela
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Linux/Mac
    #endif

    cout << "\n=== Bingo Numbers ===\n";
    for (int i = 1; i <= 100; ++i) {
        // Verifica se o número já foi sorteado
        bool isDrawn = find(drawnNumbers.begin(), drawnNumbers.end(), i) != drawnNumbers.end();
        if (isDrawn) {
            cout << RED << setw(3) << i << RESET << " ";
        } else {
            cout << GREEN << setw(3) << i << RESET << " ";
        }
        if (i % 10 == 0) {
            cout << "\n";
        }
    }
    cout << "\n";
}