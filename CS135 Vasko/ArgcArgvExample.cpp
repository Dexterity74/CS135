#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

int main(int args, char * argv[]) {

    string argument = "";
    char ch;
    int dice;
    int amount = 0;

    if(args == 2) {
        argument = argv[1];
    }

    if(argument == "debug") {
        srand(0);
    }
    else{
        srand(time(NULL));
    }
    
    while(amount<5) {
        if(argument != "silent") {
            cin.get(ch); //wait for user to hit enter
        }
        dice = rand() % 6+1;

        cout << dice << endl;
        amount++;
    }

    return 0;
}