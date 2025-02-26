#include "Board.h"

Board::Board() : m_row(0), m_col(0), m_score(0), m_sizeCell(0), m_starsOfBoard(0), m_level(1)
{  
	setDatasMenu();

	m_boardTXT.open("Board.txt");
	ResourseManager::instance();
}

bool Board::readFromFile()
{
	if (m_boardTXT.is_open())
	{
		if (m_boardTXT.eof())
			return false;

		deleteLevel();
		m_starsOfBoard = m_boardTXT.tellg();

		std::string line;
		std::getline(m_boardTXT, line);
		std::istringstream lineStream(line);

		lineStream >> m_row;
		lineStream >> m_col; 
		lineStream >> m_stopper;
		
		setLimitsBoard();

		for (int i = 0; i < m_row; i++)
		{
			std::getline(m_boardTXT, line);
			for (int j = 0; j < m_col; j++)
			{
				sf::Vector2f loc = {float(m_locationBoard.x + (j * m_sizeCell)) , float(m_locationBoard.y + (i * m_sizeCell))};
				char cell = line[j];
				sf::Texture m;
				switch (cell)
				{
				case 'H':
					m_staticBoard.push_back(std::make_unique<Ladder>());
					m_staticBoard[m_staticBoard.size() - 1]->upData(loc, { m_sizeCell, m_sizeCell }, ResourseManager::instance().getImage("ladder"));
					break;

				case '-':
					m_staticBoard.push_back(std::make_unique<Mot>());
					m_staticBoard[m_staticBoard.size() - 1]->upData(loc, { m_sizeCell, m_sizeCell/3 }, ResourseManager::instance().getImage("mot"));
					break;

				case '#':
					m_staticBoard.push_back(std::make_unique<Wall>());
					m_staticBoard[m_staticBoard.size() - 1]->upData(loc, { m_sizeCell, m_sizeCell }, ResourseManager::instance().getImage("wall"));
					break;

				case '@':
					m_player.upData(loc, {(m_sizeCell / 5) * 3, (m_sizeCell / 5) * 3}, ResourseManager::instance().getImage("player"));
					break;

				case '%':
					newMonster(loc);
					break;

				case '*':
					newMoney(loc);
					break;
				case'$':
					newGift(loc);

				default:
					break;
				}
			}
		}
	}	
	return true;
}

void Board::deleteLevel()
{
	m_vectorMoney.clear();
	m_staticBoard.clear();
	m_vectorMonsters.clear();
}

void Board::draw(sf::RenderWindow& window)
{
	window.draw(m_rectangle);

	for (int i = 0; i < m_staticBoard.size(); i++)
		m_staticBoard[i]->draw(window);

	for (int i = 0; i < m_vectorMoney.size(); i++)
		m_vectorMoney[i]->draw(window);

	for (int i = 0; i < m_vectorGift.size(); i++)
		m_vectorGift[i]->draw(window);

	for (int i = 0; i < m_vectorMonsters.size(); i++)
		m_vectorMonsters[i]->draw(window);

	m_player.draw(window);
	//להדפיס את הוקטור של המתנות
}

void Board::drawMenu(sf::RenderWindow& window)
{
	setDatasMenu();
	window.draw(m_textTime);
	window.draw(m_textLife);
	window.draw(m_textScore);
	window.draw(m_textLevel);
	window.draw(m_textTimeData);
	window.draw(m_textLifeData);
	window.draw(m_textScoreData);
	window.draw(m_textLevelData);
}

void Board::moveObjects(sf::RenderWindow& window)
{
	movePlayer(window);
	moveMonster(window);
}

