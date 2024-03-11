#pragma once
#include "Gift.h"

class FreezeGift : public Gift
{
public:
	FreezeGift(sf::Vector2f position, sf::Vector2f size);
	virtual int getScore()const override;
	virtual Gift_t giftAct() const override;

};