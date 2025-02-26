#include "MonsterSmart.h"
#include "Player.h"
#include "Board.h"

MonsterSmart::MonsterSmart()
{
	m_isFall = false;
}

sf::Vector2f MonsterSmart::moveMonster(const sf::Vector2f& locPlayer)
{
	if (locPlayer.y > m_picture.getPosition().y)
		return { m_picture.getPosition().x, m_picture.getPosition().y + 0.15f};

	if (locPlayer.x > m_picture.getPosition().x)
		return { m_picture.getPosition().x + 0.15f, m_picture.getPosition().y };

	if (locPlayer.y < m_picture.getPosition().y)
	{
		m_direction = 3;
		return { m_picture.getPosition().x, m_picture.getPosition().y - 0.15f };
	}

	if (locPlayer.x < m_picture.getPosition().x)
		return { m_picture.getPosition().x - 0.15f, m_picture.getPosition().y };
}

bool MonsterSmart::handleCollision(Objects& object, Board& board)
{
	if (&object == this) return true;

	return object.handleCollision(*this, board);
}

bool MonsterSmart::handleCollision(Player& object, Board& board)
{
	object.setLife(-1);
	board.setMBoardTXT();
	board.readFromFile();
	return false;
}

bool MonsterSmart::handleCollision(MonsterSmart& object, Board& board)
{
	return false;
}

bool MonsterSmart::handleCollision(MonsterRandomal& object, Board& board)
{
	return false;
}

bool MonsterSmart::handleCollision(Wall& object, Board& board)
{
	return false;
}

bool MonsterSmart::handleCollision(Mot& object, Board& board)
{
	return false;
}

bool MonsterSmart::handleCollision(Money& object, Board& board)
{
	return false;
}

bool MonsterSmart::handleCollision(Ladder& object, Board& board)
{
	return false;
}

bool MonsterSmart::handleCollision(MonsterDirection& object, Board& board)
{
	return true;
}
