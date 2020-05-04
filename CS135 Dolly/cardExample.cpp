#include <iostream>
#include "cardDeckType.h"

using namespace std;

int main(){

  cardDeckType deck;

  cout << "NORMAL Deck" << endl;
  deck.printDeck();
  cout << endl;

  deck.shuffle( );
  cout << "Shuffle Deck " << endl;
  deck.printDeck( );
  cout << endl;

  cout << "Deck Configured for TIE0 "<< endl;
  deck.setDeck( TIE0 );
  deck.printDeck( );
  cout << endl;

  cout << "Drawing 10 cards from the deck" << endl;
  for ( int i = 0; i < 10; i++ )
        cout << deck.drawCard() << endl;
}
