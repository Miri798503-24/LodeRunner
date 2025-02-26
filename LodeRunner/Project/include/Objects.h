#pragma once
#include <SFML/Graphics.hpp>

class Player;
class MonsterSmart;
class MonsterRandomal;
class Wall;
class Mot;
class Money;
class Ladder;
class Board;
class MonsterDirection;

class Objects {
public:
	Objects();
	Objects(const sf::Vector2f& location, const float& size, const sf::Texture& tex);
	
	virtual void draw(sf::RenderWindow& window);
	virtual void setLocation(const sf::Vector2f& location);
	virtual void upData(const sf::Vector2f& location, const sf::Vector2i & size, const sf::Texture& tex);

	virtual bool handleCollision(Objects & object, Board & board) = 0;
	virtual bool handleCollision(Player & object, Board& board) = 0;
	virtual bool handleCollision(MonsterSmart & object, Board& board) = 0;
	virtual bool handleCollision(MonsterRandomal & object, Board& board) = 0;
	virtual bool handleCollision(MonsterDirection & object, Board& board) = 0;
	virtual bool handleCollision(Wall & object, Board& board) = 0;
	virtual bool handleCollision(Mot & object, Board& board) = 0;
	virtual bool handleCollision(Money & object, Board& board) = 0;
	virtual bool handleCollision(Ladder & object, Board& board) = 0;
	
	virtual sf::Vector2f getLocation();
	virtual sf::Vector2f getSizeObject();
	virtual sf::RectangleShape getRec();
	
protected:
	sf::RectangleShape m_picture;
};