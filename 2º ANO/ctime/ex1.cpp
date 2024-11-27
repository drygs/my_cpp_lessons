#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

int main(){

    while(true){
        system("cls");

        time_t timestamp;
        time(&timestamp);

        cout << "the current time is " << ctime(&timestamp) << "\n";
        sleep(1);
    };

    return 0;
}