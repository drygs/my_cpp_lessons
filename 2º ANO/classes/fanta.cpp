#include <iostream>
#include <string>
#include <random>

using namespace std;

class Lata_fanta {

    private:
    string marca, tipo, sabor, validade, ingredientes;
    int id_produto;
    bool state, agitada, caiu = false;
    
    void gas() {
        random_device rd;  // Seed inicial
        mt19937 gen(rd()); // Mersenne Twister
        uniform_int_distribution<> distrib(0, 2); // Distribuição entre 0, 1 e 2
        int nivel = distrib(gen);

        if(nivel == 0) {
            cout << "Sem gas" << "\n";
        } else if(nivel == 1) {
            cout << "Pouco gas" << "\n";
        } else {
            cout << "Muito gas" << "\n";
        }
    }
    void arrebenta() {
        if(agitada || caiu) {
            cout << "Lata aberta, mas voou sumo" << "\n";
        } else {
            cout << "Lata aberta" << "\n";
        }
    }

    public:

        // Mover a função gas() para a secção public

        void abrirLata() {
            if(state) {
                cout << "Lata já está aberta!" << "\n";
            } else {
                this->state = true;
                arrebenta();
                gas();
            }
        }
};

int main() {
    Lata_fanta lata;
    lata.abrirLata(); 
    return 0;
}
