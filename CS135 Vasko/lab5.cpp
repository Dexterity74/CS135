#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() { 
  
    int choiceNumber;
    int random;
    char userSelection;
    bool test = true;
  
    while(userSelection != 'E' || userSelection != 'e') {

        srand(time(0));

        cout << "[R]ock" << endl;     // 0
        cout << "[P]aper" << endl;    // 1
        cout << "[S]cissor" << endl;  // 2
        cout << "[E]xit" << endl;     // Exit

        cout << "What's your move? ";
        cin >> userSelection;

        switch(userSelection) {
        
            case 'R':
            case 'r':
                choiceNumber = 0;
                break;

            case 'P':
            case 'p':
                choiceNumber = 1;
                break;

            case 'S':
            case 's':
                choiceNumber = 2;
                break;

            case 'E':
            case 'e':
                cout << "Thanks for playing!\n" << endl;
                return 0;
                break;

            default:
                cout << "Your move is invalid!\n" << endl;
                test = false;
                
        }

        if(test == true) {
            cout << "The computer used ";
            random = rand() % 3;
            if (random == 0){
                cout << "rock." << endl;
            }
            if (random == 1){
                cout << "paper." << endl;
            }
            if (random == 2){
                cout << "scissors." << endl;
            }

            if (random == choiceNumber){
                cout << "It's a tie!" << endl;
                cout << " " << endl;
            }
            if (choiceNumber == 2 && random == 0){
                cout << "You lost!" << endl;
                cout << " " << endl;
            }
            if (choiceNumber == 0 && random == 2){
                cout << "You won!" << endl;
                cout << " " << endl;
            }
            if (choiceNumber == 1 && random == 2){
                cout << "You lost!" << endl;
                cout << " " << endl;
            }
            if (choiceNumber == 2 && random == 1){
                cout << "You won!" << endl;
                cout << " " << endl;
            }
            if (choiceNumber == 0 && random == 1){
                cout << "You lost!" << endl;
                cout << " " << endl;
            }
            if (choiceNumber == 1 && random == 0){
                cout << "You won!" << endl;
                cout << " " << endl;
            }
        }
    }
}