#include "GiftMoney.h"
#include "Player.h"
#include "Board.h"

bool GiftMoney::handleCollision(Objects& object, Board& board)
{
	if (&object == this) 
		return true;

	return object.handleCollision(*this,board);
}

bool GiftMoney::handleCollision(Player& object, Board& board)
{
	board.addScore(2 * board.getLevel());
	return false;
}

bool GiftMoney::handleCollision(MonsterSmart& object, Board& board)
{
	return false;
}

bool GiftMoney::handleCollision(MonsterRandomal& object, Board& board)
{
	return false;
}

bool GiftMoney::handleCollision(Wall& object, Board& board)
{
	return false;
}

bool GiftMoney::handleCollision(Mot& object, Board& board)
{
	return false;
}

bool GiftMoney::handleCollision(Money& object, Board& board)
{
	return false;
}

bool GiftMoney::handleCollision(Ladder& object, Board& board)
{
	return false;
}

bool GiftMoney::handleCollision(MonsterDirection& object, Board& board)
{
	return false;
}
