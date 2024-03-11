#include "Resources.h"

/**********************************************
This class uses a singleton to manage the resources of the programs, 
it loads the relevant resources in the constructor
************************************************/
Resources& Resources::instance()
{
    static Resources insta;
    return insta;
}

const sf::Texture& Resources::getTexture(int index) 
{
    return m_pic[index];
}

const sf::SoundBuffer& Resources::getSound(int index)
{
    return m_sound[index];
}

const void Resources::playMusic()
{
    if (m_music.getStatus() != sf::Music::Status::Playing) {
        m_music.setVolume(20);
        m_music.setLoop(true);
        m_music.play();
    }

}

const sf::Font& Resources::getFont() 
{
    return m_font;
}

Resources::Resources()
{
    m_pic.resize(StatusPic+1);
    for (int i = 0; i < m_pic.size(); i++) {
        if (i > 9) {
            int j = i > 19 ? 2 : 1;
            int k = i > 19 ? i - 20 : i - 10;
            char png[] = "  .png";
            png[0] = j + 48;
            png[1] = k + 48;
            m_pic[i].loadFromFile(png);
        }
        else {
            char png[] = " .png";
            png[0] = i + 48;
            m_pic[i].loadFromFile(png);
        }
    }

    m_sound.resize(CatSound+1);
    for (int i = 0; i < m_sound.size() ; i++)
    {
        char ogg[] = " .ogg";
        ogg[0] = i + 48;
        m_sound[i].loadFromFile(ogg);
    }

    m_font.loadFromFile("C:/Windows/Fonts/FTLTLT.TTF");
    m_music.openFromFile("tiger.ogg");
}



