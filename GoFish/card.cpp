//
// Created by spoud on 11/3/2020.
//
#include "card.h"

//CONSTRUCTORS

//Default (myRank = ace, mySuit = spades)
Card::Card() {
    myRank = 1;
    mySuit = spades;
}

//Overloaded (myRank = rank, mySuit = s)
Card::Card(int rank, Card::Suit s) {
    myRank = rank;
    mySuit = s;
}

//FUNCTIONS

//Returns the string version of Card
string Card::toString() const {
    return rankString(myRank) + suitString(mySuit);
}

//Compares suit of (this) Card with suit of Card c
bool Card::sameSuitAs(const Card &c) const {
    if(mySuit == c.mySuit){
        return true;
    }

    return false;
}

//Return rank of Card (as int)
int Card::getRank() const {
    return myRank;
}

Card::Suit Card::getSuit() const{
    return mySuit;
}

//Return suit s (as string)
string Card::suitString(Card::Suit s) const {
    if(s == spades){
        return "s";
    }
    else if(s == hearts){
        return "h";
    }
    else if(s == diamonds){
        return "d";
    }
    else{
        return "c";
    }
}

//Return rank r (as string)
string Card::rankString(int r) const {
    if(r == 1){
        return "A";
    }
    else if(r >= 2 && r <= 10){
        return std::to_string(r);
    }
    else if(r == 11){
        return "J";
    }
    else if(r == 12){
        return "Q";
    }
    else{
        return "K";
    }

}

//OPERATORS

//Check if rank and suit are ==
bool Card::operator==(const Card &rhs) const {
    if(this->myRank == rhs.myRank && this->mySuit == rhs.mySuit){
        return true;
    }
    else{
        return false;
    }
}

//Check if rank and suit are !=
bool Card::operator!=(const Card &rhs) const {
    if(operator==(rhs)){
        return false;
    }
    else{
        return true;
    }
}

//Overload output stream operator for a Card
ostream& operator << (ostream& out, const Card& c){
    out << c.rankString(c.getRank()) << c.suitString(c.getSuit());;

    return out;
}

