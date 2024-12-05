#include "Carro.h"
#include "Moto.h"

int main() {
    Carro meuCarro("Toyota Supra MK3", 2);
    Moto minhaMoto("Yamaha MT-07", "Esportivo");

    meuCarro.mostrarDetalhes();
    minhaMoto.mostrarDetalhes();


    return 0;
}
