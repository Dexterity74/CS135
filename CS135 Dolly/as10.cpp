/* File: as10.cpp
 *
 * Name: Justin Negron
 *
 * Input: The input of this program utiilizes many functions for various reasons. 
 *        Using these many functions actually simplified the program a little bit 
 *        because I was able to input a segment of code where ever I pleased.
 *        This program uses two dimensional arrays and everything else we have learned thus far.
 * 
 * 
 * 
 * Output: The output of this program displays the classic game Minesweeper. The program should fully 
 *         operate by allowing the user to choose a square and if you hit a mine, you lose. If you don't
 *         it should either open up an area where bombs are not located and reveal boxes with numbers 
 *         depending on how many bombs are touching the cell. If all cells are revealed, you win!
 *         If a mine is hit at any time, you lose!
 * 
*/

#include<iostream>
#include<cstdlib>
#include<iomanip>                             //Needed libraries
#include<ctime>
using namespace std;

void cTable(char boxes[10][13]); 
void pTable(char array[10][13]); 
void cellN(); 
void cellOpen();                              //Defined functions
//void reveal(int, int);  
void reveal(char boxes[10][13], bool minePositions[10][13]);
void minePosition(char minePositions[10][13]); 
bool endGameCheckW();

/*  Algorithm:
 *   1. Define needed variables
 *   2. Call to cTable();
 *   3. Call to minePosition();
 *   4. Test if game loss is true
 *      a) If game loss is true, display current table
 *      b) Output lost message
 *      c) return 0;
 *   5. Test if game won is true
 *      a) If game won is true, display current boxes
 *      b) Output winning message
 *      c) return 0;
 *   6. If neither If statements executed, game has not finished
 *   7. Re-prompt user to enter coordinates and keep looping
*/  

int main() {

    char boxes[10][13];
    bool minePositioning[10][13];
    bool endGameL = false;
    char minePositions[10][13];

    int i = 0, j = 0;
    cTable(boxes);
    minePosition(minePositions);
    reveal(boxes, minePositioning);

    if(endGameL) {

        pTable(boxes);                                              //display current board
        cout << endl << "You hit a mine!  Game over." << endl;      //friendly message

        return 0;                                                   //exit
    }

    if(endGameCheckW()) {

        pTable(boxes);                                              //display current board
        cout << endl << "You won!" << endl;                         //friendly message        

        return 0;                                                   //exit
    }

    while(!endGameL && !endGameCheckW()) {
    
        pTable(boxes);                                              //display current board

        cout << endl << "Dig At x : ";
        cin >> i;
        cout << "Dig at y : ";                          //Prompt for coordinates
        cin >> j;
    }
}

/* function: cTable(char boxes[10][13])
 *
 * function_identifier: This function simply creates the spaces required inside the table
 *
 * parameters: function is defined by void cTable(char boxes[10][13]); 
 *
 * return value: no return value 
*/

/*  Algorithm:
 *   1. Create for loop for height
 *      a) Nest another for loop for width
 *         i) Create spaces for two dimensional array boxes
 *   2. return;
*/  

void cTable(char boxes[10][13]) {

    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 13; j++) {
            boxes[i][j] = '?';        //fills in the whole table with question marks because nothing has been dug up yet
        }
    }
    
    return;
}

/* function: pTable(char array[10][13])
 *
 * function_identifier: 
 *
 * parameters: function is defined by void pTable(char array[10][13]);
 *
 * return value: no return value 
*/

/*  Algorithm:
 *   1. Define a two dimensional array inside function
 *   2. Create a for loop to display the width of the table
 *   3. Create another for loop to display the height of the table
 *   4. Create the visual aspects to allow user to understand table
 *   5. return;
*/  

void pTable(char array[10][13]) {              //displays nice visual features to game

    cout << "  ";
    for(int i = 1; i < 13; i++) {
        cout << fixed << setw (4) << i;      //displays the width numbers on top of board
    }

    cout << endl;

    for(int i = 1; i < 10; i++) {
        cout << "   +---+---+---+---+---+---+---+---+---+---+---+---+" << endl; 
        cout << fixed << i << setw(3)  << "|";                       //separates each height line for separation ease
        for(int j = 1 ; j < 13; j++) {
            cout << fixed << setw(2) << array[i][j] << setw(2) << "|";
        }
        cout << endl;
    }
    cout << "   +---+---+---+---+---+---+---+---+---+---+---+---+" << endl;   //displays one last line for bottom

    return;
}

/* function: cellOpen()
 *
 * function_identifier: This function is set to open the cells and 
 *                      test if a mine was hit to end the game, else it reveals
 *                      the box.
 *
 * parameters: function is defined by void cellOpen();
 *
 * return value: no return value 
*/

/*  Algorithm:
 *   1. Set a do-while loop and input to the i and j variables
 *   2. Test if mine positions are bombs
 *   3. End game if bomb is hit
 *   4. else, reveal the box
 *   5. return;
*/  

void cellOpen() {

    int i, j;
    char boxes[10][13];
    bool minePositioning[10][13];
    char minePositions[10][13];
    //bool endGameL = false;                     //only commented out to avoid -Wall -pedantic errors

    do{
        cin >> i >> j;

    }while(i < 0 || i > 13 || j < 0 || j > 9);

    if(minePositions[i][j] == '*') {
        
        boxes[i][j] = '*';
        //endGameL = true;                       //only commented out to avoid -Wall -pedantic errors
 
        for(int i = 0; i < 13; i++) {
            for(int j = 0; j < 9; j++) {
                if(minePositions[i][j] == '*') {
                    boxes[i][j] = '*';
                }
            }
        }
    }
    else{
        reveal(boxes, minePositioning);
    }
    //else{
        //reveal(i, j);
    //}

    return;
}

