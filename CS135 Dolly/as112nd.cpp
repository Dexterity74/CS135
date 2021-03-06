/* File: as11.cpp
 *
 * Name: 
 *
 * Input: The input of this program utiilizes many functions for various reasons. 
 *        Using these many functions actually simplified the program a little bit 
 *        because I was able to input a segment of code where ever I pleased.
 *        This program uses two dimensional arrays and everything else we have learned thus far.
 *        Now we are using structs to display the information.
 * 
 * 
 * Output: The output of this program displays the classic game Minesweeper. The program should fully 
 *         operate by allowing the user to choose a square and if you hit a mine, you lose. If you don't
 *         it should either open up an area where bombs are not located and reveal boxes with numbers 
 *         depending on how many bombs are touching the cell. If all cells are revealed, you win!
 *         If a mine is hit at any time, you lose!
 *         Since we are using structs to display the information, we can create a nice menu that allows
 *         the user to be able to choose whether they want to dig a tile, place a flag, or quit the game.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>                             //Needed libraries
#include <ctime>
using namespace std;

const int BOARD_HEIGHT = 9;
const int BOARD_WIDTH = 12;                    //global constants

struct tile{                                   //struct #1
    char letter;
    bool hasMine;                              
};

struct minesweeper{                            //struct #2
    char tilesBoard[BOARD_HEIGHT][BOARD_WIDTH];                 
    int width, height, mineCount, flagCount = 0, unrevealedCount, moves;
};

//pass by reference the structs

void displayBoard(char board[][BOARD_WIDTH], int width, int height);

void displayMines(bool mines[][BOARD_WIDTH], char board[][BOARD_WIDTH], int width, int height);

bool hasPlayerWon(char board[][BOARD_WIDTH], bool mines[][BOARD_WIDTH], int width, int height);      //These are our defined functions

bool isValidLocation(bool mines[][BOARD_WIDTH], char board[][BOARD_WIDTH], int width, int height);

void revealSquare(bool mines[][BOARD_WIDTH], char board[][BOARD_WIDTH], int width, int height);

//void game();

/*int main() 

    char selection;                 // To simplify, anything you see randomly commented out like this
    switch(selection) {             // I only left in to show my thought process. This will occur fairly frequently
        case 'D':
        case 'd':

    }
}*/



/*  Algorithm:
 *   1. Declare needed variables
 *   2. Execute srand
 *   3. Fill array will '?'
 *   4. call to displayMines
 *   5. create a loop that doesn't end
 *   6. Run if test to see if player has won 
 *   7. test if hasPlayerWon is false
 *      a) if hasPlayerWon is false, display won message and display total moves
 *      b) exit(0)
 *   8. Display friendly interactable menu
 *   9. Create switch statement for different selections
 *      a) If D
 *          i. display dig message and let choose coordinate
 *          ii. test if coordinates are in valid range
 *          iii. call to isValidLocation
 *          iV. call to revealSquares
 *          v. call to hasPlayerWon
 *          vi. add 1 to moves
 *      b) If F
 *          i. display flag message and let player choose flag positioning
 *          ii. test if coordinates are in valid range
 *          iii. run nested for loop to count how many flags have been placed and are currently on the board
 *          iv. make flagCount = to the counter
 *      c) If Q
 *          i. display quitting message
 *          ii. exit(0)
*/  

