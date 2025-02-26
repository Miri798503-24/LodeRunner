#include "Player.h"
#include "Board.h"

Player::Player(const sf::Vector2f& location, const float& size, const sf::Texture& tex)
	:MoveObject(location, size, tex) {}

Player::Player() { m_life = 3; m_direction = 0; m_isFall = false;}

bool Player::handleCollision(Ladder& object, Board& board)
{
	return false;
}

bool Player::handleCollision(MonsterDirection& object, Board& board)
{
	return false;
}

bool Player::getIsFall() const
{
	return m_isFall;
}

void Player::setIsFall(const bool& f)
{
	m_isFall = f;
}

void Player::setLife(const int& num)
{
	m_life += num;
}

int Player::getDirection() const
{
	return m_direction;
}

int Player::getLife() const
{
	return m_life;
}

sf::Vector2f Player::movePlayer(sf::RenderWindow& window)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(EXIT_SUCCESS);
			break;

		case sf::Event::KeyPressed:
		{
			sf::Vector2f positionPlayer = getLocation();
			switch (event.key.code)
			{
			case sf::Keyboard::Right:
				m_direction = 1;
				return { positionPlayer.x + 4, positionPlayer.y };
				break;

			case sf::Keyboard::Left:
				m_direction = 2;
				return { positionPlayer.x - 4, positionPlayer.y };
				break;

			case sf::Keyboard::Up:
				m_direction = 3;
				return { positionPlayer.x, positionPlayer.y - 4 };
				break;

			case sf::Keyboard::Down:
				m_direction = 4;
				return { positionPlayer.x, positionPlayer.y + 4 };
				break;

			default:
				break;
			}
		}

		default:
			break;
		}

	}

	return sf::Vector2f({ 0.f, 0.f });
}

bool Player::handleCollision(Objects& object, Board& board)
{
	if (&object == this) 
		return true;

	return object.handleCollision(*this, board);
}

bool Player::handleCollision(Player& object, Board& board)
{
	return false;
}

bool Player::handleCollision(MonsterSmart& object, Board& board)
{
	setLife(-1);
	board.setMBoardTXT();
	board.readFromFile();
	return true;
}

bool Player::handleCollision(MonsterRandomal& object, Board& board)
{
	setLife(-1);
	board.setMBoardTXT();
	board.readFromFile();
	return true;
}

bool Player::handleCollision(Wall& object, Board& board)
{
	return false;
}

bool Player::handleCollision(Mot& object, Board& board)
{
	return false;
}

bool Player::handleCollision(Money& object, Board& board)
{
	board.addScore(2 * board.getLevel());
	return false;
}