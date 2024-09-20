#include <iostream>

using namespace std;

// Definição da struct Produto
struct Produto {
    string nome;
    float preco;
    int quantidade;
};

// Função para adicionar um novo produto ao array
void adicionarProduto(Produto produtos[], int &quantidadeAtual) {
    // Solicitando os dados do produto
    cout << "Insira o nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;

    cout << "Insira o preço do produto: ";
    cin >> produtos[quantidadeAtual].preco;

    cout << "Insira a quantidade em stock do produto: ";
    cin >> produtos[quantidadeAtual].quantidade;

    // Atualizando a quantidade de produtos no sistema
    quantidadeAtual++;
    cout << "Produto adicionado com sucesso!\n";
}

// Função para exibir todos os produtos cadastrados
void exibirProdutos(const Produto produtos[], int quantidadeAtual) {
    if (quantidadeAtual == 0) {
        cout << "Nenhum produto cadastrado.\n";
        return;
    }

    cout << "\nLista de Produtos:\n";
    for (int i = 0; i < quantidadeAtual; i++) {
        cout << "Produto " << i + 1 << ": " << produtos[i].nome << "\n";
        cout << "Preço: R$ " << produtos[i].preco << "\n";
        cout << "Quantidade: " << produtos[i].quantidade << "\n\n";
    }
}

// Função para calcular o valor total do stock da loja
float calcularValorTotal(const Produto produtos[], int quantidadeAtual) {
    float valorTotal = 0;

    for (int i = 0; i < quantidadeAtual; i++) {
        valorTotal += produtos[i].preco * produtos[i].quantidade;
    }

    return valorTotal;
}

int main() {
    const int MAX_PRODUTOS = 100; // Capacidade máxima de produtos
    Produto produtos[MAX_PRODUTOS]; // Array para armazenar os produtos
    int quantidadeAtual = 0; // Contador para a quantidade de produtos atualmente cadastrados
    int opcao;

    do {
        // Exibindo o menu de opções
        cout << "\nSistema de Gestão de Produtos\n";
        cout << "1. Adicionar Produto\n";
        cout << "2. Exibir Produtos\n";
        cout << "3. Calcular Valor Total do Stock\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarProduto(produtos, quantidadeAtual);
                break;
            case 2:
                exibirProdutos(produtos, quantidadeAtual);
                break;
            case 3: {
                float valorTotal = calcularValorTotal(produtos, quantidadeAtual);
                cout << "Valor total do stock: R$ " << valorTotal << "\n";
                break;
            }
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 0);

    return 0;
}
