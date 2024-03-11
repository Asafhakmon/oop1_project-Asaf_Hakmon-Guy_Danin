#pragma once
#include "CharactersAndObjects.h"

class Key : public CharactersAndObjects
{
public:
	Key(sf::Vector2f position, sf::Vector2f size);
	virtual int getScore()const override;

	virtual bool block(int&,sf::RectangleShape)override { return true; };
	virtual Gift_t giftAct() const override { return None; };


};
