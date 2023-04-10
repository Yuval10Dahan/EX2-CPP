#include "player.hpp"
using namespace std;

#define PLAYER_DECK_SIZE 26

// init variable
int zero = 0;

// Constructor 
Player::Player(const string &Pname) : name_(Pname), wonCards_(zero), numOfDraws_(zero){}

// ### Getters ###

// getter method for the "name" data member
string Player::getPName() const
{
    return this->name_;
}  

// getter method for the size of "stackOfCards" data member
int Player::stacksize() const
{
    return this->stackOfCards_.size();
}

// getter method for the "wonCards" data member
int Player::cardesTaken() const
{
    return this->wonCards_;
}

// getter method for the "numOfDraws" data member
int Player::getNumOfDraws() const
{
    return this->numOfDraws_;
}

// // getter method for the "stackOfCards" data member
// vector<Card>& Player::getPlayerStack() 
// {
//     return this->stackOfCards_;
// }


// ### Setters ###

// increase the "wonCards" data member
void Player::increaseWonCards(int wCards)
{
    this->wonCards_ += wCards;
}

// increase the "numOfDraws" data member by 1
void Player::increaseNumOfDraws()
{
    this->numOfDraws_++;
}

// // set the "wonCards" data member to zero
// void Player::resetWonCards()
// {
//     this->wonCards_ = 0;
// }

// // set the "numOfDraws" data member to zero
// void Player::resetnumOfDraws()
// {
//     this->numOfDraws_ = 0;
// }



// this method return the win rate in percentage
double Player::winRate()
{
    // the player own deck size
    int stacksize = this->stacksize();

    // the number of cards that both players used allready casting to double
    double totalUsedCards = static_cast<double>( (PLAYER_DECK_SIZE - stacksize) * 2 );

    // contain the current won Cards casting to double
    double cardsTaken = static_cast<double>(this->cardesTaken());

    // number of won cards divided by the total used cards in the game
    double cWon = cardsTaken / totalUsedCards;

    // multiply by 100 in order to get the win rate as a percentage
    return cWon * 100.0;
}

// this method return the draw rate in percentage
double Player::drawRate()
{
    // the player own deck size
    int stacksize = this->stacksize();

    // the number of cards that both players used allready casting to double
    double totalUsedCards = static_cast<double>( (PLAYER_DECK_SIZE - stacksize) * 2 );
    
    // contain the current number of draws casting to double
    double numOfDraws = static_cast<double>(this->getNumOfDraws());

    // number of draws divided by the total used cards in the game
    double draw = numOfDraws / totalUsedCards;

    // multiply by 100 in order to get the draw rate as a percentage
    return draw * 100.0;
}

// this method print a single player statistics 
void Player::printPlayerStats()
{
    cout << "#################################################" << endl;

    // print player name, won cards, win rate, number of draws and draw rate
    cout << "Player name: " << this->name_ << endl;
    cout << "Cards won: " << to_string(this->wonCards_) << endl;
    cout << "Win rate: " << to_string(this->winRate()) << endl;
    cout << "Number of draws: " << to_string(this->numOfDraws_) << endl;
    cout << "Draw rate: " << to_string(this->drawRate()) << endl;
}

// this method adds a specific card to the player own deck of cards
void Player::addCard(const Card& card) 
{
    this->stackOfCards_.push_back(card);
}

// this method return the last card from the player own deck, and removes it after
Card& Player::useCard()
{
    Card &retCard = this->stackOfCards_.back();
    this->removeCard();

    return retCard;                       
}

// this method remove the last card from the player own deck
void Player::removeCard()
{
    this->stackOfCards_.pop_back();
}