int main() {

    //tile tile;
    minesweeper mSweeper;
    int width = 0, height = 0, counter = 0;
    //bool test = true;
    char board[BOARD_HEIGHT][BOARD_WIDTH];          //declarations needed for main()
    bool mines[BOARD_HEIGHT][BOARD_WIDTH];
    char selection;
    mSweeper.moves = 1;

    ////calls to the displayBoard function

    /*cout << "Move #" << mSweeper.moves << endl;
    cout << "[D]ig up Tile" << endl;
    cout << "[F]lag/Unflag Tile.  " << mSweeper.flagCount << "flag(s) placed." << endl;
    cout << "[Q]uit" << endl;
    cout << "Choose an action: ";
    cin >> selection;*/

    //while(test == true) {

        srand(time(NULL));            //randomizer generator

        for(int i = 0; i < BOARD_HEIGHT; i++) {
            for(int j = 0; j < BOARD_WIDTH; j++) {
                board[i][j] = '?';            //this nested for loop fills the entire array with ?
            }
        }
    
        /*board[9][9] = '?';
        board[9][10] = '?';
        board[9][11] = '?';
        board[9][12] = '?'; 

        cout <<"* " << board[9][9] << " *" << endl;
        cout <<"* " << board[9][10] << " *" << endl;
        cout <<"* " << board[9][11] << " *" << endl;
        cout <<"* " << board[9][12] << " *" << endl;*/

        displayMines(mines, board, width, height);      //calls to the displayMines function

        //test = false;
    //}

    while(1 < 2) {

        displayBoard(board, width, height);             //calls to the displayBoard function             

        if(!hasPlayerWon(board, mines, width, height)) {

            displayBoard(board, width, height);             //calls to the displayBoard function
            cout << "You won in " << mSweeper.moves << " moves!" << endl;

            exit(0);                                        //exits the program
        }

        cout << "Move #" << mSweeper.moves << endl;             //This is our friendly main menu
        cout << "[D]ig up Tile" << endl;
        cout << "[F]lag/Unflag Tile.  " << mSweeper.flagCount << " flag(s) placed." << endl;
        cout << "[Q]uit" << endl;                  
        cout << "Choose an action: ";
        cin >> selection;

        switch(selection) {         
            case 'D':
            case 'd':
                cout << "Dig at..." << endl;

                cout << "Column: ";
                cin >> height;
                height--;
                cout << "Row: ";                          //Prompt for coordinates
                cin >> width;
                width--;
                cout << endl;

                while( height < 0 || width < 0 || height > BOARD_WIDTH-1 || width > BOARD_HEIGHT-1) {

                    cout << "Invalid Coordinates - Try Again" << endl;
                        
                    cout << endl;
                    cout << "Column: ";
                    cin >> height;
                    height--;
                    cout << "Row: ";                          //Prompt for coordinates
                    cin >> width;
                    width--;
                    cout << endl;
                }

                isValidLocation(mines, board, width, height);      //calls to isValidLocation function

                if(mines[width][height] == false || board[width][height] == '?') {
                    board[width][height] = 'c';
                }

                revealSquare(mines, board, width, height);         //calls to revealSquare function

                hasPlayerWon(board, mines, width, height);         //calls to hasPlayerWon function

                mSweeper.moves++;     //adds 1 every cycle to display to user what move they are on

                break;
            case 'F':
            case 'f':
                cout << "Place flag at:" << endl;

                cout << "Column: ";
                cin >> height;
                --height;
                cout << "Row: ";                          //Prompt for coordinates
                cin >> width;
                --width;
                cout << endl;

                while( height < 0 || width < 0 || height > BOARD_WIDTH-1 || width > BOARD_HEIGHT-1) {

                    cout << "Invalid Coordinates - Try Again" << endl;
                        
                    cout << endl;
                    cout << "Column: ";
                    cin >> height;
                    --height;
                    cout << "Row: ";                          //Prompt for coordinates
                    cin >> width;
                    --width;
                    cout << endl;
                }

                if(board[width][height] == '?') {
                    board[width][height] = 'P';

                    mSweeper.flagCount++;
                }
                else if(board[width][height] == 'P') {
                    board[width][height] = '?';

                    mSweeper.flagCount--;
                }

                /*counter = 0;
                for(int i = 0; i < BOARD_HEIGHT; i++) {
                    for(int j = 0; j < BOARD_WIDTH; j++) {         //this nested for loop counts every time 
                        if(board[i][j] == 'P') {                    //there is a 'P' inside the array and counts
                            counter++;                              //so that if the player places a flag but even
                        }                                           //unflags that position, it will always display
                    }                                               //the correct amount of 'P' on the board
                }
                mSweeper.flagCount = counter;*/
                break;
            case 'Q':
            case 'q':
                cout << "Quiting..." << endl;                       //quitting message

                exit(0);                                            //exits the program
            default:
                cout << "Invalid Option." << endl << endl;
        }

        if( height >= 0 && width >= 0 && height < BOARD_WIDTH && width < BOARD_HEIGHT) {
            if(mines[width][height] == true) {

            //displayBoard(board, width, height);             //calls to the displayBoard function
            //mines[0][0] = false;
            //mines[0][1] = false;
            //mines[1][0] = false;

            //board[0][0] = ' ';
            //board[0][1] = ' ';
            //board[1][0] = ' ';

            for(int i = 0; i <= BOARD_HEIGHT; i++) {
                for(int j = 0; j <= BOARD_WIDTH; j++) {

                    if(mines[i][j] == false) {                      //this empties all character arrays that don't have mines
                        board[i][j] = ' ';
                    }

                    if(mines[i][j] == true) {                       //this fills all character arrays that do have mines
                        board[i][j] = '*';
                    }
                }
            }

            displayBoard(board, width, height);             //calls to the displayBoard function

            cout << endl << "You hit a mine!  Game over." << endl;
            cout << endl;

            exit(0);          //exit the program
            }
        }
    }

    /*while(1 < 2) {

        mSweeper.moves++;

        //int counter = 0;

        while(test == true) {

            srand(time(NULL));

            for(int i = 0; i <= BOARD_HEIGHT; i++) {
                for(int j = 0; j <= BOARD_WIDTH; j++) {
                    board[i][j] = '?';
                }
            }

            displayMines(mines, board, width, height);      //display the displayMines function 

            test = false;
        }

        for(int i = 0; i <= BOARD_HEIGHT; i++) {
            for(int j = 0; j <= BOARD_WIDTH; j++) {
                if(mines[i][j] == true) {
                    cout << i << " " << j << endl;
                    counter++;
                    cout << counter << " test" << endl;
                    cout << endl;
                }
            }
        }

        if(!hasPlayerWon(board, mines, width, height)) {

            displayBoard(board, width, height);             //calls to the displayBoard function
            cout << "You won!" << endl;

            exit(0);
        }

        if(hasPlayerWon(board, mines, width, height) == true) {

            displayBoard(board, width, height);             //calls to the displayBoard function

            //do{
                cout << endl;
                cout << "Dig at x: ";
                cin >> height;
                --height;
                cout << "Dig at y: ";                          //Prompt for coordinates
                cin >> width;
                --width;
                cout << endl;
            //}while( width <= 0 || height <= 0 || width >= BOARD_WIDTH || height >= BOARD_HEIGHT);

            while( height < 0 || width < 0 || height > BOARD_WIDTH || width > BOARD_HEIGHT) {

                cout << "Invalid Coordinates - Try Again" << endl;
                    
                cout << endl;
                cout << "Dig at x: ";
                cin >> height;
                --height;
                cout << "Dig at y: ";                          //Prompt for coordinates
                cin >> width;
                --width;
                cout << endl;

            }

            isValidLocation(mines, board, width, height);

            revealSquare(mines, board, width, height);

            hasPlayerWon(board, mines, width, height);
        }*/
    
}

