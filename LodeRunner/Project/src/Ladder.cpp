#include "Ladder.h"

Ladder::Ladder(const sf::Vector2f& location, const float& size, const sf::Texture& tex) :StaticObject(location, size, tex)
{
}

Ladder::Ladder() {}

Ladder::~Ladder() {}

bool Ladder::handleCollision(Objects& object, Board& board)
{
    if (&object == this) return true;

    return object.handleCollision(*this, board);
}

bool Ladder::handleCollision(Player& object, Board& board)
{
    return true;
}

bool Ladder::handleCollision(MonsterSmart& object, Board& board)
{
    return true;
}

bool Ladder::handleCollision(MonsterRandomal& object, Board& board)
{
    return true;
}

bool Ladder::handleCollision(Wall& object, Board& board)
{
    return false;
}

bool Ladder::handleCollision(Mot& object, Board& board)
{
    return false;
}

bool Ladder::handleCollision(Money& object, Board& board)
{
    return false;
}

bool Ladder::handleCollision(Ladder& object, Board& board)
{
    return false;
}

bool Ladder::handleCollision(MonsterDirection& object, Board& board)
{
    return false;
}
