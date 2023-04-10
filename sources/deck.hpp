#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "card.hpp"
#include "player.hpp"

using namespace std; 


class Deck
{
    private:
        vector<Card> deckOfCards_;


    public:

        Deck();
        
        vector<Card> getDeckOfCards() const;
        void shuffleDeck();
        void removeFromDeck();

}; 