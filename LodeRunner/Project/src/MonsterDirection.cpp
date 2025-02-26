#include "MonsterDirection.h"
#include "Player.h"
#include "Board.h"

MonsterDirection::MonsterDirection()
{
	m_isFall = false;
	m_d = false;
}

sf::Vector2f MonsterDirection::moveMonster(const sf::Vector2f& locPlayer)
{
	sf::Vector2f m_locNew = m_picture.getPosition();
	
	if (m_d)
		m_locNew.x += 0.2f;

	else
		m_locNew.x -= 0.2f;

	return m_locNew;
}

bool MonsterDirection::handleCollision(Objects& object, Board& board)
{
	if (&object == this) return true;

	return object.handleCollision(*this, board);
}

bool MonsterDirection::handleCollision(Player& object, Board& board)
{
	object.setLife(-1);
	board.setMBoardTXT();
	board.readFromFile();
	return false;
}

bool MonsterDirection::handleCollision(MonsterSmart& object, Board& board)
{
	return true;
}

bool MonsterDirection::handleCollision(MonsterRandomal& object, Board& board)
{
	return true;
}

bool MonsterDirection::handleCollision(Wall& object, Board& board)
{
	return false;
}

bool MonsterDirection::handleCollision(Mot& object, Board& board)
{
	return false;
}

bool MonsterDirection::handleCollision(Money& object, Board& board)
{
	return false;
}

bool MonsterDirection::handleCollision(Ladder& object, Board& board)
{
	return false;
}

bool MonsterDirection::handleCollision(MonsterDirection& object, Board& board)
{
	return true;
}

void MonsterDirection::setD()
{
	m_d = !m_d;
}
