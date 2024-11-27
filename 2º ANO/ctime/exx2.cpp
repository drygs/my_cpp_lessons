#include <iostream>
#include <sstream>
#include <ctime>
#include <unistd.h> // Para sleep no Linux/Unix (use Sleep no Windows)
#include <iomanip>

using namespace std;

int main() {
    // Define a data e hora alvo como string
    const string alvo = "Nov 27 12:27:00 2024";

    // Prepara uma estrutura tm para o horário alvo
    tm tmAlvo = {};
    istringstream ss(alvo);
    ss >> get_time(&tmAlvo, "%b %d %H:%M:%S %Y"); // Converte string para tm

    if (ss.fail()) {
        cerr << "Erro ao configurar o horário alvo.\n";
        return 1;
    }

    time_t tempoAlvo = mktime(&tmAlvo); // Converte tm para time_t

    if (tempoAlvo == -1) {
        cerr << "Erro ao calcular o horário alvo.\n";
        return 1;
    }

    while (true) {
        system("cls"); // Para limpar o terminal (no Windows). Use "clear" no Linux.

        // Obtém o horário atual
        time_t timestamp;
        time(&timestamp);

        cout << "The current time is " << ctime(&timestamp) << "\n";

        // Verifica se o horário atual coincide com o horário alvo
        if (timestamp >= tempoAlvo) { // >= para considerar pequenos atrasos
            cout << "Alarme! O horário alvo foi atingido!\n";
            break; // Sai do loop
        }

        sleep(1); // Aguarda 1 segundo antes de verificar novamente
    }

    return 0;
}
