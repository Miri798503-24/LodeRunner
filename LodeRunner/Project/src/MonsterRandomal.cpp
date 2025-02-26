#include "MonsterRandomal.h"
#include "Player.h"
#include "Board.h"
#include "MonsterDirection.h"

MonsterRandomal::MonsterRandomal() { m_direction = 0; m_numSteps = 0; m_isFall = false;}

sf:: Vector2f MonsterRandomal::moveMonster(const sf::Vector2f& locPlayer)
{
	if (m_numSteps == 0)
	{
		m_direction = rand() % 4 + 1;
		m_numSteps = rand() % 150 + 140;
	}

	sf::Vector2f loc = getLocation();
	sf::Vector2f newLoc;
	         
	switch (m_direction)
	{
	case 1:
		newLoc = { loc.x - 0.3f, loc.y };
		break;

	case 2:
		newLoc = { loc.x + 0.3f , loc.y };
		break;

	case 3:
		newLoc = { loc.x , loc.y - 0.3f };
		break;

	default:
		newLoc = { loc.x , loc.y + 0.3f };
		break;
	}

	m_numSteps--;
	return newLoc;
}

bool MonsterRandomal::handleCollision(Objects& object, Board& board)
{
	if (&object == this) return true;

	return object.handleCollision(*this, board);
}

bool MonsterRandomal::handleCollision(Player& object, Board& board)
{
	object.setLife(-1);
	board.setMBoardTXT();
	board.readFromFile();
	return false;
}

bool MonsterRandomal::handleCollision(MonsterSmart& object, Board& board)
{
	return true;
}

bool MonsterRandomal::handleCollision(MonsterRandomal& object, Board& board)
{
	return true;
}

bool MonsterRandomal::handleCollision(Wall& object, Board& board)
{
	return false;
}

bool MonsterRandomal::handleCollision(Mot& object, Board& board)
{
	return false;
}

bool MonsterRandomal::handleCollision(Money& object, Board& board)
{
	return false;
}

bool MonsterRandomal::handleCollision(Ladder& object, Board& board)
{
	return false;
}

bool MonsterRandomal::handleCollision(MonsterDirection& object, Board& board)
{
	return true;
}
