#include <iostream>
using namespace std;

//Declare prototypes below
int max(int [], int);
int min(int [], int);
double sum(int[], int);
double average(int [], int);

int main() {

    int size = 0;
    cin >> size;

    //fills in array
    int a [size];
    for(int i = 0; i < size; i++) {
        cin >> a[i];
    }
    // print out the max, min, sum, average, and range of the list
    cout << "Max = " << max(a, size) << endl;
    cout << "Min = " << min(a, size) << endl;
    cout << "Sum = " << sum(a, size) << endl;
    cout << "Average = " << average(a, size) << endl;
    cout << "Range = " << max(a, size) - min(a, size) << endl;

    return 0;
}
//Write code below for the following functions
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
