#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double pi = M_PI;
const string planets [8] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
const double planetDiameter [8] = {4879, 12104, 12756, 6792, 142298, 120536, 51118, 49528};
const double planetMass [8] = {0.330*pow(10,24), 4.87*pow(10,24), 5.97*pow(10,24), 
			       0.642*pow(10,24), 1898*pow(10,24), 568*pow(10,24), 
			       86.8*pow(10,24), 102*pow(10,24)};

int main() {

    double diameter = 0.0, mass = 0.0, radi, circ, vol, dens;
    string planet = "";
    int userInput = 0;

    cout << "Mercury[1]\nVenus[2]\nEarth[3]\nMars[4]\nJupiter[5]\nSaturn[6]\nUranus[7]\nNeptune[8]" << endl;
    cout << "Welcome to planetary statistics, enter a number corresponding to the planet above to continue: ";
    cin >> userInput;
    
    while(cin.fail()){
        cout << "Not an integer, try again" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> userInput;
    }
    if(userInput < 1 || userInput > 8){
        cout << "Invalid input, try again" << endl;
        cin >> userInput;
    }

    // set local variables to user input
    diameter = planetDiameter[userInput-1];
    mass = planetMass[userInput-1];
    planet = planets[userInput-1];
    
    /* Your code here. Calculate radius, circumference, volume, and density.
        Use the variable pi declared above for pi. Diameter is given in km, Mass is given in kg.
        radius(km) = diameter / 2
        circumference(km) = pi*diameter
        volume in m^3 = (4/3 * pi * radius^3) * 1000^3
        density in kg/m^3 = (mass / volume)
    */

    radi = diameter / 2.0;
    circ = pi*diameter;
    vol = ((4.0/3.0) * pi * pow(radi,3.0)) * pow(1000.0,3.0);
    dens = (mass / vol);

    cout << fixed;
    cout << setprecision(2) << planet << " statistics:" << endl;
    cout << setprecision(2) << planet << " radius: " << radi << " km" << endl;
    cout << setprecision(2) << planet << " circumference: " << circ << " km" << endl;
    cout << scientific;
    cout << setprecision(2) << planet << " volume: " << vol << " m^3" << endl;
    cout << fixed;
    cout << setprecision(2) << planet << " density: " << dens << " kg/m^3\n" << endl;

    return 0;

}