/* function: reveal(char boxes[10][13], bool minePositioning[10][13])
 *
 * function_identifier: This reveal checks all 8 elements around the selected element if there was no bombs touching
 *
 * parameters: function is defined by void reveal(char boxes[10][13], bool minePositioning[10][13]);
 *
 * return value: no return value 
*/

/*  Algorithm:
 *   1. Triple nest loop
 *   2. Create for loop to check if check is true, execute our defined variables
 *   3. Create for loop and nested for loop to loop our height and width arrays
 *   4. run if statements to put characters into boxes and and run more tests for the elemenets touching the selected one
 *   5. if there is a whole section away from bombs, all spots are dug up
 *   6. return;
*/  

void reveal(char boxes[10][13], bool minePositioning[10][13]) {

    int minesLocated = 0;
    bool check = true;
    bool noBombs = false;

    for(check = true; check;) {
        minesLocated = 0;
        check = false;
        noBombs = true;

        for(int i = 0; i < 13; i++) {
            for(int j = 0; j < 10; j++) {
                if(boxes[i][j] == 'c') {
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        if(minePositioning[i - 1][j - 1] != false) {
                            minesLocated++;

                            boxes[i - 1][j - 1] = '0' + minesLocated;
                            noBombs = false;
                        }
                        else if(boxes[i - 1][j - 1] == '?') {
                            if(noBombs) {
                                boxes[i - 1][j - 1] = 'c';
                                check = true;
                            }
                            else{
                                //boxes[i + 1, j] = ' ';
                                //boxes[i, j - 1] = ' ';
                                //boxes[i, j + 1] = ' ';
                                //boxes[i + 1, j - 1] = ' ';
                                //boxes[i + 1, j + 1] = ' ';
                                //boxes[i - 1, j + 1] = ' ';
                                //boxes[i - 1, j] = ' ';
                                boxes[i - 1][j - 1] = ' ';
                            }
                        }
                    }
                    if(minesLocated > 0) {
                        boxes[i][j] = '0' + minesLocated;
                    }
                    else{ 
                        //boxes[i + 1, j] = ' ';
                        //boxes[i, j - 1] = ' ';
                        //boxes[i, j + 1] = ' ';
                        //boxes[i + 1, j - 1] = ' ';
                        //boxes[i + 1, j + 1] = ' ';
                        //boxes[i - 1, j + 1] = ' ';
                        //boxes[i - 1, j] = ' ';
                        boxes[i - 1][j - 1] = ' ';
                    }
                }
            }
        }
    }
}
/*void reveal(int i, int j) {

    char boxes[10][13];
    char minePositions[10][13];

    if (boxes[i][j] == '*' && i >= 13 && i < 0 && j >= 9 && j < 0 && minePositions [i][j] != '*') {
        
        boxes[i][j] = minePositions[i][j];

        if(minePositions[i][j] == ' ') {
            
            reveal(i, j - 1);
            reveal(i, j + 1);
            reveal(i - 1, j - 1);
            reveal(i + 1, j - 1);
            reveal(i + 1, j + 1);            //ignore this. I had many many attempts at this reveal function.
            reveal(i - 1, j + 1);
            reveal(i - 1, j);
            reveal(i + 1, j);
        }
    }

    return;
}*/

/* function: cellN(int i,int j)
 *
 * function_identifier: This function allows the minePositions function to randomly set mines
 *
 * parameters: function is defined by void cellN(int i, int j);
 *
 * return value: no return value 
*/

/*  Algorithm:
 *   1. define a char for minePositions
 *   2. run multiple tests inside if statement
 *   3. This will determine whether to ++ to char or no
 *   4. return;
*/  

void cellN(int i,int j) {

    //char minePositions[10][13];                                                       //only commented out to avoid -Wall -pedantic errors

    //if(i >= 0 && i < 10 && j >= 0 && j < 13 && minePositions[i][j] != '*') {          //only commented out to avoid -Wall -pedantic errors
        //minePositions[i][j]++;
    //}

    return;
}

/* function: minePosition(char minePositions[10][13])
 *
 * function_identifier: Uses CellN to randomly set mines across the graph
 *
 * parameters: function is defined by void minePosition(char minePositions[10][13]);
 *
 * return value: no return value 
*/

/*  Algorithm:
 *   1. define counter variable
 *   2. declare srand
 *   3. Create nested for loops for height and width and set minePositions to hold 'c'
 *   4. Reset i and j
 *   5. Create while loop for the height and randomize the mines throughout each line
 *   6. return;
*/  

void minePosition(char minePositions[10][13]) {

    int ctr = 0;
    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 13; j++) {
            minePositions[i][j] = 'c';
        }
    }

    //int i = 0;                            //only commented out to avoid -Wall -pedantic errors
    //int j = 0;

    while(ctr <= 9) {
        
        int i = rand()%10;
        int j = rand()%13;

        if(minePositions[i][j] == 'c') {

            minePositions[i][j] = '*';

            cellN(i - 1, j);
            cellN(i + 1, j);
            cellN(i + 1, j - 1);
            cellN(i + 1, j + 1);
            cellN(i - 1, j - 1);
            cellN(i - 1, j + 1);
            cellN(i, j - 1);
            cellN(i, j + 1);
            ctr++;
        }
    }

    return;
} 

/* function: endGameCheckW()
 *
 * function_identifier: This function should test 
 *
 * parameters: function is defined by bool endGameCheckW() {
 *
 * return value: no return value 
*/

/*  Algorithm:
 *   1. Run if tests to check if bomb was hit
 *   2. Display flag counter
 *   3. Send back true unless bomb was hit
 *   4. return true;
*/  

bool endGameCheckW() {

                            //not commented out to avoid -Wall -pedantic errors

    return false;
}