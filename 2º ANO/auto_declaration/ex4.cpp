#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

struct Numeros {
    int num[100];
    bool confirm;
};

int sorteio() {
    int numSorteado;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    numSorteado = dis(gen);

    return numSorteado;
    }


void bingo() {
    Numeros numeros;
    numeros.confirm = true;  

    for (int i = 0; i < 100; i++) {
        numeros.num[i] = i + 1;
    }

    // Imprime os números
    for (int i = 0; i < 100; i++) {
        cout << setw(4) << numeros.num[i];
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;

    cout << "numSorteado: " << numeros.num[sorteio()] << numeros.confirm[sorteio()] << endl;
    
    


    
}

int main() {
    bingo();
    return 0;
}
