#include <iostream>
#include <string>
#include <cctype>  // Para toupper()

using namespace std;

string maiusculas() {
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);

    for (char &c : frase) {
        c = toupper(c);
    }

    return frase;
}

void exibirFrase(const string& frase, string& reveladas) {
    // Exibe a frase com _ para as letras não reveladas (ignora os espaços)
    for (int i = 0; i < frase.length(); i++) {
        if (frase[i] == ' ' || reveladas[i] == '1') {
            cout << frase[i] << " ";  // Exibe a letra ou espaço
        } else {
            cout << "_ ";  // Exibe _ para as letras não reveladas
        }
    }

    cout << endl;

    // Solicita ao usuário que adivinhe uma letra
    char letra;
    cout << "Digite uma letra: ";
    cin >> letra;
    letra = toupper(letra);  // Garante que a letra seja maiúscula

    // Revela as letras na string reveladas se o usuário acertar
    bool acertou = false;
    for (int i = 0; i < frase.length(); i++) {
        if (frase[i] == letra) {
            reveladas[i] = '1';  // Revela a letra
            acertou = true;
        }
    }
}

bool fraseRevelada(const string& reveladas, const string& frase) {
    // Verifica se todas as letras foram reveladas, ignorando espaços
    for (int i = 0; i < reveladas.length(); i++) {
        if (frase[i] != ' ' && reveladas[i] == '0') { 
            return false;  
        }
    }
    return true;
}

int main() {
    string frase = maiusculas();
    string reveladas(frase.length(), '0');

    while (!fraseRevelada(reveladas, frase)) {
        system("clear||cls");
        exibirFrase(frase, reveladas);  
    }

    cout << frase << endl;
    cout << "Parabéns! Você revelou toda a frase!" << endl;
    return 0;
}
