#include <iostream>
#include <string>

using namespace std;

int main() {

    string input;
    string reverse = "";
    int palindromeCount = 0;
   
    while(cin >> input) {
        for(int i = 0; i < input.length(); i++) {
            reverse += input[ input.length() - i - 1];
        }
        if(input == reverse) {
            palindromeCount++;
        }
        cout << "Reverse of " << input << " is " << reverse << endl;
        reverse = "";
    }
    cout << "There are " << palindromeCount << " palindromes in the input file." << endl;
}
