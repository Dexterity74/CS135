#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.141592653589;

int main() {

    double d, h, r, sHeight, lSurface, sArea, fPoint, efficiency, volume, wLength, gain;

    cout << "*******************************************" << endl;
    cout << "** Rebel Alliance Computational Division **" << endl;
    cout << "*******************************************" << endl;

    cout << "Enter the diameter of the super laser lens(km): ";
    cin >> d;

    r = d/2.0;

    cout << "Enter the height of the lens(km): ";
    cin >> h;

    sHeight = sqrt(pow(h, 2.0) + pow(r, 2.0));
    lSurface = r*sHeight*PI;
    sArea = r*PI*(r+sHeight);
    volume = (1.0/3.0)*(pow(r, 3.0)*PI*h);
    fPoint = (pow((2.0*r), 2.0))/(16.0*h);

    cout << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Specifications for Super Laser" << endl;
    cout << "Height: " << h << " km" << endl;
    cout << "Diameter: " << d << " km" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Slant Height: " << sHeight << " km" << endl;
    cout << "Lateral Surface: " << lSurface << " km" << endl;
    cout << "Area: " << sArea << " km squared" << endl;
    cout << "Volume: " << volume << " km cubed" << endl;
    cout << "Focal Point: " << fPoint << " km" << endl;
    cout << endl;
    cout << "Enter the efficiency of the lens/antenna: ";
    cin >> efficiency;
    cout << "Enter the wave length (meters): ";
    cin >> wLength;

    gain = 10.0*(log10(efficiency*pow(((PI*d)/wLength), 2.0)));

    cout << "The Super Laser lens gain is: " << gain << " dB" << endl;
    cout << endl;
    cout << "<<<<<<<<<<< - >>>>>>>>>>>" << endl;
    cout << "May the Force be with you!" << endl;
    cout << "<<<<<<<<<<< - >>>>>>>>>>>" << endl;

    return 0;
}