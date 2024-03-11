#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


const int timeAdj = 100,timeAdjB=150;

class Board ;

class Cat 
{
public:
	Cat();
	void move(Board *board, sf::Time);
	void checkBlock(bool& up, bool& down, bool& left, bool& right, sf::RectangleShape cur,Board * board, sf::Time time) const;
	bool isIn(sf::FloatRect) ;
	void pushBack(sf::Vector2f position, sf::Vector2f size);
	void display(sf::RenderWindow*) const;
	void deleteCat();
	void setPosition(std::vector<sf::Vector2f> cat);
	void deleteAllcats();
	void makeCatFreeze();
	void makeCatUnfreeze();

private:

	std::vector<sf::RectangleShape> m_cats;
	sf::Sound m_effect;
};