bool Board::handleCollisions(Objects& object, sf::Vector2f& locNew, const bool& isPlayer)
{
	for (int i = 0; i < m_staticBoard.size(); i++)
		if (isCollisions(locNew, *m_staticBoard[i], object))
			return object.handleCollision(*m_staticBoard[i], *this);
	
	if (isPlayer)
	{
		for (int i = 0; i < m_vectorMoney.size(); i++)
			if (isCollisions(locNew, *m_vectorMoney[i], object))
			{
				bool f = object.handleCollision(*m_vectorMoney[i], *this);
				m_vectorMoney.erase(m_vectorMoney.begin() + i);
				return f;
			}

		for (int i = 0; i < m_vectorGift.size(); i++)
			if (isCollisions(locNew, *m_vectorGift[i], object))
			{
				bool f = object.handleCollision(*m_vectorGift[i], *this);
				m_vectorGift.erase(m_vectorGift.begin() + i);
				return f;
			}

		for (int i = 0; i < m_vectorMonsters.size(); i++)
			if (isCollisions(locNew, *m_vectorMonsters[i], object))
				return object.handleCollision(*m_vectorMonsters[i], *this);
	}

	else
		if (isCollisions(locNew, m_player, object))
			return object.handleCollision(m_player, *this);

	return true;
}

bool Board::isCollisions(const sf::Vector2f & newLoc, Objects& objectA, Objects& objectB)
{
	sf::RectangleShape objA;
	sf::RectangleShape objB;

	objA.setPosition(newLoc);
	objA.setSize(objectB.getSizeObject());
	objB.setPosition(objectA.getLocation());
	objB.setSize(objectA.getSizeObject());

	if (objA.getGlobalBounds().intersects(objB.getGlobalBounds()))
		return true;

	return false;
}

bool Board::isFailure()
{
	if (m_vectorMoney.size() == 0)
	{
		m_score += 50 * m_level;
		m_level++;
		if (!readFromFile())
		{
			m_s = "Excelent";
			restartBoard();
			readFromFile();
			return true;
		}

		return false;
	}

	if (m_stopper == 0)
	{
		setMBoardTXT();
		readFromFile();
		m_player.setLife(-1);
		return false;
	}

	if (m_player.getLife() <= 0)
	{
		m_s = "Game Over";
		restartBoard();
		return true;
	}

	return false;
}

int Board::getLevel() const
{
	return m_level;
}

string Board::getS()
{
	return m_s;
}

sf::Font& Board::getFont() const
{
	return ResourseManager::instance().getFont();
}

void Board::setLimitsBoard()
{
	if (Max())
		calculation(m_col);

	else
		calculation(m_row);
}

void Board::calculation(const int& numCell)
{
	m_sizeCell = 600 / numCell;

	m_locationBoard = { float((1000 - (m_col * m_sizeCell)) / 2) , 100.f };
	
	m_rectangle.setPosition(m_locationBoard);
	m_rectangle.setSize({float(m_col * m_sizeCell),float( m_row * m_sizeCell)});
	m_rectangle.setFillColor(sf::Color::White);
}

void Board::newMonster(const sf::Vector2f& loc)
{
	int r = rand() % 4 + 1;
	
	switch (r)
	{
	case 1:
	case 2:
		m_vectorMonsters.push_back(std::make_unique<MonsterRandomal>());
		m_vectorMonsters[m_vectorMonsters.size() - 1]->upData(loc, { m_sizeCell / 3, m_sizeCell / 3 }, ResourseManager::instance().getImage("monster"));
		break;

	case 3:
		m_vectorMonsters.push_back(std::make_unique<MonsterDirection>());
		m_vectorMonsters[m_vectorMonsters.size() - 1]->upData(loc, { m_sizeCell / 3, m_sizeCell / 3 }, ResourseManager::instance().getImage("monster"));
		break;

	default:
		m_vectorMonsters.push_back(std::make_unique<MonsterSmart>());
		m_vectorMonsters[m_vectorMonsters.size() - 1]->upData(loc, { m_sizeCell / 3, m_sizeCell / 3 }, ResourseManager::instance().getImage("monster"));
		break;
	}
}

