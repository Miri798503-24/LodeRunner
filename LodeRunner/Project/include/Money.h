#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "MonsterDirection.h"

class Player;
class Money :
	public StaticObject {
public:
	Money();
	~Money() = default;

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