/* function: displayBoard()
 *
 * function_identifier: This function is used to display the board anywhere in the program
 *
 * parameters: This punctions parameters are void displayBoard(char board[][BOARD_WIDTH], int width, int height);
 *
 * return value: no return value 
*/

/*  Algorithm:
 *   1. Create the display of the width of the board using a for loop
 *   2. Create the format of the board along with displaying the height using a for loop
 *   3. return;
*/  

void displayBoard(char board[][BOARD_WIDTH], int width, int height) {

    bool test = true;
    cout << endl;
    cout << "  ";
    for(int i = 0; i < BOARD_WIDTH; i++) {
        cout << fixed << setw (4) << i + 1;      //displays the width numbers on top of board
    }

    cout << endl;

    /*while(test == true) {

        for(int i = 0; i < BOARD_HEIGHT; i++) {
            for(int j = 0; j < BOARD_WIDTH; j++) {
                board[i][j] = '?';
            }
        }
        test = false;
    }*/

    for(int i = 0; i < BOARD_HEIGHT; i++) {
        cout << "   +---+---+---+---+---+---+---+---+---+---+---+---+" << endl; 
        cout << fixed << i + 1 << setw(3)  << "|";                       //separates each height line for separation ease
        for(int j = 0; j < BOARD_WIDTH; j++) {
            cout << fixed << setw(2) << board[i][j] << setw(2) << "|";
        }
        cout << endl;
    }
    /*cout <<"* " << board[9][9] << " *" << endl;
    cout <<"* " << board[9][10] << " *" << endl;
    cout <<"* " << board[9][11] << " *" << endl;
    cout <<"* " << board[9][12] << " *" << endl;*/
    cout << "   +---+---+---+---+---+---+---+---+---+---+---+---+" << endl;   //displays one last line for bottom

    return;
}

