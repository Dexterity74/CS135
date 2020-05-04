/* CS135 Fall 2019 
   Assignment 8
   
   Justin Negron
*/

// Don't need main function algorithm.

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;
 
// function prototypes
void fish( );
double mysteryY( double );
double mysteryX( double );
void mystery();
void archimedean( );

void genPlotScript( string );

// Global named constant
const double PI=3.14159;

int main() {

    char selection=' ';
   
    while( true ) {
        cout << "Parametric Equation Plotter"<<endl;
        cout << "---------------------------"<< endl;
        cout << "F/f - Fish Curve " << endl;
        cout << "A/a - Archimedean " << endl;
        cout << "M/m - Mystery" << endl;
        cout << "Q/q - quit" << endl;
        cout << "Selection: ";

        cin >> selection;

        switch ( selection ) {
        
            case 'F':
            case 'f':               
                fish( );
                genPlotScript( "fish" );
                system("gnuplot fish_plot.me");
                break;
        
            case 'A':
            case 'a':
                archimedean( );
                genPlotScript( "archimedean" );
                system("gnuplot archimedean_plot.me");
                break;

            case 'm':
            case 'M': 
                cout<< "Mystery Equation plotter" << endl;
                mystery();
                genPlotScript( "mystery" );
                system("gnuplot mystery_plot.me");
                break;

            case 'q':
            case 'Q':
                cout << "Exiting ... " << endl;
                exit(0);

            default:
                cout << "Error - try again" << endl;
        }
    }
}

/* function: void fish( )
 *
 * function_identifier: When this function is called, x and y values for the fish
 *                      curve are sent to the gnu plot
 *
 * parameters: function is defined by fish(); 
 *
 * return value: no return value  */

/*  Algorithm:
 *   1. Define ofstream output
 *   2. Define size, count, rotation, and plot offset as double
 *   3. Define x and y values as double
 *   4. Prompt user for variables
 *   5. If value entered is not a number, clear variables and send error message and prompt for value again
 *   6. Open text file to output to
 *   7. If file fails to open, send error message and exit
 *   8. Create for loop (i=0; i<count; i++)
 *      a) Create nested for loop for parameters 0 <= t <= (10*PI)
 *          i) Calculate x and y values inside for loop   
 *          ii) Outpout x and y values to file
 *   9. Close file
 *   10. return;
*/  
void fish( ) {

    ofstream outfile;

    double size = 0.0, count = 0.0, rotation = 0.0, plotOffset = 0.0;
    double x = 0, y = 0;

    cout << "Fish curve plotter" << endl;                           //display message

    cout << "Enter size: ";
    cin >> size;
    while( cin.fail() == true ) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Illegal value - try again" << endl;
        cout << "Enter size: ";
        cin >> size;  
    }

    cout << "Enter rotation: ";
    cin >> rotation;
    while( cin.fail() == true ) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Illegal value - try again" << endl;
        cout << "Enter rotation: ";
        cin >> rotation;
    }

    cout << "Enter count: ";
    cin >> count;
    while( cin.fail() == true ) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Illegal value - try again" << endl;
        cout << "Enter count: ";
        cin >> count;
    }

    cout << "Enter plot offset: ";
    cin >> plotOffset;
    while( cin.fail() == true ) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Illegal value - try again" << endl;
        cout << "Enter plot offset: ";
        cin >> plotOffset;
    }

    outfile.open("fish.txt");                                       
    while(outfile.is_open() != true) {                              //open text file
        cout << "Error opening file" << endl;                       //test if file is open, if not, display error message and exit
        
        exit(0);
    }

    for(double i = 0; i < count; i++) {
        for(double t = 0; t <= 10*PI; t += 0.1) {
            x = size * (cos(t) + 2.0 * rotation * cos(t / 2.0));    //test if file is open, if not, display error message and exit
            y = size * sin(t);
            outfile << x << " " << y << endl;
        }
        size *= plotOffset;
    }

    outfile.close();                                                //file close
    return;                                                         //return
}


