#include "staticObject.h"

StaticObject::StaticObject(const sf::Vector2f& location, const float& size, const sf::Texture& tex) 
	:Objects(location, size, tex) {}

StaticObject::StaticObject()
{
}