/* function: displayMines()
 *
 * function_identifier: This function is used to choose mine positions ONCE
 *
 * parameters: This punctions parameters are void displayMines(bool mines[][BOARD_HEIGHT], char board[][BOARD_HEIGHT], int width, int height);
 *
 * return value: no return value 
*/

/*  Algorithm:
 *   1. Declare needs variables
 *   2. Create a for loop to set the entire mines array to false
 *   3. Run a while loop that only executes once to ensure no more than 10 mines are selected
 *   4. Run for loop inside while loop that chooses a valid random coordinates for x and y  
 *   5. Choose that position of our mines array and set it to true to indicate there is a mine
 *   6. return;
*/  

void displayMines(bool mines[][BOARD_WIDTH], char board[][BOARD_WIDTH], int width, int height) {

    //tile tile;
    minesweeper mSweeper;
    int counter = 0;
    bool test = true;
    int x = 0, y = 0;
    //mines[BOARD_WIDTH][BOARD_HEIGHT];

    for(int i = 0; i < BOARD_HEIGHT; i++) {
        for(int j = 0; j < BOARD_WIDTH; j++) {          //loops to fill bool array to false
            mines[i][j] = false;    
        }
    }

    while(test == true) {             //this test is just so I know it is only executed once
        while(counter < 10) {

            x = 0;
            y = 0;
            
            //x = (rand()%12);                //this randomly selects 10 random x and y values to randomize mine positions
            //y = (rand()%9);

            //test if mines is already true or not
            do{
                x = (rand()%12);
                y = (rand()%9);
            }while(mines[y][x] == true);

            mines[y][x] = true;
            /*if(mines[y][x] == true) {
                cout << y << " " << x << endl;
                //counter++;
                cout << counter << " test" << endl;
            }*/
            counter++;
        }

        test = false;
    }
    /*mines[2][3] = true;
    mines[3][4] = true;
    mines[4][5] = true;
    mines[5][6] = true;*/
 
    return;
}

/* function: hasPlayerWon()
 *
 * function_identifier: This function is used to count how many '?' are on the board to check if the player has won or not
 *
 * parameters: This punctions parameters are bool hasPlayerWon(char board[][BOARD_HEIGHT], bool mines[][BOARD_HEIGHT], int width, int height);
 *
 * return value: no return value 
*/

/*  Algorithm:
 *   1. Declare needed variables
 *   2. Run test to check if counter = 10 
 *      a) If counter does = 10 that means all tiles have been uncovered except for mine locations
 *      b) return false;
 *   3. If counter does not = 10, run a nested for loop to count the amount of question marks
 *   4. return true;
*/  

bool hasPlayerWon(char board[][BOARD_WIDTH], bool mines[][BOARD_WIDTH], int width, int height) {

    //tile tile;
    minesweeper mSweeper;
    int counter = 0;
    //counter = 10;
    if(counter == 10) {         // if counter = 10, then all tiles have been uncovered besides mines.
        return false;           // When this function is called to and tested for false, won message will display
    }

    if(counter != 10) {
        for(int i = 0; i < BOARD_HEIGHT; i++) {
            for(int j = 0; j < BOARD_WIDTH; j++) {         //this nested for loop just counts the amount of ? left on the board
                if(board[i][j] == '?') {
                    counter++;
                }
                //cout << counter << endl;
            }
        }
    }

    return true;
}

