#include "DeleteGift.h"

DeleteGift::DeleteGift(sf::Vector2f position, sf::Vector2f size)
	: Gift(position,size)
{
	setObject(DeleteGiftT);
}

int DeleteGift::getScore() const
{
	if (getPicType() != SpaceT)
		return score;
	return 0;
}

Gift_t DeleteGift::giftAct() const
{
	return getPicType() == SpaceT ? None : Delete;
}
