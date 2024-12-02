#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<int> numeros = {1,2,3,4,5};
list<int> lista ={1,2,3,4,5,6,7,8,9,10}

int main(){
    for (int num : numeros){
        cout << num << "\n";
    }

    return 0;

}