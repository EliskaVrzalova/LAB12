// CardDeck class declaration
#pragma once

#include "SFML/Graphics.hpp"  // Headers for SFML projects

class CardDeck
{
	// the data members are private by default
	std::string cardSuit; // the suit of the card eg Hearts, Spades etc
	std::string cardFace; // the number of the card eg Ace, 3, Queen etc

public:	  // declaration of member functions	
	  // default constructor
	void dealCard();  // Randomly generate a new card
	
	// Get functions
	std::string getCardSuit(); // this function should ONLY return the cardSuit
	std::string getCardFace(); // this function should ONLY return the cardFace
};









