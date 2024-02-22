#include <iostream>
using namespace std;

int opcao;

void soma(int a, int b){
    cout << a + b << endl;
}

void mult(int a, int b){
    cout << a*b << endl;
}

void divisao(int a, int b){
    cout << a/b << endl;
}

void rest(int a, int b){
    cout << a%b << endl;
}

void menu(){
    cout <<"======================="<<endl;
    cout <<"          MENU"<<endl;
    cout <<"======================="<<endl;
    cout << " 1- soma \n 2- multiplicação \n 3- divisão \n 4- resto da divisão" << endl;
}
int getOpcao(){
    cout << "Escolha a opção" << endl;
    cin >> opcao;
    return opcao;
}
void executaCalculo(int i){
    switch (i)
    {
    case 1:
        soma(int a, int b);
        break;
    case 2:
        mult();
        break;
    case 3:
        divisao();
        break;
    case 4:
        rest();
        break;
    
    default:
        break;
    }

}

int main(){

}


