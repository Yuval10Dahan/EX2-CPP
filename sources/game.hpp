#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "player.hpp"
#include "deck.hpp"

using namespace std;

namespace ariel{}

// struct that contains a card and other information, the struct added to the pile
typedef struct Element
{
    Card card;
    bool needed; // flag to indicate if a card is crucial for printing, true if it is
    string name;
    bool printDraw; // flag to indicate if there a need to print draw in the printLastTurn method, true if it is
}Element;

class Game 
{
    private:
        Player &one_; // data member of the first player that gets a reference to a Player object
        Player &two_; // data member of the second player that gets a reference to a Player object
        Deck gameDeck_; // the game initial Deck of cards
        string winnerName_; // name of the current turn winner

        // vector that contains all the used cards by the players,
        // with a printing flag, name of player and draw flag
        vector<Element> pile_;

        // vector that contains all the printed turns
        vector<string> turnsData_;
        
 

    public:

        // Constructor
        Game(Player &pl1, Player &pl2); // *** didn't used const because there were issues with it

          
        // getter methods for the data members
        Player& getOne();
        Player& getTwo();
        std::string getWinnerName() const;
        
        


        // other methods
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();   
        int betterCard(const Card &card1, const Card &card2); 
        string turnStr(vector<Element> &pile);
};