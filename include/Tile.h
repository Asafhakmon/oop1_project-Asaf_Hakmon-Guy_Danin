#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Wall.h"
#include "Door.h"
#include "Key.h"
#include "DeleteGift.h"
#include "FreezeGift.h"
#include "Cheese.h"
#include "TimeGift.h"
#include "LifeGift.h"
#include "Space.h"
#include "GiftEnum.h"


class Tile
{
public:
	Tile(char c, sf::Vector2f p, sf::Vector2f s);
	Tile(const Tile& other);

	int getScore()const;
	void update()const;
	Gift_t giftAct()const;
	bool block(int&,sf::RectangleShape) const;
	sf::RectangleShape getShape();
	Type getPicType();

private:
	char m_type;
	sf::Vector2f m_size;
	sf::Vector2f m_posotion;
	std::unique_ptr<CharactersAndObjects> m_obj;
};