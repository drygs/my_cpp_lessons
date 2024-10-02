#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sstream>
using namespace std;

// Definição da estrutura do produto
struct Produto {
    int id;
    string nome;
    float preco;
    int quantidade;
};

// Declaração de variáveis globais
Produto produtos[100];
int quantidadeAtual = 0;
int ultimonum = 0;

// Função para obter o último ID da base de dados
int obterUltimoId(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    string linha;
    string ultimaLinha;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            ultimaLinha = linha;  // Armazena a última linha
        }
        arquivo.close();
    }
    
    if (!ultimaLinha.empty()) {
        stringstream ss(ultimaLinha);
        string idStr;
        getline(ss, idStr, ',');  // Obtém o primeiro valor (ID) até a primeira vírgula
        ultimonum = stoi(idStr);  // Converte a string ID para inteiro
    }
    return ultimonum;
}

// Verifica a existência de arquivo de base de dados 
bool arquivoExiste(const std::string& nomeArquivo) {
    struct stat buffer;
    return (stat(nomeArquivo.c_str(), &buffer) == 0);  // Retorna true se o arquivo existir
}

// Pergunta se quer criar base de dados ou não
void create_db() {
    char confirm;
    string db = "dados.csv";

    while (true) {
        cout << "Usar data base? [S|N]: ";
        cin >> confirm;
        confirm = tolower(confirm);

        if (confirm == 's') {
            if (arquivoExiste(db)) {
                cout << "Usando DB existente" << "\n";
                ultimonum = obterUltimoId(db);  // Carrega o último ID
            } else {
                cout << "Criando DB" << "\n";
                ofstream arquivo(db);  // Cria um novo arquivo
                arquivo.close();
            }

            cout << "Pressione Enter" << "\n";
            cin.ignore();
            cin.get();  // Aguarda a tecla Enter

            system("clear||cls");
            break;
        } else if (confirm == 'n') {
            cout << "Após o processo os dados serão perdidos" << "\n";
            cout << "Pressione Enter" << "\n";
            cin.ignore();
            cin.get();  // Aguarda a tecla Enter

            system("clear||cls");
            break;
        } else {
            cout << "Digite um valor válido" << "\n";
            cout << "Pressione Enter" << "\n";
            cin.ignore();
            cin.get();  // Aguarda a tecla Enter

            system("clear||cls");
        }
    }
}

// Função para adicionar um produto à base de dados
void adicionarProduto(Produto produtos[], int& quantidadeAtual, int& ultimonum) {
    produtos[quantidadeAtual].id = ++ultimonum;

    cout << "Insira o nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;

    cout << "Insira o preco do produto: ";
    cin >> produtos[quantidadeAtual].preco;

    cout << "Insira a quantidade em estoque do produto: ";
    cin >> produtos[quantidadeAtual].quantidade;

    // Abrir arquivo e adicionar produto
    ofstream arquivo("dados.csv", ios::app);  // "append" adiciona ao final
    arquivo << produtos[quantidadeAtual].id << ","
            << produtos[quantidadeAtual].nome << ","
            << produtos[quantidadeAtual].preco << ","
            << produtos[quantidadeAtual].quantidade << ","
            << "E" << "\n";
    arquivo.close();  // Fecha o arquivo
    cout << "Produto adicionado com sucesso!\n";

    quantidadeAtual++;  // Incrementa o contador de produtos
}

// Função para exibir produtos
void exibirProdutos() {
    if (quantidadeAtual == 0) {
        cout << "Nenhum produto cadastrado.\n";
        return;
    }

    cout << "Produtos cadastrados:\n";
    for (int i = 0; i < quantidadeAtual; i++) {
        cout << "ID: " << produtos[i].id << ", "
             << "Nome: " << produtos[i].nome << ", "
             << "Preço: " << produtos[i].preco <<"€" << ", "
             << "Quantidade: " << produtos[i].quantidade << "\n";
             
    }
}

// Função para calcular o valor total do estoque
void calcularValorTotal() {
    float total = 0.0;

    for (int i = 0; i < quantidadeAtual; i++) {
        total += produtos[i].preco * produtos[i].quantidade;
    }

    cout << "Valor total do estoque: " << total <<"€"<< "\n";
}

// Menu principal
void menu() {
    int escolha;
    do {
        cout << "Escolha: \n 1-Adicionar produto \n 2-Exibir produtos \n 3-Calcular valor total de estoque \n 0-Sair \n";
        cin >> escolha;
        switch (escolha) {
            case 1:
                system("cls||clear");
                adicionarProduto(produtos, quantidadeAtual, ultimonum);
                system("cls||clear");
                break;
            case 2:
                system("cls||clear");
                exibirProdutos();
                cout << "Pressione Enter para continuar...\n";
                cin.ignore();
                cin.get();  // Aguarda a tecla Enter
                system("cls||clear");
                break;
            case 3:
                system("cls||clear");
                calcularValorTotal();
                cout << "Pressione Enter para continuar...\n";
                cin.ignore();
                cin.get();  // Aguarda a tecla Enter
                system("cls||clear");
                break;
            case 0:
                system("clear||cls");
                break;
            default:
                cout << "Escolha inválida! Tente novamente.\n";
        }
    } while (escolha != 0);
}

int main() {
    create_db();
    menu();
    return 0;
}
