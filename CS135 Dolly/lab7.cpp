#include <iostream>
#include <cstdlib>

using namespace std;
    
int main() {

    int c = 0, temp1 = 0, temp2 = 0, sumTemp = 0;
    cin >> c;
    for(int i=0; i<c; i++) {
        int v1, v2 = 0, v3 = 0;
        cin >> v1;
        temp1 += v1;
        cout << "Reverse of " << v1;
        while(v1 > 0) {
            v3 = v1%10;
            v2 = 10*v2;
            v2+=v3;
            v1/=10;
        }
        temp2+=v2;
        cout << " is " << v2 << endl; 
    }
    sumTemp = temp1 + temp2;
    cout << "The sum of all reverse and non-reverse numbers is " << sumTemp;
    cout << endl;

    return 0;
    
}