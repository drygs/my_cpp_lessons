#include "Moto.h"
#include <iostream>

Moto::Moto(const std::string& nome, const std::string& tipoDeGuidao)
    : Veiculo(nome), tipoDeGuidao(tipoDeGuidao) {}

void Moto::mostrarDetalhes() const {
    std::cout << "Moto: " << nome << ", Tipo de guidão: " << tipoDeGuidao << std::endl;
}
