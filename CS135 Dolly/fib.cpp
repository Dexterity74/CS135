#include <iostream>
using namespace std;

//declare function prototypes
int fibonacci( int n );
void print_fib( int n );

int main(int argc, char *argv[]) {

    int x, y;

    x = atoi(argv[1]);
    y = atoi(argv[2]);

    cout << "The " << x << "th number in the fibonacci sequence is: " << fibonacci(x) << endl;
    cout << "Fibonacci sequence up to " << y << " is: " << endl;
    print_fib(y);

    return 0;
}
//returns nth number in the fibonacci sequence
int fibonacci( int n ) {
        
int previous1 = 0, previous2 = 1, current = 1;

    for(int i = 3; i < n; i++) {
        previous1 = previous2;
        previous2 = current;
        current = previous1 + previous2;
    }

    return current;
}

//prints out all fibonacci numbers up to n
void print_fib( int n ) {

    int previous1 = 0, previous2 = 1, current = 1;
    cout << previous1 << " " << previous2 << " ";
    while(previous1 + previous2 < n) {
        
        current = previous1 + previous2;
        cout << current << " ";
        previous1 = previous2;
        previous2 = current;
    }
    cout << endl;
    return;

}


