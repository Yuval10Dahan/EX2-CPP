#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "card.hpp"

using namespace std;

 
class Player
{
    private:
        string name_; // name of the player
        vector<Card> stackOfCards_; // vector that contains the player own deck of cards
        int wonCards_; // number of cards the player won
        int numOfDraws_; // number of draws the player had
         

    public:

        // Constructor 
        Player(const string &Pname);

        // getter methods for the data members
        string getPName() const;
        int stacksize() const;
        int cardesTaken() const;
        int getNumOfDraws() const;
        // vector<Card>& getPlayerStack();

        // setter methods for the data members
        void increaseWonCards(int);
        void increaseNumOfDraws();

        // void resetWonCards();
        // void resetnumOfDraws();
        
        // stats methods
        double winRate();
        double drawRate();
        void printPlayerStats();

        // other methods
        void addCard(const Card& card);
        Card& useCard();
        void removeCard(); 
};