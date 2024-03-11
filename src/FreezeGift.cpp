#include "FreezeGift.h"

FreezeGift::FreezeGift(sf::Vector2f position, sf::Vector2f size)
	: Gift(position, size)
{

	setObject(FreezeT);

}

int FreezeGift::getScore() const
{
	if (getPicType() != SpaceT)
		return score;
	return 0;
}

Gift_t FreezeGift::giftAct() const
{
	return getPicType() == SpaceT ? None : Freeze;
}