/* function: isValidLocation()
 *
 * function_identifier: This function is used to test if the coordinates that the player has chosen are valid or not
 *                      I also used this function to execute the board clear and output of the mines positions if a mine was hit
 *                      because I found it best fit here                     
 * 
 * parameters: This punctions parameters are bool isValidLocation(bool mines[][BOARD_HEIGHT], char board[][BOARD_HEIGHT], int width, int height)
 *
 * return value: return value of true if player had a valid location, otherwise game exited because of loss
*/

/*  Algorithm:
 *   1. test the bool array if the coordinate that the user selected is true
 *      a) if it is true, that means the player has stepped on a mine
 *      b) run a nested for loop and test for all locations where the bool array tests false
 *          i. for the bool array indices that test false, set the char array to ' '.
 *          ii. for the bool array indices that test true, set the char array to '*'.
 *          iii. call to displayBoard
 *          iv. display lost message
 *          v. exit the program
 *   2. Run if tests to ensure the player has chosen a coordinate inside the valid range
 *   3. if it does test true, make the character array at this position = 'c'
 *   4. return true;
*/  

bool isValidLocation(bool mines[][BOARD_WIDTH], char board[][BOARD_WIDTH], int width, int height) {

    //tile tile;
    minesweeper mSweeper;
    //int counter = 0;
    
    if( height >= 0 && width >= 0 && height < BOARD_WIDTH && width < BOARD_HEIGHT) {  //test for valid location

        //board[width][height] = 'c';        //sets the users selection to char array 'c'

        return true;
    }

    return false;
}

/* function: revealSquare()
 *
 * function_identifier: This function is used to reveal a whole section of the board and count when a element is touching a mine                   
 * 
 * parameters: This punctions parameters are void revealSquare(bool mines[][BOARD_HEIGHT], char board[][BOARD_HEIGHT], int width, int height)
 *
 * return value: no return value
*/

/*  Algorithm:
 *   1. Declare need variables
 *   2. Run a for loop as long as checkAgain is true, which is set to run at least once.
 *   3. Run a series of for loops that test how many mines the element that the user selected is touching
 *   4. If the element that the user has selected is not touching any mines, then set that space empty
 *      a) Run tests on ALL 8 elements around this element to see if they are also touching any mines
 *      b) repeat this until a wave occurs and it shows spaces that aren't mines, but are touching mines.
 *   5. set the original value back to ' ' because it did not have a mine, nor was touching one
 *   6. return;
*/  

