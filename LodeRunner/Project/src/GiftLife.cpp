#include "GiftLife.h"
#include "Player.h"
#include "MonsterDirection.h"

bool GiftLife::handleCollision(Objects& object, Board& board)
{
	if (&object == this) return true;

	return object.handleCollision(*this, board);
}

bool GiftLife::handleCollision(Player& object, Board& board)
{
	object.setLife(1);
	return false;
}

bool GiftLife::handleCollision(MonsterSmart& object, Board& board)
{
	return false;
}

bool GiftLife::handleCollision(MonsterRandomal& object, Board& board)
{
	return false;
}

bool GiftLife::handleCollision(Wall& object, Board& board)
{
	return false;
}

bool GiftLife::handleCollision(Mot& object, Board& board)
{
	return false;
}

bool GiftLife::handleCollision(Money& object, Board& board)
{
	return false;
}

bool GiftLife::handleCollision(Ladder& object, Board& board)
{
	return false;
}

bool GiftLife::handleCollision(MonsterDirection& object, Board& board)
{
	return false;
}
