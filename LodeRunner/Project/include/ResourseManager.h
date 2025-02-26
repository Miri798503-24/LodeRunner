#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <map>
#include <string.h>

using std::string;

class ResourseManager
{
public:
	~ResourseManager() = default;
	static ResourseManager& instance();

	sf::Texture& getImage(const string& name);
	sf::Font& getFont() const;

	void setvec();

private:
	ResourseManager();
	ResourseManager(const ResourseManager&);
	
	std::map<string, sf::Texture> m_mapPictures;
	std::unique_ptr<sf::Font> m_font;
};