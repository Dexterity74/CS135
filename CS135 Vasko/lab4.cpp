#include <iostream>
using namespace std;

int main() {

    char select;
    double fValue, sValue, answer;

    cout << "First value: ";
    cin >> fValue;

    if(cin.fail()) {
        cout << "Error: invalid input\n";
        cout << endl;
        return 1;
    }

    cout << "Second value: ";
    cin >> sValue;

    if(cin.fail()) {
        cout << "Error: invalid input\n";
        cout << endl;
        return 1;
    }

    cout << "Operation (+, -, *, /); ";
    cin >> select;

    switch(select) {
        case '+': 
            answer = fValue + sValue;
            cout << fValue << " + " << sValue << " = " << answer;

            break;
        case '-':
            answer = fValue - sValue;
            cout << fValue << " - " << sValue << " = " << answer;

            break;
        case '*':
            answer = fValue * sValue;
            cout << fValue << " * " << sValue << " = " << answer;

            break;
        case '/':
            answer = fValue / sValue;
            cout << fValue << " / " << sValue << " = " << answer;

            break;
        default:
            cout << "Invalid entry\n";
            cout << endl;
            return 1;
    }
    cout << endl << endl;
    return 0;
}