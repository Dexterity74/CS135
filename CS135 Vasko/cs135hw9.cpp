/* Name: , NSHE ID: 5004991051, CS135-1019, Assignment #9
 *
 * Description: The empire needs help, the rebels are doing too well because let’s face it, 
 *              all the current storm troopers havereally bad aiming skills.  
 *              The empire has started a new recruitment program to hire better candidates then
 *              the current storm troopers, each candidate demonstrated his/her blaster skills,  
 *              and from the list ofcandidates, the top 3 will be chosen.
 *
 * Input: The input is the files requested by the user, which are saved into array files.
 *
 * Output: The output displays if the file the user inputted succeeded or failed, same with target weights
 *         Then it outputs a graph showing which storm trooper hit what and how many they hit and what their
 *         total score was. Followed by outputting the top 3 that were selected.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int BEST = 3;    //global constant to limit array that holds Top 3 Storm Troopers
const int SIZE = 20;   //global constant that limits arrays and loops for 
                       //   the highest possible .txt size
const int TRGTS = 10;  //global constant that limits arrasy and loops for 
                       //   the amount of targets the Storm Troopers shoot at

struct bestStormTroopers{     //struct array that holds the values for the top 3 troopers
    string names = { " " };
    int counter = 0;
    double scores = 0.0;
};

struct scoresMinusOne{        //struct to hold scores[counter-1] for other functions
    double previousScore = 0.0;
};

//function prototpyes
int readData(string[], bool[][TRGTS], double[]);
double computeScore(bool[], double[], int);
void outputStormTroopers(string[], bool[], double[], int);
void outputOneStormTrooper(string, bool[], double);

/* Algorithm:
 * 1. Declare variables
 * 2. call to readData() and make it equal to length
 * 3. Output the title of each row for the score board
 * 4. Create a while loop that will repeat all sequential outputting functions
 * 5. Inside the while loop, call to outputStormTrooper and computeScore
 * 6. Create a series of if-else statements that compare the current value 
 *    to the previous value and saves it to our struct, and if another larger value is found
 *    save that first struct array to the next indice and save that first array to the current score
 * 7. output top 3
 * 8. create a series of for loops and nest a if statement that checks when a single score indice is equal
 *    to the highest score and execute outputOneStormTrooper with those respective parameters
 * 9. Make the same for loop but now check for the second highest, and the third highest.
 * 10. return 0;
*/
int main() {

    //variable declarations
    string names[SIZE] = { " " };
    bool targets[SIZE][TRGTS] = { false };
    double targetWeights[TRGTS];
    double scores[SIZE] = { 0.0 };
    int counter, length;
    ifstream infile;
    scoresMinusOne sub;
    bestStormTroopers BotB[BEST];
    bestStormTroopers v1, v2, v3;

    //length of the entire StormTrooperData.txt file
    length = readData(names, targets, targetWeights);

    //Visually appealing scoreboard
    cout << "NAME       ";
    for(int i = 1; i < TRGTS; i++) {
        cout << "T" << i << "   ";
    }
    cout << "T" << TRGTS << "  ";
    cout << "TOTAL";
    cout << "      SCORE\n";
    cout << "-------------";
    cout << "-------------";
    cout << "-------------";
    cout << "-------------";
    cout << "-------------";
    cout << "------------\n";
    counter = 0;
    //all the magic happens here
    while(counter < length) {
        
        //This function outputs the storm trooper name along with the what targets were hit
        outputStormTroopers(names, targets[counter], targetWeights, counter);

        //This function calculates what targets the trooper hit and calculates the score
        scores[counter] = computeScore(targets[counter], targetWeights, length);
        cout << setprecision(4) << scores[counter] << "\n";
        //calculates the amount of the
        
        //This entire if statement is how we store the top 3 storm troopers
        if(scores[counter - 1] <= scores[counter]) {
            if(v1.scores == 0) {
                v1.names = names[counter];
                v1.scores = scores[counter];
            }
            else if(v1.scores < scores[counter]) {
                v3.names = v2.names;
                v3.scores = v2.scores;

                v2.names = v1.names;
                v2.scores = v1.scores;

                v1.names = names[counter];
                v1.scores = scores[counter];
            }
            else if(v2.scores < scores[counter]) {
                v3.names = v2.names;
                v3.scores = v2.scores;
                
                v2.names = names[counter];
                v2.scores = scores[counter];
            }
            else if(v3.scores < scores[counter]) {
                v3.names = names[counter];
                v3.scores = scores[counter];   
            }
        }

        /*cout << v1.scores << "\n";
        cout << v2.scores << "\n";
        cout << v3.scores << "\n";*/

        counter++;
    }
    cout << "\nTop 3\n\n";

    //This function outputs the top 3 storm troopers one at a time
    for(int i = 0; i < SIZE; i++) {
        if(v1.names == names[i] && v1.scores == scores[i]) {
            outputOneStormTrooper(names[i], targets[i], scores[i]);
        }
    }
    for(int i = 0; i < SIZE; i++) {
        if(v2.names == names[i] && v2.scores == scores[i]) {
            outputOneStormTrooper(names[i], targets[i], scores[i]);
        }
    }
    for(int i = 0; i < SIZE; i++) {
        if(v3.names == names[i] && v3.scores == scores[i]) {
            outputOneStormTrooper(names[i], targets[i], scores[i]);
        }
    }
        
    /*cout << "NAME: " << v1.names << "\n";
    cout << "Targets hit: " << v1.counter << "\n";
    cout << "SCORE: " << v1.scores << "\n" << "\n" << "\n";

    cout << "NAME: " <<  v2.names << "\n";
    cout << "Targets hit: " << v2.counter << "\n";
    cout << "SCORE: " <<  v2.scores << "\n" << "\n" << "\n";   //running some tests

    cout << "NAME: " <<  v3.names << "\n";
    cout << "Targets hit: " << v3.counter << "\n";
    cout << "SCORE: " <<  v3.scores << "\n" << "\n";*/

    return 0;
}

