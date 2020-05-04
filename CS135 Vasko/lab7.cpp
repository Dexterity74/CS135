#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream infile;
    //string filename;
    char  s[5];
    int r[5];
    int dummy = 0;
    //int counter = 0;

    //cin >> filename;

    infile.open("input7.txt");

    while(infile.eof() == false){
        infile >> s[dummy];
        infile >> r[dummy];
        dummy++;
    }

    infile.close();
    
    //cout << s[0] << " " << r[0] << endl;
    //cout << s[1] << " " << r[1] << endl;
    
    for(int i = 0; i < dummy-1; i++) {
        cout << "Symbol: " << s[i] << endl;
        cout << "Size: " << r[i] << endl;
        cout << endl;
        for(int j = 0; j < r[i]; j++) {
            for( int k = 0; k <= j; k++) {
                cout << s[i];  //<< endl;      
    

            /* while(counter < r[i]) {
                cout << s[i] << endl;

                counter++;*/            
            }
            cout << endl;
        }   
        cout << endl;
        //counter = 0;
    }      

    return 0;
}
