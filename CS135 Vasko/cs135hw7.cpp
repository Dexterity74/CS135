/* Name: , NSHE ID: 5004991051, CS135-1019, Assignment #7
 *
 * Description: This assignment is a program that is a game. The game
 * 				essentially mimics an old classic called Mastermind.
 * 				The game will allow users to find a passcode using 
 *				logical deduction.
 *
 * Input: The input of this program uses several void functions and one bool function
 * 		  main was given and cannot be altered. setupGame() creates the first menu, 
 * 		  startGame() is essentially a infinite loop that uses break; to exit at certain points
 * 		  and process other functions. generatePasscode creates a random wanted passcode for the
 * 		  user to guess. validateGuess() validates the length of the users guess and makes sure 
 * 		  the user inputted a number, returns true if it has been validated. reportDifferences()
 * 		  is used for the menu that counts the accuracy of the guess to the passcode required. 
 * 		  displayHelp() is called to in mulitple instances whenever the user needs help.
 * 		  foldCase() was given to us, it just makes all character input lowercase.
 *
 * Output: The output of this program starts with a menu that you can choose
 * 		   to start the simulation, output a guide, or quit the program.
 * 		   The guide is a helpful display of difficulty differences and 
 * 		   tips and tricks to win the game.
 * 		   If the game is started, you can choose from 3 difficulties.
 * 		   You can display the help screen at any point during the game and not lose progress.
 * 		   You can return to menu during a game but lose progress of that game.
 * 		   If you win the game, it will say you were successful.
 * 		   If you run out of guessing attempts, it will output a fail message and output the wanted code. 
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototypes
void setupGame();
void startGame( int& att, bool test );
void generatePasscode( string& passcode, int count, int minD, int maxD );
bool validateGuess( string passcode, int minD, int maxD, uint count, string& guess );
void reportDifferences( string passcode, string guess, int& att, bool& test );
void displayHelp();
void foldCase( string& str );

//-----------------------------------------------
//------------DO NOT ALTER MAIN------------------
//-----------------------------------------------
int main(int argc, char* argv[])
{
	//Check command line arguments for debug mode
	//Normal
	if(argc == 1)
	{
		srand(time(NULL));
	}
	else if(argc >= 2)
	{
		//Debug Mode
		string argument = argv[1];
		if(argc == 2 && argument == "debug")
		{
			srand(0);
		}
		//Usage Guidelines
		else
		{
			cout << "To start program in debug mode: \n";
			cout << argv[0] << " debug\n";
			return -1;
		}
	}
	    
	//Main Menu
	string choice = "";
	do
	{
		cout << "+--------------------+\n";
		cout << "| Main Menu          |\n";
		cout << "+--------------------+\n";
		cout << "| [Start] Simulation |\n";
		cout << "| [Help] Guide       |\n";
		cout << "| [Quit]             |\n";
		cout << "+--------------------+\n";
		cout << endl;
		
		do
		{
			cout << "Select a menu option: ";
			cin >> choice;
			foldCase(choice);
			if(choice == "start")
			{
				setupGame();
				break;
			}
			else if(choice == "help")
			{
				displayHelp();
				break;
			}
			else if(choice == "quit")
			{
				break;
			}
			else
			{
				cout << "Invalid menu selection.\n";
			}
		}
		while(true);
	}
	while(choice != "quit");
	
	return 0;
}
//-----------------------------------------------
//------------DO NOT ALTER MAIN------------------
//-----------------------------------------------

void setupGame() {

	int att;
	bool test = false;

	cout << endl;
	cout << "+--------------------+" << endl;
	cout << "| Select Difficulty  |" << endl;
	cout << "+--------------------+" << endl;
	cout << "| [Easy]             |" << endl;
	cout << "| [Medium]           |" << endl;
	cout << "| [Hard]             |" << endl;
	cout << "+--------------------+" << endl;
	cout << "| [Help]             |" << endl;
	cout << "| [Main] Menu        |" << endl;
	cout << "+--------------------+" << endl;
	cout << endl;

	startGame( att, test );

	return;
}
//editted some function parameters to avoid -Wextra -Wall -pedantic errors
void startGame( int& att, bool test ) {

	string passcode;
	string choice;
	string guess;
	
	while( true ) {

		cout << "Select a menu option: ";
		cin >> choice;
		foldCase(choice);

		if( choice == "easy" ) {
			att = 10;
			cout << endl;
			cout << "+--------------------|" << endl;
			cout << "| Additional Options |" << endl;
			cout << "+--------------------|" << endl;
			cout << "| [Help]             |" << endl;
			cout << "| [Main] Menu        |" << endl;
			cout << "+--------------------|" << endl;
			cout << endl;
			generatePasscode( passcode, 3, 1, 3 );

			while( true ) {

				cout << "Guess Code (3 Digits, 1-3)  [Attempts: " << att << "/10]: ";

				reportDifferences( passcode, guess, att, test );

				if( test ) {
					break;
				}
			}
			
			break;
		}
		else if( choice == "medium" ) {
			att = 15;
			cout << endl;
			cout << "+--------------------|" << endl;
			cout << "| Additional Options |" << endl;
			cout << "+--------------------|" << endl;
			cout << "| [Help]             |" << endl;
			cout << "| [Main] Menu        |" << endl;
			cout << "+--------------------|" << endl;
			cout << endl;
			generatePasscode( passcode, 4, 1, 5 );

			while( true ) {

				cout << "Guess Code (4 Digits, 1-5)  [Attempts: " << att << "/15]: ";

				reportDifferences( passcode, guess, att, test );

				if( test ) {
					break;
				}
			}

			break;
		}
		else if( choice == "hard" ) {
			att = 20;
			cout << endl;
			cout << "+--------------------|" << endl;
			cout << "| Additional Options |" << endl;
			cout << "+--------------------|" << endl;
			cout << "| [Help]             |" << endl;
			cout << "| [Main] Menu        |" << endl;
			cout << "+--------------------|" << endl;
			cout << endl;
			generatePasscode( passcode, 5, 0, 9 );

			while( true ) {

				cout << "Guess Code (5 Digits, 0-9)  [Attempts: " << att << "/20]: ";

				reportDifferences( passcode, guess, att, test );

				if( test ) {
					break;
				}
			}

			break;
		}
		else if( choice == "help" ) {
			displayHelp();
			break;
		}
		else if( choice == "main" ) {
			cout << endl;
			break;
		}
		else {
			cout << "Error - Incorrect choice" << endl;
			
		}
	}
	

	return;
}

void generatePasscode( string& passcode, int count, int minD, int maxD ) {

	if( count == 3 ) {

		char *mode = new char[count];
		//char mode[count]; syntax error

		for( int i = 0; i < count; i++ ) {
			mode[i] = '0' + rand()%maxD + minD;
		}

		passcode.append(mode);

		//cout << passcode << endl;

	}
	else if( count == 4 ) {
		
		char *mode = new char[count];
		//char mode[count]; syntax error

		for( int i = 0; i < count; i++ ) {
			mode[i] = '0' + rand()%maxD + minD;
		}

		passcode.append(mode);

		//cout << passcode << endl;

	}
	else if( count == 5 ) {
		
		char *mode = new char[count];
		//char mode[count]; syntax error

		for( int i = 0; i < count; i++ ) {
			mode[i] = '0' + rand()%maxD + minD;
		}

		passcode.append(mode);

		//cout << passcode << endl;

	}
	else {
		cout << "Error - Incorrect choice" << endl;
	}

	//cout << passcode << endl;
	return;
}

bool validateGuess( string passcode, int minD, int maxD, uint count, string& guess ) {

	cin >> guess;
	foldCase(guess);
	//cout << guess << endl;
	//cout << guess[0] << " " << guess[1] << " " << guess[2] << " " << guess[3] << " " << guess[4] << endl;
	count = passcode.length();
	//intGuess = guess[0];
	//cout << intGuess << endl;
	//cout << count << endl;

	if( count == 3 ) {
		minD = 49;         //ASCII values
		maxD = 51;         //ASCII values
		
		if( guess.length() != 3 ) {
			return false;
		}
		if( guess[0] > maxD || guess[0] < minD ) {
			return false;
		}
		if( guess[1] > maxD || guess[1] < minD ) {
			return false;
		}
		if( guess[2] > maxD || guess[2] < minD ) {
			return false;
		}
	}
	else if( count == 4 ) {
		minD = 49;        //ASCII values
		maxD = 53;        //ASCII values
	
		if( guess.length() != 4 ) {
			return false;
		}
		if( guess[0] > maxD || guess[0] < minD ) {
			return false;
		}
		if( guess[1] > maxD || guess[1] < minD ) {
			return false;
		}
		if( guess[2] > maxD || guess[2] < minD ) {
			return false;
		}
		if( guess[3] > maxD || guess[3] < minD ) {
			return false;
		}
	}
	else if( count == 5 ) {
		minD = 48;        //ASCII values
		maxD = 57;        //ASCII values

		if( guess.length() != 5 ) {
			return false;
		}
		if( guess[0] > maxD || guess[0] < minD ) {
			return false;
		}
		if( guess[1] > maxD || guess[1] < minD ) {
			return false;
		}
		if( guess[2] > maxD || guess[2] < minD ) {
			return false;
		}
		if( guess[3] > maxD || guess[3] < minD ) {
			return false;
		}
		if( guess[4] > maxD || guess[4] < minD ) {
			return false;
		}
	}
	else if( count < 3 || count > 5) {
		return false;
	}

	return true;
}

void reportDifferences( string passcode, string guess, int& att, bool& test ) {

	int correct = 0, high = 0, low = 0;
	int minD, maxD, counter, count = 0;
	test = false;

	if( passcode.length() == 3 ) {
		minD = 1;
		maxD = 3;
		counter = 3;
		//cout << "easy" << endl;
	}
	if( passcode.length() == 4 ) {
		minD = 1;
		maxD = 5;
		counter= 4;
		//cout << "medium" << endl;
	}
	if( passcode.length() == 5 ) {
		minD = 0;
		maxD = 9;
		counter = 5;
		//cout << "hard" << endl;
	}
	
	if(validateGuess(passcode, minD, maxD, count, guess)) {

		for( int i = 0; i < counter; i++ ) {
			if( passcode[i] == guess[i] ) {
				correct++;
			}
			if( passcode[i] < guess[i] ) {
				high++;
			}
			if( passcode[i] > guess[i] ) {
				low++;
			}
		}
		cout << endl;
		cout << "+-------------+------+" << endl;
		cout << "|     Correct |    " << correct << " |" << endl;
		cout << "|    Too High |    " << high << " |" << endl;
		cout << "|     Too Low |    " << low << " |" << endl;
		cout << "+-------------+------+" << endl;
		cout << endl;
		att--;
	}
	else if( guess == "help" ) {
		displayHelp();
	}
	else if( guess == "main" ) {
		cout << endl;
		test = true;
	}
	else{
		cout << endl;
		cout << "Error. Invalid Code Format." << endl;
		cout << endl;
	}

	if( correct == counter ) {
		
		cout << "Code Found Successfully: " << passcode << endl;
		cout << endl;
		test = true;
	}
	if( att == 0 && correct != counter) {
	
		cout << "Abort Mission: Imperial security alerted to intrusion." << endl;
		cout << "Code was " << passcode << "." << endl;
		cout << endl;
		test = true;
	}

	return;
}

void displayHelp() {
	cout << endl;
	cout << "============================================================================================================================\n";
	cout << "---Difficulties---" << endl;
	cout << "Easy Mode: Passcode is strictly 3 digits long, each digit can only be 1, 2, or 3. You have 10 attempts." << endl;
	cout << "Normal Mode: Passcode is strictly 4 digits long, each digit can only be 1, 2, 3, 4, or 5. You have 15 attempts." << endl;
	cout << "Hard Mode: Passcode is strictly 5 digits long, each digit can only be 0, 1, 2, 3, 4, 5, 6, 7, 8, or 9. You have 20 attempts." << endl;
	cout << "---Tips/Advice---" << endl;
	cout << "Use the table that counts how many you have correct to keep track!" << endl;
	cout << "The table also counts if you guessed a digit too high or too low, use that to your advantage!" << endl;
	cout << "If you keep receiving \"Error. Invalid Code Format.\" Check if you're guessing a digit below or above the allowed range" << endl;
	cout << "To return to the main menu, type \"main\" -CAREFUL- You will lose your progress" << endl;
	cout << "If you run out of attempts, you will alert the Imperial security!" << endl;
	cout << "If you guess the code correctly, we're in!" << endl;
	cout << "============================================================================================================================\n"; 
	cout << endl;
	
	return;
}

void foldCase(string& str) {
	for(uint i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]); //reassigns character in str at position i to a lowercase equivalent
	}
	return;
}
