#include "TimeGift.h"

TimeGift::TimeGift(sf::Vector2f position, sf::Vector2f size)
	: Gift(position, size)
{
	setObject(TimeT);
}

int TimeGift::getScore() const
{
	if (getPicType() != SpaceT)
		return score;
	return 0;
}

Gift_t TimeGift::giftAct() const
{
	return getPicType() == SpaceT ? None : Time;
}
