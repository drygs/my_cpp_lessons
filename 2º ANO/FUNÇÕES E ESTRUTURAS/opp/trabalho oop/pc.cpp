#include <iostream>
#include <string>
using namespace std;

struct hardware {
    string RAM;
    string CPU;
    string GPU;
    string DISCO_RIGIDO;
    string PSU;
    string CAIXA;
    string MOTHERBOARD;
    string DISPO_EXTER;
    string PANs;
};

class Pc {
public:
    hardware hw;

    // Constructor para inicializar o hardware
    Pc(hardware h) : hw(h) {} // MUDANÇA

    void ligar() {
        cout << "PC is turning on." << endl;
    }

    void desligar() {
        cout << "PC is turning off." << endl;
    }

    void reset() {
        cout << "PC is resetting." << endl;
    }

    void abrir_tampa() {
        cout << "Opening case." << endl;
    }

    void executar() {
        formatar();
        abrir_pasta();
        init_SO();
        remove_ficheros();
    }

    void input() {
        cout << "Receiving input." << endl;
    }

private:
    void formatar() {
        cout << "Formatting system." << endl;
    }

    void abrir_pasta() {
        cout << "Opening folder." << endl;
    }

    void init_SO() const {
        cout << "Initializing operating system." << endl;
    }

    void remove_ficheros() {
        cout << "Removing files." << endl;
    }
};

// Adicionei o parâmetro Pc &pc para aceitar o objeto pc1 // MUDANÇA
void menu(Pc &pc) { // MUDANÇA
    int opcao;
    cout << "Escolha a Opcão \n1-Ligar \n2-Desligar \n3-Reset \n4-Executar \n5-Input" << endl;
    cin >> opcao;
    switch(opcao) {
        case 1:
            pc.ligar(); // MUDANÇA: chamei ligar() usando o objeto pc
            break;
        case 2:
            pc.desligar(); // MUDANÇA: chamei desligar() usando o objeto pc
            break;
        case 3:
            pc.reset(); // MUDANÇA: chamei reset() usando o objeto pc
            break;
        case 4:
            pc.executar(); // MUDANÇA: chamei executar() usando o objeto pc
            break;
        case 5:
            pc.input(); // MUDANÇA: chamei input() usando o objeto pc
            break;
        default: // MUDANÇA: movi o default para dentro do switch
            cout << "Opção inválida." << endl; 
            break;
    }
}

int main() {
    hardware hardware1 = {"16GB RAM", "RYZEN 5 7535HS", "RTX 3050", "500GB SSD", "1000W PSU", "MSI Case", "GIGABYTE Motherboard", "500GB External", "500GB Backup"};
    Pc pc1(hardware1);

    // Passei o objeto pc1 para o menu // MUDANÇA
    menu(pc1); // MUDANÇA

    return 0;
}
