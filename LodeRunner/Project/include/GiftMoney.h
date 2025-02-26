#pragma once
#include <SFML/Graphics.hpp>
#include "Present.h"
#include "MonsterDirection.h"

class GiftMoney : 
	public Present {

public:
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