#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

      double length, width, height;
      double centimeters;
      double kilograms, density, volume, mass;
      string material = " ";


      cout << "Length of cube in meters: ";
      cin >> length;

      cout << "Width of cube in meters: ";
      cin >> width;

      cout << "Height of cube in meters: ";
      cin >> height;

      cout << "Material name: ";
      cin >> material;

      cout << "Density of " << material << " in grams per cubic centimeter: ";
      cin >> density;


      volume = length * width * height;
      mass = volume * density;
      kilograms = mass * 1000.0;
      centimeters = volume * 1000000.0;


      cout << " " << endl;

      cout << "Name" << right << setw(20) << "Vol. (cm^3)" << right << setw(20) << "Dens. (g/cm^3)" << right << setw(20) << "Mass (kg)" << endl;

      cout << fixed << material << right << setw(20) << setprecision(1) << centimeters << right << setw(20) << density << right << setw(20) << setprecision(4) << kilograms << endl;

      
     

}
