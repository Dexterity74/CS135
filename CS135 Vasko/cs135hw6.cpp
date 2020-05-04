/* Name: , NSHE ID: 5004991051, CS135-1019, Assignment #6
 *
 * Description: This assignment is a program that reads in a file and
 *              generates random droids of random models and assigns
 *              them to the names in the inputted file based on their
 *              name. 
 *
 * Input: The input of this program is a file with separated name with
 *        the first word on the line being the first name and the
 *        second word on the same line being the last name.
 *
 * Output: The output of this program will be chosen by the user and the
 *         output will be an organized list started with the number of
 *         records generated to first name and last name then the
 *         assigned droid type which may be assigned Administrative 
 *         if and only if the first name is a manager. FOllowed by the
 *         model type which is always random.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

/* Algorithm:
 * 1. Create separated structs with the the different droid types 
 *    and model types assigned to strings for ease later when randomzing
 *    and a counter for each different type to keep track
 * 2. Put the 5 enums for the droid types and model types required for
 *    the assignment
 * 3. Create int main() and declare all required variables
 * 4. Allow user to input a file to open
 * 5. Verify if file opened correctly, if not, prompt again
 * 6. Allow user to pick any file to open and store output
 * 7. Allow user to select whether they want to process all the files
 *    or not.
 * 8. Create a switch statement
 *   a) If yes to process all files
 *      i.   Create a while loop to loop while eof() is false
 *      ii.  Run an if statement to test if the first name is a manager
 *      iii. If true, assign droidName to administrative and add 1 to
 *           administrative counter then generate a random number to 
 *           choose a random model type.
 *      iv.  If false, generate a random number to pick a random droid
 *           type and add 1 to that droid type respectively then 
 *           generate another random number to pick a
 *           random model type.
 *      v.   Outside of the while loop, output to the file the total 
 *           droid count of each droid type, and required droids.
 *      vi.  break;
 *   b) If no to process all files
 *      i.   Allow user to select how many files to process
 *      ii.  If user enters a 0 value or negative number or a none
 *           integer, output error message and reprompt
 *      iii. When valid value goes through, create a for loop instead of
 *           a while loop and limit it to repeat only the requested 
 *           amount of times.
 *      iv.  Run an if statement to test if the first name is a manager
 *      v.   If true, assign droidName to administrator then generate
 *           a random number to choose a random model type.
 *      vi.  If false, generate a random number to pick a random droid
 *           type and add 1 to the specific droid counter then generate 
 *           another random number to pick a
 *           random model type.
 *      vii. Outside of the for loop, output to the file the total droid
 *           count of each droid type, and required droids. 
 *      viii.break;
 *   c) Default in case the user did not select either y or n.
 *      i.   Output error message
 *      ii.  return 1;
 * 9. Close the inputted file.
 * 10. Close the file chosen for output.
 * 11. Output to display thank you message and Rebel Alliance symbol
 * 12. return 0;
*/

struct droid{
	string zero = "administrative";
	string one = "maintenance";
	string two = "protocol";
	string three = "astromech";
};
struct admin{
	string zero = "ET_74";
	string one = "XA_540";
	string two = "3D_4X";
	int counter = 0;
};
struct maint{
	string zero = "F1_DX";
	string one = "EB_89";
	string two = "CB_2B";
	string three = "SA_45";
	int counter = 0;
};
struct proto{
	string zero = "C3PO";
	string one = "L80";
	string two = "SA_5";
	string three = "RA_7";
	int counter = 0;
};
struct astro{
	string zero = "M4_Y6";
	string one = "BB_8";
	string two = "D3_S5";
	string three = "R2_D2";
	int counter = 0;
};

enum DROID_TYPES { ADMINISTRATIVE, MAINTENANCE, PROTOCOL, ASTROMECH  };
enum ADMINISTRATIVE_TYPES { ET_74, XA_540, a3D_4X };
enum MAINTENANCE_TYPES { F1_DX, EB_89, CB_2B, SA_45 };
enum PROTOCOL_TYPES { C3PO, L80, SA_5, RA_7 };
enum ASTROMECH_TYPES { M4_Y6, BB_8, D3_S5, R2_D2 };

