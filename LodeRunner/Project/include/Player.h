#pragma once
#include <SFML/Graphics.hpp>
#include "MoveObject.h"

class Board;
class Player : 
	public MoveObject 
{
public:
	Player(const sf::Vector2f& location, const float& size, const sf::Texture& tex);
	Player();
	~Player() = default;

	bool handleCollision(Objects& object, Board & board);
	bool handleCollision(Player& object, Board& board);
	bool handleCollision(MonsterSmart & object, Board& board);
	bool handleCollision(MonsterRandomal& object, Board& board);
	bool handleCollision(Wall& object, Board& board);
	bool handleCollision(Mot& object, Board& board);
	bool handleCollision(Money& object, Board& board);
	bool handleCollision(Ladder& object, Board& board);
	bool handleCollision(MonsterDirection& object, Board& board);
	bool getIsFall() const;

	void setIsFall(const bool& f);
	void setLife(const int & num);

	int getDirection() const;
	int getLife() const;
	
	sf::Vector2f movePlayer(sf::RenderWindow& window);

private:
	int m_life;
	int m_direction;

	bool m_isFall;
};

