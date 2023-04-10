#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "card.hpp"
#include "player.hpp"

using namespace std; 

namespace ariel{}

class Deck
{
    private:
        vector<Card> deckOfCards_; // vector that holds the main deck of cards


    public:

        // constructor
        Deck();
        
        vector<Card> getDeckOfCards() const;
        void shuffleDeck();
        void removeFromDeck();

}; 