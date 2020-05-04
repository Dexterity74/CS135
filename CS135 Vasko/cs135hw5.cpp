/* Name: , NSHE ID: 5004991051, CS135-1019, Assignment #5
 *
 * Description: This program is a chance based game using a die to land on
 *              a number 1 - 6 and the numbers correlate to body parts on
 *              a bug. Though there are game rules to what body part you
 *              require first.
 *
 * Input: I am using 3 structs to make ease in player variables and a 
 *        separate struct for some bool variables also for ease of 
 *        distinguishing player 1 from player 2. I am also using an 
 *        enum to compare what the dice rolls on. I will also be using 
 *        a bool function to create less clutter in the main() function.
 *        Since we test if a player won right after the player rolls, it 
 *        is much easier to place a function rather than a block of code.
 *        At that same time we also test if the bool function returned true,
 *        if it does we then break the loop, output the winner and tables,
 *        and return 0;
 *
 * Output: There are 3 different expected outputs. If the game was to run normally,
 *         the rolled die would always be random. The game would operate as a game
 *         and not rigged, it would operate one roll at a time as well. If we are to 
 *         run the program in "debug" mode, then the game will still operate one roll
 *         at a time, but instead of the rolls actually being random, they will be the
 *         same everytime the game is ran in "debug" mode. Also, there will be a number
 *         next to the enumerated variable to confirm if it is correct or not. Lastly, 
 *         for the "silent" mode, the game will run without displaying the table every 
 *         consecutive turn and it will loop until the end and display the winner along
 *         with the game results.
*/

/*  Algorithm:
 *   1. Have 3 structs for p1 and p2 difference and bool tests for who won
 *   2. Have enum for body parts of can-cell
 *   3. Define the bool function to test if someone won
 *   4. Create main() to operate on argument commands
 *   5. Define needed variables
 *   6. Check if we passed anything into the command line
 *      i. If we did, assign that to the array argv[1]
 *   7. Run if tests if argument command was silent or debug
 *      i. If debug was the argument
 *          a) set srand(0)
 *          b) Allow integer values before body part
 *      ii. If silent was the argument 
 *          a) keep srand(time(NULL))
 *          b) Erase all output of tables
 *          c) do not require user to press enter to loop
 *   8. If nothing was passed into the command line operate normally
 *   9. Player rolls die
 *   10. Series of if statements to validate the roll
 *   11. Output results accordingly
 *   12. Randomize the die roll again for player 2
 *   13. Run the same series of if statements to validate the roll
 *   14. Output the results accoringly
 *   15. Add up body parts and save into variable
 *   16. Once body parts all add up to 15 for a player, that player wins
 *   17. When a player wins, set bool didSomeoneWin = true. Otherwise, set = false
 *   18. Test if didSomeoneWin = true right after each player rolls
 *   19. When didSomeoneWin = true, break the loop
 *   20. Game results are displayed
 *   21. return 0;
*/  

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct player1{
    int body = 0, head = 0, wing = 0, leg = 0, eye = 0, tail = 0, all = 0;
};

struct player2{
    int body = 0, head = 0, wing = 0, leg = 0, eye = 0, tail = 0, all = 0;
};

struct whoWon{
    bool pl1 = false;
    bool pl2 = false;
};

enum CAN_CELL_PARTS {UNUSED, BODY, HEAD, WING, LEG, EYE, TAIL};

bool didSomeoneWin( whoWon, player1, player2);

