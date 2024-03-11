#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <fstream>
#include "Status.h"
#include "Tile.h"
#include <iostream>
#include "GiftEnum.h"

enum ExitType { GameOver, Exit, Win, Continue };


class Mouse ;
class Cat;

const int FRM_X = 1800, FRM_Y = 700 , SoundSize = 2;

class Board
{
public:
	Board();
	bool newBoard(); 
	void buildLevel(Cat* cats, Mouse* mouse);
	void display(sf::RenderWindow*);
	Gift_t setBoard(sf::Vector2f);
	bool isValid(sf::RectangleShape) ;
	void addTime();
	void addLife(); 
    ExitType checkEnd(Cat* cat, Mouse* mouse); 
	sf::FloatRect getMouse() const;
	void saveMouse(sf::Vector2f p);
	void loadSound();
	bool setTime(sf::Time);




private:

	bool restartLevel(Cat* cat, Mouse* mouse);
	Status m_status;
	std::ifstream m_file;
	std::vector<std::vector<Tile>> m_Tile;
	std::vector<sf::Vector2f> m_catLastPosition;
	sf::Vector2f m_mouseLastPosition;
	sf::Vector2f m_mouseCurPosition;
	std::string m_levelName;

	std::vector <sf::Sound> m_effect;


	int m_levelScore;

	int m_cheese;
	int m_rows;
	int m_cols;

};