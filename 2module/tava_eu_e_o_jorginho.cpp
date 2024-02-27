#include <iostream>
using namespace std;
    /**
     * @brief Função que calcula a soma dos numeros até um determinado limite
     * @param limite -limite para a soma
     * @return int soma dos numeros até o limite
    */

int somaNumeros(int limite){
    int soma = 0, sum=0;

    for (int x = 1 ; x <= limite; x++)
    {
        soma += x;
    }
    return soma;
}

int getLimite(){
    
    int limite;
    cout << "qual o limite: ";
    cin >> limite;
    
    return limite;
}

int main(){
    system("clear || cls");
    int limite;
    limite = getLimite();
    cout << "Total: " << somaNumeros(limite) << endl;
    return 0;
}
