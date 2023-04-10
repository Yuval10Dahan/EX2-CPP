#include <string>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "deck.hpp"
#include "card.hpp"

using namespace std;


// Constructor - create a deck of 52 cards
Deck::Deck()
{   
    // loop through the 4 types of card names(SPADES, HEARTS, DIAMONDS, CLUBS) 
    for (int i = 0; i < 4; i++)
    {
        // loop through the 13 types of card numbers(2-10, JACK, QUEEN, KING, ACE)
        for (int j = 2; j < 15; j++)
        {
            // cast the card name index into CardNames
            CardNames cName = static_cast<CardNames>(i);

            // cast the card number index into CardNumbers
            CardNumbers cNum = static_cast<CardNumbers>(j);

            // create a card object
            Card card(cName, cNum);

            // push the card into the deckOfCards vector from the back
            deckOfCards_.push_back(card);
        }
    } 

    // shuffle the deck of cards
    this->shuffleDeck();  
}

// getter method for "deckOfCards" data member
vector<Card> Deck::getDeckOfCards() const
{
    return this->deckOfCards_;
}

// this method randomly shuffles the order of the cards in the deck
void Deck::shuffleDeck()
{
    // i found this shuffle technique online
    unsigned int param = static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());
    auto randEngine = default_random_engine{param};

    // this method takes the range to be shuffled in the vector and the random number generator.
    // reorder the elements in deckOfCards data member randomly 
    shuffle( this->deckOfCards_.begin(), this->deckOfCards_.end(), randEngine);
}

// this method remove the last element from the deck of cards
void Deck::removeFromDeck()
{
    this->deckOfCards_.pop_back();
}