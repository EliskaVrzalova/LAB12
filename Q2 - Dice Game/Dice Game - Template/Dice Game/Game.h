// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 

#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Dice.h"   // include Dice header file

class Game
{
	// data members of the Game class (private by default)
	Dice gameDice; // variable to store the new Dice object 
	sf::RenderWindow window;  // main game window

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

public:	  // declaration of member functions
	Game(); //  default constructor function
	void	loadContent();
	void	run();
	void	update(); // handles input in the game
	void	draw(); // draws/renders the game world
}; 
