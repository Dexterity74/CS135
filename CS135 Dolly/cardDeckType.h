
enum GAME_TYPE {NORMAL, DUPLICATE, TIE0, TIE3, TIE33, TIE_OTHER,
                PLAYER1_WIN, PLAYER2_WIN};

class cardDeckType
{

    public:
    cardDeckType(GAME_TYPE = NORMAL);   //constructor
    int drawCard();
    int cardsRemaining();
    void shuffle();
    void printDeck();  
    void initDeck(); 
    void setDeck(GAME_TYPE);
    
    private:
    int deck[52];
    int nextCard = 0;
    void duplicate();
    void tie ( GAME_TYPE );
    void player( GAME_TYPE );
   
};
  

