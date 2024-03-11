#pragma once
#include "CharactersAndObjects.h"

class Blocks : public CharactersAndObjects
{
public:
	using CharactersAndObjects::CharactersAndObjects;

	virtual int getScore()const override { return 0; };
	virtual Gift_t giftAct() const override { return None; };
};