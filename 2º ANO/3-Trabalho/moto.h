#ifndef MOTO_H
#define MOTO_H

#include "Veiculo.h"

class Moto : public Veiculo {
private:
    std::string tipoDeGuidao;

public:
    Moto(const std::string& nome, const std::string& tipoDeGuidao);
    void mostrarDetalhes() const;
};

#endif
