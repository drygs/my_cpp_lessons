//Grupo Alexandre Carvalho e Diogo Soares

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

    for (int i = 0; i < frase.length(); i++) {
        if (frase[i] == ' ' || reveladas[i] == '1') {
            cout << frase[i] << " ";  // Mostra a letra ou espaço
        } else {
            cout << "_ ";  // Mostra _ para as letras não reveladas
        }
    }

    cout << endl;

    
    char letra;
    cout << "Digite uma letra: ";
    cin >> letra;
    letra = toupper(letra);  // letra  maiúscula

    bool acertou = false;
    for (int i = 0; i < frase.length(); i++) {
        if (frase[i] == letra) {
            reveladas[i] = '1';  // mostra a letra
            acertou = true;
        }
    }

    if (acertou) {
        cout << "Você acertou! A letra '" << letra << "' foi revelada." << endl;
    } else {
        cout << "A letra '" << letra << "' não está na frase." << endl;
    }
}

bool fraseRevelada(const string& reveladas, const string& frase) {
    for (int i = 0; i < reveladas.length(); i++) {
        if (frase[i] != ' ' && reveladas[i] == '0') { 
            return false;  
        }
    }
    return true; 
}

int main() {
    string frase = maiusculas();
    string reveladas(frase.length(), '0');  // Inicializa a string de revelação com '0'

    while (!fraseRevelada(reveladas, frase)) {
        system("clear||cls");
        exibirFrase(frase, reveladas);  
    }

    cout << frase << endl;
    cout << "Parabéns! Você revelou toda a frase!" << endl;

    return 0;
}