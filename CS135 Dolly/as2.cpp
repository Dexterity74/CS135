/* File: as2.cpp
 *
 * Name: 
 *
 * Input: Using iostream and cmath, the assignment is to write a program to essentially
 * 	  calculates the time for the rocks to hit the lava. 
 *
 * Output: The outcome will be the user inputting the initial height and initial
 * 	   velocity and that will be calculated to find the final velocity and the time
 *	   it took to hit the lava.  */

#include <iostream>             // Utilizes the cout/cin function.
#include <cmath>                /* Allows math functions like sin(), cos(), and tan(). 
                                 * cmath allows pow() and sqrt() to be used.  */
using namespace std;

int main ()
{ //beginning of main

	int height = 0;                           //
	double initialVelocity = 0.0;               //
	double g = 64.348118;                         //    These are different data
	int initialVelocitysq = 0;                      //  types that need to be
	double finalVelocity = 0.0;                       //defined for the compiler
	double time = 0.0;                              // 
	double finalVelocitya = 0.0;                  //
	double pow( double base, double exponent );

/* function: double pow()
 *
 * function_identifier: double pow allows us to calculate numbers to a certain power
 *
 * parameters: function must be defined by double pow( double base, double exponent ); 
 *
 * return value: function returns as a floating point value  */

	cout << "Distance from volcano rim to lava(ft): "; //cout is code being outputted
	cin >> height;					   //cin allows the user to input
							   //numbers

	cout << "Initial velocity(ft/sec): ";
	cin >> initialVelocity;


	initialVelocitysq = pow(initialVelocity,2.0);
	finalVelocity = sqrt(initialVelocitysq + g * height);

/* function: sqrt()
 *
 * function_identifier: sqrt() allows us to take the square root of a number
 *
 * parameters: sqrt is allowed by cmath. as long as parens are filled correctly it 
 * 	       will compile
 *
 * return value: we receive a value in its square root form  */

	cout << "Final velocity: " << finalVelocity << " feet/second " << endl;


	finalVelocitya = (finalVelocity - initialVelocity);  //i was receiving 'inf' as a
							     //return so I created an
							     //extra variable

	time = (finalVelocitya) /(0.5 * g);                  //this calculates the time
							     //it takes for the rock to
							     //hit the lava


	cout << "Time to ground: " << time << " seconds " << endl;


	cout << "Thank you for playing " << endl;



	return 0;



} //end of main
