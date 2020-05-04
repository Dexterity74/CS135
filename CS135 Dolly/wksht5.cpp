#include <iostream>
#include <cmath>

using namespace std;

int main()
{

	int a = 0;
	double x = 0.0;
	const double PI = 3.14159;
	double radians = 0.0;
	double y = 0.0;


	y = (PI / 180);


	cout << "Enter an angle value, in degrees: ";
	cin >> a;
	

	radians = a * y;
	x = sin(radians);
	y = cos(radians);


	cout << "sin(" << a << ") = " << x << endl;

	cout << "cos(" << a << ") = " << y << endl;



	return 0;
	


}
