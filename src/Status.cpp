#include "Status.h"
#include <string>
#include "Resources.h"

Status::Status()
	:m_level(0), m_score(0) , m_time(45.f) , m_key(0)
{
	m_statusBar.setTexture(Resources::instance().getTexture(StatusPic));
}

//This function displays the status of the game, updating a temporary 
// variable that displays the time, score, and stage number
void Status::display(sf::RenderWindow *window) 
{
	sf::Text text;
	float y = 90;
	window->draw(m_statusBar);
	for (int i = 0; i < m_life.size(); i++) {
		window->draw(m_life[i]);
	}
	for (int i = 0; i < m_key.size(); i++) {
		window->draw(m_key[i]);
	}
	text.setFont(Resources::instance().getFont());
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(50);
	text.setString(std::to_string(m_level));
	text.setPosition({ 450.f , m_statusBar.getPosition().y + y });
	window->draw(text);
	text.setString(std::to_string((int)m_time));
	text.setPosition({ 1400.f , m_statusBar.getPosition().y + y });
	window->draw(text);
	text.setString(std::to_string(m_score));
	text.setPosition({ 1100.f , m_statusBar.getPosition().y + y });
	window->draw(text);

}

void Status::setLevel()
{
	m_level++;
}

int Status::getLevel() const
{
	return m_level;
}

bool Status::setTime(sf::Time time)
{
	m_time -= time.asSeconds();
	if (m_time <= 0)
		m_time = 0;

	return m_time == 0;
}

void Status::setScore(int s)
{
	if(s!=Key)
		m_score += s;
}

void Status::addTime()
{
	m_time += 15.f;
}
//This function updates the hearts vector so that they are in the correct position on the board.
void Status::addLife()
{
	
	float xIncreas = 30 , yIncreas = 0;
	int i;
	sf::Vector2f increas;
	if (m_life.size() >= 3) {
		yIncreas = 30;
		i = m_life.size()-3;
		xIncreas = m_life[i].getPosition().x;
	}
	else {
		yIncreas = 0;
		i = m_life.size() - 1;
		xIncreas = m_life[i].getPosition().x +30;
	}
	sf::Sprite heart;
	heart.setTexture(Resources::instance().getTexture(HeartStatus));
	heart.setPosition({xIncreas,
		m_life[i].getPosition().y + yIncreas });
	m_life.push_back(heart);
}

float Status::getTime() const
{
	return m_time;
}

int Status::getLife() const
{
	if (m_life.empty())
		return 0;

	return m_life.size();
}

void Status::setLife()
{
	if (m_life.size() == 1)
		m_life.clear();
	else
		m_life.erase(m_life.begin() + m_life.size() - 1);
}
//This function updates the key vector so that they are in the correct position on the board.
void Status::keyPick()
{
	float xIncreas = 800, yIncreas = 105;
	if (!m_key.empty())
		xIncreas = m_key[m_key.size() - 1].getPosition().x + 30;

	sf::Sprite key;
	key.setTexture(Resources::instance().getTexture(KeyStatus));
	key.setPosition({xIncreas,
		m_statusBar.getPosition().y + yIncreas });
	m_key.push_back(key);
}

int Status::getKey() const
{
	return m_key.size();
}

void Status::keyUsed()
{
	if (m_key.size() == 1)
		m_key.clear();
	else
		m_key.resize(m_key.size() - 1);
}

void Status::setPosition(sf::Vector2f position)
{
	m_statusBar.setPosition(position);
	float xIncreas = 600, yIncreas = 100;

	if (!m_life.empty())
		return;
	for (int i = 0; i < 3; i++, xIncreas += 30)
	{
		sf::Sprite heart;
		heart.setTexture(Resources::instance().getTexture(HeartStatus));
		heart.setPosition({ m_statusBar.getPosition().x + xIncreas,
			m_statusBar.getPosition().y + yIncreas });
		m_life.push_back(heart);
	}
}

void Status::newLevel()
{
	m_time = 45.f;
}

void Status::repeatLevel()
{
	m_level--;
}
