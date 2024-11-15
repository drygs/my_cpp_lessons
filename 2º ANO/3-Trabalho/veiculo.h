#ifndef VEICULO_H
#define VEICULO_H

#include <string>

class Veiculo {
protected:
    std::string nome;

public:
    Veiculo(const std::string& nome);
    void mostrarDetalhes() const;
};

#endif
