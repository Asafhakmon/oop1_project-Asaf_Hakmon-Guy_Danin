#pragma once
#include "Gift.h"

class TimeGift : public Gift
{
public:
	TimeGift(sf::Vector2f position, sf::Vector2f size);
	virtual int getScore()const override;
	virtual Gift_t giftAct() const override;

};
