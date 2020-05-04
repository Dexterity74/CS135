#include <iostream>

using namespace std;

const int MAX = 25;

void readChars( int max, char data[], int& count);
void printReverse( char data[], int count);

int main() {

    int count = 0;
    char data[MAX];
    readChars( MAX, data, count);
    printReverse( data, count);

    return 0;    
}

void readChars( int max, char data[], int& count) {

    int t = 0;
    char Char = 'x';
    count = 0;

    cout << "How many chars: ";
    cin >> t;

    if(t > max) {
        cout << "Error - max chars 25" << endl;

        exit(0);
    }

    while(count < t) {
        cin >> Char;
        data[count] = Char;
        count++;
    }

    return;

}

void printReverse(char data[], int count) {

    for( int x=count; x>=0; x--) {
        cout << data[x] << " ";
    }
    cout << endl;

    return;

}

