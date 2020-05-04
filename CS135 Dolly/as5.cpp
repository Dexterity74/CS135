/* File: as5.cpp
*
*  Name: Justin Negron
*
*  Input: The input of this program utiilized while loops and if-else statement to create a program that drew cards
*         from a shuffled deck. 
*  
*  Output: The output of this program displays a welcome sign and when executing the game itself, not the test bench menu,
*          it will play out the game without flaws or bugs of false winners.
*
*/

/* Algorithm: 
*  1. Created program shell with argv and argc in main
*  2. Added if statement that determined if argc is greater than 1
*  3. Set correct configuration for cardDeckType
*  4. Dealt Players cards
*  5. Used printDeck to check debug menus
*  6. Checked players caards to see if any matched current table card to replace with 0
*  7. Updated players totals
*  8. Looped 5 rounds 
*  9. Determined winner based of Dessert 333 Game rules
*
*/


#include <iostream>                        // cout() cin() 
#include <iomanip>                         // setw()
#include "cardDeckType.h"                  // custom library for card deck input

using namespace std;

int main(int argc, char* argv[]) {         //beginning of main. Inside the paranthesis was used to operate debug mode

    int tCard1 = 0, tCard2 = 0, tCard3 = 0, tCard4 = 0, tCard5 = 0, p1Card1 = 0, p1Card2 = 0, p1Card3 = 0;
    int p2Card1 = 0, p2Card2 = 0, p2Card3 = 0, p1Total = 0, p2Total = 0, cCard = 0, lCard = 0, userSelection;       // declared variables
    int rNumber = 1;

    cout << "------------------------------------------" << endl;
    cout << "Welcome to the Lunch Time Dessert 333 Game" << endl;
    cout << "------------------------------------------" << endl;

    if (argc > 1){
        cout << "Test Bench Menu" << endl;
        cout << "1 - Normal" << endl;
        cout << "2 - Duplicate table cards" << endl;
        cout << "3 - Tie score 0" << endl;
        cout << "4 - Tie score 3" << endl;             // Test Bench Menu if we typed ./a.out debug would execute
        cout << "5 - Tie score 33" << endl;            // Otherwise ./a.out alone would execute Normal mode game
        cout << "6 - Tie score other" << endl;
        cout << "7 - Player 1 win" << endl;
        cout << "8 - Player 2 win" << endl;
        cout << " " << endl;
        cout << "Enter your selection: ";
        cin >> userSelection;
        cout << " " << endl;

        switch (userSelection) {

            case 1: {                                  // GAME_TYPE Normal debug
                cardDeckType deck;

/* function_identifier cardDeckType
*
*  parameters: must have correct header and compuler
*
*  output: none
*/    
                deck.shuffle();                        // shuffle the card deck
/* function_identifier deck.shuffle();
*
*  parameters: must be put after deck has been set
*
*  output: this shuffled the deck and kept values saved
*
*/
                p1Card1 = deck.drawCard();
                p2Card1 = deck.drawCard();  
                p1Card2 = deck.drawCard();             // draw shuffled cards to deal players
                p2Card2 = deck.drawCard();
                p1Card3 = deck.drawCard();
                p2Card3 = deck.drawCard();       

                p1Total = p1Card1+p1Card2+p1Card3;     // adding up the totals of each player
                p2Total = p2Card1+p2Card2+p2Card3;

                cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << p1Total << endl;
                cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << p2Total << endl;
                cout << " " << endl;

                while( rNumber <= 5 ) {                                 // while loop to loop the rounds and have the dealer draw a table card
                    cCard = deck.drawCard();                           
                
                    cout << "Round " << rNumber++ << endl;
                    cout << "------------------" << endl;
                    cout << "Table card is " << cCard << endl;
                    cout << " " << endl;

                    if ( p1Card1 == cCard ) {
                        p1Card1 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card2 = 0;
                    }
                    if ( p1Card2 == cCard ) {                          // if the table card matches a players card, that cards value is set to 0                
                        p1Card3 = 0;
                    }
                    if ( p2Card1 == cCard ) { 
                        p2Card1 = 0;
                    }
                    if ( p2Card2 == cCard ) {
                        p2Card2 = 0;
                    }
                    if ( p2Card3 == cCard ) {
                        p2Card3 = 0;
                    }
                    
                    cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << p1Total << endl;           
                    cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << p2Total << endl;
                    cout << " " << endl;
                }    
                
                cout << "Player 1 total: " << p1Total << endl;
                cout << "Player 2 total: " << p2Total << endl;                          // Total's after the loops are added up
                cout << "Game result - ";
                if ( p1Total == p2Total ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 0 ) {
                    cout << "Player 1 gets the goodies" << endl;                                            
                }
                else if ( p2Total == 0 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }   
                else if ( p1Total == 3 && p2Total == 33 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 33 && p2Total == 3 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;           // All if/else-if statements are cases to determine who the winner is
                }
                else if ( p1Total <= 3 && p2Total > 3 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total <= 3 && p1Total > 3 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else if ( p1Total > p2Total ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if( p1Total < p2Total ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
            } 
                break;                                                                        // break; is used to separate cases

            case 2: {                                       // GAME_TYPE Duplication debug
                cardDeckType deck;

                deck.setDeck(DUPLICATE);                    // Duplication pre-set deck is selected

                p1Card1 = deck.drawCard();
                p2Card1 = deck.drawCard();
                p1Card2 = deck.drawCard();
                p2Card2 = deck.drawCard();
                p1Card3 = deck.drawCard();
                p2Card3 = deck.drawCard();       

                p1Total = p1Card1+p1Card2+p1Card3;
                p2Total = p2Card1+p2Card2+p2Card3;

                cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << p1Total << endl;
                cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << p2Total << endl;
                cout << " " << endl;
                
                cCard = deck.drawCard();
                
                while( rNumber <= 5 ) {

                    cout << "Round " << rNumber++ << endl;
                    cout << "------------------" << endl;
                    cout << " " << endl;

                    if ( rNumber > 2 ) {
                        lCard = cCard;

                        cCard = deck.drawCard();

                        cout << "Table card is " << cCard;

                        while ( lCard == cCard) {
                            cout << "**Duplicate**" << endl;
                            cCard = deck.drawCard();
                            cout << "Table card is " << cCard << endl;
                            cout << " " << endl;
                        }
                    }
                    else{ 
                        cCard = deck.drawCard();
                        cout << "Table card is " << cCard << endl;
                       
                    }

                    cout << " " << endl;

                    if ( p1Card1 == cCard ) {
                        p1Card1 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card2 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card3 = 0;
                    }
                    if ( p2Card1 == cCard ) { 
                        p2Card1 = 0;
                    }
                    if ( p2Card2 == cCard ) {
                        p2Card2 = 0;
                    }
                    if ( p2Card3 == cCard ) {
                        p2Card3 = 0;
                    }
                    
                    cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << p1Total << endl;           
                    cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << p2Total << endl;
                    cout << " " << endl;
                }    
                
                cout << "Player 1 total: " << p1Total << endl;
                cout << "Player 2 total: " << p2Total << endl;
                cout << "Game result - ";
                if ( p1Total == p2Total ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 0 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total == 0 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }   
                else if ( p1Total == 3 && p2Total == 33 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 33 && p2Total == 3 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total > p2Total ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if( p1Total < p2Total ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
               


            }
                
                break;
                    
            case 3: {                                   // GAME_TYPE Tie0 debug
                cardDeckType deck;

                deck.setDeck(TIE0);

                p1Card1 = deck.drawCard();  
                p1Card2 = deck.drawCard();
                p1Card3 = deck.drawCard();                              // deals 3 cards to each player
                p2Card1 = deck.drawCard();
                p2Card2 = deck.drawCard();
                p2Card3 = deck.drawCard(); 

                p1Total = p1Card1+p1Card2+p1Card3;                      // totals are added up for each player
                p2Total = p2Card1+p2Card2+p2Card3;  

                cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
                cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
                cout << " " << endl;

                while( rNumber <= 5 ) {                             // while loop to loop the rounds and have the dealer draw a table card 
                    cCard = deck.drawCard();                        // draws a card for the table

                    cout << "Round " << rNumber++ << endl;          // loops round numbers 1-5
                    cout << "------------------" << endl;
                    cout << "Table card is " << cCard << endl;     
                    cout << " " << endl;

                        if ( p1Card1 == cCard ) {
                            p1Card1 = 0;
                        }
                        if ( p1Card2 == cCard ) {
                            p1Card2 = 0;
                        }
                        if ( p1Card2 == cCard ) {
                            p1Card3 = 0;
                        }
                        if ( p2Card1 == cCard ) { 
                            p2Card1 = 0;
                        }
                        if ( p2Card2 == cCard ) {
                            p2Card2 = 0;
                        }
                        if ( p2Card3 == cCard ) {
                            p2Card3 = 0;
                        }

                    p1Total = p1Card1+p1Card2+p1Card3;
                    p2Total = p2Card1+p2Card2+p2Card3;  

                   cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
                   cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
                   cout << " " << endl;
                }

                cout << "Player 1 total: " << p1Total << endl;
                cout << "Player 2 total: " << p2Total << endl;
                cout << "Game result - ";
                if ( p1Total == p2Total ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 0 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total == 0 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }   
                else if ( p1Total == 3 && p2Total == 33 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 33 && p2Total == 3 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total <= 3 && p2Total > 3 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total <= 3 && p1Total > 3 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else if ( p1Total > p2Total ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if( p1Total < p2Total ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }



            }
            
                break;

            case 4: {                                   // GAME_TYPE Tie3 debug
                cardDeckType deck;
   
                deck.setDeck(TIE3);

                p1Card1 = deck.drawCard();  
            p1Card2 = deck.drawCard();
            p1Card3 = deck.drawCard();                              // deals 3 cards to each player
            p2Card1 = deck.drawCard();
            p2Card2 = deck.drawCard();
            p2Card3 = deck.drawCard(); 

            p1Total = p1Card1+p1Card2+p1Card3;                      // totals are added up for each player
            p2Total = p2Card1+p2Card2+p2Card3;  

            cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
            cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
            cout << " " << endl;

            while( rNumber <= 5 ) {                             // while loop to loop the rounds and have the dealer draw a table card 
                cCard = deck.drawCard();                        // draws a card for the table

                cout << "Round " << rNumber++ << endl;          // loops round numbers 1-5
                cout << "------------------" << endl;
                cout << "Table card is " << cCard << endl;     
                cout << " " << endl;

                if ( p1Card1 == cCard ) {
                        p1Card1 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card2 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card3 = 0;
                    }
                    if ( p2Card1 == cCard ) { 
                        p2Card1 = 0;
                    }
                    if ( p2Card2 == cCard ) {
                        p2Card2 = 0;
                    }
                    if ( p2Card3 == cCard ) {
                        p2Card3 = 0;
                    }

                p1Total = p1Card1+p1Card2+p1Card3;
                p2Total = p2Card1+p2Card2+p2Card3;  

                cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
                cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
                cout << " " << endl;
            }

            cout << "Player 1 total: " << p1Total << endl;
            cout << "Player 2 total: " << p2Total << endl;
            cout << "Game result - ";
            if ( p1Total == p2Total ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 0 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total == 0 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }   
                else if ( p1Total == 3 && p2Total == 33 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 33 && p2Total == 3 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total <= 3 && p2Total > 3 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total <= 3 && p1Total > 3 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else if ( p1Total > p2Total ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if( p1Total < p2Total ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }


            }
                break;

            case 5: {                                   // GAME_TYPE Tie33 debug
                cardDeckType deck;

                deck.setDeck(TIE33);

                p1Card1 = deck.drawCard();  
                p1Card2 = deck.drawCard();
                p1Card3 = deck.drawCard();                              // deals 3 cards to each player
                p2Card1 = deck.drawCard();
                p2Card2 = deck.drawCard();
                p2Card3 = deck.drawCard(); 

                p1Total = p1Card1+p1Card2+p1Card3;                      // totals are added up for each player
                p2Total = p2Card1+p2Card2+p2Card3;  

                cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
                cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
                cout << " " << endl;

                while( rNumber <= 5 ) {                             // while loop to loop the rounds and have the dealer draw a table card 
                    cCard = deck.drawCard();                        // draws a card for the table

                    cout << "Round " << rNumber++ << endl;          // loops round numbers 1-5
                    cout << "------------------" << endl;
                    cout << "Table card is " << cCard << endl;     
                    cout << " " << endl;

                if ( p1Card1 == cCard ) {
                        p1Card1 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card2 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card3 = 0;
                    }
                    if ( p2Card1 == cCard ) { 
                        p2Card1 = 0;
                    }
                    if ( p2Card2 == cCard ) {
                        p2Card2 = 0;
                    }
                    if ( p2Card3 == cCard ) {
                        p2Card3 = 0;
                    }

                p1Total = p1Card1+p1Card2+p1Card3;
                p2Total = p2Card1+p2Card2+p2Card3;  

                cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
                cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
                cout << " " << endl;
            }

            cout << "Player 1 total: " << p1Total << endl;
            cout << "Player 2 total: " << p2Total << endl;
            cout << "Game result - ";
            if ( p1Total == p2Total ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 0 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total == 0 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }   
                else if ( p1Total == 3 && p2Total == 33 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 33 && p2Total == 3 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total <= 3 && p2Total > 3 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total <= 3 && p1Total > 3 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else if ( p1Total > p2Total ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if( p1Total < p2Total ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
     

            }
                break;

            case 6: {                                   // GAME_TYPE Tie_other debug
                cardDeckType deck;
    
                deck.setDeck(TIE_OTHER);

                p1Card1 = deck.drawCard();  
                p1Card2 = deck.drawCard();
                p1Card3 = deck.drawCard();                              // deals 3 cards to each player
                p2Card1 = deck.drawCard();
                p2Card2 = deck.drawCard();
                p2Card3 = deck.drawCard(); 

                p1Total = p1Card1+p1Card2+p1Card3;                      // totals are added up for each player
                p2Total = p2Card1+p2Card2+p2Card3;  

                cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
                cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
                cout << " " << endl;

                while( rNumber <= 5 ) {                             // while loop to loop the rounds and have the dealer draw a table card 
                     cCard = deck.drawCard();                        // draws a card for the table

                     cout << "Round " << rNumber++ << endl;          // loops round numbers 1-5
                     cout << "------------------" << endl;
                     cout << "Table card is " << cCard << endl;     
                     cout << " " << endl;

                if ( p1Card1 == cCard ) {
                        p1Card1 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card2 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card3 = 0;
                    }
                    if ( p2Card1 == cCard ) { 
                        p2Card1 = 0;
                    }
                    if ( p2Card2 == cCard ) {
                        p2Card2 = 0;
                    }
                    if ( p2Card3 == cCard ) {
                        p2Card3 = 0;
                    }

                p1Total = p1Card1+p1Card2+p1Card3;
                p2Total = p2Card1+p2Card2+p2Card3;  

                cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
                cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
                cout << " " << endl;
            }

            cout << "Player 1 total: " << p1Total << endl;
            cout << "Player 2 total: " << p2Total << endl;
            cout << "Game result - ";
            if ( p1Total == p2Total ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 0 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total == 0 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }   
                else if ( p1Total == 3 && p2Total == 33 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 33 && p2Total == 3 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total <= 3 && p2Total > 3 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total <= 3 && p1Total > 3 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else if ( p1Total > p2Total ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if( p1Total < p2Total ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
      

            }
                break;

            case 7: {                                   // GAME_TYPE Player1_wins debug
                cardDeckType deck;

                deck.setDeck(PLAYER1_WIN);

                p1Card1 = deck.drawCard();  
                p1Card2 = deck.drawCard();
                p1Card3 = deck.drawCard();                              // deals 3 cards to each player
                p2Card1 = deck.drawCard();
                p2Card2 = deck.drawCard();
                p2Card3 = deck.drawCard(); 

                p1Total = p1Card1+p1Card2+p1Card3;                      // totals are added up for each player
                p2Total = p2Card1+p2Card2+p2Card3;  

               cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
               cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
             cout << " " << endl;

            while( rNumber <= 5 ) {                             // while loop to loop the rounds and have the dealer draw a table card 
                cCard = deck.drawCard();                        // draws a card for the table

                cout << "Round " << rNumber++ << endl;          // loops round numbers 1-5
                cout << "------------------" << endl;
                cout << "Table card is " << cCard << endl;     
                cout << " " << endl;

                if ( p1Card1 == cCard ) {
                        p1Card1 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card2 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card3 = 0;
                    }
                    if ( p2Card1 == cCard ) { 
                        p2Card1 = 0;
                    }
                    if ( p2Card2 == cCard ) {
                        p2Card2 = 0;
                    }
                    if ( p2Card3 == cCard ) {
                        p2Card3 = 0;
                    }

                p1Total = p1Card1+p1Card2+p1Card3;
                p2Total = p2Card1+p2Card2+p2Card3;  

                cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
                cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
                cout << " " << endl;
            }

            cout << "Player 1 total: " << p1Total << endl;
            cout << "Player 2 total: " << p2Total << endl;
            cout << "Game result - ";
            if ( p1Total == p2Total ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 0 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total == 0 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }   
                else if ( p1Total == 3 && p2Total == 33 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 33 && p2Total == 3 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total <= 3 && p2Total > 3 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total <= 3 && p1Total > 3 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else if ( p1Total > p2Total ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if( p1Total < p2Total ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }



            }
                break;

            case 8: {                                   // GAME_TYPE Player2_wins debug
                cardDeckType deck;

                deck.setDeck(PLAYER2_WIN);

                p1Card1 = deck.drawCard();  
                p1Card2 = deck.drawCard();
                p1Card3 = deck.drawCard();                              // deals 3 cards to each player
                p2Card1 = deck.drawCard();
                p2Card2 = deck.drawCard();
                p2Card3 = deck.drawCard(); 

                p1Total = p1Card1+p1Card2+p1Card3;                      // totals are added up for each player
                p2Total = p2Card1+p2Card2+p2Card3;  

                cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
                cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
                cout << " " << endl;

                while( rNumber <= 5 ) {                             // while loop to loop the rounds and have the dealer draw a table card 
                     cCard = deck.drawCard();                        // draws a card for the table

                     cout << "Round " << rNumber++ << endl;          // loops round numbers 1-5
                     cout << "------------------" << endl;
                     cout << "Table card is " << cCard << endl;     
                     cout << " " << endl;

                if ( p1Card1 == cCard ) {
                        p1Card1 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card2 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card3 = 0;
                    }
                    if ( p2Card1 == cCard ) { 
                        p2Card1 = 0;
                    }
                    if ( p2Card2 == cCard ) {
                        p2Card2 = 0;
                    }
                    if ( p2Card3 == cCard ) {
                        p2Card3 = 0;
                    }

                p1Total = p1Card1+p1Card2+p1Card3;
                p2Total = p2Card1+p2Card2+p2Card3;  

                cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
                cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
                cout << " " << endl;
            }

            cout << "Player 1 total: " << p1Total << endl;
            cout << "Player 2 total: " << p2Total << endl;
            cout << "Game result - ";
            if ( p1Total == p2Total ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 0 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total == 0 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }   
                else if ( p1Total == 3 && p2Total == 33 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 33 && p2Total == 3 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total <= 3 && p2Total > 3 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total <= 3 && p1Total > 3 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else if ( p1Total > p2Total ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if( p1Total < p2Total ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
   


            }
                break;

            default: {                                  // Just incase someone puts down anything other than 1-8
                cout << "Invalid Entry" << endl;
            }

        }
            
    }    
    else{                             // This is the actual game execution when just executing with ./a.out alone
        cout << " " << endl;
        cardDeckType deck;                                      // deck of 52 cards

        deck.shuffle();                                         // shuffles deck

        p1Card1 = deck.drawCard();  
        p1Card2 = deck.drawCard();
        p1Card3 = deck.drawCard();                              // deals 3 cards to each player
        p2Card1 = deck.drawCard();
        p2Card2 = deck.drawCard();
        p2Card3 = deck.drawCard(); 

        p1Total = p1Card1+p1Card2+p1Card3;                      // totals are added up for each player
        p2Total = p2Card1+p2Card2+p2Card3;  

        cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
        cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
        cout << " " << endl;

            while( rNumber <= 5 ) {                             // while loop to loop the rounds and have the dealer draw a table card 
                cCard = deck.drawCard();                        // draws a card for the table

                cout << "Round " << rNumber++ << endl;          // loops round numbers 1-5
                cout << "------------------" << endl;
                cout << "Table card is " << cCard << endl;     
                cout << " " << endl;

                if ( p1Card1 == cCard ) {
                        p1Card1 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card2 = 0;
                    }
                    if ( p1Card2 == cCard ) {
                        p1Card3 = 0;
                    }
                    if ( p2Card1 == cCard ) { 
                        p2Card1 = 0;
                    }
                    if ( p2Card2 == cCard ) {
                        p2Card2 = 0;
                    }
                    if ( p2Card3 == cCard ) {
                        p2Card3 = 0;
                    }

                p1Total = p1Card1+p1Card2+p1Card3;
                p2Total = p2Card1+p2Card2+p2Card3;  

                cout << fixed << "Player 1:  " << setw(3) << p1Card1 << setw(3) << p1Card2 << setw(3) << p1Card3 << " Total:  " << setw(3) << p1Total << endl;
                cout << fixed << "Player 2:  " << setw(3) << p2Card1 << setw(3) << p2Card2 << setw(3) << p2Card3 << " Total:  " << setw(3) << p2Total << endl;
                cout << " " << endl;
            }

            cout << "Player 1 total: " << p1Total << endl;
            cout << "Player 2 total: " << p2Total << endl;
            cout << "Game result - ";
            if ( p1Total == p2Total ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 0 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total == 0 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }   
                else if ( p1Total == 3 && p2Total == 33 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total == 33 && p2Total == 3 ) {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }
                else if ( p1Total <= 3 && p2Total > 3 ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if ( p2Total <= 3 && p1Total > 3 ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else if ( p1Total > p2Total ) {
                    cout << "Player 1 gets the goodies" << endl;
                }
                else if( p1Total < p2Total ) {
                    cout << "Player 2 gets the goodies" << endl;
                }
                else {
                    cout << "Tie  => You both have to split the goodies" << endl;
                }


       }

    return 0;

}   
