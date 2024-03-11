#include "Cat.h"
#include "Board.h"
#include "Resources.h"

Cat::Cat()
{	
	m_effect.setBuffer(Resources::instance().getSound(CatSound));
}
/************************************************************************
This function is responsible for the movement of the cat, 
which takes into account the position of the mouse and all other cats 
so that there are no duplicates
***************************************************************************/
void Cat::move(Board* board, sf::Time time)
{
	sf::FloatRect mouse = board->getMouse();
	size_t size = m_cats.size();
	sf::Vector2f directionUp = { 0.f , -time.asSeconds() * timeAdj },
		directionDown = { 0.f ,time.asSeconds() * timeAdj },
		directionRight = { time.asSeconds() * timeAdj , 0.f },
		directionLeft = { -time.asSeconds() * timeAdj , 0.f };

	for (int i = 0; i < size; i++)
	{
		bool up = true, down = true, left = true, right = true;

		checkBlock(up, down, left, right, m_cats[i], board, time);
		if (std::abs(m_cats[i].getPosition().x - mouse.getPosition().x) > //check priority y/x. if true start with x check
			std::abs(m_cats[i].getPosition().y - mouse.getPosition().y))
		{
			if (m_cats[i].getPosition().x < mouse.getPosition().x)
			{
				if (right)
				{
					m_cats[i].move(directionRight);
					if (m_cats[i].getScale().x > 0)
						m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
					continue;
				}
				else if (m_cats[i].getPosition().y < mouse.getPosition().y)
				{
					if (down)
					{
						m_cats[i].move(directionDown);
						continue;
					}
					else if (up)
					{
						m_cats[i].move(directionUp);
						continue;
					}
					else if (left)
					{
						if (m_cats[i].getScale().x < 0)
							m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
						m_cats[i].move(directionLeft);
						continue;
					}
				}
				else if (up)
				{
					m_cats[i].move(directionUp);
					continue;
				}
				else if (down)
				{
					m_cats[i].move(directionDown);
					continue;
				}
				else if (left)
				{
					if (m_cats[i].getScale().x < 0)
						m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
					m_cats[i].move(directionLeft);
					continue;

				}
			}
			else if (left)
			{
				if (m_cats[i].getScale().x < 0)
					m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
				m_cats[i].move(directionLeft);
				continue;
			}
			else if (m_cats[i].getPosition().y < mouse.getPosition().y)
			{
				if (down)
				{
					m_cats[i].move(directionDown);
					continue;
				}
				else if (up)
				{
					m_cats[i].move(directionUp);
					continue;
				}
				else if (right)
				{
					if (m_cats[i].getScale().x > 0)
						m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
					m_cats[i].move(directionRight);
					continue;
				}
			}
			else if (up)
			{

				m_cats[i].move(directionUp);
				continue;
			}
			else if (down)
			{
				m_cats[i].move(directionDown);
				continue;
			}
			else if (right)
			{
				if (m_cats[i].getScale().x > 0)
					m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
				m_cats[i].move(directionRight);
				continue;

			}

		}
		else if (m_cats[i].getPosition().y < mouse.getPosition().y)  // the ys len is higher then xs len -> check ys
		{
			if (down)
			{
				m_cats[i].move(directionDown);
				continue;
			}
			else if (m_cats[i].getPosition().x < m_cats[i].getPosition().x)
			{
				if (right)
				{
					if (m_cats[i].getScale().x > 0)
						m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
					m_cats[i].move(directionRight);
					continue;
				}
				else if (left)
				{
					if (m_cats[i].getScale().x < 0)
						m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
					m_cats[i].move(directionLeft);
					continue;
				}
				else if (up)
				{
					m_cats[i].move(directionUp);
					continue;
				}
			}
			else if (left)
			{
				if (m_cats[i].getScale().x < 0)
					m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
				m_cats[i].move(directionLeft);
				continue;
			}
			else if (right)
			{
				if (m_cats[i].getScale().x > 0)
					m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
				m_cats[i].move(directionRight);
				continue;
			}
			else if (up)
			{
				m_cats[i].move(directionUp);
				continue;
			}
		}
		else if (up)
		{
			m_cats[i].move(directionUp);
			continue;
		}
		else if (m_cats[i].getPosition().x < mouse.getPosition().x)
		{
			if (right)
			{
				if (m_cats[i].getScale().x > 0)
					m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
				m_cats[i].move(directionRight);
				continue;
			}
			else if (left)
			{
				if (m_cats[i].getScale().x < 0)
					m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
				m_cats[i].move(directionLeft);
				continue;
			}
			else if (down)
			{
				m_cats[i].move(directionDown);
				continue;
			}
		}
		else if (left)
		{
			if (m_cats[i].getScale().x < 0)
				m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
			m_cats[i].move(directionLeft);
			continue;
		}
		else if (right)
		{
			if (m_cats[i].getScale().x > 0)
				m_cats[i].setScale(m_cats[i].getScale().x * -1, m_cats[i].getScale().y);
			m_cats[i].move(directionRight);
			continue;
		}
		else if (down)
		{
			m_cats[i].move(directionDown);
			continue;
		}
	}

}

