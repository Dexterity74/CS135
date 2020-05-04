#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream infile;

    int count = 100;
    double sum = 0;
    double avg = 0;
    double x[100];

    infile.open("wksheet17.txt");
    if(infile.is_open() != true) {
        cout << "Error opening file" << endl;

        return 1;
    }

    for(int i = 0; i < count; i++) {
        infile >> x[i];
        
        if(infile.eof() == true) {
            infile.close();
        }
    }
    
    for(int i = 0; i < count; i++) {
        sum += x[i];
    }

    avg = sum / 100;
    cout << "Average is " << avg << endl;
    
    return 0;

}