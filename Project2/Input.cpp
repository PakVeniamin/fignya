#include "Engine.h"
void Engine::input()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			// Handle the player quitting
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_Window.close();
			}
			// Handle the player starting the game
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				m_Playing = true;
			}
			// Switch between Thomas and Bob
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				m_Character1 = !m_Character1;
			}
			// Switch between full and split-screen
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				m_SplitScreen = !m_SplitScreen;
			}
		}
	}
	// Handle input specific to Thomas
	if (m_Thomas.handleInput())
	{
		// Play a jump sound
		m_SM.playJump();

	}
	// Handle input specific to Bob
	if (m_Bob.handleInput())
	{
		// Play a jump sound
		m_SM.playJump();
	}
}