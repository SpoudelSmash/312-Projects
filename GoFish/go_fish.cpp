//goFish_driver.cpp
//Driver for a simulated game of Go Fish, puts game results in goFish_results.txt

#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


void dealHand(Deck &d, Player &p, int numCards);

int totalBooks(Player &p1, Player &p2);

void checkPairs(Player &p);

ofstream results;


int main() {
    //Open files
    results.open("gofish_results.txt");
    if(!(results.is_open())){
        cout << "ERROR: could not open gofish_results.txt";
        return EXIT_FAILURE;
    }

    //Initialize game
    Deck mainD;

    Player p1("Annie");
    Player p2("Rocko");

    int numPlayers = 2;

    int startingHand;
    if(numPlayers > 2){
        startingHand = 5;
    }
    else{
        startingHand = 7;
    }

    mainD.shuffle();


    //Decide who goes first (by drawing)
    Card p1Draw = mainD.dealCard();
    Card p2Draw = mainD.dealCard();

    //cout << p1.getName() << "'s draw: " << p1Draw << endl;
    results << p1.getName() << "'s draw: " << p1Draw << endl;
    //cout << p2.getName() << "'s draw: " << p2Draw << endl;
    results << p2.getName() << "'s draw: " << p2Draw << endl;

    Player *currentP;
    Player *nextP;

    if(p1Draw.getRank() < p2Draw.getRank()){
        currentP = &p1;
        nextP = &p2;

        //cout << p1.getName() << " had the lowest draw. They go first." << endl;
        results << p1.getName() << " had the lowest draw. They go first." << endl;
    }
    else{
        currentP = &p2;
        nextP = &p1;

        //cout << p2.getName() << " had the lowest draw. They go first." << endl;
        results << p2.getName() << " had the lowest draw. They go first." << endl;
    }

    mainD.shuffle();    //Reset deck


    //Deal cards
    dealHand(mainD, p1, startingHand);
    dealHand(mainD, p2, startingHand);

    //cout << endl << "Dealing each player " << startingHand << " cards..." << endl;
    results << endl << "Dealing each player " << startingHand << " cards..." << endl;

    //Show starting hand
    //cout << p1.getName() <<" starts with : " << p1.showHand() << endl;
    results << p1.getName() <<" starts with : " << p1.showHand() << endl;
    //cout << p2.getName() <<" starts with : " << p2.showHand() << endl;
    results << p2.getName() <<" starts with : " << p2.showHand() << endl;

    //Pre-Game
    //cout << endl << "Checking for pairs..." << endl;
    results << endl << "Checking for pairs..." << endl;

    checkPairs(p1);
    checkPairs(p2);


    //cout << endl << "GAME START!!!" << endl;
    results << endl << "GAME START!!!" << endl;

    //Gameplay
    //while(mainD.size() || currentP->getHandSize()){
    while(totalBooks(p1, p2) < 52){

        //cout << currentP->getName() << "'s turn:" << endl;

        if(currentP->getHandSize() > 0){
            //Decide what to ask for
            Card ask;
            ask = currentP->chooseCardFromHand();

            //cout << currentP->getName() << " asks for a " << ask.rankString(ask.getRank()) << endl;
            results << currentP->getName() << " asks for a " << ask.rankString(ask.getRank()) << endl;

            //cout << nextP->getName() << " says - ";
            results << nextP->getName() << " says - ";

            //Next player checks hand for asked Card
            if(nextP->rankInHand(ask)){
                //cout << "Yes, I have a " << ask.rankString(ask.getRank()) << endl;
                results << "Yes, I have a " << ask.rankString(ask.getRank()) << endl;

                //Trade card
                Card trade = nextP->findRankInHand(ask.getRank());
                nextP->removeCardFromHand(trade);
                currentP->addCard(trade);

            }


            else{
                //cout << "Go Fish " << endl;
                results << "Go Fish " << endl;

                //Draw a card (go fish)
                currentP->addCard(mainD.dealCard());

            }


        }
        else{
            //Draw a card (empty hand)
            currentP->addCard(mainD.dealCard());
            //cout << currentP->getName() << "'s hand is empty! They draw 1 card" << endl;
            results << currentP->getName() << "'s hand is empty! They draw 1 card" << endl;
        }

        //Check for pairs after turn
        checkPairs(*currentP);

        //New hand
        //cout << currentP->getName() <<"'s hand: " << currentP->showHand() << endl;
        results << currentP->getName() <<"'s hand: " << currentP->showHand() << endl;

        //Next player (code only works with 2 players)
        auto temp = currentP;

        currentP = nextP;
        nextP = temp;

        //cout << endl;
        results << endl;
    }



    //cout << endl << "The deck is empty, deciding winner..." << endl;
    results << endl << "The deck is empty, deciding winner..." << endl;
    //Final check
    checkPairs(p1);
    checkPairs(p2);

    //cout << endl << "And the winner is..." << endl;
    results << endl << "And the winner is..." << endl;

    if(p1.getBookSize() == p2.getBookSize()){
        //cout << "It's a tie! Each player had " << p1.getBookSize() / 2 << " pairs." << endl << endl;
        results << "It's a tie! Each player had " << p1.getBookSize() / 2<< " pairs." << endl << endl;
    }
    else if(p1.getBookSize() < p2.getBookSize()){
        //cout << p2.getName() << "!!! with " << p2.getBookSize() / 2 << " pairs." << endl << endl;
        results << p2.getName() << "!!! with " << p2.getBookSize() / 2 << " pairs." << endl << endl;

    }
    else{
        //cout << p1.getName() << "!!! with " << p1.getBookSize() / 2 << " pairs." << endl << endl;
        results << p1.getName() << "!!! with " << p1.getBookSize() / 2 << " pairs." << endl << endl;
    }

    //cout << p1.getName() << " booked: " << p1.showBooks() << endl;
    results << p1.getName() << " booked: " << p1.showBooks() << endl;
    //cout << p2.getName() << " booked: " << p2.showBooks() << endl;
    results << p2.getName() << " booked: " << p2.showBooks() << endl;


    results.close();
    cout << endl << "Game results stored in gofish_results.txt" << endl;
    return EXIT_SUCCESS;

}





//METHODS
//Deal cards (for starting hand)
void dealHand(Deck &d, Player &p, int numCards){

    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());


}

//Count total books
int totalBooks(Player &p1, Player &p2){
    return p1.getBookSize() + p2.getBookSize();
}



//Check hand for pairs
void checkPairs(Player &p){
    Card pair1;
    Card pair2;

    while(p.checkHandForBook(pair1, pair2)){
        p.removeCardFromHand(pair1);
        p.removeCardFromHand(pair2);

        //cout << p.getName() << " books " <<  pair1.rankString(pair1.getRank()) << endl;
        results << p.getName() << " books " <<  pair1.rankString(pair1.getRank()) << endl;

        p.bookCards(pair1, pair2);
    }

}

