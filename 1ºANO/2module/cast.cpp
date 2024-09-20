/**
 * c++ program desmonstrate string
*/
#include <iostream>
using namespace std;


const int INT_NUM = 20;
int i = 0;
void showASCIITable(){
    for(int x = 33; x <= 127 ; x++){
        cout << " " <<(char)x;
        i++;
        if (i % 20 == 0 || i >= 94){
            cout << endl;
        }
    
    }

}
int main(){
/*
    int i = 10;
    float f = 3.14;
    char c = 'a';


    // cast implicito

    float f2 = i;
    char c2 = i;

    cout << "f2: " << f2 << endl;
    cout << "c2: " << c2 << endl;


    // cast implícito

    int i2 = (int)f;
    int i3 = (int)c;

    cout << "i2" << i2 << endl;
    cout << "i3" << i3 << endl;

    return 0;
*/



showASCIITable();
}