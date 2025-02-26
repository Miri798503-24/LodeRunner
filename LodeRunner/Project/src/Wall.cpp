#include "Wall.h"
#include "Player.h"
#include "MonsterSmart.h"
#include "MonsterRandomal.h"
#include "MonsterDirection.h"

Wall::Wall(const sf::Vector2f& location, const float& size, const sf::Texture& tex) :StaticObject(location, size, tex) {}

Wall::Wall() {}

Wall::~Wall() {}

bool Wall::handleCollision(Objects& object, Board& board)
{
    if (&object == this) return true;

    return object.handleCollision(*this, board);
}

bool Wall::handleCollision(Player& object, Board& board)
{
    if (object.getIsFall())
        object.setLocation({ object.getLocation().x, object.getLocation().y - 2 });

    object.setIsFall(false);
    return false;
}

bool Wall::handleCollision(MonsterSmart& object, Board& board)
{
    if (object.getFall())
        object.setLocation({ object.getLocation().x, object.getLocation().y - 2 });
   
    object.setFall(false);
    return false;
}

bool Wall::handleCollision(MonsterRandomal& object, Board& board)
{
    if (object.getFall())
        object.setLocation({ object.getLocation().x, object.getLocation().y - 2 });

    object.setFall(false);
    return false;
}

bool Wall::handleCollision(Wall& object, Board& board)
{
    return false;
}

bool Wall::handleCollision(Mot& object, Board& board)
{
    return false;
}

bool Wall::handleCollision(Money& object, Board& board)
{
    return false;
}

bool Wall::handleCollision(Ladder& object, Board& board)
{
    return false;
}

bool Wall::handleCollision(MonsterDirection& object, Board& board)
{
    object.setD();
    return false;
}
