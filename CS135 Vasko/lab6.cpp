#include <iostream>
#include <fstream>
using namespace std;

//Declare prototypes below
int max(int [], int);
int min(int [], int);
double sum(int [], int);
double average(int [], int);

int main() {

    int size = 0;
    ifstream infile;
    string line;

    infile.open("input6.txt");    
    if(infile.is_open() == false) {
        cout << "Error opening file" << endl;
    
        return 1;
    }
    while(getline(infile, line)) {
        size++;
    }
    infile.close();
    //cout << size;

    //int a[size]; //syntax error
    int *a = new int[size];
    //int a [size];
    for(int i = 0; i < size; i++) {
       cin >> a[i];
    }
    
    // print out the max, min, sum, average, and range of the list
    cout << "max: " << max(a, size) << endl;
    cout << "min: " << min(a, size) << endl;
    cout << "sum: " << sum(a, size) << endl;
    cout << "average: " << average(a, size) << endl;
    cout << "range: " << max(a, size) - min(a, size) << endl << endl;

    return 0;
}

int max(int a[], int size) {

    int max = a[0];

    for(int i = 0; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

int min(int a[], int size) {

    int min = a[0];

    for(int i = 0; i < size; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }

    return min;
}

double sum(int a[], int size) {
    
    double sum = 0.0;

    for(int i = 0; i < size; i++) {
        sum+=a[i];
    }

    return sum;
}

double average(int a[], int size) {

    double average = 0.0;

    for(int i = 0; i < size; i++) {
        average+=a[i];
    }

    return average / size;
}
