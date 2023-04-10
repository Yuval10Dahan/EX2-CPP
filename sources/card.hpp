#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace ariel{}
    
    // enum that holds the card type of numbers
    enum class CardNumbers
    {
        TWO = 2,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE  
    }; 

    // enum that holds the card type of names
    enum class CardNames
    {
        SPADES,
        HEARTS,
        DIAMONDS,
        CLUBS
    };

    class Card
{
    private:
        CardNames name_; // card name
        CardNumbers number_; // card number

    public:

        // Constructor
        Card(CardNames nameOfCard, CardNumbers num);

        // Getters
        CardNames getName() const;
        CardNumbers getNumber() const;
        int getCardValue() const;
        string cardNumberStr() const;
        string cardNameStr() const;   
};