#include <iostream>
#include <stdlib.h>
using namespace std;

void bubblesort(int A[], int size);

int main() {
    int size = 25;
    int A[size];
    for(int i = 0; i < size; i++) {
        A[i] = rand()%100+74;
    }
    bubblesort(A,size);
    for(int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}

void bubblesort(int A[], int size) {

    int temp;
    bool swapped;

    for(int i = 0; i < size-1; i++){
        swapped = false;
        for(int j = 0; j < size-i-1; j++) {
            if(A[j] > A[j+1]){
                temp = A[j]; 
                A[j] = A[j + 1]; 
                A[j + 1] = temp;

                swapped = true;
            }
        }
    }
}