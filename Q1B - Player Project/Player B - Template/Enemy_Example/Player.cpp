// Player class

#include "Player.h"   // include Player header file


// Definition of member functions of the Player class


Player::Player() // default constructor
{
	loadImage(); // load the image file for the sprite
	setPosition(300, 200);  // set the position of the Player 

	speed = 1; // the average speed
	direction = (rand() % 4) + 1;     // Generates a random number between 1 - 4
	lives = 3;

	image_height = 96;
	image_width = 124;
}

void Player::loadImage()
// Loads the image for the Player object
{
	if (!texture.loadFromFile("ASSETS/IMAGES/SquareGuy.bmp"))
	{
		std::cout << "error with player image file";
	}

	sprite.setTexture(texture);
}


sf::Sprite Player::getBody() // get the Player's body
{
	return sprite;
}


void Player::setPosition()  // set the position of the Player on the screen
{
	sprite.setPosition(300, 200);
}


void Player::setPosition(int xPos, int yPos)  // set the position of the Player on the screen
{
	sprite.setPosition(xPos, yPos);
}

void Player::setUpSpeed()
{
	speed = speed + 2;
}

void Player::moveWest()
{
	sf::Vector2f pos(sprite.getPosition());

	if (pos.x + image_width < SCREEN_WIDTH)
	{
		pos.x += speed;;
		direction = WEST;
	}
	sprite.setPosition(pos);
}

void Player::moveEast()
{
	sf::Vector2f pos(sprite.getPosition());

	if (pos.x > 0)
	{
		pos.x -=speed;
		direction = EAST;
	}
	sprite.setPosition(pos);
}

void Player::moveSouth()
{
	sf::Vector2f pos(sprite.getPosition());

	if (pos.y + image_height < SCREEN_HEIGHT)
	{
		pos.y += speed;
		direction = SOUTH;
	}
	sprite.setPosition(pos);
}

void Player::moveNorth()
{
	sf::Vector2f pos(sprite.getPosition());
	if (pos.y > 0)
	{
		pos.y -= speed;
		direction = NORTH;
	}
	sprite.setPosition(pos);
}

