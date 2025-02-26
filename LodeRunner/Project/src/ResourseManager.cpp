#include "ResourseManager.h"

ResourseManager::ResourseManager()
{
	setvec();
}

ResourseManager& ResourseManager::instance()
{
	static ResourseManager insta;
	return insta;
}

void ResourseManager::setvec()
{
	//לטעון את כל התמונות	
	sf::Texture a, b, c, d, e, f, g;
	a.loadFromFile("wall.jpg");
	m_mapPictures.insert(std::pair<string, sf::Texture>("wall", a));
	b.loadFromFile("mot.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("mot", b));
	c.loadFromFile("ladder.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("ladder", c));
	d.loadFromFile("player.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("player", d));
	e.loadFromFile("monster.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("monster", e));
	f.loadFromFile("money.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("money", f));
	g.loadFromFile("present.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("present", g));
	
	m_font = (std::make_unique<sf::Font>());
	m_font->loadFromFile("COOPBL.TTF");
}

sf::Texture& ResourseManager::getImage(const string& name)
{
	return m_mapPictures[name];
}

sf::Font& ResourseManager::getFont() const
{
	return *m_font;
}

