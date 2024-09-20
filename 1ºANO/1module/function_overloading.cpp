#include <iostream>
using namespace std;



int somaNumeros(int x, int y){
    return x+y;
}


int soma(int k){
    if(k>0){
        return k+ soma(k - 1);
    }else{
        return 0;
    }
}

int main(){
    int resultado = soma(5);
    cout << resultado << "\n";
}


/*double somaNumeros(double x, double y){
    return x+y;
}

int main(){


    cout << somaNumeros(2.2, 6.4) << "\n";
    return 0;
}*/