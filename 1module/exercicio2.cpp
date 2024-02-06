#include <iostream>
#include <iomanip>
using namespace std;

/*
crie um programa capaz de multiplicar uma matriz bidimensional de inteiros
por um dado numero e criar uma nova matriz com o produto
*/

int arr[3][3] = { {1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};

void multiplicacao(int mult, int nummult ,int size ){
    cout << "Qual o número para a multiplicação: ";
    cin  >> mult;


    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = mult * arr[i][j];
            int nummult = arr[i][j];
            cout << setw(5) << nummult;
        }
        cout << endl;
    }
}

int main()
{

    multiplicacao(0, 0, 3);

    return 0;
}


