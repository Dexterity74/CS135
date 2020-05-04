/* File: as4.cpp
 *
 * Name: Justin Negron
 *
 * Input: The input of this program utilized switch's and if-else statements to create a program
 * 	  that had mulitple scenarios that would execute when the user entered a value. I used case
 * 	  to distinguish the different outcomes that the user put in, and break's to separate
 * 	  each possibility. If the user did not put any variable that the program supported, the
 * 	  default function prompted an invalid entry error. The program was also set to calculate
 * 	  each different size rock inside each of it's own case.
 * 	  
 * Output: The output of this program was a neat and well spaced interface for the user to determine
 * 	   the volume of the rocks mined at Slate Rock and Gravel Quarry. If the user ever inputted
 * 	   an incorrect value, they would be prompted invalid and to restart. When they did input
 * 	   a accepted value, it would calculate to their needs.     */

#include <iostream>     // iostream utilizes the cout/cin function.
#include <cmath>        // cmath allows math functions like sin(), cos(), tan(), pow(), and sqrt() 
#include <iomanip>      // iomanip allows manipulators such as setw(), setprecision, and more

using namespace std;

int main() { //beginning of main


	double edgeLength;
	char S;                                      // declared variables
	double surfaceArea, Volume, Height, STVR;

	cout << " " << endl;
	cout << "   ***************************" << endl;
	cout << "   *  Slate Rock and Gravel  *" << endl;
	cout << "   *  Rock Volume Calculator *" << endl;
	cout << "   ***************************" << endl;
	cout << " " << endl;

	cout << " (p/P) - Pentagonal Pyramid" << endl;
	cout << " (b/B) - Pentagonal Bipyramid" << endl;
	cout << " (d/D) - Gyroelongated Square Dipyramid" << endl;
	cout << " (g/G) - Gyrobifastgium" << endl;
	cout << " (e/E) - Elongated Pnetagonal Pyramid" << endl;
	cout << " (q/Q) - Quit" << endl;
	cout << " " << endl;
	cout << " Your selection: ";
	cin >> S;
	cout << " " << endl;

switch (S) {

/* function: switch () 
 *
 * function_identifier: The switch function allows a field that uses 'case' and 'breaks' to make
 * 			different outcomes based on what the user inputs or what a value holds
 *
 * parameters: We pass a variable that the user can input and based on their choosing it selects
 * 	       the menu they want.
 *
 * return_value: Does not return  */

    case 'P':
	case 'p':

/* function: case:
 *
 * function_identifier: The case function is set with a variable or char that is executed when the
 * 			switch function runs through it
 *
 * parameters: The case needs to be given a variable that, if selected, executes a line of code
 *
 * return_value: This returns any output attached to the variable that the case is assigned to   */

		cout << "Pentogonal Pyramid" << endl;
		cout << "Valid range [2.00 < Edge Length < 500]" << endl;
		cout << "Edge Length: ";
		cin >> edgeLength;
		
		if (2.00<edgeLength && edgeLength<500){
			cout << " " << endl;
			cout << "--------------------------------------" << endl;
			cout << "Calculations for a Pentogonal Pyramid" << endl;
			cout << fixed << "Edge Length: " << setprecision(2) << edgeLength << endl;
			cout << "--------------------------------------" << endl;
			cout << " " << endl;

			surfaceArea = (sqrt(25+10*sqrt(5))/4+5*sqrt(3)/4)*pow(edgeLength,2);
			Volume = (5+sqrt(5))/24*pow(edgeLength,3);
			Height = sqrt((5-sqrt(5))/10)*edgeLength;
			STVR = (surfaceArea/Volume);
			
			cout << fixed << "Surface Area: " << setprecision(2) << surfaceArea << endl;
			cout << fixed << "Volume: " << setprecision(2) << Volume << endl;
			cout << fixed << "Height: " << setprecision(2) << Height << endl;
			cout << fixed << "Surface to Volume Ratio: " << setprecision(2) << STVR << endl;

			cout << " " << endl;
			cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			cout << " " << endl;
		}
		else{
			cout << "Error - edge length out of range" << endl;
			cout << " " << endl;
			cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			cout << " " << endl;
		}

/* function: if-else statement
 *
 * function_identifier: if-else is a used to execute files if an input is under certain order, if it's 
 * 			not under a certain order, whatever the else statement has will be excecuted
 *
 * parameters: if needs to have parameters, for exmaple (a > b)
 *
 * return_value: If a is greater than b, a program could say 'A is greater than B', however if a
 * 		 is not greater than b, the else statement will execute 'A is not greater than B'  */		
	
	break;

/* function: break: 
 *
 * function_identifier: The break function simply separates cases
 *
 * parameters: the break function must be inserted between cases that are intended to have separate
 * 	       intentions
 *
 * return_value: Does not return   */
	
	case 'B':
	case 'b':
		cout << "Pentagonal Bipyramid" << endl;
		cout << "Valid range [1.00 < Edge Length < 1502]" << endl;
		cout << "Edge Length: ";
		cin >> edgeLength;

		if (1.00<edgeLength && edgeLength<1502){
			cout << " " << endl;
			cout << "---------------------------------------" << endl;
			cout << "Calculations for a Pentagonal Bipyramid" << endl;
			cout << fixed << "Edge Length " << setprecision(2) << edgeLength << endl;
			cout << "---------------------------------------" << endl;
			cout << " " << endl;

			surfaceArea = 5*sqrt(3)/2*pow(edgeLength,2);
			Volume = (5+sqrt(5))/12*pow(edgeLength,3);
			Height = 2*sqrt((5-sqrt(5))/10) * edgeLength;
			STVR = (surfaceArea/Volume);

			cout << fixed << "Surface Area: " << setprecision(2) << surfaceArea << endl;
			cout << fixed << "Volume: " << setprecision(2) << Volume << endl;
			cout << fixed << "Height: " << setprecision(2) << Height << endl;
			cout << fixed << "Surface to Volume Ratio: " << setprecision(2) << STVR << endl;

			cout << " " << endl;
			cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			cout << " " << endl;
		}
		else{
			cout << "Error - edge length out of range" << endl;
			cout << " " << endl;
			cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			cout << " " << endl;
		}

	break;

	case 'D':
	case 'd':
		cout << "Gyroelongated Square Dipygramid" << endl;
		cout << "Valid range [7.00 < Edge Length < 1502" << endl;
		cout << "Edge Length: ";
		cin >> edgeLength;

		if (7.00<edgeLength && edgeLength<1502){
			cout << " " << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "Calculations for a Gyroelongated Square Dipyramid" << endl;
			cout << fixed << "Edge Length: " << setprecision(2) << edgeLength << endl;
			cout << "-------------------------------------------------" << endl;
			cout << " " << endl;
										
			surfaceArea = 4*sqrt(3)*pow(edgeLength,2);
			Volume = (sqrt(2)+sqrt(4+3*sqrt(2)))/3*pow(edgeLength,3);
			Height = (sqrt(1-1/(2+sqrt(2)))+2/sqrt(2))*edgeLength;
			STVR = (surfaceArea/Volume);

			cout << fixed << "Surface Area: " << setprecision(2) << surfaceArea << endl;
			cout << fixed << "Volume: " << setprecision(2) << Volume << endl;
			cout << fixed << "Height: " << setprecision(2) << Height << endl;
			cout << fixed << "Surface to Volume Ratio: " << setprecision(2) << STVR << endl;

			cout << " " << endl;
			cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			cout << " " << endl;
		}
		else{
			cout << "Error - edge length out of range" << endl;
			cout << " " << endl;
			cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			cout << " " << endl;
		}

	break;

	case 'G':
	case 'g':
		cout << "Gyrobifastigium" << endl;
	       	cout << "Valid range [0.00 < Edge Length < 1740]" << endl;
		cout << "Edge Length: ";
		cin >> edgeLength;

		if(0.00<edgeLength && edgeLength<1740){
			cout << " " << endl;
			cout << "----------------------------------" << endl;
			cout << "Calculations for a Gyrobifastigium" << endl;
			cout << fixed << "Edge Length: " << setprecision(2) << edgeLength << endl;
			cout << "----------------------------------" << endl;
			cout << " " << endl;
			
			surfaceArea = (4+sqrt(3))*pow(edgeLength,2);
			Volume = sqrt(3)/2*pow(edgeLength,3);
			Height = sqrt(3) * edgeLength;
			STVR = (surfaceArea/Volume);

			cout << fixed << "Surface Area: " << setprecision(2) << surfaceArea << endl;
			cout << fixed << "Volume: " << setprecision(2) << Volume << endl;
			cout << fixed << "Height: " << setprecision(2) << Height << endl;
			cout << fixed << "Surface to Volume Ratio: " << setprecision(2) << STVR << endl;

			cout << " " << endl;
			cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			cout << " " << endl;
		}
		else{
			cout << "Error - edge length out of range" << endl;
			cout << " " << endl;
			cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			cout << " " << endl;
		}
	
	break;

	case 'E':
	case 'e':
		cout << "Elongated Pentagonal Pyramid Calculator" << endl;
		cout << "Valid range [0.52 < edgelength < 2751.00]" << endl;
		cout << "Edge Length: ";
		cin >> edgeLength;

		if (0.52<edgeLength && edgeLength< 2751.00){
			cout << " " << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Calculations for an Elongated Pentagonal Pyramid" << endl;
			cout << fixed << "Edge Length: " << setprecision(2) << edgeLength << endl;
			cout << "------------------------------------------------" << endl;
			cout << " " << endl;

			surfaceArea = (sqrt(25+10*sqrt(5)) / 4+5*sqrt(3)/4+5)*pow(edgeLength,2);
			Volume = ((5+sqrt(5))/24+sqrt(25+10*sqrt(5))/4)*pow(edgeLength,3);
			Height = (sqrt((5-sqrt(5))/10)+1)*edgeLength;
			STVR = (surfaceArea/Volume);

			cout << fixed << "Surface Area: " << setprecision(2) << surfaceArea << endl;
			cout << fixed << "Volume: " << setprecision(2) << Volume << endl;
			cout << fixed << "Height: " << setprecision(2) << Height << endl;
			cout << fixed << "Surface to Volume Ratio: " << setprecision(2) << STVR << endl;

			cout << " " << endl;
			cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			cout << " " << endl;
		}
		else{
			cout << "Error - edge length out of range" << endl;
			cout << " " << endl;
			cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			cout << " " << endl;
		}

	break;

	case 'Q':
	case 'q':
		cout << "Quitting . . . "<< endl;
		cout << " " << endl;
		cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
		cout << " " << endl;
	break;

	default:
		cout << "Error - invalid entry" << endl;
		cout << " " << endl;
		cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
		cout << " " << endl;
}

/* function: default: 
 *
 * function_identifier: default is used to execute code when no 'cases' hold the variable that was 
 * 			inputted
 *
 * parameters: if default is used, whatever code it is attached to will be executed under the conditions
 * 	       where none of the cases were utilized.
 *
 * return value: the code given under default will be executed if needed   */



	return 0;



} //end of main
