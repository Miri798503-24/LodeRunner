#pragma once
#include <SFML/Graphics.hpp>
#include "Monsters.h"
#include "Present.h"

class MonsterDirection : 
	public Monsters
{
public:
	MonsterDirection();
	~MonsterDirection() = default;
	sf::Vector2f moveMonster(const sf::Vector2f& locPlayer);

	bool handleCollision(Objects& object, Board& board);
	bool handleCollision(Player& object, Board& board);
	bool handleCollision(MonsterSmart& object, Board& board);
	bool handleCollision(MonsterRandomal& object, Board& board);
	bool handleCollision(Wall& object, Board& board);
	bool handleCollision(Mot& object, Board& board);
	bool handleCollision(Money& object, Board& board);
	bool handleCollision(Ladder& object, Board& board);
	bool handleCollision(MonsterDirection& object, Board& board);

	void setD();

private:
	bool m_d;
};