// Student header documentation goes here

/* Name: , NSHE ID: 5004991051, CS135-1019, Assignment #8
 *
 * Description: This assignment is a generator to expose the resistance new method
 *              of passing messages to one another. This assignment is a decoder and
 *              will generate the shape of a character.
 *
 * Input: Input comes from AS8Data.txt
 *
 * Output: There's output that is displayed to the screen that lets the user
 *         know if a file has been process with the respective fileName.
 *         The rest of the output is sent to separate files containing information
 *         on the symbol the shape is and the size of the shape and the
 *         character used to create the shape. 
 *         It also has width and height counters also lined up with the shape.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


// prototypes
void openInputFile( ifstream&, string);
bool openOutputFile( ofstream & oFile, string fname);
void outputChar( ofstream&, int count, char l);
void makeEight( ofstream& oFile, int size, char c );
void makeTriangle( ofstream&, int size, char c );
void makeSlash( ofstream& oFile, int size, char c);
string createOutputFilename(  string typeString, int labelSize );
bool readRecord ( ifstream& iFile, string& typeString, int& lSize, char& c );

// Do not change main 
int main(){
    ifstream iFile;
    ofstream oFile;
    string ofName;
    string typeString;
    int  labelSize = 0;
    char labelChar = 0;
    int recordCount = 0;
    bool done = false;

    cout << "Welcome to Rebel Alliance Computational Support" << endl;
    cout << "\t            x" << endl;
    cout << "\t      x    xxx    x" << endl;
    cout << "\t     x    x x x    x" << endl;
    cout << "\t    x      xxx      x" << endl;
    cout << "\t   xx       x       xx" << endl;
    cout << "\t  xxx      xxx      xxx" << endl;
    cout << "\t  xxxx     xxx     xxxx" << endl;
    cout << "\t  xxxxx    xxx   xxxxx" << endl;
    cout << "\t   xxxxxxxxxxxxxxxxxxx" << endl;
    cout << "\t    xxxxxxxxxxxxxxxxx" << endl;
    cout << "\t     xxxxxxxxxxxxxxx" << endl;
    cout << "\t       xxxxxxxxxxx" << endl;

    cout << endl << endl;
    
    // Open input file
    openInputFile( iFile, "Input Specification File: " );
    
    // read all records from the specification file. 
    while(true){
        
        // read a record from the file
         done = readRecord ( iFile, typeString,  labelSize, labelChar );

         // verify that it worked, if not exit.
         if ( !done ){   
            cout << "Finished processing input file" << endl;
            cout << recordCount<< " Shapes Created " <<endl;
            iFile.close();
            oFile.close();
            exit(0);            
        }

        recordCount++;    
  
        // create the output filename
        ofName = createOutputFilename( typeString, labelSize );

        // open output file
        if( !openOutputFile( oFile, ofName )) {
            // output a message if the file did not open
            cout << "Output file \"" << ofName << "\" did not open" << endl;
            cout << "File \"" << ofName << "\" not generated" << endl;
        }else{
               // output a message that the file successfully opened
               cout << "File \"" << ofName << "\" successfully opened" << endl;

               // call appropriate function 
               if( typeString == "figureEight")
                    makeEight( oFile, labelSize, labelChar );
                else if(typeString == "triangle")
                    makeTriangle( oFile, labelSize, labelChar);
                else if( typeString == "slash")
                    makeSlash( oFile, labelSize, labelChar );

        } 
        // close the shape file so that we can re-use oFile variable
        oFile.close();
      }  
}

// function documentation here

/* Function Documentation: The function readRecord() is used soley to read the records
 *                         of the input file and set them to variables that are then
 *                         passed by reference.
 *                         We also check to test if the end of file was reached
 *                         Once the end of file is reached, we return the bool function 
 *                         as false to then close the file in main.
*/
bool readRecord ( ifstream& iFile, string& typeString, int& lSize, char& c ){

    iFile >> typeString >> lSize >> c;
    if(iFile.eof()) {
        return false;
    }
    
    // This return is included because value returing functions must
    // return a value. It must be replaced by the appropriate return
    // value  in the students code. 
    return true;
                  
}

// function documentation here

/* Function Documentation: The function createOutputFilename() is used to add
 *                         strings together create a file name to then return 
 *                         the string for use in main()
*/
string createOutputFilename( string typeString, int labelSize ){

    typeString+= "_" + to_string(labelSize) + ".txt";

    // This return is included because value returing functions must
    // return a value. It must be replaced by the appropriate return
    // value  in the students code. 
    return typeString;

}

// function documentation here