int main(int args, char * argv[]) {

    string argument = " ";
    char ch;
    int dice = 0;
    int counter = 0;
    whoWon wW;
    player1 p1;
    player2 p2;

    //checks to see if we passed in anything via command line argument
    if (args == 2) {
        argument = argv[1]; //if we did, assign that to the string variable
    }

    //if we wish to run in debug mode, set the random number generator seed to 0
    //so the random numbers will be the same everytime you run your program
    if (argument == "debug") {
        srand(0);
    }
    else {
        srand(time(NULL)); //if not debug mode, then make the random number generator different each time you run the program
    }
    cout << "***************************\n";
    cout << "    Welcome to Can-cell\n";
    cout << "***************************\n";

    if( argument != "silent" ) {
        while (true) { //infinite loop 


            cout << "################\n";
            cout << "Round # " << ++counter << endl;
            //if silent mode not enabled
            //if (argument != "silent") {
                cin.get(ch); //wait for user to hit enter
            //}

            dice = rand() % 6 + 1; //genrates a random number between 1 to 6
            
            //Write the code here to output content and increment bug parts if applicable
            cout << "Hit enter to roll die:\n";
            cout << "Player one roll is ";
            if( dice == BODY ) {
                if( p1.body == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{BODY} << " ";
                    }
                    cout << "BODY" << endl;
                    p1.body++;
                }
                else {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{BODY} << " ";
                    }
                    cout << "duplicate BODY" << endl;
                }
            }
            if( dice == HEAD ) {
                if( p1.body == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{HEAD} << " ";
                    }
                    cout << "HEAD, must have BODY first" << endl;
                }
                else if( p1.head == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{HEAD} << " ";
                    }
                    cout << "HEAD" << endl;
                    p1.head++;
                }
                else{
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{HEAD} << " ";
                    }
                    cout << "duplicate HEAD" << endl;
                }
            }
            if( dice == EYE ) {
                if( p1.body == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{EYE} << " ";
                    }
                    cout << "EYE, must have BODY first" << endl;
                }
                else if( p1.head == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{EYE} << " ";
                    }
                    cout << "EYE, must have HEAD first" << endl;
                }
                else if( p1.eye != 2 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{EYE} << " ";
                    }
                    cout << "EYE" << endl;
                    p1.eye++;
                }
                else{
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{EYE} << " ";
                    }
                    cout << "duplicate EYE" << endl;
                }
            }
            if( dice == WING ) {
                if( p1.body == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{WING} << " ";
                    }
                    cout << "WING, must have BODY first" << endl;
                }
                else if( p1.wing != 4 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{WING} << " ";
                    }
                    cout << "WING" << endl;
                    p1.wing++;
                }
                else{
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{WING} << " ";
                    }
                    cout << "duplicate WING" << endl;
                }
            }
            if( dice == LEG ) {
                if( p1.body == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{LEG} << " ";
                    }
                    cout << "LEG, must have BODY first" << endl;
                }
                else if( p1.leg != 6 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{LEG} << " ";
                    }
                    cout << "LEG" << endl;
                    p1.leg++;
                }
                else{
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{LEG} << " ";
                    }
                    cout << "duplicate LEG" << endl;
                }
            }
            if( dice == TAIL ) {
                if( p1.body == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{TAIL} << " ";
                    }
                    cout << "TAIL, must have BODY first" << endl;
                }
                else if( p1.tail == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{TAIL} << " ";
                    }
                    cout << "TAIL" << endl;
                    p1.tail++;
                }
                else{
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{TAIL} << " ";
                    }
                    cout << "duplicate TAIL" << endl;
                }
            }
            if( didSomeoneWin( wW, p1, p2)) {
                break;
            }
            cout << "Player 1 Inventory\n";
            cout << "Body:       " << p1.body << endl;
            cout << "Head:       " << p1.head << endl;
            cout << "Eye:        " << p1.eye << endl;
            cout << "Wing:       " << p1.wing << endl;
            cout << "Leg:        " << p1.leg << endl;
            cout << "Tail:       " << p1.tail << endl << endl;

            dice = rand() % 6 + 1; //genrates a random number between 1 to 6

            cout << "Player two roll is ";
            if( dice == BODY ) {
                if( p2.body == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{BODY} << " ";
                    }
                    cout << "BODY" << endl;
                    p2.body++;
                }
                else {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{BODY} << " ";
                    }
                    cout << "duplicate BODY" << endl;
                }
            }
            if( dice == HEAD ) {
                if( p2.body == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{HEAD} << " ";
                    }
                    cout << "HEAD, must have BODY first" << endl;
                }
                else if( p2.head == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{HEAD} << " ";
                    }
                    cout << "HEAD" << endl;
                    p2.head++;
                }
                else{
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{HEAD} << " ";
                    }
                    cout << "duplicate HEAD" << endl;
                }
            }
            if( dice == EYE ) {
                if( p2.body == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{EYE} << " ";
                    }
                    cout << "EYE, must have BODY first" << endl;
                }
                else if( p2.head == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{EYE} << " ";
                    }
                    cout << "EYE, must have HEAD first" << endl;
                }
                else if( p2.eye != 2 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{EYE} << " ";
                    }
                    cout << "EYE" << endl;
                    p2.eye++;
                }
                else{
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{EYE} << " ";
                    }
                    cout << "duplicate EYE" << endl;
                }
            }
            if( dice == WING ) {
                if( p2.body == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{WING} << " ";
                    }
                    cout << "WING, must have BODY first" << endl;
                }
                else if( p2.wing != 4 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{WING} << " ";
                    }
                    cout << "WING" << endl;
                    p2.wing++;
                }
                else{
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{WING} << " ";
                    }
                    cout << "duplicate WING" << endl;
                }
            }
            if( dice == LEG ) {
                if( p2.body == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{LEG} << " ";
                    }
                    cout << "LEG, must have BODY first" << endl;
                }
                else if( p2.leg != 6 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{LEG} << " ";
                    }
                    cout << "LEG" << endl;
                    p2.leg++;
                }
                else{
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{LEG} << " ";
                    }
                    cout << "duplicate LEG" << endl;
                }
            }
            if( dice == TAIL ) {
                if( p2.body == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{TAIL} << " ";
                    }
                    cout << "TAIL, must have BODY first" << endl;
                }
                else if( p2.tail == 0 ) {
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{TAIL} << " ";
                    }
                    cout << "TAIL" << endl;
                    p2.tail++;
                }
                else{
                    if( argument == "debug" ) {
                        cout << CAN_CELL_PARTS{TAIL} << " ";
                    }
                    cout << "duplicate TAIL" << endl;
                }
            }
            if( didSomeoneWin( wW, p1, p2)) {
                break;
            }
            cout << "Player 2 Inventory\n";
            cout << "Body:       " << p2.body << endl;
            cout << "Head:       " << p2.head << endl;
            cout << "Eye:        " << p2.eye << endl;
            cout << "Wing:       " << p2.wing << endl;
            cout << "Leg:        " << p2.leg << endl;
            cout << "Tail:       " << p2.tail << endl << endl;
        }
    }

    if( argument == "silent" ) {
        cout << endl << "<<<<<<<<<<<  Silent Mode Active >>>>>>>>>>>\n";
        while (true) { //infinite loop 

            cout << "################\n";
            cout << "Round # " << ++counter << endl << endl;
            //if silent mode not enabled
            //if (argument != "silent") {
                //cin.get(ch); //wait for user to hit enter
            //}
                                                    
            dice = rand() % 6 + 1; //genrates a random number between 1 to 6
            
            //Write the code here to output content and increment bug parts if applicable
            //cout << "Hit enter to roll die:\n";
            cout << "Player one roll is ";
            if( dice == BODY ) {
                if( p1.body == 0 ) {
                    cout << "BODY" << endl;
                    p1.body++;
                }
                else {
                    cout << "duplicate BODY" << endl;
                }
            }
            if( dice == HEAD ) {
                if( p1.body == 0 ) {
                    cout << "HEAD, must have BODY first" << endl;
                }
                else if( p1.head == 0 ) {
                    cout << "HEAD" << endl;
                    p1.head++;
                }
                else{
                    cout << "duplicate HEAD" << endl;
                }
            }
            if( dice == EYE ) {
                if( p1.body == 0 ) {
                    cout << "EYE, must have BODY first" << endl;
                }
                else if( p1.head == 0 ) {
                    cout << "EYE, must have HEAD first" << endl;
                }
                else if( p1.eye != 2 ) {
                    cout << "EYE" << endl;
                    p1.eye++;
                }
                else{
                    cout << "duplicate EYE" << endl;
                }
            }
            if( dice == WING ) {
                if( p1.body == 0 ) {
                    cout << "WING, must have BODY first" << endl;
                }
                else if( p1.wing != 4 ) {
                    cout << "WING" << endl;
                    p1.wing++;
                }
                else{
                    cout << "duplicate WING" << endl;
                }
            }
            if( dice == LEG ) {
                if( p1.body == 0 ) {
                    cout << "LEG, must have BODY first" << endl;
                }
                else if( p1.leg != 6 ) {
                    cout << "LEG" << endl;
                    p1.leg++;
                }
                else{
                    cout << "duplicate LEG" << endl;
                }
            }
            if( dice == TAIL ) {
                if( p1.body == 0 ) {
                    cout << "TAIL, must have BODY first" << endl;
                }
                else if( p1.tail == 0 ) {
                    cout << "TAIL" << endl;
                    p1.tail++;
                }
                else{
                    cout << "duplicate TAIL" << endl;
                }
            }
            if( didSomeoneWin( wW, p1, p2)) {
                break;
            }
            //cout << "Player 1 Inventory\n";
            //cout << "Body:       " << p1.body << endl;
            //cout << "Head:       " << p1.head << endl;
            //cout << "Eye:        " << p1.eye << endl;
            //cout << "Wing:       " << p1.wing << endl;
            //cout << "Leg:        " << p1.leg << endl;
            //cout << "Tail:       " << p1.tail << endl << endl;

            dice = rand() % 6 + 1; //genrates a random number between 1 to 6

            cout << "Player two roll is ";
            if( dice == BODY ) {
                if( p2.body == 0 ) {
                    cout << "BODY" << endl;
                    p2.body++;
                }
                else {
                    cout << "duplicate BODY" << endl;
                }
            }
            if( dice == HEAD ) {
                if( p2.body == 0 ) {
                    cout << "HEAD, must have BODY first" << endl;
                }
                else if( p2.head == 0 ) {
                    cout << "HEAD" << endl;
                    p2.head++;
                }
                else{
                    cout << "duplicate HEAD" << endl;
                }
            }
            if( dice == EYE ) {
                if( p2.body == 0 ) {
                    cout << "EYE, must have BODY first" << endl;
                }
                else if( p2.head == 0 ) {
                    cout << "EYE, must have HEAD first" << endl;
                }
                else if( p2.eye != 2 ) {
                    cout << "EYE" << endl;
                    p2.eye++;
                }
                else{
                    cout << "duplicate EYE" << endl;
                }
            }
            if( dice == WING ) {
                if( p2.body == 0 ) {
                    cout << "WING, must have BODY first" << endl;
                }
                else if( p2.wing != 4 ) {
                    cout << "WING" << endl;
                    p2.wing++;
                }
                else{
                    cout << "duplicate WING" << endl;
                }
            }
            if( dice == LEG ) {
                if( p2.body == 0 ) {
                    cout << "LEG, must have BODY first" << endl;
                }
                else if( p2.leg != 6 ) {
                    cout << "LEG" << endl;
                    p2.leg++;
                }
                else{
                    cout << "duplicate LEG" << endl;
                }
            }
            if( dice == TAIL ) {
                if( p2.body == 0 ) {
                    cout << "TAIL, must have BODY first" << endl;
                }
                else if( p2.tail == 0 ) {
                    cout << "TAIL" << endl;
                    p2.tail++;
                }
                else{
                    cout << "duplicate TAIL" << endl;
                }
            }
            if( didSomeoneWin( wW, p1, p2)) {
                break;
            }
            //cout << "Player 2 Inventory\n";
            //cout << "Body:       " << p2.body << endl;
            //cout << "Head:       " << p2.head << endl;
            //cout << "Eye:        " << p2.eye << endl;
            //cout << "Wing:       " << p2.wing << endl;
            //cout << "Leg:        " << p2.leg << endl;
            //cout << "Tail:       " << p2.tail << endl << endl;
        }
    }

    return 0;    
}

