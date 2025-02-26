#include "Controller.h"
#include "Board.h"
#include "Player.h"
Controller::Controller()
	:m_window(sf::RenderWindow({ 1000, 700 }, "Lode Runner")) {
}

void Controller::run()
{
	//����� ���� ����� ��� ���� ���� ���� ������ ���� ����� ���� ��� ����� �� ����� �� ���� �� ��  ���� �������� ������ ��� �����
	if (m_cLevel.screenStart(m_window, m_board.getFont(), "Welcome to game"))
	{
		if (m_board.readFromFile())
			while (m_window.isOpen())
			{
				while (!m_board.isFailure())
				{
					m_window.clear(sf::Color::White);
					move();
					draw();
					m_window.display();
				}

				if (m_cLevel.screenStart(m_window, m_board.getFont(), m_board.getS()))
				{
					//����� ������ ��� �� ��� ����� ���� ������
					run();
				}
			}
	}
}

void Controller::draw()
{
	m_board.draw(m_window);	
	m_board.drawMenu(m_window);
}

void Controller::move()
{
	//����� �������� ������ ������ �� ��������
	m_board.moveObjects(m_window);
}