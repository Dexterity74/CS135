#include <iostream>

using namespace std;

    const double PI = 3.14159;

double circle( double r );

int main() {
    
    double r = 0.0;

    cout << "Enter a radius to calculate circumference: ";
    cin >> r;

    cout << "The circumference of the circle is " << circle( r ) << endl;

    return 0;

}

double circle( double r ) {
    
    double circumference = 0.0;
    
    circumference = 2.0 * PI * r;

    return circumference;
    
}
