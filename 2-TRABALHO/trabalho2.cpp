#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <cctype>
using namespace std;



struct Produto
{
    int id;
    string nome;
    float preco;
    int quantidade;
};

Produto produtos[100];
int quantidadeAtual = 0;



//verifica existencia de arquivo de data base 
bool arquivoExiste(const std::string& nomeArquivo) {
    struct stat buffer;
    return (stat(nomeArquivo.c_str(), &buffer) == 0);  // Retorna true se o arquivo existir
}


//pergunta se quer criar base de dados ou nao

void create_db(){
    char confirm;
    string db = "dados.csv";


    while(true){
        cout << "Usar data base? [S|N]";
        cin >> confirm;
        confirm = tolower(confirm);
    
        if(confirm == 's'){
            if (arquivoExiste(db)){
                cout <<"Usando DB existente" << "\n";
                ifstream arquivo("dados.csv");
            }
            else{
                cout << "Criando DB" << "\n";
                ofstream arquivo("dados.csv");
            }

            cout << "Press Enter" << "\n";
            cin.get();
            cin.ignore();

            system("clear||cls");
            break;
        }
        else if(confirm == 'n'){

            cout << "Apos o processo os dados serão perdidos"<<"\n";
            cout << "Press Enter" << "\n";

            cin.get();
            cin.ignore();

            system("clear||cls");
            break;
        }
        else{

            cout << "Digite um valor valido" << "\n";
            cout << "Press Enter" << "\n";

            cin.get();
            cin.ignore();

            system("clear||cls");
            
        }  

    }


}

void adicionarProduto(Produto produtos[], int& quantidadeAtual){
    cout << "Insira o id do produto: ";
    cin >> produtos[quantidadeAtual].id;

    cout << "Insira o nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;

    cout << "Insira o preço do produto: ";
    cin >> produtos[quantidadeAtual].preco;

    cout << "Insira a quantidade em stock do produto: ";
    cin >> produtos[quantidadeAtual].quantidade;

    ofstream arquivo("dados.csv", ios::app);  //"append" adiciona ao final
        //Escreve na db
    arquivo <<produtos[quantidadeAtual].id <<","
            << produtos[quantidadeAtual].nome << ","
            << produtos[quantidadeAtual].preco << ","
            << produtos[quantidadeAtual].quantidade << "\n";
    arquivo.close();  // Fecha o arquivo
    cout << "Produto adicionado com sucesso!\n";

    // 4. Atualiza a quantidade de produtos no array
    quantidadeAtual++;

}

void menu(){
    int escolha;
    do
    {
    cout << "Escolha: \n 1-Adicionar produto \n 2-Exibir produtos \n 3-Calcular valor total de Stock \n 0-Sair \n";
    cin >> escolha;
    switch(escolha)
    {
    case 1:
        system("cls||clear");
        adicionarProduto(produtos, quantidadeAtual);
        system("cls||clear");

        break;
    case 2:

        break;
    case 3:

        break;
    case 0:
        system("clear||cls");
        break;
        }
    } while (escolha != 0);
}


int main(){
    create_db();
    menu();
    
}



