#include "Board.h"
#include "Cat.h"
#include "Mouse.h"
#include "Resources.h"


Board::Board()
    :m_rows(0), m_cols(0), m_status(), m_cheese(0) ,m_levelScore(0)
{
    if (!newBoard())
    {
        std::cout << "file is empty\n";
        exit(EXIT_FAILURE);
    }
    loadSound();
}

/// This function loads the buffer from the Resources class into the effects vector

void Board::loadSound()
{
    m_effect.resize(SoundSize);
    for (int i = 0; i < SoundSize; i++)
    {
        m_effect[i].setBuffer(Resources::instance().getSound(i));
    }
    
}

bool Board::setTime(sf::Time time)
{
    return (m_status.setTime(time));
}

/**************************************************************************************
This function reads from a playlist file the relevant stage if it exists,
then counts how many rows and columns there are in the stage 
and updates the data structure accordingly
***************************************************************************************/
bool Board::newBoard()
{
    m_file = std::ifstream("playlist.txt");
    m_status.setLevel();
    std::string level;
    int i;
    for (i = 0; i < m_status.getLevel() && (m_file >> level); i++);

    if (i != m_status.getLevel())
    {
        return false;
    }

    auto file = std::ifstream(level);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file " << level << std::endl;

    }

    char c;
    int count = 0;
    while (file.get(c))
    {
        if (c == '\n')
        {
            count = 0;
            m_rows++;
            continue;
        }
        count++;
        if (m_cols < count)
            m_cols = count;
    }
    m_levelName = level;
    m_rows++;

    m_Tile.resize(m_rows);

    return true;
}

/**************************************************************
This function builds the data structure according to the relevant stage, 
takes care of matching the size of the objects against the stage size and the board size.
***************************************************************/

void Board::buildLevel(Cat* cats, Mouse* mouse)
{
    auto file = std::ifstream(m_levelName);
    float colIncreas = (float)(FRM_X / m_cols);
    float rowIncreas = (float)(FRM_Y / m_rows);

    float row = 0, col;
    for (int i = 0; i < m_rows; i++, row += rowIncreas)
    {
        col = 0;
        char c;
        for (int j = 0; j <= m_cols && file.get(c); j++, col += colIncreas)
        {
            if (c == '%')
            {
                mouse->setPosition({ col,row });
                mouse->setSize({ colIncreas / 100,rowIncreas / 100 });
                m_mouseLastPosition = m_mouseCurPosition = { col,row };
                c = ' ';
            }
            else if (c == '^')
            {
                cats->pushBack({ col,row }, { colIncreas / 100,rowIncreas / 100 });
                m_catLastPosition.push_back({ col, row });
                c = ' ';
            }
            Tile t(c, { col , row }, { colIncreas / 100 , rowIncreas / 100 });
            m_Tile[i].push_back(t);
            if (c == '*')
                m_cheese++;
        }
    }
    m_status.setPosition({ 0.f,row });

}
/*********************************************************************************
This function display the objects in their relevant position as obtained from the
CharactersAndObjects class and also calls the status to display itself
******************************************************************************/
void Board::display(sf::RenderWindow* window)
{
    for (int i = 0; i < m_Tile.size(); i++)
    {
        for (int j = 0; j < m_Tile[i].size(); j++)
        {
            sf::RectangleShape temp = m_Tile[i][j].getShape();
            temp.setTexture(&Resources::instance().getTexture(m_Tile[i][j].getPicType()));
            window->draw(temp);
        }
    }
    m_status.display(window);
}

//This function updates a state after a mouse movement and returns the action to the game controller
Gift_t Board::setBoard(sf::Vector2f position)
{
    Gift_t act = None;

    int col = (FRM_X / m_cols);
    int row = (FRM_Y / m_rows);
    int score = m_Tile[(int)position.y / row][(int)position.x / col].getScore();

    m_status.setScore(score);
    if(score>0)
        m_levelScore += score;

    if (score == Key) {
        m_status.keyPick();  
        m_effect[Pick].play();
    }

    else if (score == Cheese)
    {
        m_effect[Eat].play();
        m_effect[Eat].setPlayingOffset(sf::seconds(1.3f));
        m_cheese--;
        if (m_cheese == 0) {
            return EndLevel;
        }
    }
    else if (score == Gift)
    {
        m_effect[Pick].play();
        act = m_Tile[(int)position.y / row][(int)position.x / col].giftAct();
        switch (act)
        {
        case Time:
            addTime();
            break;
        case Life:
            addLife();
            break;
        }
    }

    m_Tile[(int)position.y / row][(int)position.x / col].update();
    return act;
}
/******************************************************************
This function takes the form of an object that moves and returns whether its
movement is possible in the data structure
*******************************************************************/
bool Board::isValid(sf::RectangleShape temp)
{
    int col = (FRM_X / m_cols);
    int row = (FRM_Y / m_rows);
    int key = m_status.getKey();
    if (temp.getPosition().x / col < 0
        || temp.getPosition().x / col > m_cols
        || temp.getPosition().y / row < 0
        || temp.getPosition().y / col > m_rows)
        return false;

    if (m_Tile[(temp.getPosition().y / row)][(temp.getPosition().x / col)].block(key, temp))
    {
        if (key < m_status.getKey())
            m_status.keyUsed();
        return true;
    }
    return false;
}

void Board::addTime()
{
    m_status.addTime();
}

void Board::addLife()
{
    m_status.addLife();
}
/**********************************************************
This function checks the reason for the end of the stage and 
updates the data accordingly, 
returning whether the game is over or continues
***********************************************************/
ExitType Board::checkEnd(Cat* cat, Mouse* mouse)
{
    if (cat->isIn(mouse->getShape()))
    {
		m_status.setLife();
        if (restartLevel(cat, mouse)) {
            return Continue;
        }
        return GameOver;
    }
    if (m_status.getTime() == 0) {
        m_status.setScore(-m_levelScore);
        m_status.setLife();
        m_status.repeatLevel();
        if (m_status.getLife() == 0)
            return GameOver;
    }
    m_Tile.clear();
    m_cheese = 0;
    m_cols = 0;
    m_rows = 0;
    m_levelScore = 0;
    m_status.newLevel();
    cat->deleteAllcats();
    m_catLastPosition.clear();
    if (newBoard())
    {        
        buildLevel(cat, mouse);
        return Continue;
    }
    return Win;
}
//This function returns the shape and position of the mouse as stored in the data structure. 
sf::FloatRect Board::getMouse() const
{
    float colIncreas = (float)(FRM_X / m_cols);
    float rowIncreas = (float)(FRM_Y / m_rows);

    sf::RectangleShape r({ colIncreas , rowIncreas });
    r.setPosition(m_mouseCurPosition);

    return r.getGlobalBounds();
}

void Board::saveMouse(sf::Vector2f p)
{
    m_mouseCurPosition = p;
}

bool Board::restartLevel(Cat* cat, Mouse* mouse)
{
    if (m_status.getLife() == 0)
        return false;

    mouse->setPosition(m_mouseLastPosition);
    m_mouseCurPosition = m_mouseLastPosition;

    cat->setPosition(m_catLastPosition);
    return true;
}
