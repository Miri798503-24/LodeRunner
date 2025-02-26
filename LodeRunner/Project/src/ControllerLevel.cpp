#include "ControllerLevel.h"

ControllerLevel::ControllerLevel()
{
	m_buttonStart.setPosition({ 200,400 });
	m_buttonStart.setSize({600, 100});
	m_buttonStart.setFillColor(sf::Color::Green);

	m_textStart.setString("play");
	m_textStart.setCharacterSize(70);
	m_textStart.setPosition({ 430 ,400 });
	m_textStart.setColor(sf::Color::Black);

	m_buttonEnd.setPosition({ 200,550 });
	m_buttonEnd.setSize({ 600, 100 });
	m_buttonEnd.setFillColor(sf::Color::Red);

	m_textEnd.setString("exit");
	m_textEnd.setCharacterSize(70);
	m_textEnd.setPosition({ 430 ,550 });
	m_textEnd.setColor(sf::Color::Black);

	m_headLine.setPosition({100 , 100});
	m_headLine.setCharacterSize(90);
	m_headLine.setColor(sf::Color::Black);
}

ControllerLevel::~ControllerLevel() {}

bool ControllerLevel::screenStart(sf::RenderWindow& window, const sf::Font& font, const std::string & headLine)
{
	m_textStart.setFont(font);
	m_textEnd.setFont(font);
	m_headLine.setFont(font);
	setHeadLine(headLine);

	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		if (events(window))
			return true;

		draw(window);
		window.display();
	}
	
	return false;
}

bool ControllerLevel::events(sf::RenderWindow& window)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(EXIT_SUCCESS);
			break;

		case sf::Event::MouseButtonPressed:
			if (clickButton(window, event) == 0)
			{
				window.close();
				exit(EXIT_SUCCESS);
				return false;
			}
			
			if (clickButton(window, event) == 1)
				return true;
			break;
		}
	}
	
	return false;
}

int ControllerLevel::clickButton(sf::RenderWindow& window, sf::Event event)
{
	if (m_buttonStart.getGlobalBounds().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
		return 1;

	if (m_buttonEnd.getGlobalBounds().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
		return 0;

	return 2;
}


void ControllerLevel::draw(sf::RenderWindow& window)
{
	window.draw(m_headLine);

	window.draw(m_buttonStart);
	window.draw(m_textStart);
	
	window.draw(m_buttonEnd);
	window.draw(m_textEnd);
}

void ControllerLevel::setHeadLine(const std::string& headLine)
{
	m_headLine.setString(headLine);
}
