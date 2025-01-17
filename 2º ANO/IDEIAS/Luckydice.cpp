#include <iostream>
using namespace std;


int* gerarNum() {
    int dado[3];
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        dado[i] = 1 + rand() % 6; 
    }
    return dado;
}


int* escolhas() {
    int escolha[3];
    cout << "Aposte em 3 números de 1 a 6: ";
    cin >> escolha[0] >> escolha[1] >> escolha[2]; 
    return escolha;
}

void mult(){
    int multiplicador, aposta = 0;
    int* escolha = escolhas();
    int* dado = gerarNum();

    cout << "Quanto quer apostar? ";
    cin >> aposta;
    for(int n = 0; n < 3; n++){
        for(int i = 0; i < 3; i++){
            if(escolha[i] == dado[n])
                aposta =aposta*1.7;
        }
    }
    cout << "Os valores dos dados foram: " << dado[0] << " " << dado[1] << " " << dado[2] << endl;
    cout << "Teve um ganho de " << aposta << endl;   
}

int main(){
    system("clear|| cls");
    mult();
    return 0;
}  