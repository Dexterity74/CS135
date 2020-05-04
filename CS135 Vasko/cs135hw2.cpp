#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358;

void calculationOutput();

int main() {

    calculationOutput();

    return 0;
}

void calculationOutput() {

    double volume = 0.0, area = 0.0, d = 0.0, r = 0.0;
    double rSquared = 0.0, rCubed = 0.0;

    cout << "Enter the diameter of the celestial body (km): ";
    cin >> d;

    while(!cin) {
        cout << "Error - not a number" << endl;
        cin.clear();
        cin.ignore(1000,'\n');
        cout << endl;

        cout << "Enter the diameter of the celestial body (km): ";
        cin >> d;
    }

    r = d/2;

    rSquared = pow(r,2.0);
    rCubed = pow(r,3.0);

    volume = (4.0/3.0)*PI*rCubed;
    area = (4.0*PI)*rSquared;

    cout << "The volume of the celestial body: " << volume << " km" << endl;
    cout << "The surface area is: " << area << " square km" << endl;
    cout << endl;

    return;

}