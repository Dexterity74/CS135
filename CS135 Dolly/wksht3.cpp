#include <iostream>

using namespace std;

int main()
{

	const int A = 5;
	const int B = 2;
	const double X = 5.0;
	const double Y = 2.0;

	double W = 0.0;
	int Z = 0;
	int V = 0;

	Z = A/B;
	W = X/Y;
	V = A%B;

	cout << "Int 5/2 is " << Z <<endl;

	cout << "Int 5 % 2 is " << V <<endl;

	cout << "Double 5.0/2.0 is " << W <<endl;

	

	return 0;



}
