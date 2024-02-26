// Player class

#include "Player.h"   // include Player header file


// Definition of member functions of the Player class


Player::Player() // default constructor
{
	loadImage(); // load the image file for the sprite

	image_width = 124; // the width of the image in pixels
	scaled = false; // the image is not scaled

	int xPos = SCREEN_WIDTH/2;        // place the player object in the centre of the screen
	int yPos = SCREEN_HEIGHT/2;
	setPosition(xPos, yPos);  // set the position of the players sprite

	speed = 5; // the average speed
	direction = (rand() % 2) + 1;        // Generates a random number between 1 and 2
	lives = 3;
}

void Player::loadImage()
// Loads the image for the player object
{
	if (!texture.loadFromFile("ASSETS/IMAGES/SquareGuy.bmp"))
	{
		std::cout << "error with player image file";
	}

	sprite.setTexture(texture);
}



sf::Sprite Player::getBody() // get the player's body
{
	return sprite;
}


void Player::setPosition()  // set the position of the player on the screen
{
	sprite.setPosition(200, 40);
}


void Player::setPosition(int xPos, int yPos)  // set the position of the player on the screen
{
	sprite.setPosition(xPos, yPos);
}

void Player::move()
{
	sf::Vector2f movement(sprite.getPosition());


	if (direction == WEST) //left
	{
		movement.x = movement.x - speed;
		if (movement.x <= 0)
		{
			direction = EAST;
		}
	}
	else if (direction == EAST) // right
	{
		movement.x = movement.x + speed;
		if (movement.x + image_width >= SCREEN_WIDTH)
		{
			direction = WEST;
		}
	}
	sprite.setPosition(movement);
}

void Player::increaseSpeed()
{
	if (speed <= 15)
	{
		speed++;
	}
}

void Player::decreaseSpeed()
{
	if (speed > 1)
	{
		speed--;
	}
}




