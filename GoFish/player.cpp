//
// Created by spoud on 11/3/2020.
//
#include "player.h"

//CONSTRUCTORS

Player::Player() {
    myName = "???";
}


//FUNCTIONS

//Add card to player's hand
void Player::addCard(Card c) {
    myHand.push_back(c);
}

//Book cards into player's book
void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}


/*checkHandForBook
//  this function will check a players hand for a pair.
//  If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
*/
bool Player::checkHandForBook(Card &c1, Card &c2) {
    for(auto card1 : myHand){
        for(auto card2 : myHand){
            //Check if rank is same (but not the same card)
            if(card1.getRank() == card2.getRank() && !(card1.sameSuitAs(card2))){
                //Found pair
                c1 = card1;
                c2 = card2;
                return true;
            }
        }
    }
    //No pair found
    return false;
}

//rankInHand
//  Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const {
    int rank = c.getRank();

    //Look for same rank in hand
    for(auto current : myHand){
        if(current.getRank() == rank){
            return true;
        }
    }
    //No match
    return false;
}

/*chooseCardFromHand
 *  Choose one card from the player's hand
 *  so they can say "Do you have a 4?"
 */
Card Player::chooseCardFromHand() const {
    srand(time(nullptr));
    //Pick random index to choose from
    int picked = rand() % myHand.size();

    return myHand.at(picked);
}

/*cardInHand
 *  Does the player have the card c in her hand?
 */
bool Player::cardInHand(Card c) const {
    for(auto current : myHand){
        if(current == c){
            return true;
        }
    }
    //No Match
    return false;
}

/*removeCardFromHand
 *Remove the card c from the hand and return it to the caller
 */
Card Player::removeCardFromHand(Card c) {
    //Move through myHand looking for match
    for(int i = 0; i < (int) myHand.size(); i++){
        if(myHand.at(i) == c){
            myHand.erase(myHand.begin() + i);
            return c;  //Successfully removed
        }
    }
    return c;
}

/*showHand
 *Returns current Cards from hand as a string
 */
string Player::showHand() const {
    string handStr;
    for(auto pCard : myHand){
        handStr += pCard.toString();
        handStr += " ";
    }
    return handStr;
}

/*showBooks
 *Returns current Books from hand as a string
 */
string Player::showBooks() const {
    string bookStr;
    for(auto bCard : myBook){
        bookStr += bCard.toString();
        bookStr += " ";
    }
    return bookStr;
}

/*getHandSize
 *Return current hand size as int
 */
int Player::getHandSize() const {
    return myHand.size();
}

/*getBookSize
 *Return current book size as int
 */
int Player::getBookSize() const {
    return myBook.size();
}

/*checkHandForPair
//  this function will check a players hand for a pair.
//  If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
*/
bool Player::checkHandForPair(Card &c1, Card &c2) {
    for(auto card1 : myHand){
        for(auto card2 : myHand){
            //Check if rank is same (but not the same card)
            if(card1.getRank() == card2.getRank() && !(card1.sameSuitAs(card2))){
                //Found pair
                c1 = card1;
                c2 = card2;
                return true;
            }
        }
    }
    //No pair found
    return false;
}

/*
 *
 */
bool Player::sameRankInHand(Card c) const {
    int rank = c.getRank();

    //Look for same rank in hand
    for(auto current : myHand){
        if(current.getRank() == rank){
            return true;
        }
    }
    //No match
    return false;
}


Card Player::findRankInHand(int rank) {

    for(auto current : myHand){
        if(current.getRank() == rank){
            return current;
        }
    }

    return {};
}
