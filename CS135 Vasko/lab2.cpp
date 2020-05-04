#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double temp, celsius, kelvin, romer, rankine;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> temp;

    celsius = (temp - 32.0) * (5.0/9.0);
    kelvin = celsius + 273.15;
    romer = celsius * (21.0/40.0) + 7.5;
    rankine = (celsius + 273.15) * (9.0/5.0);

    cout << temp << " Fahrenheit = " << celsius << " Celsius" << endl;
    cout << temp << " Fahrenheit = " << kelvin << " Kelvin" << endl;
    cout << temp << " Fahrenheit = " << romer << " Romer" << endl;
    cout << temp << " Fahrenheit = " << rankine << " Rankine" << endl;

    cout << endl;

    return 0;
}



    

  
