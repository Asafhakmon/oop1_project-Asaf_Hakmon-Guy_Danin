#include "LifeGift.h"

LifeGift::LifeGift(sf::Vector2f position, sf::Vector2f size)
	: Gift(position, size)
{
	setObject(LifeT);
}

int LifeGift::getScore() const
{
	if (getPicType() != SpaceT)
		return score;
	return 0;
}

Gift_t LifeGift::giftAct() const
{
	return getPicType() == SpaceT ? None : Life;
}
