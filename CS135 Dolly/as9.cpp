/* File: as9.cpp
 *
 *  Name: 
 *
 *  Input: The input of this program is going to consist of functions that generate bowling score. 
 *         If we want our values from a file we will call to a bool function to read the players rolls,
 *         or if we want to enter it manually, we will call to a void function to get the players rolls.
 *         There will first be a pop-up menu to allow the user to select what choice they want, if any
 *         errors occur, they will exit the program.
 *
 *  Output: The output of this program is to visually see a bowling game being played out, if the user 
 *          asks for a file that doesn't have a full game in it, the game will be classified as -Game in Progress-.
 *          If the user manually inputs a -1, the game will be paused and they will have the choice to save the game or not.
 *          They will also have the choice to save the game after it has been completed, in which it will create a file and output
 *          the scoring as requested
*/

/* Algorithm: 
 *  1. Create friendly menu in main() inside a while loop
 *  2. Create switch statement to allow user to select which menu item they want
 *  3. In case R/r
        i. Ask user for filename
        ii. Call to bool function to test if file opening was true or false.
        iii. If file successfully opened, Call to generateScoreText
        iv. Call to saveGame to allow user the option to save data or not
 *  4. In case M/m
        i. Call to getPlayerRolls to allow user to input values
        ii. Call to generateScoreText to output the scoring menu
        iii. Call to saveGame to allow user the option to save data or not
 *  5. In case Q/q
        i. This is the quit option so just exit.
 *  6. Default just incase somebody puts something either than those options
 *  7. Create void generateScoreText() function
 *  8. Create void getPlayerRolls() function
 *  9. Create void saveGame() function
 *  10. Create bool readPlayerRolls() function
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Defined functions
void generateScoreText(int points[], int rollCount, string& fileName);
void getPlayerRolls(int points[], int& rollCount); 
void saveGame(int points[], int rollCount, string fileName);
bool readPlayerRolls(int points[], int& rollCount, string fileName);

int main() { //beginning of main

    string fileName;
    char S;
    int rollCount = 0, points[21] = {0};

    while(true) {
        cout << "********************************" << endl;
        cout << "Welcome to Bedrock Bowling Alley" << endl;
        cout << "********************************" << endl;
        cout << "Menu Options" << endl;
        cout << "R/r Read roll data from file" << endl;        //Friendly menu
        cout << "M/m Manually enter data" << endl;
        cout << "Q/q quit" << endl;
        cout << "Selection: ";
        cin >> S;

    
    //while(true) {
        switch (S) {
            case 'R':
            case 'r':
                cout << "Enter filename to read: ";
                cin >> fileName;
                if(!readPlayerRolls(points, rollCount, fileName)) { 
                    cin.clear();
                    cin.ignore(1000,'\n');

                    break;
                }
                else{
                    generateScoreText(points, rollCount, fileName);
                }
                saveGame(points,rollCount, fileName);

                break;
            case 'M':
            case 'm':
                getPlayerRolls(points, rollCount);
                generateScoreText(points, rollCount, fileName);
                saveGame(points,rollCount, fileName);

                break;
            case 'Q':
            case 'q':

                exit(0);
                break;
            default:
                cout << "Invalid Selection" << endl;

                exit(0);
        }
    }
} // end of main

/* Algorithm: 
 *  1. Create a for loop to count until rollCount is reached
 *  2. Run if statements to test if there was a strike, spare, or regular rolls
 *  3. Calculate bonus score for each respective instance
 *  4. If game ends early, state the game is still in progress
 *  5. return;
*/

/* function: void generateScoreText(int points[], int rollCount, string& fileName)
 *
 * function_identifier: this function allows the saved array to output to the display a series of rolls
 *                      
 * parameters: function is defined by generateScoreText(int points[], int rollCount, string& fileName); 
 *
 * return value: no return value
*/
void generateScoreText(int points[], int rollCount, string& fileName) { //beginning of generateScoreText
    
    int nF = 0, nR = 0, score = 0, j = 0;
    ifstream inFile;

    for(int i = 0; i < rollCount; i++) {    //i++ until rollCount is reached
        if(nF < 10) {
            cout << "Frame #" << ++nF << endl;
            cout << "-Roll #" << ++nR << " ";
            if(points[i] == 10) {
                cout << "Strike";
                cout << endl;
                score += points[i] + points[i+1] + points[i+2];
                cout << "-Score " << score;
            }
            else{
                cout << points[i];
                score += points[i];
                j = i;
                if(points[j] + points[++i] == 10) {
                    cout << endl;
                    cout << "-Roll #" << ++nR << " ";
                    cout << "Spare";   
                    cout << endl;
                    score += points[i] + points[i+1];
                    cout << "-Score " << score;
                }
                else{
                    cout << endl;
                    cout << "-Roll #" << ++nR << " ";
                    cout << points[i];
                    cout << endl;
                    score += points[i];
                    cout << "-Score " << score;
                }
                
            }
            nR = 0;
            if(i == rollCount) {
                cout << endl << endl;
                cout << "-Game in Progress-" << endl << endl;

                return;
            }
            cout << endl << endl;
        }
    }
    return;
}// end of generateScoreText

