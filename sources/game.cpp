#include "game.hpp"
#include "player.hpp"
#include <sstream>
#include <exception>

using namespace std;
 
#define TWO_CARDS 2

// Constructor 
Game::Game(Player &pl1, Player &pl2) : one_(pl1), two_(pl2), winnerName_("")
{
    // the constructor wrap with try-catch in order to catch exceptions in initialization
    try
    {
        // if the vector isn't empty continue
        while( this->gameDeck_.getDeckOfCards().empty() == false )
        {
            // the card that located in the last element in the vector for the first player
            Card cPl1 = this->gameDeck_.getDeckOfCards().back();

            // remove the last element from the vector
            this->gameDeck_.removeFromDeck();

            // the same operation for the second player
            Card cPl2 = this->gameDeck_.getDeckOfCards().back();
            this->gameDeck_.removeFromDeck();
  
            // dealing the cards to the players
            this->getOne().addCard(cPl1);
            this->getTwo().addCard(cPl2);
        }
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 
}



// ### Getters ###

// getter method for the "one" data member
Player& Game::getOne()
{
    return this->one_;
}

// getter method for the "Two" data member
Player& Game::getTwo()
{
    return this->two_;
}

// getter method for the "winnerName" data member
string Game::getWinnerName() const
{
    return this->winnerName_;
}

// this method make each player to play one turn in the game
void Game::playTurn()
{
    string name1 = this->one_.getPName();
    string name2 = this->two_.getPName();

    // check if you can't play a turn and throw exception accordingly
    if( (this->one_.stacksize() == 0 || this->two_.stacksize() == 0) || (&this->one_ == &this->two_) ||
    (this->one_.cardesTaken() > 52 || this->two_.cardesTaken() > 52) || (this->gameDeck_.getDeckOfCards().size() > 0) )
    {
        throw runtime_error("The initialization of game failed\n");
        return;
    }

    // it's okay to play a turn
    else
    {
        // add the used card of p1 to the pile
        Card card1 = this->one_.useCard();

        // this card needed for printing, therefore true in the second field of the struct
        this->pile_.push_back( {card1, true, name1, false} );

        // add the used card of p2 to the pile
        Card card2 = this->two_.useCard();

        // check which card is the higher card, or if it is a draw
        int gameCase = this->betterCard(card1, card2);

        // -----------------------------------------------------------------------------
        // if there isn't enough cards left for draw, we still need to set the draw flag to true
        if( (this->one_.stacksize() < 2 || this->two_.stacksize() < 2) && gameCase == 0 )
        {
            this->pile_.push_back( {card2, true, name2, true} );
        }
        
        // there is enough cards for draw - no need to set the draw flag
        else
        {
            // if it's a draw then the draw flag set to true
            if(gameCase == 0)
            {
                this->pile_.push_back( {card2, true, name2, true} );
            }
            
            // set the draw flag to false
            else
            {
                // this card needed for printing, therefore true. the draw flag set to false
                this->pile_.push_back( {card2, true, name2, false} );
            }
        }
        // -----------------------------------------------------------------------------

        // player1 win
        if(gameCase == 1)
        {   
            // add 2 cards to p1 number of won cards and set his name as the game winner
            this->one_.increaseWonCards(TWO_CARDS);
            this->winnerName_ = name1;
        }

        // player2 win
        else if(gameCase == 2)
        {
            // add 2 cards to p2 number of won cards and set his name as the game winner
            this->two_.increaseWonCards(TWO_CARDS);
            this->winnerName_ = name2;
        }

        // draw             
        else
        {
            // flag to indicate if it is still a draw
            bool stillDraw = true;

            while(stillDraw == true)
            {
                // update the number of draws for each player
                this->one_.increaseNumOfDraws();
                this->two_.increaseNumOfDraws();

                // if there isn't cards left in the players stack,
                // devide the numbers of cards in the pile to the 2
                // players and add them to their number of won cards            
                if( (this->one_.stacksize() == 0 && this->two_.stacksize() == 0) )
                {
                    this->one_.increaseWonCards(this->pile_.size() / 2);
                    this->two_.increaseWonCards(this->pile_.size() / 2);
                            
                    // set it to false to break the while loop
                    stillDraw = false;
                }

                // if there is 1 card left in the players stack,
                // the players add their single card to the pile.
                // after that devide the numbers of cards in the pile to the 2
                // players and add them to their number of won cards
                else if( (this->one_.stacksize() == 1 && this->two_.stacksize() == 1) )
                {
                    Card del1 = this->one_.useCard();
                    Card del2 = this->two_.useCard();

                    // those cards are useless for printing, therefore false in the second field of the struct
                    this->pile_.push_back( {del1, false, name1, false} );
                    this->pile_.push_back( {del2, false, name2, false} );

                    this->one_.increaseWonCards(this->pile_.size() / 2);
                    this->two_.increaseWonCards(this->pile_.size() / 2);

                    // set it to false to break the while loop
                    stillDraw = false;
                }

                else
                {
                    // use this cards as the reverse cards and add them to the pile
                    Card reverse1 = this->one_.useCard();
                    Card reverse2 = this->two_.useCard();
                    // those cards are useless for printing, therefore false
                    this->pile_.push_back( {reverse1, false, name1, false} );
                    this->pile_.push_back( {reverse2, false, name2, false} );

                    // use this cards to continue the war and add them to the pile
                    Card temp1 = this->one_.useCard();
                    Card temp2 = this->two_.useCard();
                    // those card needed for printing, therefore true in the second field of the struct
                    this->pile_.push_back( {temp1, true, name1, false} );
                    this->pile_.push_back( {temp2, true, name2, false} );

                    // check which card is the higher card, or if it is a draw
                    int betterC = this->betterCard(temp1, temp2);

                    // player1 win
                    if(betterC == 1)
                    {
                        // add the number of cards in the pile to p1 
                        // number of won cards and set his name as the game winner
                        this->one_.increaseWonCards(this->pile_.size());
                        this->winnerName_ = name1;

                        // set it to false to break the while loop
                        stillDraw = false;
                    }

                    // player2 win    
                    else if(betterC == 2)
                    {
                        // add the number of cards in the pile to p2 
                        // number of won cards and set his name as the game winner
                        this->two_.increaseWonCards(this->pile_.size());
                        this->winnerName_ = name2;

                        // set it to false to break the while loop
                        stillDraw = false;
                    }

                    // draw again
                    else
                    {
                        // erase temp2(the last element in the pile)
                        this->pile_.pop_back();

                        // push temp2 again but with the draw flag set to true
                        this->pile_.push_back( {temp2, true, name2, true} );
                        
                        // set it to true to continue the while loop
                        stillDraw = true;
                    }
                }
            }
        }
    }

    // string that contains the last turn
    string turnStr = this->turnStr(this->pile_);
        
    // adding this round winner name to the last turn    
    turnStr += this->winnerName_ + " wins. ";   

    // add the last turn to vector that contains all the printed turns in the game
    this->turnsData_.push_back(turnStr);                                     

    // empty the pile for the next turn
    this->pile_.clear();
}
 
// this method prints the last turn stats
void Game::printLastTurn()
{   
    // throw exception if no turns have occurred yet
    if(this->turnsData_.empty() == true)
    {
        throw logic_error("No turns have occurred yet\n");
    }

    else
    {
        cout << "#################################################" << endl; 
        cout << "Last Turn: " << endl;   
        
        // the last turn that was added to turnsData(last element in the vector)
        string lTurn = this->turnsData_.back();

        // print the last turn
        cout << lTurn << endl;
    }
}

// this method makes the players to play turns until there isn't cards left
void Game::playAll()
{
    // the code wrap with try-catch in order to catch exceptions
    try
    {
        // if the players has cards left in their stack - continue to play a turn
        while( (this->one_.stacksize() > 0) && (this->two_.stacksize() > 0) )
        {
            this->playTurn();
        }
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }  
}

// this method prints the name of the winner in the current game
void Game::printWiner()
{
    // the code wrap with try-catch in order to catch exceptions
    try
    {
        cout << "#################################################" << endl; 
        cout << "Print Winner: " << endl;   

        // number off winning cards of the players
        int cardesTaken1 = this->one_.cardesTaken();
        int cardesTaken2 = this->two_.cardesTaken();

        // names of the players
        string name1 = this->one_.getPName();
        string name2 = this->two_.getPName();

        // player1 win
        if(cardesTaken1 > cardesTaken2)
        {
            cout << "The winner is: " << name1 << endl;
        }

        // player 2 win
        else if(cardesTaken2 > cardesTaken1)
        {
            cout << "The winner is: " << name2 << endl;
        }

        // Tie
        else
        {
            cout << "It is a Tie" << endl;
        }
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }   
}

// this method prints all the turns played one line per turn
void Game::printLog()
{   
    // throw exception if no turns have occurred yet
    if(this->turnsData_.empty() == true)
    {
        throw logic_error("No turns have occurred yet\n");
    }

    else
    {    
        cout << "#################################################" << endl; 
        cout << "Print Log: " << endl;   
        cout << "Number of Turns: " << this->turnsData_.size() << endl;

        // loop through the vector and printed the turns from start to finish
        for(string turn : this->turnsData_)
        {
            cout << turn << endl;
        }
    }
}

// this method print each player his basic statistics: win rate, cards won, draw rate and amount of draws that happened
void Game::printStats()
{
    // the code wrap with try-catch in order to catch exceptions
    try
    {
        cout << "#################################################" << endl;
        cout << "Players Stats: " << endl;
        // use the printing method in class Player for each of the players
        this->one_.printPlayerStats();
        this->two_.printPlayerStats();
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

// this method return a number that represent which player 
// has a higher card - 1 for p1, 2 for p2, 0 if draw.
int Game::betterCard(const Card &card1, const Card &card2)
{
    // numbers of the cards as integers
    int c1 = card1.getCardValue();
    int c2 = card2.getCardValue();

    // returning integer - default is draw
    int result = 0;

    // p1 has a higher card
    if(c1 > c2)
    {
        // if c1 is ACE and c2 is 2
        if(c1 == 14 && c2 == 2)
        {
            result = 2;
        }
        result = 1;
    }
    
    // p2 has a higher card
    if(c2 > c1)
    {
        // if c2 is ACE and c1 is 2
        if(c2 == 14 && c1 == 2)
        {
            result = 1;
        }
        result = 2;
    }

    return result;
}

// this method return string that contains the last turn
string Game::turnStr(vector<Element> &pile)
{
    string retStr = "";

    // loop through the pile
    for(Element& elem : pile)
    {
        string temp;

        // check if the card crucial for printing
        if(elem.needed == true)
        {
            string Pname = elem.name;
            string cNumber = elem.card.cardNumberStr();
            string cName = elem.card.cardNameStr();
            string winner = this->winnerName_;
            
            // string that contains the current element information from the pile
            temp = Pname + " played " + cNumber + " of " + cName + ". ";

            // check if there was a draw
            if(elem.printDraw == true)
            {
                temp += "Draw. ";
            }

            // the total return string
            retStr += temp;
        }
    }

    return retStr;
}