bool didSomeoneWin( whoWon wW, player1 p1, player2 p2) {

    p1.all = p1.body + p1.head + p1.eye + p1.wing + p1.leg + p1.tail; 
    p2.all = p2.body + p2.head + p2.eye + p2.wing + p2.leg + p2.tail; 

    if( p1.all == 15 ) {
        wW.pl1 = true;
    }
    if( p2.all == 15 ) {
        wW.pl2 = true;
    }
    
    /*if(wW.pl1 == true && wW.pl2 == true) { //technically possible tie?
        cout << "*******************\n";
        cout << "Players have tied\n";
        cout << "               Game Results\n";
        cout << "----------------------------------------------\n";                                 // I thought a tie was possible,
        cout << "Player 1 Inventory     Player 2 Inventory\n";                                      // but I realized since we check
        cout << "Body:       " << p1.body << "          Body:       " << p2.body << endl;           // if there is a winner after 
        cout << "Head:       " << p1.head << "          Head:       " << p2.head << endl;           // player 1 rolls the die,
        cout << "Eye:        " << p1.eye << "          Eye:        " << p2.eye << endl;             // that player 1 has an advantage
        cout << "Wing:       " << p1.wing << "          Wing:       " << p2.wing << endl;           // in the sense that they roll first
        cout << "Leg:        " << p1.leg << "          Leg:        " << p2.leg << endl;             // and if they win then player 2
        cout << "Tail:       " << p1.tail << "          Tail:       " << p2.tail << endl << endl;   // does not roll

        return true;
    }*/
    if (wW.pl1 == true && wW.pl2 != true) { //if player 1 won, escape loopbreak;
        cout << "*******************\n";
        cout << "Player one has won\n";
        cout << "               Game Results\n";
        cout << "----------------------------------------------\n";
        cout << "Player 1 Inventory     Player 2 Inventory\n";
        cout << "Body:       " << p1.body << "          Body:       " << p2.body << endl;
        cout << "Head:       " << p1.head << "          Head:       " << p2.head << endl;
        cout << "Eye:        " << p1.eye << "          Eye:        " << p2.eye << endl;
        cout << "Wing:       " << p1.wing << "          Wing:       " << p2.wing << endl;
        cout << "Leg:        " << p1.leg << "          Leg:        " << p2.leg << endl;
        cout << "Tail:       " << p1.tail << "          Tail:       " << p2.tail << endl << endl;

        return true;
    }
    if (wW.pl2 == true && wW.pl1 != true) { //if player 2 won, escape loopbreak;
        cout << "*******************\n";
        cout << "Player two has won\n";
        cout << "               Game Results\n";
        cout << "----------------------------------------------\n";
        cout << "Player 1 Inventory     Player 2 Inventory\n";
        cout << "Body:       " << p1.body << "          Body:       " << p2.body << endl;
        cout << "Head:       " << p1.head << "          Head:       " << p2.head << endl;
        cout << "Eye:        " << p1.eye << "          Eye:        " << p2.eye << endl;
        cout << "Wing:       " << p1.wing << "          Wing:       " << p2.wing << endl;
        cout << "Leg:        " << p1.leg << "          Leg:        " << p2.leg << endl;
        cout << "Tail:       " << p1.tail << "          Tail:       " << p2.tail << endl << endl;

        return true;
    }
    return false;
}