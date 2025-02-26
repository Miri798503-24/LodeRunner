#include "GiftMonster.h"
#include "Board.h"

bool GiftMonster::handleCollision(Objects& object, Board& board)
{
    if (&object == this) return true;

    return object.handleCollision(*this, board);
}

bool GiftMonster::handleCollision(Player& object, Board& board)
{
    board.newMonster({500, 500});
    return false;
}

bool GiftMonster::handleCollision(MonsterSmart& object, Board& board)
{
    return false;
}

bool GiftMonster::handleCollision(MonsterRandomal& object, Board& board)
{
    return false;
}

bool GiftMonster::handleCollision(Wall& object, Board& board)
{
    return false;
}

bool GiftMonster::handleCollision(Mot& object, Board& board)
{
    return false;
}

bool GiftMonster::handleCollision(Money& object, Board& board)
{
    return false;
}

bool GiftMonster::handleCollision(Ladder& object, Board& board)
{
    return false;
}

bool GiftMonster::handleCollision(MonsterDirection& object, Board& board)
{
    return false;
}
