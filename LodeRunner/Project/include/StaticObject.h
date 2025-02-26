#pragma once
#include <SFML/Graphics.hpp>
#include "Objects.h"

class StaticObject :
	public Objects 
{
public:
	StaticObject(const sf::Vector2f& location, const float& size, const sf::Texture& tex);
	StaticObject();
	~StaticObject() = default;
protected:	
};