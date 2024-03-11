#pragma once
#include "Gift.h"

class DeleteGift : public Gift
{
public:
	DeleteGift(sf::Vector2f position, sf::Vector2f size);
	virtual int getScore()const override;
	virtual Gift_t giftAct() const override;


};