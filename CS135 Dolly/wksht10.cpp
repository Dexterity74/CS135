#include <iostream>

using namespace std;

int main() {

    int x = 0;

    cout << "for loop" << endl;
    for(int x = 0; x < 5; ) {
        x++;
        cout << "hello ";
    }

    cout << " " << endl;    
    cout << " " << endl;

    cout << "while loop" << endl;
    while(x < 5) {
        x++;
        cout << "hello ";
    }

    cout << " " << endl;
    cout << " " << endl;

    cin.clear();
   
    cout << "do while loop" << endl;
    do {
        cout << "hello ";
        x++;
        
    } while(x < 10);
    
    cout << " " << endl;
    cout << " " << endl;


    return 0;


}
