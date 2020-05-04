#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream infile;
    string in;
    int num1, num2, sum;
    
    cout << "Enter filename ";
    cin >> in;
    infile.open(in);
    if(infile.is_open() == false) {
        cout << "Error opening file" << endl;
        
        return 1;
    }
    
    while(true) {
        infile>>num1>>num2;

        if(infile.eof() == true) {
            infile.close();
            cout << "End of file reached, Exiting ..." << endl;
            
            return 0;
        }
        else {
            if(!infile) {
                infile.clear();
                infile.ignore(1000, '\n');
                cout << "Error - line contains a letter" << endl;
            }
            else{
                sum = num1 + num2;
                cout << "Sum of " << num1 << " + " << num2 << " = " << sum << endl;
            }        
        }
    } 
}           