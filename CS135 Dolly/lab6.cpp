#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() { 
  
  int choiceNumber;
  int random;
  char userSelection;
  
  while(userSelection != 'E' || 'e') {

    srand(time(0));

    cout << "[R]ock" << endl;     // 0
    cout << "[P]aper" << endl;    // 1
    cout << "[S]cissor" << endl;  // 2
    cout << "[E]xit" << endl;     // Exit

    cout << "Your move: ";
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
	    cout << "Exiting Program" << endl;
	    return 0;
	    break;

         default:
	    cout << "Invalid Entry" << endl;
	    return 0;
    }


  
    cout << "Computer move: ";
    random = rand() % 3;
      if (random == 0){
        cout << "[R]ock" << endl;
      }
      if (random == 1){
        cout << "[P]aper" << endl;
      }
      if (random == 2){
        cout << "[S]cissors" << endl;
      }


    
    cout << "Result: ";
      if (random == choiceNumber){
        cout << "Tie" << endl;
	cout << " " << endl;
      }
      if (choiceNumber == 2 && random == 0){
        cout << "You lose!" << endl;
	cout << " " << endl;
      }
      if (choiceNumber == 0 && random == 2){
        cout << "You win!" << endl;
	cout << " " << endl;
      }
      if (choiceNumber == 1 && random == 2){
        cout << "You lose!" << endl;
	cout << " " << endl;
      }
      if (choiceNumber == 2 && random == 1){
        cout << "You win!" << endl;
	cout << " " << endl;
      }
      if (choiceNumber == 0 && random == 1){
        cout << "You lose!" << endl;
	cout << " " << endl;
      }
      if (choiceNumber == 1 && random == 0){
        cout << "You win!" << endl;
	cout << " " << endl;
      }
    
   }

}
