#include <iostream>
using namespace std;

// Definição da estrutura 'lata'
struct lata {
    string marca;
    string sabor;
    string validade;
    string fornecedor;
    string codBarras;
    string lote;
    string dataFabricacao;
    string infoFornecedor;
    string infoNutrucional[5];
    string materialEmbalagem;

    double capacidade;
    double preco;
    double peso;

    bool status; // false significa que a lata está fechada, true que está aberta
};

// Definição da classe 'Refrigerante'
class Refrigerante {
    private:
        lata refrigerante;
        double qntSumoDisponivel;  // Quantidade de sumo disponível para beber

    public:
        // Construtor que inicializa a lata e a quantidade de sumo disponível
        Refrigerante(lata lataInicial) {
            refrigerante = lataInicial;
            qntSumoDisponivel = refrigerante.capacidade;
        }

        // Método para abrir a lata
        void abrirLata() {
            if (refrigerante.status == false) {
                refrigerante.status = true;  // Alterando o status da lata para aberta
                cout << "A lata foi aberta!" << endl;
            } else {
                cout << "A lata já está aberta." << endl;
            }
        }

        // Método para beber refrigerante
        void beberRefrigerante(double quantidade) {
            if (refrigerante.status == true) {
                cout << "Há " << qntSumoDisponivel << " litros de sumo disponível." << endl;

                if (quantidade <= qntSumoDisponivel) {
                    qntSumoDisponivel -= quantidade;
                    cout << "Você bebeu " << quantidade << " litros de sumo." << endl;
                } else {
                    cout << "Sumo insuficiente! Restam apenas " << qntSumoDisponivel << " litros." << endl;
                }
            } else {
                cout << "A lata está fechada! Abra-a antes de beber." << endl;
            }
        }
};

int main() {
    // Inicializando uma lata de refrigerante
    lata lata1 = {"Coca-Cola", "Cola", "10/10/2021", "Coca-Cola",
                  "123456789", "Lote 1", "01/01/2021", "Coca-Cola Company",
                  {"750kcal", "3g de proteínas", "150g de carboidratos", "0.1g de fibra", "2g de sódio"},
                  "Alumínio", 1000.00, 5.00, 0.350, false};

    // Criando o objeto 'Refrigerante' com a lata inicial
    Refrigerante refri(lata1);

    while (true) {
        int opcao;

        // Menu de opções
        cout << "1 - Abrir lata" << endl;
        cout << "2 - Beber refrigerante" << endl;
        cout << "3 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        // Processamento da escolha do utilizador
        if (opcao == 1) {
            refri.abrirLata();
        } else if (opcao == 2) {
            double quantidade;
            cout << "Quantos litros de sumo vai beber? ";
            cin >> quantidade;
            refri.beberRefrigerante(quantidade);
        } else if (opcao == 3) {
            cout << "Programa encerrado." << endl;
            break;
        } else {
            cout << "Opção inválida, tente novamente!" << endl;
        }
    }

    return 0;
}
