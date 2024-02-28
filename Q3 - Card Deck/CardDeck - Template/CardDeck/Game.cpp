// Name: Eliska Vrzalova
// Login: c00301768
// Date: 28/02/2024
// Approx hours of work : 
//---------------------------------------------------------------------------
// A program which creates a deck of cards for a game.
// The program should generate a new card when the down arrow key is pressed.
// The program should display the card suit and face on the screen. 
// ---------------------------------------------------------------------------
// Known Bugs:
// 

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "Game.h"   // include Game header file


int main()
{
	Game game;
	game.loadContent();
	game.run();

	return 0;
}

Game::Game() : window(sf::VideoMode(400, 300), "CardDeck Game")
//  default constructor function
{
}

void Game::loadContent()
// load the font file
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen
}


void Game::run()
// Contains the main game loop
{
	srand(time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

} // end main function


void Game::draw()
// draws/renders the game world
{
	// Clear the screen
	window.clear();

	//Display the card face and suit on the screen
	m_message.setString("The card is : " + aCardDeck.getCardFace()+ " " + aCardDeck.getCardSuit());
	window.draw(m_message);  // write the message on the screen

	window.display();
}

void Game::update()
// handles input in the game
{
	// get keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		 // Generate a new card
		aCardDeck.dealCard();
	}

}


