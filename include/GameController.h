#pragma once
#include "Board.h"
#include "Cat.h"
#include "Mouse.h"




class GameController 
{
public:
	GameController();
	ExitType run();

private:
	bool catManage(float& , Gift_t  , sf::Time);
	ExitType endLevel();
	void display();

	sf::RenderWindow m_window;
	sf::Clock m_clock;

	Cat m_cat;
	Mouse m_mouse;
	Board m_boardManage;
};