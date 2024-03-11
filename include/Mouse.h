#pragma once
#include <SFML/Graphics.hpp>
#include "GiftEnum.h"
#include <SFML/Audio.hpp>


const int secAdj = 200;
class Board;

class Mouse 
{
public:
	Mouse(sf::Vector2f position, sf::Vector2f size);
	void display(sf::RenderWindow*) const;
	Gift_t move(Board*, sf::Time) ;
	bool handlePressed(Board* board, sf::Vector2f moveTo);
	sf::FloatRect getShape() const;
	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);

private:
	sf::RectangleShape m_mouse;
};



