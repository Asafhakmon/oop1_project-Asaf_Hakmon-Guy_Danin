#include "Tile.h"


/// This class represents a member of the data structure, 
/// it holds a game object that does not move. 
/// and is responsible for returning the relevant function to that object

Tile::Tile(char c , sf::Vector2f p , sf::Vector2f s)
	:m_type(c) , m_size(s) , m_posotion(p)
{

	m_obj = std::make_unique<Space>(p, s);
	switch (c)
	{
	case '*':
		m_obj =std::make_unique<Cheese>(p, s);
		break;
	case '+':  
		m_obj = std::make_unique< LifeGift>(p, s);
		break;
	case 'z':  
		m_obj = std::make_unique<FreezeGift>(p, s);
		break;
	case 't': 
		m_obj = std::make_unique< TimeGift>(p, s);
		break;
	case '#':
		m_obj = std::make_unique< Wall>(p, s);
		break;
	case 'D':
		m_obj = std::make_unique< Door>(p, s);
		break;
	case 'F':
		m_obj = std::make_unique< Key>(p, s);
		break;
	case 'r': 
		m_obj = std::make_unique< DeleteGift>(p, s);
		break;
	}
}

Tile::Tile(const Tile& other)
	:m_type(other.m_type) , m_posotion(other.m_posotion) , m_size(other.m_size)
{
	sf::Vector2f p = other.m_posotion, s = other.m_size;
	m_obj = std::make_unique<Space>(p, s); 
	switch (other.m_type)
	{
	case '*':
		m_obj = std::make_unique<Cheese>(p, s);
		break;
	case '+':
		m_obj = std::make_unique<LifeGift>(p, s);
		break;
	case 'z':
		m_obj = std::make_unique< FreezeGift>(p, s);
		break;
	case 't':
		m_obj = std::make_unique<TimeGift>(p, s);
		break;
	case '#':
		m_obj = std::make_unique<  Wall>(p, s);
		break;
	case 'D':
		m_obj = std::make_unique<Door>(p, s);
		break;
	case 'F':
		m_obj = std::make_unique<Key>(p, s);
		break;
	case '$':
		m_obj = std::make_unique< DeleteGift>(p, s);
		break;
	}
}

	


int Tile::getScore() const
{
	return m_obj->getScore();
}

void Tile::update() const
{
	m_obj->setObject(SpaceT);
}

Gift_t Tile::giftAct() const
{
	return m_obj->giftAct();
}

bool Tile::block(int &k, sf::RectangleShape temp) const
{
	return m_obj->block(k ,temp);
}

sf::RectangleShape Tile::getShape()
{
	return m_obj->getShape();
}

Type Tile::getPicType()
{
	return m_obj->getPicType();
}








