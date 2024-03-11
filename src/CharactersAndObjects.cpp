#include "CharactersAndObjects.h"


/// In this file are the common functions of the objects in the game


CharactersAndObjects::CharactersAndObjects(sf::Vector2f position, sf::Vector2f size)
	:m_object({ objSize,objSize })
{
	m_object.setScale(size);
	m_object.setPosition(position);
	setObject(SpaceT);
}

CharactersAndObjects::CharactersAndObjects(const CharactersAndObjects& other)
{
	m_object.scale(other.m_object.getScale());
	m_object.setPosition(other.m_object.getPosition());
	m_pic = other.m_pic;
	setObject(SpaceT);
}

CharactersAndObjects& CharactersAndObjects::operator=(const CharactersAndObjects& other)
{
	if (this != &other)
	{
		m_pic = other.m_pic;
		m_object = other.m_object;
	}
	return *this;
}



sf::FloatRect CharactersAndObjects::getGlobalRec() const
{
	return m_object.getGlobalBounds();
}

void CharactersAndObjects::setObject(Type pic)
{
	m_pic = pic;
}

Type CharactersAndObjects::getPicType()const
{
	return m_pic;
}

sf::RectangleShape CharactersAndObjects::getShape() const
{
	return m_object;
}

