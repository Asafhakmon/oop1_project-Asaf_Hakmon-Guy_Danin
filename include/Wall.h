#pragma once
#include "Blocks.h"

class Wall : public Blocks
{
public:
	Wall(sf::Vector2f position, sf::Vector2f size);
	virtual bool block(int&,sf::RectangleShape) override;


};