void revealSquare(bool mines[][BOARD_WIDTH], char board[][BOARD_WIDTH], int width, int height) {

    //tile tile;
    //minesweeper mSweeper;
    int minesLocated = 0;
    bool checkAgain = true;
    bool noBombs = false;
    //mines[BOARD_WIDTH][BOARD_HEIGHT];
    //board[BOARD_WIDTH][BOARD_HEIGHT];

    //while(board[width][height] == 'c') {
    for(checkAgain = true; checkAgain;) {
        minesLocated = 0;                   
        checkAgain = false;  
        noBombs = true;

        for(int i = 0; i < BOARD_HEIGHT; i++) {
            for(int j = 0; j < BOARD_WIDTH; j++) {
                
                if(board[width][height] == 'c') {
                    if(isValidLocation(mines, board, width + 1, height) == true) {
                        if(mines[width + 1][height] == true && board[width + 1][height] == '?') {
                            minesLocated++;
                            //mSweeper.mineCount++;
                            board[width][height] = '0' + minesLocated;
                        }
                    }    

                    if(isValidLocation(mines, board, width + 1, height + 1) == true) {
                        if(mines[width + 1][height + 1] == true && board[width + 1][height + 1] == '?') {
                            minesLocated++;
                            noBombs = false;
                            board[width][height] = '0' + minesLocated;
                        }
                    }    

                    if(isValidLocation(mines, board, width, height + 1) == true) {
                        if(mines[width][height + 1] == true && board[width][height + 1] == '?') {
                            minesLocated++;
                            noBombs = false;
                            board[width][height] = '0' + minesLocated;
                        }
                    }    

                    if(isValidLocation(mines, board, width, height - 1) == true) {
                        if(mines[width][height - 1] == true && board[width][height - 1] == '?') {
                            minesLocated++;
                            noBombs = false;
                            board[width][height] = '0' + minesLocated;
                        }
                    }   

                    if(isValidLocation(mines, board, width - 1, height - 1) == true) {
                        if(mines[width - 1][height - 1] == true && board[width - 1][height - 1] == '?') {
                            minesLocated++;
                            noBombs = false;
                            board[width][height] = '0' + minesLocated;
                        }
                    }    

                    if(isValidLocation(mines, board, width - 1, height) == true) {
                        if(mines[width - 1][height] == true && board[width - 1][height] == '?') {
                            minesLocated++;
                            noBombs = false;
                            board[width][height] = '0' + minesLocated;
                        }
                    }    

                    if(isValidLocation(mines, board, width - 1, height + 1) == true) {
                        if(mines[width - 1][height + 1] == true && board[width - 1][height + 1] == '?') {
                            minesLocated++;
                            noBombs = false;
                            board[width][height] = '0' + minesLocated;
                        }
                    }    

                    if(isValidLocation(mines, board, width + 1, height - 1) == true) {
                        if(mines[width + 1][height - 1] == true && board[width + 1][height - 1] == '?') {
                            minesLocated++;
                            noBombs = false;
                            board[width][height] = '0' + minesLocated;
                        }
                    }    
                    if(noBombs == true) {
                    board[width][height] = ' ';

                    noBombs = true;
                }
                
                if(noBombs == false) {
                    board[width][height] = '0' + minesLocated;

                    noBombs = false;
                }
                }

                

                if(noBombs == true) {
                    if(isValidLocation(mines, board, width + 1, height) == true) {
                        if(board[width + 1][height] == '?' && mines[width + 1][height] == false) {
                            checkAgain = true; 
                            board[width + 1][height] = 'c';
                            //width+=1;
                        }
                    }    
                    
                    if(isValidLocation(mines, board, width + 1, height + 1) == true) {
                        if(board[width + 1][height + 1] == '?' && mines[width + 1][height + 1] == false) {
                            checkAgain = true;
                            board[width + 1][height + 1] = 'c';
                            width+=1;
                            //height+=1;
                        }
                    }    
                    
                    if(isValidLocation(mines, board, width, height + 1) == true) {
                        if(board[width][height + 1] == '?' && mines[width][height + 1] == false) {
                            checkAgain = true;
                            board[width][height + 1] = 'c';
                            //height+=1;
                        }
                    }    

                    if(isValidLocation(mines, board, width, height - 1) == true) {
                        if(board[width][height - 1] == '?' && mines[width][height - 1] == false) {
                            checkAgain = true;
                            board[width][height - 1] = 'c';
                            //height-=11;
                        }
                    }   

                    if(isValidLocation(mines, board, width - 1, height - 1) == true) {
                        if(board[width - 1][height - 1] == '?' && mines[width - 1][height - 1] == false) {
                            checkAgain = true;
                            board[width - 1][height - 1] = 'c';
                            //width-=1;
                            //height-=1;
                        }
                    }    

                    if(isValidLocation(mines, board, width - 1, height) == true) {
                        if(board[width - 1][height] == '?' && mines[width - 1][height] == false) {
                            checkAgain = true;
                            board[width - 1][height] = 'c';
                            //width-=1;
                        }
                    }    

                    if(isValidLocation(mines, board, width - 1, height + 1) == true) {
                        if(board[width - 1][height + 1] == '?' && mines[width - 1][height + 1] == false) {
                            checkAgain = true;
                            board[width - 1][height + 1] = 'c';
                            //width-=1;
                            //height+=1;
                        }
                    }    

                    if(isValidLocation(mines, board, width + 1, height - 1) == true) {
                        if(board[width + 1][height - 1] == '?' && mines[width + 1][height - 1] == false) {
                            checkAgain = true;
                            board[width + 1][height - 1] = 'c';
                            //width+=1;
                            //height-=1;
                        }
                    }    
                }//displayBoard(board, width, height);
            }//displayBoard(board, width, height);
        }//displayBoard(board, width, height);
    }//displayBoard(board, width, height);
    return;      
}
