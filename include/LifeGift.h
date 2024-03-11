#pragma once
#include "Gift.h"

class LifeGift : public Gift
{
public:
	LifeGift(sf::Vector2f position, sf::Vector2f size);
	virtual int getScore()const override;
	virtual Gift_t giftAct() const override;

};