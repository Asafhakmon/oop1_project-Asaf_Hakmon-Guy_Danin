#include "Door.h"

Door::Door(sf::Vector2f position, sf::Vector2f size)
	:Blocks(position,size)
{
	setObject(DoorT);

}
//This function checks for a door collision and whether it is possible against the number of keys
bool Door::block(int& key,sf::RectangleShape temp)
{
	if(getPicType() == SpaceT)
		return true ;
	
	if (temp.getGlobalBounds().intersects(getShape().getGlobalBounds()))
	{
		if (key == 0)
		{
			return false;
		}
		key--;
		return true;
	}
	return true;
}
