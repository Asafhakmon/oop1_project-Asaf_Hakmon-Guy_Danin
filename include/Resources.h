#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

enum picType { /// <Game Objects>
				CheesePic, DoorPic, DeleteGiftPic, 
				FreezePic, TimePic, LifePic, KeyPic, WallPic, SpacePic ,
				CatPic , MousePic , FrozenCat , 
				/// <Menu> & <Buttons>//
				GameOverPic , ObjectBeckgroundPic , 
				NewGameButton,HelpButton , ObjectInfoButton , ExitButton , ReturnToMenuButton, 
				TomAndJeryPic , TomAndJeryHelpPic , WinPic ,
				///<Status> 
				HeartStatus , KeyStatus , StatusPic};

enum SoundType { Pick, Eat , CatSound };

class Resources {
public:

	static Resources& instance();
	const sf::Texture& getTexture(int);
	const sf::SoundBuffer& getSound(int);
	const void playMusic();
	const sf::Font& getFont();

private:
	Resources();

	std::vector<sf::Texture> m_pic;
	std::vector<sf::SoundBuffer> m_sound;
	
	sf::Music m_music;
	sf::Font m_font;

};