/* Function Documentation: The function openInputFile() is used purely to just
 *                         open the open the file the user inputs. We prompt the
 *                         user, and they input the requested file.
 *                         If the file does not open, an error message is outputted
 *                         and the user is prompted until they input a valid file.
*/
void openInputFile( ifstream& iFile, string prompt ){

    string fileName;

    cout << prompt;
    cin >> fileName;
    iFile.open(fileName);
    while(iFile.is_open() == false) {
        cout << "Error opening file" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << prompt;
        cin >> fileName;
        iFile.open(fileName);
    }

}

// function documentation here

/* Function Documentation: The function openOutputFile() is used only to open the
 *                         file which is inserted from main().
*/
bool openOutputFile( ofstream& oFile, string fname) {
    
    oFile.open(fname);

    // This return is included because value returing functions must
    // return a value. It must be replaced by the appropriate return
    // value  in the students code. 
    return true;
}      


// function documentation here

/* Function Documentation: The function makeEight() is used to output a figure 8 with
 *                         different width and height parameters depending on the size
 *                         Everything inside of this function is outputted to the open file
 *                         so we use oFile to output everything.
 *                         We start by outputting the symbol, size, and character, then we
 *                         create a counter that works well with the specific figure and 
 *                         counts the approriate size left to right. 
 *                         The counting will happen through a for loop, we copy/paste that for
 *                         loop and apply it to the bottom of the code with correct spacing.
 *                         Then specifically for makeEight() we create a series of if statements
 *                         that execute depending on the size because ONLY with makeEight, the size
 *                         divided by 10 is the column width and the column width divided by 2 (integer wise)
 *                         and the result of that is the row height.
 *                         After we evaluate that, we create a for loop with nested if else's and 
 *                         for loops and a while loop only if the size is odd and the row height is odd
 *                         and we iterate the same code with respective width and heights throughout
 *                         the other if statements. 
 *                         Then output the counter again at the end of the code for the bottom of the
 *                         shape and return;                       
*/
void makeEight( ofstream& oFile, int size, char c ){
    oFile << "Symbol: Eight  Size: " << size << " Character: '" << c << "'" << endl;
    oFile << "    ";
    
    int counter = 1, anotherCounter = 0;

    for( int x = 0; x < size; x++ ) {
        oFile << counter;
        counter++;
        if( counter == 10 ) {
            counter = 0;
        }
    }
    oFile << "\n\n";
    
    counter = 1;
    //for( int x = 0; x < size; x++ ) {
        if( size < 10 ) {
            oFile << "Error - Invalid Size" << endl;
            //break;
        }
        if( (size / 10) < 3 ) {
            // Row is 1 tall
            // Column is 2 wide

            for( int y = 0; y < 5; y++ ) {
                if( y == 0 || y == 2 || y == 4 ) {
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "    ";
                    for( int z = 0; z < size - 4; z++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( y == 1 || y == 3 ) {
                    if( size%2 == 0 ) {
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        if( y == 1 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-2)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 2 || z > size-3 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                        if( y == 3 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-1)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 2 || z > size-3 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                    }
                    else{
                        oFile << "\n";
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        while( anotherCounter < ((size/2)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') << setw(2);
                            oFile << counter;
                            oFile << "  ";
                            counter++;
                            for( int z = 0; z < size; z++ ) {
                                if( z < 2 || z > size-3 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                            }
                            oFile << "\n";
                            
                            anotherCounter++;
                        }
                        anotherCounter = 0;
                    }
                }
                //if(y==0) {
                   // oFile << "\n";
                //}
            }
            //break;
        }
        if( (size / 10) == 3 ) {
            // Row is 1 tall
            // Column is 3 wide

            for( int y = 0; y < 5; y++ ) {
                if( y == 0 || y == 2 || y == 4 ) {
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "     ";
                    for( int z = 0; z < size - 6; z++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( y == 1 || y == 3 ) {
                    if( size%2 == 0 ) {
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        if( y == 1 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-2)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 3 || z > size-4 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                        if( y == 3 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-1)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 3 || z > size-4 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                    }
                    else{
                        oFile << "\n";
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        while( anotherCounter < ((size/2)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') << setw(2);
                            oFile << counter;
                            oFile << "  ";
                            counter++;
                            for( int z = 0; z < size; z++ ) {
                                if( z < 3 || z > size-4 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                            }
                            oFile << "\n";
                            
                            anotherCounter++;
                        }
                        anotherCounter = 0;
                    }
                }
                //if(y==0) {
                   // oFile << "\n";
                //}
            }
        }
        if( (size / 10) == 4 ) {
            // Row is 2 tall
            // Column is 4 wide

            for( int y = 0; y < 5; y++ ) {
                if( y == 0 || y == 2 || y == 4 ) {
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "     ";
                    for( int z = 0; z < size - 6; z++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( y == 1 || y == 3 ) {
                    if( size%2 == 0 ) {
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        if( y == 1 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-2)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 3 || z > size-4 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                        if( y == 3 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-1)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 3 || z > size-4 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                    }
                    else{
                        oFile << "\n";
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        while( anotherCounter < ((size/2)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') << setw(2);
                            oFile << counter;
                            oFile << "  ";
                            counter++;
                            for( int z = 0; z < size; z++ ) {
                                if( z < 3 || z > size-4 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                            }
                            oFile << "\n";
                            
                            anotherCounter++;
                        }
                        anotherCounter = 0;
                    }
                }
                //if(y==0) {
                   // oFile << "\n";
                //}
            }
        }
        if( (size / 10) == 5 ) {
            // Row is 2 tall
            // Column is 5 wide

            for( int y = 0; y < 5; y++ ) {
                if( y == 0 || y == 2 || y == 4 ) {
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "       ";
                    for( int z = 0; z < size - 10; z++ ) {
                        outputChar( oFile, size, c );
                    }
                    oFile << "\n";
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "       ";
                    for( int z = 0; z < size - 10; z++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( y == 1 || y == 3 ) {
                    if( size%2 == 0 ) {
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        if( y == 1 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-3)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 5 || z > size-6 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                        if( y == 3 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-3)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 5 || z > size-6 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                    }
                    else{
                        oFile << "\n";
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        while( anotherCounter < ((size/2)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') << setw(2);
                            oFile << counter;
                            oFile << "  ";
                            counter++;
                            for( int z = 0; z < size; z++ ) {
                                if( z < 5 || z > size-6 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                            }
                            oFile << "\n";
                            
                            anotherCounter++;
                        }
                        anotherCounter = 0;
                    }
                }
                //if(y==0) {
                   // oFile << "\n";
                //}
            }
        }
        if( (size / 10) == 6 ) {
            // Row is 3 tall
            // Column is 6 wide

            for( int y = 0; y < 5; y++ ) {
                if( y == 0 || y == 2 || y == 4 ) {
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "       ";
                    for( int z = 0; z < size - 10; z++ ) {
                        outputChar( oFile, size, c );
                    }
                    oFile << "\n";
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "       ";
                    for( int z = 0; z < size - 10; z++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( y == 1 || y == 3 ) {
                    if( size%2 == 0 ) {
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        if( y == 1 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-3)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 5 || z > size-6 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                        if( y == 3 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-3)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 5 || z > size-6 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                    }
                    else{
                        oFile << "\n";
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        while( anotherCounter < ((size/2)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') << setw(2);
                            oFile << counter;
                            oFile << "  ";
                            counter++;
                            for( int z = 0; z < size; z++ ) {
                                if( z < 5 || z > size-6 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                            }
                            oFile << "\n";
                            
                            anotherCounter++;
                        }
                        anotherCounter = 0;
                    }
                }
                //if(y==0) {
                   // oFile << "\n";
                //}
            }
        }
        if( (size / 10) == 7 ) {
            // Row is 3 tall
            // Column is 7 wide

            for( int y = 0; y < 5; y++ ) {
                if( y == 0 || y == 2 || y == 4 ) {
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "         ";
                    for( int z = 0; z < size - 14; z++ ) {
                        outputChar( oFile, size, c );
                    }
                    oFile << "\n";
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "         ";
                    for( int z = 0; z < size - 14; z++ ) {
                        outputChar( oFile, size, c );
                    }
                    oFile << "\n";
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "         ";
                    for( int z = 0; z < size - 14; z++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( y == 1 || y == 3 ) {
                    if( size%2 == 0 ) {
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        if( y == 1 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-5)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 7 || z > size-8 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                        if( y == 3 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-4)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 7 || z > size-8 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                    }
                    else{
                        oFile << "\n";
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        while( anotherCounter < ((size/2)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') << setw(2);
                            oFile << counter;
                            oFile << "  ";
                            counter++;
                            for( int z = 0; z < size; z++ ) {
                                if( z < 7 || z > size-8 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                            }
                            oFile << "\n";
                            
                            anotherCounter++;
                        }
                        anotherCounter = 0;
                    }
                }
                //if(y==0) {
                   // oFile << "\n";
                //}
            }
        }
        if( (size / 10) == 8 ) {
            // Row is 4 tall
            // Column is 8 wide

            for( int y = 0; y < 5; y++ ) {
                if( y == 0 || y == 2 || y == 4 ) {
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "           ";
                    for( int z = 0; z < size - 14; z++ ) {
                        outputChar( oFile, size, c );
                    }
                    oFile << "\n";
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "           ";
                    for( int z = 0; z < size - 14; z++ ) {
                        outputChar( oFile, size, c );
                    }
                    oFile << "\n";
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "           ";
                    for( int z = 0; z < size - 14; z++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( y == 1 || y == 3 ) {
                    if( size%2 == 0 ) {
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        if( y == 1 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-5)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 7 || z > size-8 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                        if( y == 3 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-4)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 7 || z > size-8 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                    }
                    else{
                        oFile << "\n";
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        while( anotherCounter < ((size/2)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') << setw(2);
                            oFile << counter;
                            oFile << "  ";
                            counter++;
                            for( int z = 0; z < size; z++ ) {
                                if( z < 7 || z > size-8 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                            }
                            oFile << "\n";
                            
                            anotherCounter++;
                        }
                        anotherCounter = 0;
                    }
                }
                //if(y==0) {
                   // oFile << "\n";
                //}
            }
        }
        if( (size / 10) == 9 ) {
            // Row is 4 tall
            // Column is 9 wide

            for( int y = 0; y < 5; y++ ) {
                if( y == 0 || y == 2 || y == 4 ) {
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "           ";
                    for( int z = 0; z < size - 18; z++ ) {
                        outputChar( oFile, size, c );
                    }
                    oFile << "\n";
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "           ";
                    for( int z = 0; z < size - 18; z++ ) {
                        outputChar( oFile, size, c );
                    }
                    oFile << "\n";
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "           ";
                    for( int z = 0; z < size - 18; z++ ) {
                        outputChar( oFile, size, c );
                    }
                    oFile << "\n";
                    oFile << right;           
                    oFile << setfill(' ') << setw(2) << counter;
                    counter++;
                    oFile << "           ";
                    for( int z = 0; z < size - 18; z++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( y == 1 || y == 3 ) {
                    if( size%2 == 0 ) {
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        if( y == 1 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-6)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 9 || z > size-10 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                        if( y == 3 ) {
                            oFile << "\n";
                            while( anotherCounter < ((size/2)-6)) {
                                oFile << right;           
                                oFile << setfill(' ') << setw(2);
                                oFile << counter;
                                oFile << "  ";
                                counter++;
                                for( int z = 0; z < size; z++ ) {
                                    if( z < 9 || z > size-10 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                }
                                oFile << "\n";
                                
                                anotherCounter++;
                            }   
                            anotherCounter = 0;
                        }
                    }
                    else{
                        oFile << "\n";
                        /*oFile << right;           
                        oFile << setfill(' ') << setw(2);
                        oFile << counter;
                        oFile << "  ";
                        counter++;*/
                        while( anotherCounter < ((size/2)-7)) {
                            oFile << right;           
                            oFile << setfill(' ') << setw(2);
                            oFile << counter;
                            oFile << "  ";
                            counter++;
                            for( int z = 0; z < size; z++ ) {
                                if( z < 7 || z > size-8 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                            }
                            oFile << "\n";
                            
                            anotherCounter++;
                        }
                        anotherCounter = 0;
                    }
                }
                //if(y==0) {
                   // oFile << "\n";
                //}
            }
        }
    //}
    oFile << "\n\n";
    oFile << "    ";
    counter = 1;
    for( int x = 0; x < size; x++ ) {
        oFile << counter;
        counter++;
        if( counter == 10 ) {
            counter = 0;
        }
    }
    return;
}

// function documentation here

/* Function Documentation: The function outputChar() is made to output one character
 *                         one at a time. It is used in for loops so when called it 
 *                         will repeat and call one char at a time.
*/
void outputChar(ofstream& of, int count, char l){

    int a = count;

    of << l;
    l = a;
    return;
}

// function documentation here

/* Function Documentation: The function makeTriangle() is used to output an even triangle
 *                         Everything inside of this function is outputted to the open file
 *                         so we use oFile to output everything.
 *                         We start by outputting the symbol, size, and character, then we
 *                         create a counter that works well with the specific figure and 
 *                         counts the approriate size left to right. 
 *                         The counting will happen through a for loop, we copy/paste that for
 *                         loop and apply it to the bottom of the code with correct spacing.
 *                         Then specifically for makeTriangle() create a for loop and nest another
 *                         for loop and then inside the nested for loop we create a while loop that
 *                         only outputs a character if count equals x times 2 - 2 else it will output 
 *                         a space or if the counter is equal to 0.
 *                         Always increment count when ending the line and put the count for loop at
 *                         the bottom to be on the bottom of the shape when outputted to the file.
 *                         return;                       
*/
void makeTriangle( ofstream& oFile, int size, char c ){
    oFile << "Symbol: Triangle  Size: " << size << " Character: '" << c << "'\n" << "    ";
    
    int p = 1, xTwo;

    for(int x = 0; x <= 2 * size - 1; x++) {

        oFile << p;
        p++;
        if(p == 10) {
            p = 0;
        }
        
    }
    oFile << endl;
    oFile << endl;

    int count = 0, counter = 1;
    
    for(int x = 1; x <= size-1; x++) {
        oFile << right;           
        oFile << setfill(' ') << setw(2) << counter;  
        for(int y = x; y < size; y++) {
            oFile << " ";
        }
        xTwo = x*2;
        while(count != (xTwo - 1)) {
            
            if(count == xTwo - 2) {
                oFile << " ";
                outputChar( oFile, size, c );
                outputChar( oFile, size, c );
            }
            else{
                oFile << " ";
            }
            if(count == 0) {
                
                outputChar( oFile, size, c );
                outputChar( oFile, size, c );
            }
            /*else{
                oFile << " ";
            }*/
            count++;
        }
        count = 0;
        oFile << endl;
        counter++;
    }
    oFile << setfill(' ') << setw(2) << right << counter << "  ";
    for(int x = 0; x <= 2 * size - 1; x++) {
        
        outputChar( oFile, size, c );

    }
    oFile << endl << endl;
    oFile << "    ";
    p = 1;
    for(int x = 0; x <= 2 * size - 1; x++) {

        oFile << p;
        p++;
        if(p == 10) {
            p = 0;
        }
    }
    return;
}

// function documentation here

/* Function Documentation: The function makeSlash() is used to output a slash across the output 
 *                         depending on the size.
 *                         Everything inside of this function is outputted to the open file
 *                         so we use oFile to output everything.
 *                         We start by outputting the symbol, size, and character, then we
 *                         create a counter that works well with the specific figure and 
 *                         counts the approriate size left to right. 
 *                         The counting will happen through a for loop, we copy/paste that for
 *                         loop and apply it to the bottom of the code with correct spacing.
 *                         Then specifically for makeSlash() we create a for loop with a nested for
 *                         loop then nest an if statement that also has an if-else nested inside of it.
 *                         The outside if statement will only execute if y is less than size plus one minus x.
 *                         The nested if statement will only execute if y equals size minus one minus x, if
 *                         that returns true it will output one char. If that returns false, the else statement
 *                         will execute printing a space to the output.
 *                         Then we close out by printing out the count again so that there is a count
 *                         on the bottom of the shape in the text file and return;                         
*/
void makeSlash( ofstream& oFile, int size, char c){
    oFile << "Symbol: Slash  Size: " << size << " Character: '" << c << "'" << endl;

    int p = 1, sPoneMex = 0, sMoneMex = 0;

    oFile << "    ";
    for( int x = 0; x < size; x++ ) {       
        for( int y = 0; y < size; y++ ) {     
            sPoneMex = size + 1 - x;
            sMoneMex = size - 1 - x; 
            if( y < sPoneMex ) {      
                if( y == sMoneMex ) {        
                    oFile << p;      
                    p++;         
                    if( p == 10 ) {             
                        p = 0;           
                    }          
                }        
            }             
        }            
    }   
    int count = 1;
    oFile << "\n\n";
    for( int x = 0; x < size; x++ ) {           
        oFile << right;           
        oFile << setfill(' ') << setw(2) << count;  
        for( int y = 0; y < size; y++ ) {    
            //oFile << "  ";
            sPoneMex = size + 1 - x;
            sMoneMex = size - 1 - x;              
            if( y < sPoneMex ){  
                //oFile << "  ";                        
                if( y == sMoneMex ) {                   
                    oFile << "  ";                         
                    outputChar(oFile, size, c);    
                    //oFile << "  ";            
                }                                          
                else{                                         
                    oFile << " ";                                 
                }                                              
            }                                                  
        }                                                    
        count++;                                               
        oFile << "\n";                                               
    }                                                                 
    oFile << "\n";    
      
    p = 1;       
    oFile<< "    ";     
    for( int x = 0; x < size; x++ ) {       
        for( int y = 0; y < size; y++ ) {     
            sPoneMex = size + 1 - x;
            sMoneMex = size - 1 - x; 
            if( y < sPoneMex ) {      
                if( y == sMoneMex ) {        
                    oFile << p;      
                    p++;         
                    if( p == 10 ) {             
                        p = 0;           
                    }          
                }        
            }             
        }            
    }        
    return;             
}