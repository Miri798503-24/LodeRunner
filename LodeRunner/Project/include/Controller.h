#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"
#include "ControllerLevel.h"

class Controller
{
public:
    Controller();
    ~Controller() = default;
    
    void run();
    void draw();  
    void move();

private:
    Board m_board;
    Player m_player;
    ControllerLevel m_cLevel;
    sf::RenderWindow m_window;
};
