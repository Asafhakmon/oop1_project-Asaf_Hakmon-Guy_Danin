#pragma once
#include "CharactersAndObjects.h"

class Space : public CharactersAndObjects
{
public:
	Space(sf::Vector2f position, sf::Vector2f size);


	virtual int getScore()const override { return 0; };
	virtual bool block(int&,sf::RectangleShape)override { return true; };
	virtual Gift_t giftAct() const override { return None; };

};