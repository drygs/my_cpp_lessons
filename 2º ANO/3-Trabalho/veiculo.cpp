#include "Veiculo.h"
#include <iostream>

Veiculo::Veiculo(const std::string& nome) : nome(nome) {}

void Veiculo::mostrarDetalhes() const {
    std::cout << "Nome do veículo: " << nome << std::endl;
}