int main() {

	string first, last;
	string inputFile, outputFile;
	ifstream infile;
	ofstream outfile;
	char answer;
	int amount, anotherCounter = 0;
	int valueOne, valueTwo;
	droid droid; admin admin; maint maint;
	proto proto; astro astro; string droidName, modelName;

	///////////////////////////////////////
	//You may need to loop this portion if
	//input file does not exist

	//read in input file name
	cout << "Enter file name to process: ";
	cin >> inputFile;

	//open input file stream
	infile.open(inputFile.c_str());
	while(infile.is_open() == false) {
        cout << "File " << inputFile << " did not open." << endl;
		cout << "Enter file name to process: ";
		cin >> inputFile;       
    }
	//////////////////////////////////////

	//prompt for output file name
	cout << "Enter an output file: ";
	cin >> outputFile;

	//opens output file
	//does not need a loop since it will
	//create a new output file
	outfile.open(outputFile.c_str());

	//reads in a line (reads in first and last name)
	//on each line

	//ask the user if they want to read in the entire file
	//or a portion of it
	cout << "Would you like to process all the records in the file? (y/n) ";
	cin >> answer;

	/*DROID_TYPES droid = ADMINISTRATIVE;
	value = rand() % 4;                      // This does not work, nor
	droid = static_cast<DROID_TYPE>(value);  // does it compile. I will be
	*/										 // using structs as a substitute
	//srand(time(NULL));
	switch(answer) {
        case 'N':
		case 'n':
			cout << "Enter number of records to process: ";
			cin >> amount;
			while( cin.fail() || amount <= 0) {
				cout << endl;
				cout << "XXXXXXXXXX Error - non numeric or negative value, try again\n";
				cout << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cout << "Enter number of records to process: ";
				cin >> amount;
			}
			outfile << "Number First Name     Last Name      Droid Type      Model\n";
			outfile << "------------------------------------------------------------\n";
			for(int i = 1; i <= amount; i++) {
				infile >> first >> last;
				
				if( first == "Captain" || first == "Admiral" || first == "Captain" || first == "Commander" || first == "Darth" || first == "Emperor" || first == "Queen") {
					droidName = droid.zero;

					if( last == "noLastName" ) {
						last = " ";
					}
					valueTwo = rand() % 3;      // ET_74, XA_540, a3D_4X 
					if( valueTwo == ET_74 ) {
						modelName = admin.zero;
					}
					if( valueTwo == XA_540 ) {
						modelName = admin.one;
					}
					if( valueTwo == a3D_4X ) {
						modelName = admin.two;
					}
					admin.counter++;
				}
				else{
					valueOne = rand() % 4;
					if( last == "noLastName" ) {
						last = " ";
					}
					if( valueOne == ADMINISTRATIVE ) {
						droidName = droid.zero;

						valueTwo = rand() % 4;
						if( valueTwo == ET_74 ) {
							modelName = admin.zero;
						}
						if( valueTwo == XA_540 ) {
							modelName = admin.one;
						}
						if( valueTwo == a3D_4X ) {
							modelName = admin.two;
						}
						admin.counter++;
					}
					if( valueOne == MAINTENANCE ) {
						droidName = droid.one;

						valueTwo = rand() % 4;
						if( valueTwo == F1_DX ) {
							modelName = maint.zero;
						}
						if( valueTwo == EB_89 ) {
							modelName = maint.one;
						}
						if( valueTwo == CB_2B ) {
							modelName = maint.two;
						}
						if( valueTwo == SA_45 ) {
							modelName = maint.three;
						}
						maint.counter++;
					}
					if( valueOne == PROTOCOL ) {
						droidName = droid.two;

						valueTwo = rand() % 4;
						if( valueTwo == C3PO ) {
							modelName = proto.zero;
						}
						if( valueTwo == L80 ) {
							modelName = proto.one;
						}
						if( valueTwo == SA_5 ) {
							modelName = proto.two;
						}
						if( valueTwo == RA_7 ) {
							modelName = proto.three;
						}
						proto.counter++;
					}
					if( valueOne == ASTROMECH ) {
						droidName = droid.three;

						valueTwo = rand() % 4;
						if( valueTwo == M4_Y6 ) {
							modelName = astro.zero;
						}
						if( valueTwo == BB_8 ) {
							modelName = astro.one;
						}
						if( valueTwo == D3_S5 ) {
							modelName = astro.two;
						}
						if( valueTwo == R2_D2 ) {
							modelName = astro.three;
						}
						astro.counter++;
					}
				}

				// F1_DX, EB_89, CB_2B, SA_45
				// C3PO, L80, SA_5, RA_7
				// M4_Y6, BB_8, D3_S5, R2_D2

				outfile << setfill('0') << setw(4) << right << i;
				outfile << setfill(' ') << "   ";
				outfile << left << setw(15) << first;
				outfile << left << setw(15) << last;
				outfile << left << setw(16) << droidName;
				outfile << left << modelName << endl;
			}

			outfile << endl;
			outfile << "*********************\n";
			outfile << "Assigned Droid Count\n";
			outfile << "*********************\n";
			outfile << "Astromech:         " << astro.counter << endl;
			outfile << "Maintenance:       " << maint.counter << endl;
			outfile << "Protocol:          " << proto.counter << endl;
			outfile << "Administrative:    " << admin.counter << endl;

			cout << "Maximum requested records count of " << amount << " reached\n";
			outfile << endl;
			outfile << endl;
			outfile << "Total Droids Required   " << amount << endl;

			break;
        case 'Y':
		case 'y':
			outfile << "Number First Name     Last Name      Droid Type      Model\n";
			outfile << "------------------------------------------------------------\n";
			while(!infile.eof()) {
				infile >> first >> last;
				
				if( first == "Captain" || first == "Admiral" || first == "Captain" || first == "Commander" || first == "Darth" || first == "Emperor" || first == "Queen") {
					droidName = droid.zero;

					if( last == "noLastName" ) {
						last = " ";
					}
					valueTwo = rand() % 3;      // ET_74, XA_540, a3D_4X 
					if( valueTwo == ET_74 ) {
						modelName = admin.zero;
					}
					if( valueTwo == XA_540 ) {
						modelName = admin.one;
					}
					if( valueTwo == a3D_4X ) {
						modelName = admin.two;
					}
					admin.counter++;
				}
				else{
					valueOne = rand() % 4;
					if( last == "noLastName" ) {
						last = " ";
					}
					if( valueOne == ADMINISTRATIVE ) {
						droidName = droid.zero;

						valueTwo = rand() % 4;
						if( valueTwo == ET_74 ) {
							modelName = admin.zero;
						}
						if( valueTwo == XA_540 ) {
							modelName = admin.one;
						}
						if( valueTwo == a3D_4X ) {
							modelName = admin.two;
						}
						admin.counter++;
					}
					if( valueOne == MAINTENANCE ) {
						droidName = droid.one;

						valueTwo = rand() % 4;
						if( valueTwo == F1_DX ) {
							modelName = maint.zero;
						}
						if( valueTwo == EB_89 ) {
							modelName = maint.one;
						}
						if( valueTwo == CB_2B ) {
							modelName = maint.two;
						}
						if( valueTwo == SA_45 ) {
							modelName = maint.three;
						}
						maint.counter++;
					}
					if( valueOne == PROTOCOL ) {
						droidName = droid.two;

						valueTwo = rand() % 4;
						if( valueTwo == C3PO ) {
							modelName = proto.zero;
						}
						if( valueTwo == L80 ) {
							modelName = proto.one;
						}
						if( valueTwo == SA_5 ) {
							modelName = proto.two;
						}
						if( valueTwo == RA_7 ) {
							modelName = proto.three;
						}
						proto.counter++;
					}
					if( valueOne == ASTROMECH ) {
						droidName = droid.three;

						valueTwo = rand() % 4;
						if( valueTwo == M4_Y6 ) {
							modelName = astro.zero;
						}
						if( valueTwo == BB_8 ) {
							modelName = astro.one;
						}
						if( valueTwo == D3_S5 ) {
							modelName = astro.two;
						}
						if( valueTwo == R2_D2 ) {
							modelName = astro.three;
						}
						astro.counter++;
					}
				}

				// F1_DX, EB_89, CB_2B, SA_45
				// C3PO, L80, SA_5, RA_7
				// M4_Y6, BB_8, D3_S5, R2_D2
				anotherCounter++;
				outfile << setfill('0') << setw(4) << right << anotherCounter;
				outfile << setfill(' ') << "   ";
				outfile << left << setw(15) << first;
				outfile << left << setw(15) << last;
				outfile << left << setw(16) << droidName;
				outfile << left << modelName << endl;
			}

			outfile << endl;
			outfile << "*********************\n";
			outfile << "Assigned Droid Count\n";
			outfile << "*********************\n";
			outfile << "Astromech:         " << astro.counter << endl;
			outfile << "Maintenance:       " << maint.counter << endl;
			outfile << "Protocol:          " << proto.counter << endl;
			outfile << "Administrative:    " << admin.counter << endl;

			cout << "End of file detected, " << anotherCounter << " records read\n";
			outfile << endl;
			outfile << endl;
			outfile << "Total Droids Required   " << anotherCounter << endl;

			break;
		default:
			cout << "Unknown Selection..." << endl;
			return 1;
	}
	
	//you want to make this a counter contolled loop if
	//the user does not want to read the whole file,
	//possibly add an && clause to the while condition
	//while (infile >> first >> last) {
		//check the first name if it's a manager or
		//a regular person
		
		//cout << first << last;
		//if manager, just randomly choose a droid in
		//the administrative class

		//otherise randomly choose a class and randomly
		//choose a droid within the class

		//maintain a counter
		//counter++;
	//}

	infile.close();
	outfile.close();
	
	cout << endl;
	cout << "Thank you for using Rebel Alliance Computational Support\nMay the Force be with you!\n";
    cout << "           x" << endl;      
    cout << "     x    xxx    x" << endl;   
    cout << "    x    x x x    x" << endl;     
    cout << "   x      xxx      x" << endl;   
    cout << "  xx       x       xx" << endl; 
    cout << " xxx      xxx      xxx" << endl; 
    cout << " xxxx     xxx     xxxx" << endl; 
    cout << " xxxxx    xxx    xxxxx" << endl;    
    cout << "  xxxxxxxxxxxxxxxxxxx" << endl;     
    cout << "   xxxxxxxxxxxxxxxxx" << endl;      
    cout << "    xxxxxxxxxxxxxxx" << endl;        
    cout << "      xxxxxxxxxxx\n" << endl;

	return 0;
}
