#include <iostream>
using namespace std;


class carro{
    public:
        int anos;
        string marca;
        void setVelocidade(int v){
            velocidade = v;
        }
    private:
        int velocidade;
        void velMED(int vm){
            int velMedia = vm;
        }


};

int main(){
    carro carro1;

    carro1.anos = 15;
    carro1.marca = "BMW";


    cout << carro1.anos << "\n";

    return 0;

}