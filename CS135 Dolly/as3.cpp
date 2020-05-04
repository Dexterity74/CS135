/* File: as3.cpp
 *
 * Name: 
 *
 * Input: The purpose of this assignment is to become more familiar with cmath and all
 * 	  of its uses. We will be using the sqrt() and pow() again from as2.cpp. Now
 * 	  we are also using cos() and sin().
 *
 * Output: The expected output is to allow the user to input the height of a volcano
 * 	   cone, the velocity of a flying rock, and the angle at which it is flying.
 * 	   Then the code will calculate the fly time of the rock, the maximum height
 * 	   it reached, and the range it traveled.   */

#include <iostream>             // Utilizes the cout/cin function.
#include <cmath>                /* Allows math functions like sin(), cos(), and tan(). 
                                 * cmath allows pow() and sqrt() to be used.  */
using namespace std;

int main ()
{ //beginning of main


	int height, velocity, angleD;           // 
	double Range, maxHeight, timeofFlight;   //  These are different data
	double velocityX, velocityY, angleR, blob;// types that need to be
	const double PI = 3.14159;	         //  defined for the compiler
	double g = 64.348118;  			//
	double blobUp, blobDown;


/* function: double pow()
 *
 * function_identifier: double pow allows us to calculate numbers to a certain power
 *
 * parameters: function must be defined by double pow( double base, double exponent ); 
 *
 * return value: function returns as a floating point value  */
	

	cout << " " << endl;
	cout << "***********************" << endl;
	cout << " Projectile Calculator" << endl;	// This is just fancy
	cout << "***********************" << endl;
	cout << " " << endl;


	cout << "Height of the volcano cone(ft): ";	//
	cin >> height;					 //
							  //	  
							   //  This outputs a request in
	cout << "Velocity(ft/sec): ";			    // which the user can input
	cin >> velocity; 				    // a number into a defined
							   //  variable
							  //
	cout << "Angle(degrees): ";			 //
	cin >> angleD;					//

	
	angleR = angleD * (PI/180);         // This section calculates the inputted
					    // variables and applies to the defined 
	velocityX = velocity * cos(angleR); // variables                             
										      
	velocityY = velocity * sin(angleR);					

	timeofFlight = (velocityY + sqrt(pow(velocityY,2.0) + g * height))/((0.5) * g);

	maxHeight = height + (pow(velocityY,2.0)) / (g);

	blobUp = velocityY + (sqrt((pow(velocityY,2.0)) + (g * height)));

	blobDown = 0.5 * g;

	blob = blobUp / blobDown;

	Range = velocityX * blob;


/* function: sqrt()
 *
 * function_identifier: sqrt() allows us to take the square root of a number
 *
 * parameters: sqrt() is allowed by cmath. as long as parens are filled correctly it 
 * 	       will compile
 *
 * return value: we receive a value in its square root form  */


/* function: sin()
 *
 * function_identifier: sin() allows us to calculate the sine trig quantity
 *
 * parameters: sin() is allowed by cmath. enter degrees and you will get a sine return
 *
 * return value: we receive a solved sin value back  */


/* function: cos()
 *
 * function_identifier: cos() allows us to calculate the cosine trig quantity
 *
 * parameters: cos() is allowed by cmath. enter degrees and you will get a cosine return
 *
 * return value: we receive a solved cosine value back  */



	cout << "Rock time of flight: " << timeofFlight << " seconds " << endl;


	cout << "Max height: " << maxHeight << " feet " << endl;


	cout << "Range: " << Range << " feet " << endl;


	cout << " " << endl;



	return 0;



} //end of main
