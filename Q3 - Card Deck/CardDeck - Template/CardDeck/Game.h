// Game class declaration
#pragma once

#include "SFML/Graphics.hpp"  // Headers for SFML projects
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "CardDeck.h"   // include CardDeck header file

class Game
{
	// private data members
	CardDeck aCardDeck;  // variable to store the new card deck object
	sf::RenderWindow window; // main game window

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

public:	  // declaration of member functions
	Game(); //  default constructor function
	void	loadContent();
	void	run();
	void	draw(); // draws/renders the game world
	void	update(); // handles input in the game
};
