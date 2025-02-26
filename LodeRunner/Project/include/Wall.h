#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class MonsterDirection;
class Wall :
	public StaticObject
{
public:
	Wall(const sf::Vector2f& location, const float& size, const sf::Texture& tex);
	Wall();
	~Wall();

	bool handleCollision(Objects& object, Board& board);
	bool handleCollision(Player& object, Board& board);
	bool handleCollision(MonsterSmart& object, Board& board);
	bool handleCollision(MonsterRandomal& object, Board& board);
	bool handleCollision(Wall& object, Board& board);
	bool handleCollision(Mot& object, Board& board);
	bool handleCollision(Money& object, Board& board);
	bool handleCollision(Ladder& object, Board& board);
	bool handleCollision(MonsterDirection& object, Board& board);

private:
};

