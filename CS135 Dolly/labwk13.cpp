#include <iostream>
#include <cstdlib>
using namespace std;

const int HEIGHT = 5;
const int WIDTH = 5;

int max(int [][WIDTH]);
int min(int [][WIDTH]);
double sum(int [][WIDTH]);
double average(int [][WIDTH]);

void print(int A[][WIDTH], int width, int heigth) {

}

int main() {
    int A[HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            A[i][j] = rand()%100+69;
            cout << A[i][j] << " ";
        }
    }
    cout << endl;

    cout << "Max = " << max(A) << endl;
    cout << "Min = " << min(A) << endl;
    cout << "Sum = " << sum(A) << endl;
    cout << "Average = " << average(A) << endl;
    cout << "Range = " << max(A) - min(A) << endl;
    return 0;
}

int max(int A[][WIDTH]) {

    int max = A[0][0];

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(A[i][j] > max) {
                max = A[i][j];
            }
        }
    }

    return max;
}

int min(int A[][WIDTH]) {

    int min = A[0][0];

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(A[i][j] < min) {
                min = A[i][j];
            }
        }
    }

    return min;
}

double sum(int A[][WIDTH]) {
    
    double sum = 0.0;

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            sum+=A[i][j];
        }
    }

    return sum;
}

double average(int A[][WIDTH]) {

    double average = 0.0;
    double totalSize = 0.0;

for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            average+=A[i][j];
        }
    }

    totalSize = HEIGHT * WIDTH;


    return average / totalSize;
}