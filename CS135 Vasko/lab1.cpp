#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double a, b, c, x1, x2, parem;
    
    cout << "Enter value for a: ";
    cin >> a;   

    cout << "Enter value for b: ";
    cin >> b;

    cout << "Enter value for c: ";
    cin >> c;

    cout << "The quadratic eqution is: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;

    parem = pow(b,2.0) - (4.0*a*c);

    x1 = (-b + sqrt(parem))/(2.0*a);

    x2 = (-b - sqrt(parem))/(2.0*a);

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;



    return 0;    

}
