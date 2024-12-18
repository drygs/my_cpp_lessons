#include <iostream>
#include <iomanip>
using namespace std;

void graficoHorizontal(int x, int y, int z){


    cout << "De os valores de x, y, z " << endl;
    cin >> x >> y >> z;

    int maior = x;
    if (maior < y) maior = y;
    if (maior < z) maior = z;

    int x1 = x;
    int y1 = y;
    int z1 = z;

    x = x * 50 / maior;
    y = y * 50 / maior;
    z = z * 50 / maior;

    system("cls||clear");
    cout << "x: " << setw(4) << x1 <<" ";
    while (x > 0){
        cout << "*";
        x--;
    }

    cout << endl;
    cout << "y: "<< setw(4) << y1 <<" ";
    while (y > 0){
        cout << "*";
        y--;
    }

    cout << endl;
    cout << "z: " << setw(4) << z1 <<" ";
    while (z > 0){
        cout << "*";
        z--;
    }


}

int main(){
    int x, y, z;
    graficoHorizontal(x, y, z);
    return 0;
}