#include "MoveObject.h"

MoveObject::MoveObject(const sf::Vector2f& location, const float& size, const sf::Texture& tex) :Objects(location, size, tex) {}

MoveObject::~MoveObject()
{
}