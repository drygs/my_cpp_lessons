#include <iostream>
using namespace std;


int main()
{

char a;
cout << "digite um caractere: ";
cin >> a;

cout << "letra" << a << " em maiscula e: " << char(a-32) << endl;
return 0;

}