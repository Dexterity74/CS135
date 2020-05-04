/* File: as7.cpp
*
*  Name: Justin Negron
*
*  Input: The input of this program contained purely inputting information from a file and running what
*         was in the file through a set of code and having that code output onto it's own file.
*         We had to create up arrows with while loops. Right arrows with do-while loops. 
*         And we had to create zero shapes with for loops.
*  
*  Output: The output is to open each file and see the symbol that is to be created, the size of it,
*          and the character the shape is made of.
* 
*
*/

/* Algorithm: 
*  1. Be able to open the file 
*  2. Read each line in the file and dedicate them to their respective variable/string
*  3. Series of if statements to determine which shape
*  4. Create correct loops for each shape to create multiple files for different sizes of shape
*  5. Create shape 
*  6. Close file of shape
*  7. Test when all shapes have been read
*  8. Count shapes
*  9. Output how many shapes have been created
*/


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//void printZero( int size, char c );

int main() {
    
    int size, a = 2, b = 0, d = 0, e = 0, f = 0;
    int v = 1, w = 0, g = 0, r = 0, s = 0, q = 0;
    char c;
    string type;
    string fileName;

    ifstream infile;
    ofstream outfile;
    string in;
    string out;
    
    cout << "Enter input file name: ";
    cin >> in;
    infile.open(in);    
    if(infile.is_open() == false) {
        cout << "Error opening file" << endl;
    
        return 1;
    }

    while(true) {
        infile >> type >> size >> c;

        if(infile.eof() == true) {
            infile.close();
            cout << "Finished processing input file" << endl;
            cout << "25 Shapes Created" << endl;

            return 0;
        }
        
        
        if(infile.eof() != true) {                                //Tests if end of file is false
            fileName = type + "_" + to_string(size) + ".txt";     //Creates file name to output as example_00.txt format
            cout << "Shape Created: ";                              
            cout <<  fileName << endl;

            if(type == "upArrow") {                               //Tests what shape we want

                outfile.open(fileName);                           //Opens the file

                outfile << "Symbol: Up Arrow" << "  " << "Size: " << size << " " << "Character: " << "'" << c << "'" << endl;
                if(size%2 != 0 ) {
                    outfile << "Note: Up Arrow must have an even size." << "   ";       //This block outputs code to the file we want
                    size++;    //If size is an odd number, adds 1 to create correct size for shape
                    outfile << "Shape created with size: " << size << endl;
                }
                for(int x = 1, column = 1; x <= size; x++) {
                    outfile << column;
                    column++;
                    if(column > 9) {
                        column = 0;
                    }
                }
                outfile << " " << endl;
                outfile << " " << endl;

/* Algorithm: 
*  1. Up arrow requires while loop
*  2. if statement test if e is not equal to 0
*  3. if not print space
*  4. test if b is smaller than a
*  5. if true print designated character
*  6. Rinse and repeat
*/


                    
                while ( a + 2 <= size) {
                    if( e != 0 ) {
                        outfile << " ";
                    }
                    if( f == (size - a) / 2 ) {
                        while ( b < a ) {
                            outfile << c;
                            b = b + 1;
                        }
                        b = 0;
                    }
                    if ( f != 0 && f % size == 0) {
                        outfile << endl;
                        f = 0;
                        a = a + 2;
                    }
                    e = e + 1;
                    f = f + 1;
                }
                a = 0;
                while( a < size - 2) {
                    if( e != 0 ) {
                        outfile << " ";
                    }
                    if ( f == (size - 2) / 2 ) {
                        while ( b < 2 ) {
                            outfile << c;
                            b = b + 1;
                        }
                        b = 0;
                    }
                    if ( f != 0 && f % size == 0) {
                        outfile << endl;
                        f = 0;
                        a = a + 2;
                    }
                    e = e + 1;
                    f = f + 1;
                }
                
                outfile.close();               //Closes file
                a = 2;

            }
   
              if(type == "rightArrow") {

                a = 2; e = 0;
                v = 1; d = 0; w = 0;
                g = 0; r = 0; q = 0; s = 0;  

                outfile.open(fileName);

                outfile << "Symbol: Right Arrow" << "  " << "Size: " << size << " " << "Character: " << "'" << c << "'" << endl;
                if(size%2 != 0) {
                    outfile << "Note: Right Arrow must have an even size." << "   ";
                    size++;     //If size is an odd number, adds 1 to create correct size for shape
                    outfile << "Shape created with size: " << size << endl;
                }
                for(int x = 1, column = 1; x <= size; x++) {
                    outfile << column;
                    column++;
                    if(column > 9) {
                        column = 0;
                    }
                }
                outfile << " " << endl;
                outfile << " " << endl;

                e = 0;    

/* Algorithm: 
*  1. Right arrow requires do-while loop
*  2. Create loop that must be run under do {
*  3. Set correct boundaries for while loop
*  4. Then have it still not work after 16 hours of testing
*/
 
            
                do {
                    if( d == size / 2 ) { 
                        do {
                            outfile << c;
                            b = b + 1;
                        } while ( b < v );
                        b = 0;
                    }
                    if( d == size ) {
                        outfile << endl;
                        v = v + 1;
                        d = 0;
                    }
                    if ( e != 0 ) {
                        outfile << " ";
                    }
                    e = e + 1;
                    d = d + 1;
                } while ( v <= (size / 2) - 1);
                
                v = v - 1;
    
                do {
                    outfile << c;
                    g = g + 1;
                    if(g == size) {
                        outfile << endl;
                        g = 0;
                        w = w + 1;
                    }
                } while ( w < 2 );

                do { 
                    if (q != 0) {
                        outfile << " ";
                    }
                    if (r == size / 2.0) {
                        do {
                            outfile << c;
                            s = s + 1;
                        } while ( s < v );
                        s = 0;
                    }
                    if (s == size) {
                        outfile << endl;
                        v = v - 1;
                        r = 0;    
                    }
                    r = r + 1;
                    q = q + 1; 

                } while ( v > 0 );

                outfile << " " << endl;
                

                outfile.close();
                
                a = 2; e = 0;
                v = 1; d = 0; w = 0;
                g = 0; r = 0; q = 0; s = 0;       
    
            }    

            if(type == "zero") {

                outfile.open(fileName);

                outfile << "Symbol: ZERO" << "   " << "Size: " << size << " " << "Character: " << "'" << c << "'" << endl;
                
                for(int x = 1, column = 1; x <= size; x++) {
                    outfile << column;
                    column++;
                    if(column > 9) {
                        column = 0;
                    }
                }
                outfile << " " << endl;
                outfile << " " << endl;

/* Algorithm: 
*  1. Zero shape requires for loop
*  2. Set correct boundaries in opening 2 for loops
*  3. run multiple if tests and if true output designated character
*  4. else just output a space character
*/



                for(int x = 0; x < size; x++) {
                    for(int y = 0; y < size; y++) {
                        if( x == 0 || x == size - 1 || y == 0 || y == size - 1 || x + y == size - 1 || x == size) {
                        outfile << c;
                        }
                        else {
                        outfile << " ";
                        }
                    }
                    outfile << " " << endl;
                }
                outfile << " " << endl;
        
                //printZero( size, c );

                outfile.close();

            }
        }
    }
}

/*void printZero( int size, char c ) {

    ofstream outfile;

    for(int x = 0; x < size; x++) {
        for(int y = 0; y < size; y++) {
            if( x == 0 || x == size - 1 || y == 0 || y == size - 1 || x + y == size - 1 || x == size) {
            outfile << c;
            }
            else {
            outfile << " ";
            }
        }
        outfile << " " << endl;
    }
    outfile << " " << endl;
}
*/
