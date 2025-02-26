#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "ResourseManager.h"
#include "Wall.h"
#include "Mot.h"
#include "Ladder.h"
#include "Objects.h"
#include "StaticObject.h"
#include "MoveObject.h"
#include "Player.h"
#include "ResourseManager.h"
#include "Monsters.h"
#include "MonsterRandomal.h"
#include "MonsterSmart.h"
#include "MonsterDirection.h"
#include "Money.h"
#include "Present.h"
#include "GiftLife.h"
#include "GiftMoney.h"
#include "GiftMonster.h"

class Board {
public:
	Board();
	~Board() = default;
	
	void deleteLevel(); //במעבר בין שלבים מוחקים את כל הוקטורים  על ידי פונקצית clear
	void draw(sf::RenderWindow& window);
	void drawMenu(sf::RenderWindow& window);
	void moveObjects(sf::RenderWindow& window);
	void setLimitsBoard();
	void calculation(const int& numCell);
	void newMonster(const sf::Vector2f& loc);
	void newMoney(const sf::Vector2f& loc);
	void newGift(const sf::Vector2f& loc);
	void movePlayer(sf::RenderWindow& window);
	void moveMonster(sf::RenderWindow& window);
	void addScore(const int& score);
	void setDatasMenu();
	void setText(sf::Text & text,const sf::Vector2f & position, const string & textData);
	void setMBoardTXT();
	void restartBoard();
	
	bool readFromFile();
	bool Max();
	bool handleCollisions(Objects & object, sf::Vector2f& loc, const bool& isPlayer);
	bool isCollisions(const sf::Vector2f& newLoc, Objects& objectB, Objects& objectC);
	bool isFailure();

	int getLevel() const;

	string getS();

	sf::Font& getFont() const;

protected:
	std::vector<std::unique_ptr<StaticObject>> m_staticBoard;
	std::vector<std::unique_ptr<Monsters>> m_vectorMonsters;
	std::vector<std::unique_ptr<Present>> m_vectorGift;
	std::vector<std::unique_ptr<Money>> m_vectorMoney;

	Player m_player;

	int m_score;
	int m_starsOfBoard;
	int m_row;
	int m_col;
	int m_stopper;
	int m_sizeCell;
	int m_level;

	string m_s;

	std::ifstream m_boardTXT;
	sf::RectangleShape m_rectangle;
	sf::Vector2f m_locationBoard;

	sf::Text m_textTime;
	sf::Text m_textTimeData;
	sf::Text m_textLevel;
	sf::Text m_textLevelData;
	sf::Text m_textLife;
	sf::Text m_textLifeData;
	sf::Text m_textScore;
	sf::Text m_textScoreData;
};