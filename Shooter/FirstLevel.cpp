 #include "FirstLevel.h"
#include "PlayerController.h"


CFirstLevel::CFirstLevel(sf::RenderWindow& window, std::stack<CScene*>& states ) : CScene(window, states), SpaceshipPlayer(*new CEntity("PLAYER", *new CPlayerController(250), *new SSpriteComponent(*new sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_BASE_IDLE")), 0.5, 0.5)))
{
	InitMusic();
}

CFirstLevel::~CFirstLevel()
{
	delete &SpaceshipPlayer;
}

void CFirstLevel::InitMusic() {
	// Load a music to play
	if (!Music.openFromFile("asset/musics/r-type-final-2-ost-investigation-abandoned-space-city.wav"))
		throw "ERROR:MAIN_MENU_STATE::FAILED_TO_LOAD_MUSIC";
	Music.setLoop(true);
	Music.play();
}


//functions
void CFirstLevel::UpdateInput(const float& dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		EndState();
}

void CFirstLevel::Update(const float& dt)
{
	UpdateMousePosition();
	UpdateInput(dt);
	
	SpaceshipPlayer.Update(dt);
}

void CFirstLevel::Render(sf::RenderTarget& target)
{
	SpaceshipPlayer.Render(target);
}