/**********************************************************************
This function checks the four directions of the cat against 
the data structure and the other cats
************************************************************************/
void Cat::checkBlock(bool& up, bool& down, bool& left, bool& right, sf::RectangleShape cur_cat, Board* board, sf::Time time) const
{
	sf::Vector2f cur = cur_cat.getPosition();
	size_t size = m_cats.size();

	//check wall, door and out of range 
	sf::RectangleShape temp = cur_cat;
	temp.move(0, -time.asSeconds() * timeAdj);
	up = board->isValid(temp);
	temp = cur_cat;
	temp.move(0, time.asSeconds() * timeAdj);
	down = board->isValid(temp);
	temp = cur_cat;
	temp.move(time.asSeconds() * timeAdj, 0);
	right = board->isValid(temp);
	temp = cur_cat;
	temp.move(-time.asSeconds() * timeAdj, 0);
	left = board->isValid(temp);


	// checks for duplicates of cat in the same cell
	for (int i = 0; i < size; i++)
	{
		if (m_cats[i].getPosition() != cur)
		{
			temp.move(0, -time.asSeconds() * timeAdjB);
			if (m_cats[i].getGlobalBounds().intersects(temp.getGlobalBounds()))
			{
				up = false;
			}
			temp = cur_cat;
			temp.move(0, time.asSeconds() * timeAdjB);
			if (m_cats[i].getGlobalBounds().intersects(temp.getGlobalBounds()))
			{
				down = false;
			}
			temp = cur_cat;
			temp.move(-time.asSeconds() * timeAdjB, 0);
			if (m_cats[i].getGlobalBounds().intersects(temp.getGlobalBounds()))
			{
				left = false;
			}
			temp = cur_cat;
			temp.move(time.asSeconds() * timeAdjB, 0);
			if (m_cats[i].getGlobalBounds().intersects(temp.getGlobalBounds()))
			{
				right = false;
			}
			temp = cur_cat;
		}
	}

}
//This function checks for a mouse collision
bool Cat::isIn(sf::FloatRect v)
{
	for (int i = 0; i < m_cats.size(); i++)
	{
		if (m_cats[i].getGlobalBounds().intersects(v))
		{
			m_effect.play();
			m_effect.setPlayingOffset(sf::seconds(0.5f));
			return true;
		}
	}
	return false;
}

void Cat::pushBack(sf::Vector2f position, sf::Vector2f size)
{
	sf::RectangleShape s;
	s.setTexture(&Resources::instance().getTexture(CatPic));
	s.setPosition(position);
	sf::Vector2f set = (sf::Vector2f)Resources::instance().getTexture(CatPic).getSize();
	s.setSize(set);
	s.setScale(size);
	s.setOrigin(s.getSize()*0.5f);
	m_cats.push_back(s);
}

void Cat::display(sf::RenderWindow* window) const
{
	for (int i = 0; i < m_cats.size(); i++)
	{
		window->draw(m_cats[i]);
	}
}

void Cat::deleteCat()
{
	if (m_cats.empty())
		return;

	m_cats.erase(m_cats.begin()+m_cats.size()-1);
}

void Cat::setPosition(std::vector<sf::Vector2f> cat)
{
	for (int i = 0; i < m_cats.size() ; i++)
		m_cats[i].setPosition(cat[i]);
}

void Cat::deleteAllcats()
{
	m_cats.clear();
}

void Cat::makeCatFreeze()
{
	for (size_t i = 0; i < m_cats.size(); i++)
	{
		m_cats[i].setTexture(&Resources::instance().getTexture(FrozenCat));
	}
}

void Cat::makeCatUnfreeze()
{
	for (size_t i = 0; i < m_cats.size(); i++)
	{
		m_cats[i].setTexture(&Resources::instance().getTexture(CatPic));
	}
}
