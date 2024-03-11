#pragma once
#include <SFML/Graphics.hpp>
#include "GiftEnum.h"

enum Type {CheeseT, DoorT, DeleteGiftT,
		FreezeT, TimeT, LifeT, KeyT, WallT, SpaceT };

const int  Window_X = 1800, Window_Y = 900 , objSize=100;


class CharactersAndObjects
{
public:
	CharactersAndObjects(sf::Vector2f position, sf::Vector2f size);
	virtual ~CharactersAndObjects()=default;
	CharactersAndObjects(const CharactersAndObjects& other);
	CharactersAndObjects& operator=(const CharactersAndObjects& other);
	virtual bool block(int&,sf::RectangleShape)= 0;
	virtual int getScore()const  = 0;
	virtual Gift_t giftAct() const = 0;
	sf::FloatRect getGlobalRec()const;
	void setObject(Type);
	Type getPicType()const;
	sf::RectangleShape getShape()const;

private:
	Type m_pic;
	sf::RectangleShape m_object;


};
