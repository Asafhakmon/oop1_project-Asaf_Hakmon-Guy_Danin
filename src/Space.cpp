#include "Space.h"

Space::Space(sf::Vector2f position, sf::Vector2f size)
	: CharactersAndObjects(position, size)
{
	setObject(SpaceT);
}
