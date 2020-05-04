#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void rowSumCalculator( int myArray[][10],  int rowCount, int colCount );
void openFile( ifstream& infile, string prompt );

int main() {

    ifstream infile;
    string prompt;
    int myArray[7][10], rowCount = 7, colCount = 10;

    openFile( infile, prompt );

    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            infile >> myArray[i][j];  
        } 
    }

    rowSumCalculator( myArray, rowCount, colCount );

    return 0;
}

void rowSumCalculator( int myArray[][10],  int row, int col) {

    int sum;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << right << setw(4) << myArray[i][j] << " ";
            sum += myArray[i][j];
        }
        cout << "  =  " << right << setw(4) << sum << endl;
        
        sum = 0;
    }
    return;
}

void openFile( ifstream& infile, string prompt ) {

    cout << "Enter file to process: ";
    cin >> prompt;

    infile.open(prompt);
    while(infile.is_open() != true) {
        cout << "Error - \"" << prompt << "\" did not open" << endl;

        cout << "Enter file to process: ";
        cin >> prompt;
    }
    return;
}