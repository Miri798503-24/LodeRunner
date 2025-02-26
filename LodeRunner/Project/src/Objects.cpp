#include "Objects.h"
#include "Player.h"
#include "MonsterSmart.h"
#include "MonsterRandomal.h"
#include "MonsterDirection.h"
#include "Wall.h"
#include "Mot.h"
#include "Money.h"
#include "Ladder.h"
#include "Board.h"

Objects::Objects() {}

Objects::Objects(const sf::Vector2f& location, const float& size, const sf::Texture& tex)
{
    m_picture.setPosition(location);
    m_picture.setSize({ size,size });
    m_picture.setTexture(&tex);
}

void Objects::draw(sf::RenderWindow& window)
{
    window.draw(m_picture);
}

void Objects::setLocation(const sf::Vector2f& location)
{
    m_picture.setPosition(location);
}

void Objects::upData(const sf::Vector2f& location, const sf::Vector2i & size, const sf::Texture& tex)
{
    m_picture.setPosition(location);
    m_picture.setSize({float(size.x), float(size.y)});
    m_picture.setTexture(&tex);
}

sf::Vector2f Objects::getLocation()
{
    return m_picture.getPosition();
}

sf::Vector2f Objects::getSizeObject()
{
    return m_picture.getSize();
} 

sf::RectangleShape Objects::getRec()
{
    return m_picture;
}
