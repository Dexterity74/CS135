#include <iostream>
#include <string>

using namespace std;

void writeName( int num, string name);

int main() {

    int num;
    string name;

    cout << "Enter a number and name: ";
    cin >> num >> name;


    writeName( num, name );

}

void writeName( int num, string name) {

    int count = 0;
    
    while( count < num ) {
        cout << name << " ";
        
        count ++;

    }
    
    cout << " " << endl;

}   
