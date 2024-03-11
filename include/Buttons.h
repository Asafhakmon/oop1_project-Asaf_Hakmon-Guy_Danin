#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Buttons {
public:
	Buttons(const std::string&, float, float);
	
	void setTexture(const std::string& pic);
	void setSprite(float x, float y);
	sf::Texture getTexture() const;
	sf::Sprite getSprite() const;
private:
	sf::Texture m_buttonPic;
	sf::Sprite m_button;
	
};
