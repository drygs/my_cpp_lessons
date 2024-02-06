#include <iostream>

using namespace std;

// reference is an alias for a variable
string food = "Pizza";

// create a reference varialble

string &meal = food;


int main(){

    cout << food << "\n";
    cout << &food << "\n";
    cout << meal << "\n";
    cout << &meal << "\n";
    
        
    
    
    return 0;
}