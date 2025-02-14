#include "Carro.h"
#include <iostream>

Carro::Carro(const std::string& nome, int numeroDePortas)
    : Veiculo(nome), numeroDePortas(numeroDePortas) {}

void Carro::mostrarDetalhes() const {
    std::cout << "Carro: " << nome << ", Número de portas: " << numeroDePortas << std::endl;
}
