#pragma once
#include "CharactersAndObjects.h"

const int score = 5;

class Gift : public CharactersAndObjects
{
public:
	using CharactersAndObjects::CharactersAndObjects;
	virtual bool block(int&,sf::RectangleShape) override { return true; };


};


