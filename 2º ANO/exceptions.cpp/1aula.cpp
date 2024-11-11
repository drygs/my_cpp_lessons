#include <iostream>
#include <fstream>

using namespace std;

int main(){
string nomeFicheiro;
cout << "nome do ficheiro: ";
cin >> nomeFicheiro;

try{
    ifstream file(nomeFicheiro);
    if(!file.is_open()){
        throw 1;
    }
    throw 0;

}catch(const int e){
    if (e == 1){
        cout << "Erro ao Abrir o Sistema"<< endl;
    }else if (e == 0){
        cout << "Ficheiro Aberto com Sucesso" <<  endl;
    }

}

return 0;
}