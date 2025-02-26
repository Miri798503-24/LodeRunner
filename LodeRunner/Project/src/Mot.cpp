#include "Mot.h"
#include "Player.h"
#include "MonsterSmart.h"
#include "MonsterRandomal.h"
#include "MonsterDirection.h"

Mot::Mot(const sf::Vector2f& location, const float& size, const sf::Texture& tex) :StaticObject(location, size, tex)
{
}

Mot::Mot() {}

bool Mot::handleCollision(Objects& object, Board& board)
{
    if (&object == this) return true;
   
    return object.handleCollision(*this, board);
}

bool Mot::handleCollision(Player& object, Board& board)
{
    if (object.getDirection() != 0 && object.getDirection() != 3)
    {
        if (object.getDirection() == 4)
            object.setIsFall(true);
    
        return true;
    } 
   
    return false;
}

bool Mot::handleCollision(MonsterSmart& object, Board& board)
{
    if (object.getDirection() != 4)
    {
        if (object.getDirection() == 3)
           object.setFall(true);

        return true;
    }
    return false;
}

bool Mot::handleCollision(MonsterRandomal& object, Board& board)
{
    if (object.getDirection() != 4)
    {
        if (object.getDirection() == 3)
            object.setFall(true);

            return true;
    }

    return false;
}

bool Mot::handleCollision(Wall& object, Board& board)
{
    return true;
}

bool Mot::handleCollision(Mot& object, Board& board)
{
    return true;
}

bool Mot::handleCollision(Money& object, Board& board)
{
    return true;
}

bool Mot::handleCollision(Ladder& object, Board& board)
{
    return true;
}

bool Mot::handleCollision(MonsterDirection& object, Board& board)
{
    return false;
}
