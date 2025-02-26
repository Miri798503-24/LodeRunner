#pragma once
#include <SFML/Graphics.hpp>
#include "ResourseManager.h"

class ControllerLevel
{
public:
	ControllerLevel();
	~ControllerLevel();

	bool screenStart(sf::RenderWindow& window, const sf::Font& font, const std::string& headLine);
	bool events(sf::RenderWindow& window);

	int clickButton(sf::RenderWindow& window, sf::Event event);
	
	void draw(sf::RenderWindow& window);
	void setHeadLine(const std::string & HeadLine);

private:
	sf::RectangleShape m_buttonStart;
	sf::RectangleShape m_buttonEnd;

	sf::Text m_textStart;
	sf::Text m_textEnd;
	sf::Text m_headLine;
};

