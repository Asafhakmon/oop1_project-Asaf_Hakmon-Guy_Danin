#include "Mouse.h"
#include "Board.h"
#include "Resources.h"

Mouse::Mouse(sf::Vector2f position, sf::Vector2f size)
{
	sf::Vector2f set = (sf::Vector2f)Resources::instance().getTexture(MousePic).getSize();
	m_mouse.setSize(set);
	m_mouse.setTexture(&Resources::instance().getTexture(MousePic));
	setSize(size);
	m_mouse.setOrigin(m_mouse.getSize() * 0.5f);
	m_mouse.setPosition(position);
}

void Mouse::display(sf::RenderWindow* window) const
{
	window->draw(m_mouse);
}

/****************************************************************
This function checks whether the user wants to move the mouse, if so and 
the movement is possible it moves the mouse and returns whether the mouse has collected a gift
*******************************************************************/
Gift_t Mouse::move( Board* board, sf::Time time)
{
	sf::Vector2f up({ 0.f ,-time.asSeconds()* secAdj }), down({ 0.f ,time.asSeconds()* secAdj }),
		right({  time.asSeconds()* secAdj,0.f }), left({ -time.asSeconds()* secAdj, 0.f });
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (handlePressed(board, right)) {
			if (m_mouse.getScale().x < 0)
				m_mouse.setScale(m_mouse.getScale().x * -1, m_mouse.getScale().y);
			return board->setBoard(m_mouse.getPosition());
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (handlePressed(board, up))
			return board->setBoard(m_mouse.getPosition());
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (handlePressed(board, down))
			return board->setBoard(m_mouse.getPosition());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (handlePressed(board, left)) {
			if(m_mouse.getScale().x>0)
				m_mouse.setScale(m_mouse.getScale().x * -1 , m_mouse.getScale().y );
			return board->setBoard(m_mouse.getPosition());
		}
	}
	return None;
}
//This function checks whether the movement of the mouse is possible and moves it
bool Mouse::handlePressed(Board* board, sf::Vector2f moveTo)
{
	sf::RectangleShape temp = m_mouse;
	temp.move(moveTo);
	if (board->isValid(temp))
	{
		m_mouse.move(moveTo);
		board->saveMouse(m_mouse.getPosition());
		return true;
	}
	return false;
}

sf::FloatRect Mouse::getShape() const
{
	return m_mouse.getGlobalBounds();
}

void Mouse::setPosition(sf::Vector2f position)
{
	m_mouse.setPosition(position);
}

void Mouse::setSize(sf::Vector2f size)
{
	m_mouse.setScale(size);
}
