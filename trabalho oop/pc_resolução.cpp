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
    string FANs;
    char perifericos[5]; // 5 elementos
};

class Computer {
private:
    hardware computer;
    bool state;

    void formatar() {
        cout << "Formatting system." << endl;
    }

    void abrir_pasta() {
        cout << "Opening folder." << endl;
    }

    void init_SO() {
        cout << "Initializing operating system." << endl;
    }

    void iniciarGPU() {
        cout << "Starting GPU." << endl;
    }

    void remove_ficheros() {
        cout << "Removing files." << endl;
    }

    void listaHardware() {
        cout << "Listing hardware." << endl;
        cout << "RAM: " << computer.RAM << endl;
        cout << "CPU: " << computer.CPU << endl;
        cout << "GPU: " << computer.GPU << endl;
        cout << "DISCO RIGIDO: " << computer.DISCO_RIGIDO << endl;
        cout << "PSU: " << computer.PSU << endl;
        cout << "CAIXA: " << computer.CAIXA << endl;
        cout << "MOTHERBOARD: " << computer.MOTHERBOARD << endl;
        cout << "FANs: " << computer.FANs << endl;
        cout << "Perifericos: ";

        for (int i = 0; i < 5; i++) {
            cout << "\t" << computer.perifericos[i];
        }
        cout << endl << endl;
    }

public:
    Computer(hardware hardeware) {
        this->computer = hardeware;
        this->state = false;
        cout << "Computer created." << endl;
        listaHardware();
    }

    void ligar() {
        if (state) {
            cout << "Computer already on." << endl;
        } else {
            cout << "Computer turning on." << endl;
            this->state = true;
        }
    }

    void desligar() {
        if (state) {
            cout << "Computer turning off." << endl;
            this->state = false;
        } else {
            cout << "Computer already off." << endl;
        }
    }

    void reset() {
        if (state) {
            cout << "Computer resetting." << endl;
            this->state = false; // Isso pode ser aprimorado
        } else {
            cout << "Computer already off." << endl;
        }
    }

    void abrir_tampa() {
        cout << "Opening case." << endl;
    }

    void executar(int opt) {
        switch (opt) {
            case 1:
                if (state) {
                    formatar();
                } else {
                    cout << "Computer not on." << endl;
                }
                break;
            case 2:
                if (state) {
                    abrir_pasta();
                } else {
                    cout << "Computer not on." << endl;
                }
                break;
            case 3:
                if (state) {
                    remove_ficheros();
                } else {
                    cout << "Computer not on." << endl;
                }
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    }

    void input() {
        if (state) {
            cout << "Receiving input." << endl;
        } else {
            cout << "Computer not on." << endl;
        }
    }
};

int main() {
    hardware hardware1 = {
        "16GB RAM",
        "RYZEN 5 7535HS",
        "RTX 3050",
        "500GB SSD",
        "1000W PSU",
        "MSI Case",
        "GIGABYTE Motherboard",
        "500GB External",
        {'m', 'i', 'n', 'i', 'c'} // 5 elementos
    };
    
    hardware hardware2 = {
        "16GB RAM",
        "RYZEN 5 7535HS",
        "RTX 3050",
        "500GB SSD",
        "1000W PSU",
        "MSI Case",
        "GIGABYTE Motherboard",
        "500GB External",
        {'m', 'i', 'n', 'i', 'c'}
    };

    Computer computer1(hardware1);
    Computer computer2(hardware2);

    // Exemplificando o uso do input
    computer1.ligar();
    computer1.input();

    return 0;
}
