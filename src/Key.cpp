#include "Key.h"

Key::Key(sf::Vector2f position, sf::Vector2f size)
	:  CharactersAndObjects(position, size)
{
	setObject(KeyT);
}

int Key::getScore() const
{
	if (getPicType() == SpaceT)
		return 0;
	return -1;
}
