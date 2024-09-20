#include <iostream>
using namespace std;



struct Produto
{
    string nome;
    float preco;
    int quantidade;
};

void adicionarProduto(Produto produtos[], int& quantidadeAtual){
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

void exibirProdutos(const Produto produtos[], int quantidadeAtual){
    if(quantidadeAtual == 0){
        cout << "Está vazio" << endl; 
    }
    else{
        cout << "\nLista de Produtos:\n";
        for (int i = 0; i < quantidadeAtual; i++) {
            cout << "Produto " << i + 1 << ": " << produtos[i].nome << "\n";
            cout << "Preço: " << produtos[i].preco << "\n";
            cout << "Quantidade: " << produtos[i].quantidade << "\n\n";
        }
    }
}

int main(){

    Produto produtos[100];
    int quantidadeAtual = 0;
    int escolha;
    do
    {

    cout << "Escolha: \n 1-Adicionar produto \n 2-Exibir produtos \n 3-Calcular valor total de Stock \n 0-Sair";
    cin >> escolha;
    switch(escolha)
    {
    case 1:
        adicionarProduto(produtos, quantidadeAtual);
        break;
    case 2:
        exibirProdutos(produtos, quantidadeAtual);
        break;
    case 3:
        /* code */
        break;
    case 0:
        break;
        }
    } while (escolha != 0);
    return 0;
}
    