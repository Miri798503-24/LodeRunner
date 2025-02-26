#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Present :
	public StaticObject {

public:
	Present(const sf::Vector2f& location, const float& size, const sf::Texture& tex);
	Present();
	virtual ~Present() = default;

};