#pragma once
#include <SFML/Graphics.hpp>
#include "MoveObject.h"

class Monsters : 
	public MoveObject {
public:
	Monsters();
	~Monsters()= default;
	
	virtual sf::Vector2f moveMonster(const sf::Vector2f& locPlayer) = 0;

	virtual int getDirection();
	virtual int getFall();

	virtual void setFall(const bool& flag);

protected:
	int m_direction;
	bool m_isFall;
};