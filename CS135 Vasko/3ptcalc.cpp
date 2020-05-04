#include <iostream>
using namespace std;

int main() {
    
    int att3s, made3s;
    double pct;

    cout << "Enter 3s attempted: ";
    cin >> att3s;
    cout << "Enter 3s made: ";
    cin >> made3s;

    pct = (made3s * 1.0) / att3s;

    cout << "3pt %: " << pct << endl;

    return 0;
}
