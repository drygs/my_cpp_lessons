#include <iostream>
using namespace std;

int main(){
    int a;
    int b;
    double menor;
    double maior;
    double media;
    const double PI = 3.14159;
    double raio;
    double myarray[5] = {};

    
    cout << "digite dois valores a calcular:" << endl;
    cin >> a;
    cin >> b;

    cout << "Soma:" << a+b << endl;
    cout << "Diferença: " << a-b << endl;
    cout << "Produto :" << a*b << endl;
    cout << "Quociente: " << a/b << endl;
    cout << "Resto da Divisão: " << a%b << endl;

    cout << "Qual o Raio do Circulo: " << endl;
    cin >> raio;
    cout << "Área do Circulo: " << PI * raio * raio << endl;



    for(int i = 0; i < 5; i++)
    {
        cout << "Nota do Alunos: " << endl;
        cin >> myarray[i];
        media = media + myarray[i];
    }
    menor = myarray[1];
    for (int j = 0; j < 5; j++)
    {
        if (myarray[j] < menor)
        {   
            menor = myarray[j];
        }
        if (myarray[j] > maior)
        {
            maior = myarray[j];
        }
        
        
    }
    
    
    cout << "NOTAS:" << endl;
    cout << "Média das notas é: " << media/5 << endl;
    cout << "Menor Nota: " << menor << endl;
    cout << "Maior Nota: " << maior << endl;

    



    





}