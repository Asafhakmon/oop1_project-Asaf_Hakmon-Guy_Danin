#include "Cheese.h"

Cheese::Cheese(sf::Vector2f position, sf::Vector2f size)
	: CharactersAndObjects(position,size) 
{
	
	setObject(CheeseT);
}

int Cheese::getScore() const
{
	return getPicType() == SpaceT ? 0 :  10;
}


