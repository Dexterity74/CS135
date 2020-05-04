#include <iostream> 
using namespace std;

double power(int x, int y);

int main() {

    int x, y;
    double answer = 0.0;

    cout << "Base: ";
    cin >> x;
    // I commented these tests out because they weren't fully working and I read the TA Discord and
    // they said to just assume the user will input integers
    /*while(true) {
        if(!cin) {
            cout << endl;
            cout << "Input was either not a integer or not a number, try again!\n";
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Base: ";
            cin >> x;
        }
        if(cin) {
            break;
        }
    }*/
    
    cout << "Exponenet: ";
    cin >> y;
    /*while(true) {
        if(!cin) {
            cout << endl;
            cout << "Error - Input was either not a integer or not a number, try again!\n";
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Exponent: ";
            cin >> x;
        }
        if(cin) {
            break;
        }
    }*/
    

    cout << endl;

    answer = power(x, y);
    cout << x << "^" << y << " is " << answer << endl;

    cout << endl;

    return 0;
}

double power(int x, int y) {

    double answer, dummy;

    if( x == 0 ) {
        answer = 0.0;
    }
    else {
        if( y > 0 ) {
            dummy = x;
            for( int i = 1; i < y; i++ ) {
                x = x * dummy;
            }
            answer = x;
        }
        if( y == 0 ) {
            answer = 1;
        }
        if( y < 0 ) {
            y = y*(-1);
            //cout << y << endl;
            dummy = x;
            for( int i = 1; i < y; i++ ) {
                x = x * dummy;
            }
            //cout << x << endl;
            answer = 1.0/(x);
        }
    }

    return answer;
}