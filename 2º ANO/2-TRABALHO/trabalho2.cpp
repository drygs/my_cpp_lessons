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
    char status;
};

// Declaração de variáveis globais
Produto produtos[100];
int quantidadeAtual = 0;
int ultimonum = 0;
bool usarDB = true;  // Flag para determinar se a base de dados será usada

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
        cout << "Usar base de dados? [S|N]: ";
        cin >> confirm;
        confirm = tolower(confirm);

        if (confirm == 's') {
            usarDB = true;
            if (arquivoExiste(db)) {
                cout << "Usando DB existente" << "\n";
                ultimonum = obterUltimoId(db);  // Carrega o último ID
            } else {
                cout << "Criando DB" << "\n";
                ofstream arquivo(db);  // Cria um novo arquivo
                arquivo.close();
            }
            break;
        } else if (confirm == 'n') {
            usarDB = false;
            cout << "Os dados serão perdidos após o processo.\n";
            break;
        } else {
            cout << "Digite um valor válido.\n";
        }
    }
}

// Função para adicionar um produto ao array ou à base de dados
void adicionarProduto(Produto produtos[], int& quantidadeAtual, int& ultimonum) {
    produtos[quantidadeAtual].id = ++ultimonum;

    cout << "Insira o nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;

    cout << "Insira o preco do produto: ";
    cin >> produtos[quantidadeAtual].preco;

    cout << "Insira a quantidade em estoque do produto: ";
    cin >> produtos[quantidadeAtual].quantidade;

    produtos[quantidadeAtual].status = 'E';  // Produto habilitado

    if (usarDB) {
        // Abrir arquivo e adicionar produto
        ofstream arquivo("dados.csv", ios::app);  // "append" adiciona ao final
        arquivo << produtos[quantidadeAtual].id << ","
                << produtos[quantidadeAtual].nome << ","
                << produtos[quantidadeAtual].preco << ","
                << produtos[quantidadeAtual].quantidade << ","
                << produtos[quantidadeAtual].status << "\n";
        arquivo.close();  // Fecha o arquivo
    }

    cout << "Produto adicionado com sucesso!\n";
    quantidadeAtual++;  // Incrementa o contador de produtos
}

// Função para exibir produtos habilitados
void exibirProdutos() {
    if (usarDB) {
        ifstream arquivo("dados.csv");
        string linha;

        bool produtoHabilitadoEncontrado = false;
        cout << "Produtos:\n";

        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            string idStr, nome, preco, quantidade, status;
            
            getline(ss, idStr, ',');
            getline(ss, nome, ',');
            getline(ss, preco, ',');
            getline(ss, quantidade, ',');
            getline(ss, status, ',');

            if (status == "E") {  // Apenas produtos habilitados ("E")
                produtoHabilitadoEncontrado = true;
                cout << "ID: " << idStr << ", "
                     << "Nome: " << nome << ", "
                     << "Preco: " << preco <<"€" << ", "
                     << "Quantidade: " << quantidade << "\n";
            }
        }

        if (!produtoHabilitadoEncontrado) {
            cout << "Nenhum produto .\n";
        }

        arquivo.close();
    } else {
        if (quantidadeAtual == 0) {
            cout << "Nenhum produto cadastrado.\n";
            return;
        }

        cout << "Produtos cadastrados :\n";
        for (int i = 0; i < quantidadeAtual; i++) {
            if (produtos[i].status == 'E') {
                cout << "ID: " << produtos[i].id << ", "
                     << "Nome: " << produtos[i].nome << ", "
                     << "Preço: " << produtos[i].preco << "€" << ", "
                     << "Quantidade: " << produtos[i].quantidade << "\n";
            }
        }
    }
}

// Função para calcular o valor total do estoque de produtos habilitados
void calcularValorTotal() {
    float total = 0.0;

    if (usarDB) {
        ifstream arquivo("dados.csv");
        string linha;

        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            string idStr, nome, preco, quantidade, status;

            getline(ss, idStr, ',');
            getline(ss, nome, ',');
            getline(ss, preco, ',');
            getline(ss, quantidade, ',');
            getline(ss, status, ',');

            if (status == "E") {  // Apenas produtos habilitados ("E")
                total += stof(preco) * stoi(quantidade);
            }
        }
        arquivo.close();
    } else {
        for (int i = 0; i < quantidadeAtual; i++) {
            if (produtos[i].status == 'E') {
                total += produtos[i].preco * produtos[i].quantidade;
            }
        }
    }

    cout << "Valor total do estoque de produtos habilitados: " << total << "€\n";
}

// Função para excluir (desabilitar) um produto
void excluirProduto() {
    int id;
    cout << "Insira o ID do produto a ser excluído: ";
    cin >> id;

    if (usarDB) {
        ifstream arquivo("dados.csv");
        ofstream arquivoTemp("temp.csv");  // Arquivo temporário para armazenar os dados modificados
        string linha;
        bool encontrado = false;

        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            string idStr, nome, preco, quantidade, status;
            
            getline(ss, idStr, ',');
            getline(ss, nome, ',');
            getline(ss, preco, ',');
            getline(ss, quantidade, ',');
            getline(ss, status, ',');

            if (stoi(idStr) == id) {
                status = "D";  // Desabilita o produto mudando o status para "D"
                encontrado = true;
            }

            // Escreve no arquivo temporário
            arquivoTemp << idStr << "," << nome << "," << preco << "," << quantidade << "," << status << "\n";
        }

        arquivo.close();
        arquivoTemp.close();

        remove("dados.csv");            // Remove o arquivo original
        rename("temp.csv", "dados.csv");  // Renomeia o temporário para o original

        if (encontrado) {
            cout << "Produto com ID " << id << " foi excluído com sucesso.\n";
        } else {
            cout << "Produto com ID " << id << " não encontrado.\n";
        }
    } else {
        bool encontrado = false;
        for (int i = 0; i < quantidadeAtual; i++) {
            if (produtos[i].id == id) {
                produtos[i].status = 'D';  // Desabilita o produto
                encontrado = true;
                cout << "Produto com ID " << id << " foi excluído com sucesso.\n";
                break;
            }
        }

        if (!encontrado) {
            cout << "Produto com ID " << id << " não encontrado.\n";
        }
    }
}

// Menu principal atualizado
void menu() {
    int escolha;
    do {
        cout << "Escolha: \n 1-Adicionar produto \n 2-Exibir produtos habilitados \n 3-Calcular valor total de estoque habilitado \n 4-Excluir produto \n 0-Sair \n";
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
                cin.get();
                system("cls||clear");
                break;
            case 3:
                system("cls||clear");
                calcularValorTotal();
                cout << "Pressione Enter para continuar...\n";
                cin.ignore();
                cin.get();
                system("cls||clear");
                break;
            case 4:
                system("cls||clear");
                excluirProduto();
                cout << "Pressione Enter para continuar...\n";
                cin.ignore();
                cin.get();
                system("cls||clear");
                break;
            case 0:
                system("clear||cls");
                break;
            default:
                cout << "Escolha inválida! Tente novamente.\n";
                cout << "Pressione Enter para continuar...\n";
                cin.ignore();
                cin.get();
        }    
        system("clear||cls");
    } while (escolha != 0);
}

int main() {
    create_db();
    system("clear||cls");
    menu();
    return 0;
}
