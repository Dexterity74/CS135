#include <iostream>

using namespace std;

int main() {

	double fp1 = 0.0;
	double fp2 = 0.0;
	string s1 = " ";
	string s2 = " ";

	cout << "Enter two numbers (double): ";
	cin >> fp1 >> fp2;

	cout << "You entered " << fp1 << " and " << fp2 << endl;

	if ( fp1 > fp2 ){
		cout << "The largest is " << fp1 << endl;
	}
	else{
		cout << "The largest is " << fp2 << endl;
	}

	cout << "Enter two strings: ";
	cin >> s1 >> s2;

	cout << "You entered \"" << s1 << "\" and \"" << s2 << "\"" << endl;

	if ( s1 > s2 ){
		cout << "The largest is " << s1 << endl;
	}
	else{
		cout << "The largest is " << s2 << endl;
	}



}