void Board::newMoney(const sf::Vector2f& loc)
{
	m_vectorMoney.push_back(std::make_unique<Money>());
	m_vectorMoney[m_vectorMoney.size() - 1]->upData(loc, { m_sizeCell, m_sizeCell }, ResourseManager::instance().getImage("money"));
}

void Board::newGift(const sf::Vector2f& loc)
{
	int r = rand() % 3;

	switch (r)
	{
	case 0:
		m_vectorGift.push_back(std::make_unique<GiftLife>());
		m_vectorGift[m_vectorGift.size() - 1]->upData(loc, { m_sizeCell, m_sizeCell }, ResourseManager::instance().getImage("present"));
		break;

	case 1:
		m_vectorGift.push_back(std::make_unique<GiftMonster>());
		m_vectorGift[m_vectorGift.size() - 1]->upData(loc, { m_sizeCell, m_sizeCell }, ResourseManager::instance().getImage("present"));
		break;

	default:
		m_vectorGift.push_back(std::make_unique<GiftMoney>());
		m_vectorGift[m_vectorGift.size() - 1]->upData(loc, { m_sizeCell, m_sizeCell }, ResourseManager::instance().getImage("present"));
		break;
	}
}

void Board::movePlayer(sf::RenderWindow& window)
{
	sf::Vector2f loc = { 0.f , 0.f };

	if (m_player.getIsFall())
	{
		loc = { m_player.getLocation().x , m_player.getLocation().y + 2 };
		m_player.setLocation(loc);
		handleCollisions(m_player, loc, true);
		return;
	}

	loc = m_player.movePlayer(window);
	if (loc != sf::Vector2f{ 0.f,0.f } && handleCollisions(m_player, loc, true))
		m_player.setLocation(loc);
}

void Board::moveMonster(sf::RenderWindow& window)
{
	sf::Vector2f loc;
	for (int i = 0; i < m_vectorMonsters.size(); i++)
	{
		if (m_vectorMonsters[i]->getFall())
		{
			loc = { m_vectorMonsters[i]->getLocation().x , m_vectorMonsters[i]->getLocation().y + 2 };
			m_vectorMonsters[i]->setLocation(loc);
			handleCollisions(*m_vectorMonsters[i], loc, false);
			return;
		}
		
		loc = m_vectorMonsters[i]->moveMonster(m_player.getLocation());
		if (handleCollisions(*m_vectorMonsters[i], loc, false))
			m_vectorMonsters[i]->setLocation(loc);
	}
}

void Board::addScore(const int& score)
{
	m_score += score;
}

void Board::setDatasMenu()
{
	setText(m_textTime, { 880 , 10 }, "Time");
	setText(m_textLife, { 780 , 10 }, "Life");
	setText(m_textScore, { 660 , 10 }, "Score");
	setText(m_textLevel, { 540 , 10 }, "Level");

	setText(m_textTimeData, { 880 , 40 }, std::to_string(m_stopper));
	setText(m_textLifeData, { 780 , 40 }, std::to_string(m_player.getLife()));
	setText(m_textScoreData, { 660 , 40 }, std::to_string(m_score));
	setText(m_textLevelData, { 540 , 40 }, std::to_string(m_level));
}

void Board::setText(sf::Text& text, const sf::Vector2f& position, const string& textData)
{
	text.setString(textData);
	text.setCharacterSize(25);
	text.setPosition(position);
	text.setColor(sf::Color::Black);
	text.setFont(getFont());
}

void Board::setMBoardTXT()
{
	m_boardTXT.seekg(m_starsOfBoard, std::ios::beg);
}

void Board::restartBoard()
{
	m_level = 1;
	m_stopper = -1;
	m_score = 0;
	m_sizeCell = 0;
	m_starsOfBoard = 0;
	m_row = 0;
	m_col = 0;
}

bool Board::Max()
{
	if (m_row >= m_col)
		return true;

	return false;
}