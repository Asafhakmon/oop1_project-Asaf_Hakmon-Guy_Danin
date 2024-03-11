#include "Menu.h"
#include "Resources.h"

// Constructor for Menu class
Menu::Menu()
{
    m_window.create(sf::VideoMode(MenuFrameX, MenuFrameY), "Tom & Jerry - Menu");

    m_buttonsSprite.resize(ButtonsNum);
    for (int i = 0; i < ButtonsNum; i++)
    {
        static float posX = ButtonX, posY = ButtonY;
        m_buttonsSprite[i].setTexture(Resources::instance().getTexture(i + 14));
        m_buttonsSprite[i].setPosition(posX, posY);
        posY += ButtonsSpace;
    }
}

// Show method to display the menu and handle user interactions
MenuResult Menu::Show()
{
    sf::Sprite backgroundSprite(Resources::instance().getTexture(TomAndJeryPic));
    backgroundSprite.setPosition(0, 0);

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
                return ExitMenu;
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
                sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

                for (int i = 0; i < ButtonsNum; i++)
                {
                    if (m_buttonsSprite[i].getGlobalBounds().contains(mousePosF))
                    {
                        if (i == 0)
                            return NewGame;
                        else if (i == 1)
                            return Help;
                        else if (i == 2)
                            return ObjectInfo;
                        else if (i == 3)
                        {
                            m_window.close();
                            return ExitMenu;
                        }
                    }
                }
            }
        }

        sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
        sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
        for (int i = 0; i < ButtonsNum; i++)
        {
            if (m_buttonsSprite[i].getGlobalBounds().contains(mousePosF))
                m_buttonsSprite[i].setScale(1.1f, 1.1f);
            else
                m_buttonsSprite[i].setScale(1.0f, 1.0f);
        }

        m_window.clear();
        m_window.draw(backgroundSprite);
        for (int i = 0; i < ButtonsNum - 1; i++)
            m_window.draw(m_buttonsSprite[i]);
        m_window.display();
    }

    return ExitMenu;
}

// Method to display windows with background images and a return button
void Menu::ShowWindow(int picture, float x, float y)
{
    sf::Sprite windowBackgroundSprite(Resources::instance().getTexture(picture));
    windowBackgroundSprite.setPosition(0, 0);

    m_buttonsSprite[ReturnB].setPosition(x, y);

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
            sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

            if (m_buttonsSprite[ReturnB].getGlobalBounds().contains(mousePosF))
                m_buttonsSprite[ReturnB].setScale(1.1f, 1.1f);
            else
                m_buttonsSprite[ReturnB].setScale(1.0f, 1.0f);

            if (event.type == sf::Event::Closed)
            {
                m_window.close();
                return;
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (m_buttonsSprite[ReturnB].getGlobalBounds().contains(mousePosF))
                    return;
            }
        }

        m_window.clear();
        m_window.draw(windowBackgroundSprite);
        m_window.draw(m_buttonsSprite[ReturnB]);
        m_window.display();
    }
}

// Method to display different menus based on user selection
void Menu::ShowMenu()
{   
    while (m_window.isOpen())
    {
        Resources::instance().playMusic();
        MenuResult result = Show();

        switch (result)
        {
        case NewGame:
        {
            ExitType act = run();
            // Display appropriate window based on game exit type
            switch (act)
            {
            case GameOver:
                ShowWindow(GameOverPic, ReturnButtonX, ReturnButtonY);
                break;
            case Win:
                ShowWindow(WinPic, ReturnButtonX, ReturnButtonY);
                break;
            default:
                break;
            }
        }
        break;
        case Help:
            ShowWindow(TomAndJeryHelpPic, ReturnButtonX, ReturnButtonY);
            break;
        case ObjectInfo:
            ShowWindow(ObjectBeckgroundPic, ReturnButtonX, ReturnButtonY);
            break;
        case ExitMenu:
            m_window.close();
            break;
        default:
            break;
        }
    }
}

// Method to run the game and return the exit type
ExitType Menu::run()
{
    // Create and run the game controller
    GameController g;
    ExitType showtype = g.run();
    return showtype;
}