/* function: void archimedean( )
 *
 * function_identifier: When this function is called, x and y values for the archimedean
 *                      spirals are sent to the gnu plot
 *
 * parameters: function is defined by archimedean(); 
 *
 * return value: no return value  */

/*  Algorithm:
 *   1. Define ofstream output
 *   2. Define size and count as double
 *   3. Define x and y values as double
 *   4. Prompt user for count and size
 *   5. If value entered is not a number, clear variables and send error message and prompt for value again
 *   6. Open text file to output to
 *   7. If file fails to open, send error message and exit
 *   8. Create loop for 0 < t < (count*2*PI)
 *      a) Calculate x and y values inside for loop   
 *      b) Outpout x and y values to file
 *   9.. Close file
 *   10. return;     */  
void archimedean(  ) {

    ofstream outfile;

    double size = 0.0, count = 0.0;
    double x = 0, y = 0;

    cout << "Archimedean spiral plotter" << endl;                   //display message

    cout << "Enter count: ";
    cin >> count;
    while( cin.fail() == true ) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Illegal value - try again" << endl;
        cout << "Enter count: ";
        cin >> count;  
    }

    cout << "Enter size: ";
    cin >> size;
    while( cin.fail() == true ) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Illegal value - try again" << endl;
        cout << "Enter rotation: ";
        cin >> size;
    }

    outfile.open("archimedean.txt");
    while(outfile.is_open() != true) {                              //open text file
        cout << "Error opening file" << endl;                       //test if file is open, if not, display error message and exit
        
        exit(0);
    }

    for(double t = 0; t < count*2*PI; t += 0.1) {                   //for loop that calculations x and y values and outputs to file
        x = size * t * cos(t+size);
        y = size * t * sin(t+size);                                         
        outfile << x << " " << y << endl;
    }

    outfile.close();                                                //file close
    return;                                                         //return
}

/* function: void mystery( )
 *
 * function_identifier: When this function is called, the needed x and y values will be sent to the gnu plot
 *
 * parameters: function is defined by mystery(); 
 *
 * return value: no return value  */

/*  Algorithm:
 *   1. Define ofstream output
 *   2. Open file and verify if open
 *   3. If file fails to open, send error message and exit
 *   4. Create loop for -8.0 <= t <= 8.0 
 *      a) Call both double mystery functions inside for loop
 *      b) Output to file, space delimited, x and y values that were calculated through double functions
 *   7. Close file
 *   8. Return;     */  
void mystery() {

    ofstream outfile;

    outfile.open("mystery.txt");
    while(outfile.is_open() != true) {                              //open text file
        cout << "Error opening file" << endl;
                                                                    //test if file is open, if not, display error message and exit
        exit(0);
    }

    for(double t = -8.0; t <= 8.0; t += 0.001) {
        mysteryX(t);
        mysteryY(t);
                                                                    //for loop that calls mystery functions and outputs values to file
        outfile << mysteryX(t) << " " << mysteryY(t) << endl;

    }

    outfile.close();                                                //file close
    return;                                                         //return

}

/* function: double mysteryX( double t)
 *
 * function_identifier: This function is here to hold the x value for the void mystery() function
 *
 * parameters: function is defined by mysteryX( double t ); 
 *
 * return value: function returns the calculated value for x  */

/*  Algorithm:
 *  1. Define variable for y
 *  2. Define variable for |t|
 *  3. Correctly calculate y
 *  4. return y value         */  
double mysteryX( double t ) {

    double aT = abs(t), x = 0.0;
                                                                                    //working mysteryX calculation
    x = (aT/t)*(0.3*aT+0.2*abs(aT-1.0)+2.2*abs(aT-2.0)-2.7*abs(aT-3)-3*abs(aT-5)+3*abs(aT-7)+5*sin((PI/4)*(abs(aT-3)-abs(aT-4)+1))+(5/4)*pow((abs(aT-4.0)-abs(aT-5.0)-1.0),3.0)-5.3*cos(((PI/2.0)+asin(47.0/53.0))*(((abs(aT-7.0)-abs(aT-8.0)-1.0)/2.0)))+2.8);

    return x;
} 

