#include "GameController.h"


GameController::GameController()
	:m_boardManage(), m_cat(), m_mouse({}, {})
{
	m_boardManage.buildLevel(&m_cat,&m_mouse);
	m_window.create(sf::VideoMode(Window_X, Window_Y), "Tom & Jerry");
}
/**********************************************************
This function is the axis of the game, from here the relevant 
classes and functions are called, it checks at each turn whether 
the window is closed or the user has pressed ESC to return to the menu.
**********************************************************/
ExitType GameController::run()
{
	float catFreeze = 0;
	sf::Time time = m_clock.restart();
	while (m_window.isOpen()) {
		for (auto event = sf::Event{}; m_window.pollEvent(event);) {
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::KeyPressed :
				if (sf::Keyboard::Escape == event.key.code){
					m_window.close();
					return Exit;
				}
				break;		
			}
		}
		display();
		time = m_clock.restart();
		Gift_t giftType;

		giftType = m_mouse.move(&m_boardManage, time);

		if (giftType == EndLevel || m_cat.isIn(m_mouse.getShape())) 
			if (ExitType end = endLevel(); end != Continue)
				return end;
		else
			continue;
		if (catManage(catFreeze, giftType, time))
			return GameOver;
		if (m_boardManage.setTime(time))
			if (ExitType end = endLevel(); end != Continue)
				return end;

	}

}
//This function is in charge of the cat and checks the status of the gifts the mouse has collected to manage the cat accordingly
bool GameController::catManage(float &catFreeze , Gift_t giftType , sf::Time time)
{
	if(giftType==Delete)
		m_cat.deleteCat();

	if (catFreeze == 0)
	{
		if (giftType == Freeze) {
			m_cat.makeCatFreeze();
			catFreeze = 5.f;
			return false;
		}
		m_cat.move(&m_boardManage, time);
	}
	else if(catFreeze > 0)
	{
		catFreeze -= time.asSeconds() ;
	}
	else
	{
		catFreeze = 0;
		m_cat.makeCatUnfreeze();
	}

	if (m_cat.isIn(m_mouse.getShape())) 
		if (endLevel() == GameOver)
			return true;
	return false;
}

ExitType GameController::endLevel()
{
	return m_boardManage.checkEnd(&m_cat, &m_mouse);
}

void GameController::display() 
{
	m_window.clear();

	m_boardManage.display(&m_window);
	m_cat.display(&m_window);
	m_mouse.display(&m_window);

	m_window.display();
}
