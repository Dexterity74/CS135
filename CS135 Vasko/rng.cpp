#include <iostream>
#include <cstdlib>
using namespace std;
int main() {  
    int range = 25;  
    for(int i = 0; i < range; i++) {    
        cout << rand()%1000+1 << endl;  
    }  
    return 0;
}