/* readData() is solely used once to initially fill in our arrays with the data
 * from the files. This function outputs messages to the user to request a file to be entered
 * If an invalid file is inputted, the user will be reprompted until it is valid. 
 * Inside the loop that fills in names[] and targets[][], we will count how many times
 * names[] was filled in to get an exact length of the file that we will then return to be used in main();
*/
int readData(string names[], bool targets[][TRGTS], double targetWeights[]) {

    string firstFile;
    string secondFile;
    ifstream infile;
    int counter;
    string t;

    cout << "\nPlease enter storm trooper results file: ";
    cin >> firstFile;

    //does not open file until a valid file was inputted.
    infile.open(firstFile);
    while(!infile.is_open()) {
        cout << "Invalid file!\n" << "\n";
        cout << "Please enter storm trooper results file: ";
        cin >> firstFile;
        infile.open(firstFile);
    }

    //This fills in our targets array and names array and counts for the return value
    while(counter < SIZE) {
        infile >> names[counter];
        //we must close the file and break out of the loop before any code runs if we hit the end of file
        if(infile.eof()) {
            infile.close();
            break;
        }
        for(int j = 0; j < TRGTS; j++) {
            infile >> t;

            for(uint i = 0; i < t.length(); i++) {
                t[i] = tolower(t[i]); 
            }
            //cout << t << "\n";
            if(t == "hit") {
                targets[counter][j] = true;
            }
        }
        counter++;
    }
    //cout << counter;

    cout << "Stormtrooper data read successfully\n\n";

    //cout << names[8] << "\n";
    
    /*for(int i = 0; i < counter; i++) {
        for(int j = 0; j < TRGTS; j++) {
            if(targets[i][j] == true) {
                
            }
            else{                            
                                             //running some tests
            }
        }
    }*/

    /*if(targets[8][5] == false) {
        cout << "test succeed\n";
    }
    else{
        cout << "test no succeed\n";
    }*/

    //This portion fills in the targetWeights array
    cout << "Enter target weights: ";
    cin >> secondFile;

    infile.open(secondFile);
    while(!infile.is_open()) {
        cout << "Invalid file!\n" << "\n";
        cout << "Enter target weights: ";
        cin >> secondFile;
        infile.open(secondFile);
    }
    cout << "\n";
    
    for(int i = 0; i < TRGTS; i++) {
        infile >> targetWeights[i];
    }

    //cout << targetWeights[6];   //running some tests

    cout << "Target weights updated!\n\n";
    infile.close();

    return counter;
}

/* computeScore() is used to count the amount of times the storm trooper
 * hit respectfully in a subarray. We return this value to then be outputted
*/
double computeScore(bool targets[], double targetWeights[], int count) {

    double realScore = 0;
    count = 0;
    realScore = 0;

    // targets[counter] is our subarray from main
    // targets[count] is the second dimension of the array
    // therefore we only need one loop

    while( count < TRGTS ) {
        if(targets[count] == true) {
            realScore+=targetWeights[count];
        }
        count++;
    }

    return realScore;
}

/* outputStormTroopers() uses a loop to also test the amount of times a storm trooper hit to 
 * output on the board which target was hit. While at the same time counting how many times 
 * a single storm trooper hit to be able to output total targets hit
*/ 
void outputStormTroopers(string names[], bool targets[], double targetWeights[], int counter) {

    int dummyCounter;
    double bafoon[TRGTS];
    bafoon[TRGTS] = targetWeights[TRGTS];
    dummyCounter = 0;
    bafoon[TRGTS]++;
    
    cout << names[counter] << "    ";

    

    for(int i = 0; i < TRGTS; i++) {
        
        if(targets[i] == true) {
            cout << "X    ";
            dummyCounter++;
        }
        else{
            cout << "     ";
        }
    }

    cout << "    " << dummyCounter << "      ";

    return;
}

/* outputOneStormTrooper() is called only when we want one and a specific storm trooper
 * to be outputted. We want all the information of this single storm trooper.
 * We want how many targets they hit, which is what the one for loop is for.
 * The parameters inputted in main will do the work with which storm trooper we specifically want
 * and the subarray of targets[] will make sure we are getting the correct amount of hits from that 
 * same trooper.
*/

void outputOneStormTrooper(string names, bool targets[], double scores) {
 
    int dummyCounter = 0;

    for(int i = 0; i < TRGTS; i++) {
        if(targets[i] == true) {
            dummyCounter++;
        }  
    }

    cout << "NAME: " << names << "\n";
    cout << "Targets hit: " << dummyCounter << "\n";
    cout << "SCORE: " << scores << "\n" << "\n" << "\n";

    /*cout << "NAME: " << v1.names << "\n";
    cout << "Targets hit: " << v1.counter << "\n";
    cout << "SCORE: " << v1.scores << "\n" << "\n" << "\n";

    cout << "NAME: " <<  v2.names << "\n";
    cout << "Targets hit: " << v2.counter << "\n";                //running some tests
    cout << "SCORE: " <<  v2.scores << "\n" << "\n" << "\n";

    cout << "NAME: " <<  v3.names << "\n";
    cout << "Targets hit: " << v3.counter << "\n";
    cout << "SCORE: " <<  v3.scores << "\n" << "\n";*/
    
    return;
}