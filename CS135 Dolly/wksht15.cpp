#include <iostream>

using namespace std;

void readValues( double&, double&);

double multiply( double, double );

int main() {

    double a, b, c;

    readValues( a, b );

    cout << a << " * " << b << " = " << multiply( a, b ) << endl;

    return 0;

}

void readValues( double& a, double& b) {
    
    cout << "Enter two number ";
    cin >> a >> b;

}

double multiply( double a, double b ) {
    
    double c = 0;
    
    c = a * b;
    
    return c;

}