/* Algorithm: 
 *  1. Create a for loop to count until rollCount is reached
 *  2. Run if statements to test if there was a 10, if roll[a] and roll[b] 
 *     added up to 10, or were regular rolls
 *  3. If user enters -1, pause the game, state the game is still in progress
 *  4. return;
*/

/* function: void getPlayerRolls(int points[], int& rollCount)
 *
 * function_identifier: this function allows the user to input their own custom rolls
 *                      into the array
 * 
 * parameters: function is defined by getPlayerRolls(int points[], int& rollCount); 
 *
 * return value: no return value
*/

void getPlayerRolls(int points[], int& rollCount) { // beginning of getPlayerRolls

    int nF = 0, nR = 0, j = 0;
    rollCount = 0;

    for(int i = 0; i <= rollCount; i++) {  //i++ until rollCount is reached
        if(nF < 9) {
            cout << "Frame # " << ++nF << endl;
            cout << "Roll #" << ++nR << " ";
            cin >> points[i];
            rollCount++;
            if(points[i] == -1) {
                cout << endl;

                return;
            }
            if(points[i] != 10) {
                cout << "Roll #" << ++nR << " ";
                j = ++i;
                cin >> points[j];
                rollCount++;      
            }
            nR = 0;
            cout << endl;
        }
        if(points[i] == -1) {
                cout << endl;
                
                return;
        }
        if(nF == 9) {
            cout << "Frame # 10" << endl;
            cout << "Roll #" << ++nR << " ";
            cin >> points[i+1];
            rollCount++;
            if(points[i+1] == 10) {
                cout << endl;
                cout << "Bonus roll #1 ";
                cin >> points[i+2];
                rollCount++;
                cout << "Bonus roll #2 ";
                cin >> points[i+3];
                rollCount++;
                cout << endl << endl;
                
                return;
            }
            if(points[i+1] != 10) {
                cout << "Roll #" << ++nR << " ";
                cin >> points[i+2];
                rollCount++;
            }
            if(points[i+1] + points[i+2] == 10) {
                cout << "Bonus roll #1 ";
                cin >> points[i+3];
                rollCount++;
                cout << endl << endl;

                return;
            }
            else{ 
                cout << endl << endl;

                return;
            }
        }
    }
}// end of getPlayerRolls

/* Algorithm: 
 *  1. Prompt for a y/n character to create a switch statement
 *  2. Create switch statement
 *  3. Create cases 'y' and 'n'
 *  4. In case 'y'
        i. Test if specific fileName was read in, in order to create proper text file
        ii. Open text file
        iii. outFile everything to textfile just as you would generateScoreText
        iiiv. return;
 *  5. In case 'n'
        i. Just space some lines
        ii. return;
 *  6. default, just in case invalid selection
        i. exit(0);
*/

/* function: void saveGame(int points[], int rollCount, string fileName)
 *
 * function_identifier: this function allows the user the option to save the game
 *                      and upload the games into a text file
 * 
 * parameters: function is defined by saveGame(int points[], int rollCount, string fileName); 
 *
 * return value: no return value
*/

