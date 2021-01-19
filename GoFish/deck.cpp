//
// Created by spoud on 11/3/2020.
//
#include "deck.h"
#include <time.h>

//CONSTRUCTORS

//Create a sorted Deck of 52 Cards
Deck::Deck() {
    //Fill myCards with 52 Cards in order
    int counter = 0;
    for (int suit = 0; suit < 4; suit++) {      //suit counter (0-spades... 3-clubs
        for(int rank = 1; rank <= 13; rank++){  //rank counter
            if(suit == 0){
                myCards.at(counter) = Card(rank, Card::spades);
                counter++;
            }
            else if(suit == 1){
                myCards.at(counter) = Card(rank, Card::hearts);
                counter++;
            }
            else if(suit == 2){
                myCards.at(counter) = Card(rank, Card::diamonds);
                counter++;
            }
            else{
                myCards.at(counter) = Card(rank, Card::clubs);
                counter++;
            }
        }
    }

    //Initialize index
    myIndex = 0; //Dealing 1st card in deck
}

//FUNCTIONS

//Shuffle Deck (always resets deck to 52 cards)
void Deck::shuffle() {
    srand(time(nullptr));

    //Shuffle a full deck of cards (52 cards)
    for(int i = SIZE - 1; i > 0; i--){
        int newIdx = rand() % (i + 1); //new index is rand # from 0 to i (everything after i is already shuffled)

        //Swap i and newIdx
        Card tempCard = myCards.at(i);
        myCards.at(i) = myCards.at(newIdx);
        myCards.at(newIdx) = tempCard;
    }

    myIndex = 0;
}

//Get a Card from Deck and reduce size(fails after 52 cards taken)
Card Deck::dealCard() {
    Card dCard = myCards.at(myIndex);

    myIndex++; //Increment index (new top card)
    return dCard;
}

//Returns # of Cards in Deck
int Deck::size() const {
    return SIZE - myIndex;    //52 total cards - Index = active cards
}



