#include <iostream>
#include <string>
#include <cctype>  // Para toupper()

using namespace std;

string maiusculas() {
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);

    // Converter para maiúsculas
    for (char &c : frase) {
        c = toupper(c);
    }

    return frase;
}

void exibirFrase(const string& frase, string& reveladas) {
    // Exibe a frase com _ para as letras não reveladas
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

    if (acertou) {
        cout << "Voce acertou! A letra '" << letra << "' foi revelada." << endl;
    } else {
        cout << "A letra '" << letra << "' nao esta na frase." << endl;
    }
}

bool fraseRevelada(const string& reveladas) {

    for (char c : reveladas) {
        if (c == '0') { 
            return false;
        }
    }
    return true;
}

int main() {
    string frase = maiusculas();
    string reveladas(frase.length(), '0');

    
    while (!fraseRevelada(reveladas)) {
        exibirFrase(frase, reveladas);  
    }

    cout << "Parabens! Voce revelou toda a frase!" << endl;

    return 0;
}
