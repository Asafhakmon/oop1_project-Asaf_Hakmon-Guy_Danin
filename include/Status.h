#pragma once 
#include <SFML/Graphics.hpp>


const int Cheese = 10, Gift = 5, Door = 2, Level = 25 , Key = -1;

class Status
{
public:
	Status();
	void display(sf::RenderWindow* window);
	void setLevel();
	int getLevel()const;
	bool setTime(sf::Time);
	void setScore(int);
	void addTime();
	void addLife();
	float getTime()const ;
	int getLife()const;
	void  setLife();

	void keyPick();
	int getKey()const;
	void keyUsed();
	void setPosition(sf::Vector2f position);
	void newLevel();
	void repeatLevel();

private:
	
	sf::Sprite m_statusBar;

	std::vector <sf::Sprite> m_life;
	std::vector <sf::Sprite> m_key;

	int m_level;
	int m_score; 
	float m_time;

};