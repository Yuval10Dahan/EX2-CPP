// #include "player.hpp"
// #include "game.hpp"
// #include "deck.hpp"
// #include "card.hpp"
// #include <string>

// using namespace std;

// // test
// int main()
// {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1,p2);

//     // #############################################################################
//     // Card tests:
//     cout << "######################################################" << endl;
//     cout << "Card tests: " << endl;
//     cout << "######################################################" << endl;
//     cout << endl;

//     CardNames cName = CardNames::SPADES;
//     CardNumbers cNum = CardNumbers::ACE;
//     Card card(cName,cNum);

    
//     cout << "card name: " << card.cardNameStr() << endl;
//     cout << "card number(string): " << card.cardNumberStr() << endl;
//     cout << "card number(int): " << card.getCardValue() << endl;

//     cout << "######################################################" << endl;
//     cout << endl;



//     // #############################################################################
//     // Deck tests:
//     cout << "######################################################" << endl;
//     cout << "Deck tests: " << endl;
//     cout << "######################################################" << endl;
//     cout << endl;

//     Deck deck;
    
//     cout << "init deck: " << endl;
//     cout << endl;
//     for(Card &c : deck.getDeckOfCards())
//     {
//         cout << c.cardNumberStr() << " of " << c.cardNameStr() << endl;
//     }
    
//     deck.shuffleDeck();
//     cout << endl;
//     cout << "deck after shffle: " << endl;
//     cout << endl;

//     for(Card &c : deck.getDeckOfCards())
//     {
//         cout << c.cardNumberStr() << " of " << c.cardNameStr() << endl;
//     }

//     cout << endl;
//     cout << "deck size: " << deck.getDeckOfCards().size() << endl;
//     deck.removeFromDeck();
//     cout << "deck size after remove From Deck: " << deck.getDeckOfCards().size() << endl;
//     cout << endl;




//     // #############################################################################
//     // Game tests:
//     cout << "######################################################" << endl;
//     cout << "Game tests: " << endl;
//     cout << "######################################################" << endl;
//     cout << endl;
    
//     for (int i=0;i<5;i++) 
//     {
//         game.playTurn();
//     }
//     game.printLastTurn(); 
//     cout << endl;
//     game.playAll(); 
//     game.printWiner(); 
//     cout << endl;
//     game.printLog();
//     cout << endl;
//     game.printStats();
//     cout << endl;

    
//     cout << endl;
//     cout << "winner name(getter): " << game.getWinnerName() << endl;
//     cout << endl;
    
//     CardNames cName1 = CardNames::CLUBS;
//     CardNumbers cNum1 = CardNumbers::KING;
//     Card card1(cName1,cNum1);

//     CardNames cName2 = CardNames::HEARTS;
//     CardNumbers cNum2 = CardNumbers::TWO;
//     Card card2(cName2,cNum2);

//     int res = game.betterCard(card1,card2); // needs to be 1
//     cout << "result is: " << res << endl;
//     cout << endl;




//     // #############################################################################
//     // Player tests:
//     cout << "######################################################" << endl;
//     cout << "Player tests: " << endl;
//     cout << "######################################################" << endl;
//     cout << endl;

     
//     cout << "p1 name: " << p1.getPName() << endl;


//     cout << endl;
//     cout << "p1 num of draws: " << p1.getNumOfDraws() << endl;
//     p1.increaseNumOfDraws();
//     p1.increaseNumOfDraws();
//     p1.increaseNumOfDraws();
//     cout << "p1 num of draws(after): " << p1.getNumOfDraws() << endl;

//     cout << endl;
//     cout << "p2 cardsTaken: " << p2.cardesTaken() << endl;
//     p2.increaseWonCards(4);
//     cout << "p2 cardsTaken(after): " << p2.cardesTaken() << endl;
//     cout << endl;

//     cout << "p2 win rate: " << p2.winRate() << endl;
//     cout << endl;

//     cout << "p2 draw rate: " << p2.drawRate() << endl;
//     cout << endl;

//     p2.printPlayerStats();
//     cout << endl;


//     cout << "p2 stacksize: " << p2.stacksize() << endl;
//     CardNames cName3 = CardNames::CLUBS;
//     CardNumbers cNum3 = CardNumbers::KING;
//     Card card3(cName3,cNum3); 
//     p2.addCard(card3);
//     cout << "p2 stacksize(after adding): " << p2.stacksize() << endl;
//     cout << endl;


//     Card retCard = p2.useCard();
//     cout << "the card is " << retCard.cardNumberStr() << " of " << retCard.cardNameStr() << endl;
//     cout << endl;

//     cout << "p1 stacksize: " << p1.stacksize() << endl;
//     p1.removeCard();
//     cout << "p1 stacksize(after remove): " << p1.stacksize() << endl;
//     cout << endl;


// }