#include "Wall.h"
#include <iostream>
Wall::Wall(sf::Vector2f position, sf::Vector2f size)
	:Blocks(position, size)
{

	setObject(WallT);

}
//This function checks for a wall collision
bool Wall::block(int& key, sf::RectangleShape temp)
{
	if (temp.getGlobalBounds().intersects(getShape().getGlobalBounds()))
	{
		return false;
	}

	return true;
}

