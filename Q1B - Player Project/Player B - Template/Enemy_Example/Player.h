// Player class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include "Globals.h"   // include Global header file
#include <iostream>

class Player
{
	// the data members are private by default

	sf::Texture texture; // texture for Player
	sf::Sprite sprite;   // sprite used to represent Player

	int speed;   // the speed that the Player moves
	int direction; // is the Player moving north, south, east or west
	int lives;    // the number of lives

	int image_width;
	int image_height;


public:	  // declaration of member functions	

	Player(); // default constructor
	void loadImage(); // load the image 

	sf::Sprite getBody();
	void setPosition();
	void setPosition(int xPos, int yPos);
	void setUpSpeed();

	void moveWest(); // player moves right
	void moveEast(); // player moves left
	void moveSouth(); // player moves down
	void moveNorth(); // player moves up

};
