// Name: 
// Login: 
// Date: 
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project description: Project containing menu buttons - TEMPLATE
// ---------------------------------------------------------------------------
// Known Bugs:
// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "Game.h"



int main()
{ 
	Game game; 
	game.run(); 
}

 
/// <summary>
/// main game constructor creating the render window with settings
/// </summary>
Game::Game() : m_Window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Project with Menu Buttons",sf::Style::Default)
{			
	gameMode = 1;
	loadContent();
	m_Window.setKeyRepeatEnabled(false);
}

/// <summary>
/// load the font and initialise everything else.
/// </summary>
void Game::loadContent()
{
	if (!m_ariblkFont.loadFromFile("ASSETS/FONTS/ariblk.ttf"))
	{
		std::cout << "error with font file file";
	}

	m_message.setFont(m_ariblkFont);  // set the font for the text
	m_message.setCharacterSize(22);
	m_message.setFillColor(sf::Color::White);
	m_message.setPosition(50, 100);
	m_mainMenu.initialise(m_ariblkFont);
}

/// <summary>
/// main game loop.
/// </summary>
void Game::run()
{
	srand(time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (m_Window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (m_Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_Window.close();
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

}

/// <summary>
/// call the update function corresponding to the current game mode
/// </summary>
void Game::update()
{
	if (gameMode == MENU)
	{
		m_mainMenu.update(m_Window, gameMode);
	}
	else if (gameMode == INSTRUCTIONS)
	{
		gameInstructions();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			gameMode = MENU; // go back to the menu if escape is pressed
		}
	}
	else if (gameMode == GAME_PLAY)
	{
		m_message.setString("Game Play");

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			gameMode = MENU; // go back to the menu if escape is pressed
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			myPlayer.increaseSpeed();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			myPlayer.decreaseSpeed();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			myPlayer.increaseSize();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) // key pressed
		{
			if (canChangeColor == true)
			{
				myPlayer.changeColor();
				canChangeColor = false;
			}
		}
		else // key released
		{
			canChangeColor = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // key pressed
		{
			if (canChangeDirection == true)
			{
				myPlayer.changeDirection();
				canChangeDirection = false;
			}
		}
		else // key released
		{
			canChangeDirection = true;
		}
		myPlayer.move();
	}
}

/// <summary>
/// call the draw function for the current game mode
/// </summary>
void Game::draw()
{
	m_Window.clear();

	if (gameMode == MENU)
	{
		m_mainMenu.draw(m_Window);
	}
	else if (gameMode == INSTRUCTIONS)
	{
		m_Window.draw(m_message);
	}
	else if (gameMode == GAME_PLAY)
	{
		m_Window.draw(m_message);
		m_Window.draw(myPlayer.getBody());
	}

	m_Window.display();
}

/// <summary>
/// Setup game instructions here
/// </summary>
void Game::gameInstructions()
{
	m_message.setString("Press the 'f' key on the keyboard, the player's movement speed should increase by 1.\nPress the 's' key on the keyboard, the player's movement speed should decrease by 1.\nPress the 'i' key on the keyboard to increase the size of the player.This occurs only once. \nPress the 'c' key on the keyboard to change the colour of the player. \nPress the 'd' key on the keyboard to change the direction of the player.");
}