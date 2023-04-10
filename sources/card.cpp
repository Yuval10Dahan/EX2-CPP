#include "card.hpp"
using namespace std;


// Constructor
Card::Card(CardNames nameOfCard, CardNumbers num) : name_(nameOfCard), number_(num){}

// getter method for "name" data member
CardNames Card::getName() const
{
    return this->name_;   
}

// getter method for "number" data member
CardNumbers Card::getNumber() const
{
    return this->number_;
}

// this method return the card number as int(instead of "CardNumbers" return type)
int Card::getCardValue() const
{
    int value = static_cast<int>(this->number_);
    return value;
}

// this method return the card number as string
string Card::cardNumberStr() const
{
    string result;

    int value = getCardValue();

    // if value between 2 and 10 return a regular int(as string)
    if(value >= 2 && value <= 10)
    {
        result = to_string(value);
    }

    // if value between 11 and 14 return the alias of the card number
    if(value == 11) result = "JACK";
    if(value == 12) result = "QUEEN";
    if(value == 13) result = "KING";
    if(value == 14) result = "ACE";

    return result;
}

// this method return the card name as string
string Card::cardNameStr() const
{
    string result;
    
    // cast the card name from CardNames to int
    CardNames cname = this->name_;
    int value = static_cast<int>(cname);

    // return the alias of the card name
    if(value == 0) result = "SPADES";
    if(value == 1) result = "HEARTS";
    if(value == 2) result = "DIAMONDS";
    if(value == 3) result = "CLUBS";

    return result;
}