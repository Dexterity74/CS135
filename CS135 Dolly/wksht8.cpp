#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    char Grade;

    cout << "Enter a letter grade: ";
    cin >> Grade;

    switch(Grade) {

        case 'A':
        case 'a':

            cout << "Grade range is 90-100" << endl;
            
            break;

        case 'B':
        case 'b':

            cout << "Grade range is 80-89" << endl;

            break;

        case 'C':
        case 'c':

            cout << "Grade range is 70-79" << endl;

            break;

        case 'D':
        case 'd':

            cout << "Grade range is 60-69" << endl;

            break;

        case 'F':
        case 'f':

            cout << "Grade range is 50-59" << endl;

            break;

        default:

            cout << "Error - invalid entry" << endl;
    }



    return 0;



}
