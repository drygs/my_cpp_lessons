#include <iostream>
using namespace std;


void funciona(){
   int count = 1;
   while(count <= 5){
      cout << count << "\n";
      count++;
   }
   cout << "acabou" << "\n";
}

int main(){
   funciona();

   return 0;
}