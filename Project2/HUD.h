#pragma once
#include <SFML/Graphics.hpp>
class Hud
{
private:
	sf::Font m_Font;
	sf::Text m_StartText;
	sf::Text m_TimeText;
	sf::Text m_LevelText;
public:
	Hud();
	sf::Text getMessage();
	sf::Text getLevel();
	sf::Text getTime();
	void setLevel(sf::String text);
	void setTime(sf::String text);
};
