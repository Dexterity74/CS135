#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	const double PI = 3.14159;
	double r = 0.0;
	double c = 0.0;

	cout << "Enter the radius: ";
	cin >> r;

	c = 2.0 * PI * r;

	cout << fixed << "Circumference of a cricle with a radius of " << setprecision(2) << r << " is " << c << endl;


	return 0;


}
