#pragma once
#include "Blocks.h"

class Door : public Blocks
{
public:
	Door(sf::Vector2f position, sf::Vector2f size);
	virtual bool block(int&,sf::RectangleShape)override;

};