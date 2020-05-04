#include <iostream>

using namespace std;

int main() {

  int M;

  cin >> M;

  while (cin){ // keep looping until no more input  
    
    switch(M){
      
      case 1:
        cout << "The month you entered is: January" << endl;
	break;

      case 2:
	cout << "The month you entered is: February" << endl;
	break;

      case 3:
	cout << "The month you entered is: March" << endl;
	break;

      case 4:
	cout << "The month you entered is: April" << endl;
	break;

      case 5:
	cout << "The month you entered is: May" << endl;
	break;

      case 6:
	cout << "The month you entered is: June" << endl;
	break;

      case 7:
	cout << "The month you entered is: July" << endl;
	break;

      case 8:
	cout << "The month you entered is: August" << endl;
	break;

      case 9:
	cout << "The month you entered is: September" << endl;
	break;

      case 10:
	cout << "The month you entered is: October" << endl;
	break;

      case 11:
	cout << "The month you entered is: November" << endl;
	break;

      case 12:
	cout << "The month you entered is: December" << endl;
	break;

      default:
	cout << "Invalid Month" << endl;

    }

    cin >> M;
	
  }

  return 0;

}