void saveGame(int points[], int rollCount, string fileName) { // beginning of saveGame

    ofstream outFile;
    char answer;
    int nF = 0, nR = 0, score = 0, j = 0;

    cout << "Save game to file (y/n)? ";
    cin >> answer;
    while(answer == 'n') {
        break;
    }

    switch(answer) {
        case 'y':
            if(fileName == "completeNormal.bbl") {  //file to open
                outFile.open("completeNormalScored.txt");  //respective file
                for(int i = 0; i < rollCount; i++) { 
                    if(nF < 10) {
                        outFile << "Frame #" << ++nF << endl;
                        outFile << "-Roll #" << ++nR << " ";
                        if(points[i] == 10) {
                            outFile << "Strike";
                            outFile << endl;
                            score += points[i] + points[i+1] + points[i+2];
                            outFile << "-Score " << score;
                            outFile << endl << endl;
                        }
                        else{
                            outFile << points[i];
                            score += points[i];
                            j = i;
                            if(points[j] + points[++i] == 10) {
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << "Spare";   
                                outFile << endl;                                // entire for loop essentially
                                score += points[i] + points[i+1];               // from generateScoreText function
                                outFile << "-Score " << score;                  // for text file creation purposes
                                outFile << endl << endl;
                                points[i] = points[i+1];
                            }
                            else{
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << points[i];
                                outFile << endl;
                                score += points[i];
                                outFile << "-Score " << score;
                                outFile << endl << endl;
                            }
                        }
                        nR = 0;
                        if(i == rollCount) {
                            outFile << "-Game in Progress-";

                            outFile.close();
                            cout << "filename: completeNormalScored.txt" << endl;  //respective file
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                outFile.close();
                cout << "filename: completeNormalScored.txt" << endl;  //respective file
                cout << endl << endl;
                return;
            }
            else if(fileName == "completeSpare.bbl") {  //file to open
                outFile.open("completeSpareScored.txt");  //respective file

                for(int i = 0; i < rollCount; i++) { 
                    if(nF < 10) {
                        outFile << "Frame #" << ++nF << endl;
                        outFile << "-Roll #" << ++nR << " ";
                        if(points[i] == 10) {
                            outFile << "Strike";
                            outFile << endl;
                            score += points[i] + points[i+1] + points[i+2];
                            outFile << "-Score " << score;
                            outFile << endl << endl;
                        }
                        else{
                            outFile << points[i];
                            score += points[i];
                            j = i;
                            if(points[j] + points[++i] == 10) {
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << "Spare";   
                                outFile << endl;                                // entire for loop essentially
                                score += points[i] + points[i+1];               // from generateScoreText function
                                outFile << "-Score " << score;                  // for text file creation purposes
                                outFile << endl << endl;
                            }
                            else{
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << points[i];
                                outFile << endl;
                                score += points[i];
                                outFile << "-Score " << score;
                                outFile << endl << endl;
                            }
                        }
                        nR = 0;
                        if(i == rollCount) {
                            outFile << "-Game in Progress-";

                            outFile.close();
                            cout << "filename: completeSpareScored.txt" << endl;  //respective file
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                outFile.close();
                cout << "filename: completeSpareScored.txt" << endl;  //respective file
                cout << endl << endl;
                return;
            }
            else if(fileName == "completeStrike.bbl") {  //file to open
                outFile.open("completeStrikeScored.txt");  //respective file

                for(int i = 0; i < rollCount; i++) { 
                    if(nF < 10) {
                        outFile << "Frame #" << ++nF << endl;
                        outFile << "-Roll #" << ++nR << " ";
                        if(points[i] == 10) {
                            outFile << "Strike";
                            outFile << endl;
                            score += points[i] + points[i+1] + points[i+2];
                            outFile << "-Score " << score;
                            outFile << endl << endl;
                        }
                        else{
                            outFile << points[i];
                            score += points[i];
                            j = i;
                            if(points[j] + points[++i] == 10) {
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << "Spare";   
                                outFile << endl;                                // entire for loop essentially
                                score += points[i] + points[i+1];               // from generateScoreText function
                                outFile << "-Score " << score;                  // for text file creation purposes
                                outFile << endl << endl;
                            }
                            else{
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << points[i];
                                outFile << endl;
                                score += points[i];
                                outFile << "-Score " << score;
                                outFile << endl << endl;
                            }
                        }
                        nR = 0;
                        if(i == rollCount) {
                            outFile << "-Game in Progress-";

                            outFile.close();
                            cout << "filename: completeStrikeScored.txt" << endl;  //respective file
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                outFile.close();
                cout << "filename: completeStrikeScored.txt" << endl;  //respective file
                cout << endl << endl;
                return;
            }
            else if(fileName == "partialBonus.bbl") {  //file to open
                outFile.open("partialBonusScored.txt");  //respective file

                for(int i = 0; i < rollCount; i++) { 
                    if(nF < 10) {
                        outFile << "Frame #" << ++nF << endl;
                        outFile << "-Roll #" << ++nR << " ";
                        if(points[i] == 10) {
                            outFile << "Strike";
                            outFile << endl;
                            score += points[i] + points[i+1] + points[i+2];
                            outFile << "-Score " << score;
                            outFile << endl << endl;
                        }
                        else{
                            outFile << points[i];
                            score += points[i];
                            j = i;
                            if(points[j] + points[++i] == 10) {
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << "Spare";   
                                outFile << endl;                                // entire for loop essentially
                                score += points[i] + points[i+1];               // from generateScoreText function
                                outFile << "-Score " << score;                  // for text file creation purposes
                                outFile << endl << endl;
                            }
                            else{
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << points[i];
                                outFile << endl;
                                score += points[i];
                                outFile << "-Score " << score;
                                outFile << endl << endl;
                            }
                        }
                        nR = 0;
                        if(i == rollCount) {
                            outFile << "-Game in Progress-";

                            outFile.close();
                            cout << "filename: partialBonusScored.txt" << endl;  //respective file
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                outFile.close();
                cout << "filename: partialBonusScored.txt" << endl;  //respective file
                cout << endl << endl;
                return;
            }
            else if(fileName == "partialBonusNormal.bbl") {  //file to open
                outFile.open("partialBonusNormalScored.txt");  //respective file

                for(int i = 0; i < rollCount; i++) { 
                    if(nF < 10) {
                        outFile << "Frame #" << ++nF << endl;
                        outFile << "-Roll #" << ++nR << " ";
                        if(points[i] == 10) {
                            outFile << "Strike";
                            outFile << endl;
                            score += points[i] + points[i+1] + points[i+2];
                            outFile << "-Score " << score;
                            outFile << endl << endl;
                        }
                        else{
                            outFile << points[i];
                            score += points[i];
                            j = i;
                            if(points[j] + points[++i] == 10) {
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << "Spare";   
                                outFile << endl;                                // entire for loop essentially
                                score += points[i] + points[i+1];               // from generateScoreText function
                                outFile << "-Score " << score;                  // for text file creation purposes
                                outFile << endl << endl;
                            }
                            else{
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << points[i];
                                outFile << endl;
                                score += points[i];
                                outFile << "-Score " << score;
                                outFile << endl << endl;
                            }
                        }
                        nR = 0;
                        if(i == rollCount) {
                            outFile << "-Game in Progress-";

                            outFile.close();
                            cout << "filename: partialBonusNormalScored.txt" << endl;  //respective file
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                outFile.close();
                cout << "filename: partialBonusNormalScored.txt" << endl;  //respective file
                cout << endl << endl;
                return;
            }
            else if(fileName == "partialBonusSpare.bbl") {  //file to open
                outFile.open("partialBonusSpareScored.txt");  //respective file

                for(int i = 0; i < rollCount; i++) { 
                    if(nF < 10) {
                        outFile << "Frame #" << ++nF << endl;
                        outFile << "-Roll #" << ++nR << " ";
                        if(points[i] == 10) {
                            outFile << "Strike";
                            outFile << endl;
                            score += points[i] + points[i+1] + points[i+2];
                            outFile << "-Score " << score;
                            outFile << endl << endl;
                        }
                        else{
                            outFile << points[i];
                            score += points[i];
                            j = i;
                            if(points[j] + points[++i] == 10) {
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << "Spare";   
                                outFile << endl;                                // entire for loop essentially
                                score += points[i] + points[i+1];               // from generateScoreText function
                                outFile << "-Score " << score;                  // for text file creation purposes
                                outFile << endl << endl;
                            }
                            else{
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << points[i];
                                outFile << endl;
                                score += points[i];
                                outFile << "-Score " << score;
                                outFile << endl << endl;
                            }
                        }
                        nR = 0;
                        if(i == rollCount) {
                            outFile << "-Game in Progress-";

                            outFile.close();
                            cout << "filename: partialBonusSpareScored.txt" << endl;  //respective file
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                outFile.close();
                cout << "filename: partialBonusSpareScored.txt" << endl;  //respective file
                cout << endl << endl;
                return;
            }
            else if(fileName == "partialBonusStrike0.bbl") {  //file to open
                outFile.open("partialBonusStrike0Scored.txt");  //respective file

                for(int i = 0; i < rollCount; i++) { 
                    if(nF < 10) {
                        outFile << "Frame #" << ++nF << endl;
                        outFile << "-Roll #" << ++nR << " ";
                        if(points[i] == 10) {
                            outFile << "Strike";
                            outFile << endl;
                            score += points[i] + points[i+1] + points[i+2];
                            outFile << "-Score " << score;
                            outFile << endl << endl;
                        }
                        else{
                            outFile << points[i];
                            score += points[i];
                            j = i;
                            if(points[j] + points[++i] == 10) {
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << "Spare";   
                                outFile << endl;                                // entire for loop essentially
                                score += points[i] + points[i+1];               // from generateScoreText function
                                outFile << "-Score " << score;                  // for text file creation purposes
                                outFile << endl << endl;
                            }
                            else{
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << points[i];
                                outFile << endl;
                                score += points[i];
                                outFile << "-Score " << score;
                                outFile << endl << endl;
                            }
                        }
                        nR = 0;
                        if(i == rollCount) {
                            outFile << "-Game in Progress-";

                            outFile.close();
                            cout << "filename: partialBonusStrike0Scored.txt" << endl;  //respective file
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                outFile.close();
                cout << "filename: partialBonusStrike0Scored.txt" << endl;  //respective file
                cout << endl << endl;
                return;
            }
            else if(fileName == "partialBonusStrike1.bbl") {  //file to open
                outFile.open("partialBonusStrike1Scored.txt");  //respective file

                for(int i = 0; i < rollCount; i++) { 
                    if(nF < 10) {
                        outFile << "Frame #" << ++nF << endl;
                        outFile << "-Roll #" << ++nR << " ";
                        if(points[i] == 10) {
                            outFile << "Strike";
                            outFile << endl;
                            score += points[i] + points[i+1] + points[i+2];
                            outFile << "-Score " << score;
                            outFile << endl << endl;
                        }
                        else{
                            outFile << points[i];
                            score += points[i];
                            j = i;
                            if(points[j] + points[++i] == 10) {
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << "Spare";   
                                outFile << endl;                                // entire for loop essentially
                                score += points[i] + points[i+1];               // from generateScoreText function
                                outFile << "-Score " << score;                  // for text file creation purposes
                                outFile << endl << endl;
                            }
                            else{
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << points[i];
                                outFile << endl;
                                score += points[i];
                                outFile << "-Score " << score;
                                outFile << endl << endl;
                            }
                        }
                        nR = 0;
                        if(i == rollCount) {
                            outFile << "-Game in Progress-";

                            outFile.close();
                            cout << "filename: partialBonusStrike1Scored.txt" << endl;  //respective file
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                outFile.close();
                cout << "filename: partialBonusStrike1Scored.txt" << endl;  //respective file
                cout << endl << endl;
                return;
            }
            else if(fileName == "partialGame.bbl") {  //file to open
                outFile.open("partialGameScored.txt");  //respective file

                for(int i = 0; i < rollCount; i++) { 
                    if(nF < 10) {
                        outFile << "Frame #" << ++nF << endl;
                        outFile << "-Roll #" << ++nR << " ";
                        if(points[i] == 10) {
                            outFile << "Strike";
                            outFile << endl;
                            score += points[i] + points[i+1] + points[i+2];
                            outFile << "-Score " << score;
                            outFile << endl << endl;
                        }
                        else{
                            outFile << points[i];
                            score += points[i];
                            j = i;
                            if(points[j] + points[++i] == 10) {
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << "Spare";   
                                outFile << endl;                                // entire for loop essentially
                                score += points[i] + points[i+1];               // from generateScoreText function
                                outFile << "-Score " << score;                  // for text file creation purposes
                                outFile << endl << endl;
                            }
                            else{
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << points[i];
                                outFile << endl;
                                score += points[i];
                                outFile << "-Score " << score;
                                outFile << endl << endl;
                            }
                        }
                        nR = 0;
                        if(i == rollCount) {
                            outFile << "-Game in Progress-";

                            outFile.close();
                            cout << "filename: partialGameScored.txt" << endl;  //respective file
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                outFile.close();
                cout << "filename: partialGameScored.txt" << endl;  //respective file
                cout << endl << endl;
                return;
            }
            else if(fileName == "perfect.bbl") {  //file to open
                outFile.open("perfectScored.txt");  //respective file

                for(int i = 0; i < rollCount; i++) { 
                    if(nF < 10) {
                        outFile << "Frame #" << ++nF << endl;
                        outFile << "-Roll #" << ++nR << " ";
                        if(points[i] == 10) {
                            outFile << "Strike";
                            outFile << endl;
                            score += points[i] + points[i+1] + points[i+2];
                            outFile << "-Score " << score;
                            outFile << endl << endl;
                        }
                        else{
                            outFile << points[i];
                            score += points[i];
                            j = i;
                            if(points[j] + points[++i] == 10) {
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << "Spare";   
                                outFile << endl;                                // entire for loop essentially
                                score += points[i] + points[i+1];               // from generateScoreText function
                                outFile << "-Score " << score;                  // for text file creation purposes
                                outFile << endl << endl;
                            }
                            else{
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << points[i];
                                outFile << endl;
                                score += points[i];
                                outFile << "-Score " << score;
                                outFile << endl << endl;
                            }
                        }
                        nR = 0;
                        if(i == rollCount) {
                            outFile << "-Game in Progress-";

                            outFile.close();
                            cout << "filename: perfectScored.txt" << endl;  //respective file
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                outFile.close();
                cout << "filename: perfectScored.txt" << endl;  //respective file
                cout << endl << endl;
                return;
            }
            else{
                outFile.open("manualEntriesScored.txt");  //respective file

                for(int i = 0; i < rollCount; i++) { 
                    if(nF < 10) {
                        outFile << "Frame #" << ++nF << endl;
                        outFile << "-Roll #" << ++nR << " ";
                        if(points[i] == 10) {
                            outFile << "Strike";
                            outFile << endl;
                            score += points[i] + points[i+1] + points[i+2];
                            outFile << "-Score " << score;
                            outFile << endl << endl;
                        }
                        else{
                            outFile << points[i];
                            score += points[i];
                            j = i;
                            if(points[j] + points[++i] == 10) {
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << "Spare";   
                                outFile << endl;                                // entire for loop essentially
                                score += points[i] + points[i+1];               // from generateScoreText function
                                outFile << "-Score " << score;                  // for text file creation purposes
                                outFile << endl << endl;
                            }
                            else{
                                outFile << endl;
                                outFile << "-Roll #" << ++nR << " ";
                                outFile << points[i];
                                outFile << endl;
                                score += points[i];
                                outFile << "-Score " << score;
                                outFile << endl << endl;
                            }
                        }
                        nR = 0;
                        if(i == rollCount) {
                            outFile << endl << endl;
                            outFile << "-Game in Progress-" << endl;

                            outFile.close();
                            cout << "filename: manualEntriesScored.txt" << endl;   //respective file
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                outFile.close();
                cout << "filename: manualEntriesScored.txt" << endl;  //respective file
                cout << endl << endl;
                return;
            }

            break;
        case 'n':
            cout << endl << endl;

            return;

            break;
        default:
            cout << "Invalid Selection" << endl;
            
            exit(0);
    }
}// end of saveGame

/* Algorithm: 
 *  1. User requested fileName prompted for in main()
 *  2. Open file
 *  3. Test if file open or not
        i. If file is open, count rollCount and return true
        ii. If file did not open, display error message, return false, and return to menu
 *  4. Display that the file successfully opened and display rollCount
 *  5. return true (assuming successful)
*/

/* function: bool readPlayerRolls(int points[], int& rollCount, string fileName)
 *
 * function_identifier: this function prompts the user what text file to open if they 
 *                      want to enter rolls from a file. If the file opens, it will count the proper
 *                      amount of rolls and display that Roll Count. If the file does not open,
 *                      user will be returned to the main menu and give a file open error message
 * 
 * parameters: function is defined by readPlayerRolls(int points[], int& rollCount, string fileName); 
 *
 * return value: returns either true or false
*/

bool readPlayerRolls(int points[], int& rollCount, string fileName) { // beginning of readPlayerRolls
    ifstream inFile;

    inFile.open(fileName);    
    if(inFile.is_open() != true) {
        cout << "file read error \"" << fileName << "\"" << endl;
        cout << endl << endl;

        return false;
    }
    rollCount = 0; //reset to 0 to avoid rollCounts adding up
    for(int i = 0; i <= rollCount; i++) {
        inFile >> points[i];
        if(inFile.fail() == false) {
            rollCount++;
        }
    }

    cout << "Successfully read file \"" << fileName << "\" Roll Count: " << rollCount << endl << endl;

    return true;  
} // end of readPlayerRolls
