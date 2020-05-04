#include <iostream>
#include <string>
using namespace std;

const int MAX_STRING = 11;

struct myInitials{
    string headerOne;
    string headerTwo;
};

void outputToDisplay(myInitials& initials);

int main() {

    myInitials initials;

    outputToDisplay(initials); 

	return 0;  

}

void outputToDisplay(myInitials& initials) {
    initials.headerOne = "CS135 Assignment 1";
    initials.headerTwo = "";

    char jN[MAX_STRING][100] = { "   JJJJJJJJJJJJ   NN        NN ",
                         "        JJ        NNN       NN ",
                         "        JJ        NNNN      NN ",
                         "        JJ        NN NN     NN ",
                         "        JJ        NN  NN    NN ",
                         "        JJ        NN   NN   NN ",
                         "        JJ        NN    NN  NN ",
                         "        JJ        NN     NN NN ",
                         "JJ     JJ         NN      NNNN ",
                         " JJ   JJ          NN       NNN ",
                         "   JJJ            NN        NN " };

    if(initials.headerOne == "CS135 Assignment 1" && initials.headerTwo == "Justin Negron") {
        cout << initials.headerOne << endl;
        cout << initials.headerTwo << endl;
    }
    else{
        cout << "error" << endl;
        exit(0);
    }
    cout << endl;
    for(int i = 0; i < MAX_STRING; i++) {
        cout << jN[i] << endl;
    }

    return;

}