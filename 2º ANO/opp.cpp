#include <iostream>
#include <string>
using namespace std;



class fatura{
    private:
        int id;
        string nome;
        int contribuinte;
        float valor;
    public:

        fatura(){
            cout <<"classe instaciada" << endl; //marca a classe quando é instanciada        }
        void criarFatura(){
            cout << "ID: ";
            cin >> id;
            cout << "Nome: ";
            cin >> nome;
            cout << "Contribuinte: ";
            cin >> contribuinte;
            cout << "Valor: ";
            cin >> valor;
        }

        void imprimir(){
            cout << id << endl;
            cout << nome << endl;
            cout << contribuinte << endl;
            cout << valor << endl;
        }
};

int main(){
    fatura fatura1;
    fatura1.criarFatura();
    fatura1.imprimir();
}