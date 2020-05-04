#include <iostream>

using namespace std;

int main() {

    int startingNumber, numberCount, count;

    cout << "Enter the starting number: ";
    cin >> startingNumber;

    cout << "Enter how many numbters to print: ";
    cin >> numberCount;

    count = startingNumber + numberCount;

    while (startingNumber < count) {
        cout << startingNumber << " " << endl;
        ++startingNumber;
    }

    return 0;


}
