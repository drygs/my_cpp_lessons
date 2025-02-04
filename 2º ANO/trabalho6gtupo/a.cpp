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
        if (frase[i] == ' ' || reveladas[i] == ' ') {
            cout << frase[i] << " ";  // Exibe a letra ou o espaço
        } else {
            cout << "_ ";  // Exibe _ para as letras não reveladas
        }
    }

    cout << endl;

    // Permite ao usuário tentar adivinhar uma letra
    char letra;
    cout << "Digite uma letra: ";
    cin >> letra;
    letra = toupper(letra);  // Converte a letra para maiúscula
}

int main() {
    string frase = maiusculas();  // Converte a frase para maiúsculas
    string reveladas(frase.length(), '0');  // Inicializa todas as letras como não reveladas

    // Repete a exibição até que todas as letras sejam reveladas
    while (reveladas != string(frase.length(), '1')) {
        exibirFrase(frase, reveladas);  // Exibe a frase e pede a adivinhação do usuário
    }

    cout << "Parabéns! Você revelou toda a frase!" << endl;

    return 0;
}
