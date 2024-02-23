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
    system("clear");
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
void executaCalculo(int i, int x, int y){
    switch (i)
    {
    case 1:
        soma(x,y);
        break;
    case 2:
        mult(x, y);
        break;
    case 3:
        divisao(x, y);
        break;
    case 4:
        rest(x, y);
        break;
    
    default:
        break;
    }

}

int getvalorX(){
    int x;
    cout << "Digite um valor: ";
    cin >> x;
    return x;
}

int getvalorY(){
    int y;
    cout << "Digite o Valor de Y: ";
    cin >> y;
    return y;
}

int main(){
    
    int a;
    int b;
    int opcao;
    menu();
    cin.get();
    system("clear");
    opcao = getOpcao();
    system("clear");
    a = getvalorX();
    b = getvalorY();
    executaCalculo(opcao, a, b);

    return 0;
}


