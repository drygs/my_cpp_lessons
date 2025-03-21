#include "BingoGame.h"
#include <iostream>
#include <thread>
#include <chrono>

BingoGame::BingoGame() : geradorNumeros(1, 100) {}

void BingoGame::iniciar() {
    cout << "Jogo de Bingo Iniciado!\n";
}

void BingoGame::gerarCartoes(int numCartoes) {
    for (int i = 0; i < numCartoes; ++i) {
        BingoCard cartao(i + 1);
        cartao.gerar();
        cartao.imprimirParaFicheiro("cartao_" + to_string(i + 1) + ".txt");
        cartoes.push_back(cartao);
        cout << "Cartão " << i + 1 << " gerado e guardado num ficheiro.\n";
    }
}

void BingoGame::sortearNumero() {
    int numero = geradorNumeros.gerar();
    if (numero != -1) {
        cout << "Número sorteado: " << numero << "\n";
        Display::imprimirTabela(geradorNumeros.getNumerosSorteados());
        Display::imprimirUltimosCincoNumeros(geradorNumeros.getNumerosSorteados());
    } else {
        cout << "Todos os números foram sorteados.\n";
    }
}

void BingoGame::executarModoAutomatico() {
    while (true) {
        sortearNumero();
        if (geradorNumeros.getNumerosSorteados().size() == 100) {
            cout << "Todos os números foram sorteados. Fim do jogo!\n";
            break;
        }
        this_thread::sleep_for(chrono::seconds(5)); // Espera 5 segundos
    }
}

void BingoGame::executarModoManual() {
    while (true) {
        cout << "Pressione Enter para sortear o próximo número...";
        cin.get(); // Espera o utilizador pressionar Enter
        sortearNumero();
        if (geradorNumeros.getNumerosSorteados().size() == 100) {
            cout << "Todos os números foram sorteados. Fim do jogo!\n";
            break;
        }
    }
}