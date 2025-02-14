#include <iostream>
using namespace std;


int main(){

    int a = 12, b = 25;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "a & b = " << (a & b) << endl;
    cout << "a | b = " << (a | b) << endl;
    cout << "a ^ b = " << (a ^ b) << endl;
    cout << "~a = " << ~a << endl;
    // deslocamento esquerda
    cout << "a << 2 = " << (a << 2) << endl;
    // deslocamento direita
    cout << "a >> 2 = " << (a >> 2) << endl;


    return 0;

}