/* function: double mysteryY( double t)
 *
 * function_identifier: This function is here to hold the y value for the void mystery() function
 *
 * parameters: function is defined by mysteryY( double t ); 
 *
 * return value: function returns the calculated value for y */

/*  Algorithm:
 *  1. Define variable for y
 *  2. Define variable for |t|
 *  3. Correctly calculate y
 *  4. return y value         */  
double mysteryY( double t) {

    double aT = abs(t), y = 0.0;

    //double a, b, c, d, e, f;
	//double a, b, c;
                                                                            //working mysteryY calculation
    y = (3.0/2.0)*abs(aT-1.0)-(3.0/2.0)*abs(aT-2.0)-(29.0/4.0)*abs(aT-4.0)+(29.0/4.0)*abs(aT-5.0)+(7.0/16.0)*pow((abs(aT-2.0)-abs(aT-3.0)-1.0),4.0)+4.5*sin((PI/4.0)*(abs(aT-3.0)-abs(aT-4.0)-1.0))-((3.0*sqrt(2.0))/5.0)*pow(abs(abs(aT-5.0)-abs(aT-7.0)),(5.0/2.0))+6.4*sin(((PI/2.0)+asin(47.0/53.0))*(((abs(aT-7.0)-abs(aT-8.0)+1.0)/2.0))+asin(56.0/64.0))+4.95;
    
    //a = (3.0/2.0)*abs(aT-1.0)-(3.0/2.0)*abs(aT-2.0)-(29.0/4.0)*abs(aT-4.0)+(29.0/4.0)*abs(aT-5.0)+(7.0/16.0)*pow((abs(aT-2.0)-abs(aT-3.0)-1.0),4.0);
    //b = 4.5*(sin((PI/4.0)*(abs(aT-3.0)-abs(aT-4.0)-1.0)))-((3.0*sqrt(2.0))/5=.0)*pow(abs(abs(aT-5.0)-abs(aT-7.0)),(5.0/2.0));
    //c = 6.4*(sin(((PI/2.0)+asin(47.0/53.0))*(((abs(aT-7.0)-abs(aT-8.0)+1.0)/2.0))+asin(56.0/64.0)))+4.95;

    //y = a + b + c;                                            //All comments here were trying to find errors

    //a = (3.0/2.0)*abs(aT-1.0)-(3.0/2.0)*abs(aT-2.0);
    //b = (29.0/4.0)*abs(aT-4.0)+(29.0/4.0)*abs(aT-5.0);
    //c = (7.0/16.0)*pow((abs(aT-2.0)-abs(aT-3.0)-1.0),4.0);
    //d = 4.5*sin((PI/4.0)*(abs(aT-3.0)-abs(aT-4.0)-1.0));
    //e = ((3.0*sqrt(2.0))/2.0)*pow(abs(abs(aT-5.0)-abs(aT-7.0)),(5.0/2.0));
    //f = 6.4*sin(((PI/2.0)+asin(47.0/53.0))*(((abs(aT-7.0)-abs(aT-8.0)+1.0)/2.0))+asin(56.0/64.0))+4.95;

    //y = a - b + c + d - e + f;

    return y;
}
 
/* genPlotScript 
   Creates a gnuplot script to plot the specified file.  
   argument 
	str - contains the filename of the text file to be plotted. 

   return 
	none
*/
void genPlotScript( string str ) {

    string first = "set terminal png size 640, 480 font \"Helvetica,8\" \nset output ";
    string second = " using 1:2 with lines notitle\n";

    ofstream oFile;

    oFile.open( str+"_plot.me" );
    if (oFile.is_open( )){
        oFile << first ;
        oFile << '\"' << str+".png" <<'\"' << endl;
        oFile << "plot " << '\"' << str+ ".txt" << '\"' ;
        oFile << second;
        oFile.close();
    }
}
