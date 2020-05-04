/* Name: , NSHE ID: 5004991051, CS135-1019, Assignment #4
 *
 * Description: This assignment is designed to calculate different parameters
 *              for star shapes.
 *
 * Input: I am inputting 3 void functions to make visual ease instead of having
 *        clutter inside the switch statement inside of main(). Besides general 
 *        iostream output, we are going to be using cmath to calculate a variety
 *        of values from different star shapes given specific parameters for the
 *        shape.
 *
 * Output: The user is going to provide input for the shape based off what 
 *         they choose. There will be a user friendly menu to allow them
 *         multiple options to choose from. Then they will have to enter 
 *         any value between certain parameters and the program will provide
 *         them with all the values they require.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.141592653589;

void doubleStar();
void threeStar();
void polygramPoly();

/*  Algorithm:
 *   1. Define needed variables
 *   2. Create friendly menu
 *   3. Create switch statement for user selection
 *   4. Call to designated void function to the shape user wants with respective selections
 *   5. Allow user to quit from menu
 *   6. If user does not select any of the options, output invalid entry and exit
 *   7. return 0;
*/  

int main() {

    char select;

    cout << "\n  *************************************\n";
    cout << "  *  Rebel Alliance Computation Support\n";
    cout << "  *  Star area calculator\n";
    cout << "  *************************************\n";

    cout << "\n (d/D/2) - Double star Polugon";
    cout << "\n (t/T/3) - Three star Polygon";
    cout << "\n (p/P) -   Polygram Polygon";
    cout << "\n (q/Q) -   Quit\n";

    cout << "\n Your selection: ";
    cin >> select;
    cout << endl;
    switch(select) {
        case 'd':
        case 'D':
        case '2':
            doubleStar();

            break;
        case 't':
        case 'T':
        case '3':
            threeStar();

            break;
        case 'p':
        case 'P':
            polygramPoly();

            break;
        case 'q':
        case 'Q':
            cout << "Quitting...\n\n";
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

            break;
        default:
            cout << "Error - invalid entry\n\n";
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
    }

    return 0;
    
}

