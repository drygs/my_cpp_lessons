#ifndef CARRO_H
#define CARRO_H

#include "Veiculo.h"

class Carro : public Veiculo {
private:
    int numeroDePortas;

public:
    Carro(const std::string& nome, int numeroDePortas);
    void mostrarDetalhes() const;
};

#endif
