// Dice class declaration
#pragma once

#include "SFML/Graphics.hpp" 


class Dice
{
	// the data members are private by default
	int diceNum;

public:	  // declaration of member functions	
	Dice();  // default constructor
	void rollDice();
	int getDiceNum();
	
};









