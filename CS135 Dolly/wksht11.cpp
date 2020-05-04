#include <iostream>

using namespace std;

int main() {

    double num1 = 0.0, num2 = 0.0;

    while(true) {
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
        if(cin.fail() == true) {
            cin.clear();
            cin.forget(1000,'\n');
            cout << "Error - Enter the numbers again" << endl;
            cin >> num1 >> num2;
        }

        break;
        if(cin.fail() == false) {
            cout << num1 << " + " << num2 << " = " << num1+num2 << endl;
        }
    }


    return 0;


}
