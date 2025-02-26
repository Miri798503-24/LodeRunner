#include "Money.h"
#include "Player.h"

Money::Money()
{
}

bool Money::handleCollision(Objects& object, Board& board)
{
    if (&object == this) return true;

    return object.handleCollision(*this, board);
}

bool Money::handleCollision(Player& object, Board& board)
{
    return object.handleCollision(*this, board);
}

bool Money::handleCollision(MonsterSmart& object, Board& board)
{
    return true;
}

bool Money::handleCollision(MonsterRandomal& object, Board& board)
{
    return true;
}

bool Money::handleCollision(Wall& object, Board& board)
{
    return false;
}

bool Money::handleCollision(Mot& object, Board& board)
{
    return false;
}

bool Money::handleCollision(Money& object, Board& board)
{
    return false;
}

bool Money::handleCollision(Ladder& object, Board& board)
{
    return false;
}

bool Money::handleCollision(MonsterDirection& object, Board& board)
{
    return false;
}
