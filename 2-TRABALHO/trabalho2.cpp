#include <iostream>
#include <fstream>
using namespace std;



//pergunta se quer criar base de dados ou nao

void create_db(){
    char confirm;

    while(true){
        cout << "Criar data base? [S|N]";
        cin >> confirm;
        confirm = tolower(confirm);
    
        if(confirm == 's'){


            cout << "Criando DB" << "\n";
            cout << "Press Enter" << "\n";
            ofstream arquivo("dados.csv");

            cin.get();
            cin.ignore();

            system("clear||cls");
            break;
        //falta codigo depois adicionar o a parte de criação do ficheiro .csv
        }
        else if(confirm == 'n'){

            cout << "Usando db existente caso exista"<<"\n";
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

int main(){
    
    create_db();
    
}