void doubleStar() {

    double lLong, lShort, bLength;
    double hLong, hShort, diameter, perimeter, area;

    cout << fixed << setprecision(2);
    cout << "Double Star Polygon Calculator\n";
    cout << "------------------------------\n\n";
    cout << "Length Long Valid range [1.00 < Length long < 236.00]\n";
    cout << "Length long: ";
    cin >> lLong;
    while( lLong <= 1.0 || lLong >=236.0) {
        cout << "\nInvalid parameters - try again\n";
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl;

        cout << "Length long: ";
        cin >> lLong;
    }
    cout << endl;

    cout << "Length Short Valid range [1.00 < Length short < 118.00]\n";
    cout << "Length short: ";
    cin >> lShort;
    while( lShort <= 1.0 || lShort >=118.0) {
        cout << "\nInvalid parameters - try again\n";
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl;

        cout << "Length short: ";
        cin >> lShort;
    }
    cout << endl;

    cout << "Base Length Valid range [1.00 < Base length < 29.50\n";
    cout << "Base length: ";
    cin >> bLength;
    while( bLength <= 1.0 || bLength >=29.5) {
        cout << "\nInvalid parameters - try again\n";
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl;

        cout << "Base length: ";
        cin >> bLength;
    }
    cout << endl;
    cout << "--------------------------------------\n";
    cout << "Calculations for a Double Star Polygon\n";
    cout << "Base Length: " << bLength << endl;
    cout << "Length Long: " << lLong << endl;
    cout << "Length Short: " << lShort << endl;

    hLong = sqrt(pow(lLong, 2.0) - (pow(bLength,2.0)/4.0));
    hShort = sqrt(pow(lShort, 2.0) - (pow(bLength,2.0)/4.0));
    diameter = 2.0 * hLong+bLength*(1.0+sqrt(2.0));
    perimeter = 8.0 * (lShort + lLong);
    area = 2.0*bLength*(bLength*(1.0+sqrt(2.0))+(hLong + hShort));

    cout << "--------------------------------------\n";
    cout << "Height Long: " << hLong << endl;
    cout << "Height Short: " << hShort << endl;
    cout << "Diameter: " << diameter << endl;
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl << endl;

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

    return;
}
void threeStar() {

    double edgeLength, inAngle;
    double outAngle, spikeB, spikeH, cLength, height, perimeter, area, alpha, beta;

    cout << fixed << setprecision(2);
    cout << "Threestar Polygon Calculator\n";
    cout << "----------------------------\n\n";
    cout << "Edge Length Valid range [1.00 < edge length < 132.00]\n";
    cout << "Edge length: ";
    cin >> edgeLength;
    while( edgeLength <= 1.0 || edgeLength >= 132.0) {
        cout << "\nInvalid parameters - try again\n";
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl;

        cout << "Edge length: ";
        cin >> edgeLength;
    }
    cout << endl;
    cout << "Inner Angle (degrees) Valid range [0.00 < Inner Angle < 60.00]\n";
    cout << "Inner Angle (degrees): ";
    cin >> inAngle;
    while( inAngle <= 0.0 || inAngle >= 60.0) {
        cout << "\nInvalid parameters - try again\n";
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl;

        cout << "Inner Angle (degrees): ";
        cin >> inAngle;
    }
    outAngle = 120.0 + inAngle;
    alpha = (inAngle * PI)/180.0;
    beta = (outAngle * PI)/180.0;
    spikeB = sqrt(2.0*pow(edgeLength,2.0)*(1.0-cos(alpha)));
    spikeH = sqrt((4.0*pow(edgeLength,2.0)-pow(spikeB,2.0))/4.0);
    cLength = sqrt(2.0*pow(edgeLength,2.0)*(1.0-cos(beta))); 
    height = sqrt(3.0)/2.0*cLength;
    perimeter = 6.0 * edgeLength;
    area = 3.0/2.0*spikeH*spikeB+sqrt(3.0)/4.0*pow(spikeB,2.0);

    cout << "------------------------------------\n";
    cout << "Calculations for a Threestar Polygon\n";
    cout << "Edge Length: " << edgeLength << endl;
    cout << "Outer angle: " << outAngle << endl;
    cout << "Inner angle: " << inAngle << endl;
    cout << "------------------------------------\n";
    cout << "Spike base: " << spikeB << endl;
    cout << "Spike height: " << spikeH << endl;
    cout << "Chord length: " << cLength << endl;
    cout << "Height: " << height << endl;
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;
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

    return;
}
void polygramPoly(){

    int numPoints;
    double edgeLength, outAngle;
    double inAngle, bLength, spikeH, perimeter, area, cLength, outADegrees, inADegrees;
    
    cout << fixed << setprecision(2);
    cout << "Polygram Calculator\n";
    cout << "-----------------------------\n\n";
    cout << "Point Count Valid range [3.00 < Point Count < 100.00]\n";
    cout << "Point count: ";
    cin >> numPoints;
    while( numPoints <= 3.0 || numPoints >= 100.0) {
        cout << "\nInvalid parameters - try again\n";
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl;

        cout << "numPoints: ";
        cin >> numPoints;
    }
    cout << endl;

    cout << "Edge Length Valid range [1.00 < Edge Length < 132.00]\n";
    cout << "Edge length: ";
    cin >> edgeLength;
    while( edgeLength <= 1.0 || edgeLength >= 132.0) {
        cout << "\nInvalid parameters - try again\n";
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl;

        cout << "Edge length: ";
        cin >> edgeLength;
    }
    cout << endl;

    cout << "Outer Angle Valid range [0.00 < Outer ngle < 60.00\n";
    cout << "Outer angle: ";
    cin >> outAngle;
    while( outAngle <= 0.0 || outAngle >= 60.0) {
        cout << "\nInvalid parameters - try again\n";
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl;

        cout << "Outer angle: ";
        cin >> outAngle;
    }

    /*inADegrees = 360.0/numPoints + outAngle;
    outADegrees = 360.0/numPoints + inADegrees;
    cout << inAngle;
    inARadians = cos(inAngle);                    // comments are me trying to
    cout << inARadians;                           // figure out how to convert
    inADegrees = inARadians * (180.0/PI);         // radians to degrees in C++
    cout << inADegrees;
    outADegrees = outAngle * (180.0/PI);*/

    //hard coded cos(alpha/beta) in degrees
    //bLength = sqrt(2.0*pow(edgeLength,2.0)*(1.0-.784444));
    //cLength = sqrt(2.0*pow(edgeLength,2.0)*(1.0-.7071067));
   
    outADegrees = outAngle*(PI/180.0);
    inAngle = outADegrees-((2.0*PI)/numPoints);
    inADegrees = inAngle*(180.0/PI);

    bLength = sqrt(2.0*pow(edgeLength,2.0)*(1.0-cos(inAngle)));
    cLength = sqrt(2.0*pow(edgeLength,2.0)*(1.0-cos(outADegrees)));
    spikeH = sqrt((4.0*pow(edgeLength,2.0)-pow(bLength,2.0))/4.0);
    perimeter = 2.0*numPoints*edgeLength;
    area = numPoints*pow(bLength,2.0)/(4.0*tan(PI/numPoints))+numPoints*spikeH*bLength/2.0;

    cout << endl;
    cout << "-------------------------\n";
    cout << "Calculations for Polygram\n";
    //cout << setprecision(0);
    cout << "Point count: " << numPoints << endl;
    //cout << setprecision(2);
    cout << "Edge Length: " << edgeLength << endl;
    cout << "Outer angle: " << outAngle << endl;
    cout << "-------------------------\n";
    cout << "Inner angle: " << inADegrees << endl;
    cout << "Base length: " << bLength << endl;
    cout << "Chord length: " << cLength << endl;
    cout << "Spike Height: " << spikeH << endl;
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl << endl;

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
    
    return;
}