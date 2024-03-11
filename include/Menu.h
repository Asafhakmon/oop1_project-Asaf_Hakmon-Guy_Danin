#pragma once
#include "GameController.h"

enum MenuResult { Nothing, NewGame, Help, ObjectInfo, ExitMenu,SoundOff };
enum buttonType  {HelpB , NewB , ObjectB , ExitB , ReturnB };

const int ButtonsNum = 5 ,MenuFrameX=1800, MenuFrameY=700,
          SoundVolume=50 , ButtonsSpace=100,
          ReturnButtonX=20 ,ReturnButtonY=550;

const float  ButtonX = 700, ButtonY = 85;

class Menu {
public:
    Menu();

    MenuResult Show();
    void ShowMenu();
    void ShowWindow(int , float, float);
    ExitType run();

private:

    sf::RenderWindow m_window;
    std::vector<sf::Sprite> m_buttonsSprite;

};
