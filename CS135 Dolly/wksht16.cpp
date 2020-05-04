#include <iostream>
#include <string>

using namespace std;

int larger( int i1, int i2 );
string larger( string s1, string s2 );

int main () {
    
    char v;
    int i1, i2;
    string s1, s2;

    cout << "Please select i/I/S/s: ";
    cin >> v;

    switch(v) {
        case 'i':
        case 'I':
            cout << "Please enter two integers: ";
            cin >> i1 >> i2;
            larger( i1, i2 );
            cout << "Largest integer " << larger( i1, i2) << endl;
            break;
        
        case 'S':
        case 's':
            cout << "Please enter two strings: ";
            cin >> s1 >> s2;
            larger( s1, s2 );
            cout << "Largest strings " << larger( s1, s2) << endl;
            break;
    }

}

int larger( int i1, int i2 ) {

    if( i1 > i2 ) {
        return i1;
    }
    else if( i2 > i1 ) {
        return i2;
    }
}

string larger( string s1, string s2 ) {

    if( s1 > s2 ) {
        return s1;
    }
    else if( s2 > s1 ) {
        return s2;
    }
}
