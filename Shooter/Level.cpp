#include "Level.h"
#include "PlayerController.h"
#include "PauseMenu.h"

CLevel::CLevel(sf::RenderWindow& window, std::stack<CScene*>& states ) : CScene(window, states), 
SpaceshipPlayer(*new CEntity("PLAYER", *new CPlayerController(250), *new SSpriteComponent(*new sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_BASE_IDLE")), 0.5, 0.5))),
MovementComponent(*new CMovementComponent(100))
{
	AddBackground(0.f);
	AddBackground((float)Window.getSize().x);

	InitMusic();
}

CLevel::~CLevel()
{
	delete &SpaceshipPlayer;
}

void CLevel::InitMusic() {
	// Load a music to play
	if (!Music.openFromFile("asset/musics/r-type-final-2-ost-investigation-abandoned-space-city.wav"))
		throw "ERROR:MAIN_MENU_STATE::FAILED_TO_LOAD_MUSIC";
	Music.setLoop(true);
	Music.play();
}

void CLevel::AddBackground(float positionX)
{
	Backgrounds.push_back(*new sf::RectangleShape());
	Backgrounds.back().setSize(sf::Vector2f((float)Window.getSize().x, (float)Window.getSize().y));
	Backgrounds.back().setTexture(&CTextureDictionary::GetTexture("BACKGROUND_SPACE"));
	Backgrounds.back().setPosition({ positionX, 0 });
}


//functions
void CLevel::UpdateInput(const float& dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		Scenes.push(new CPauseMenu(Window, Scenes));

}

void CLevel::UpdateBackground(const float& dt)
{
	for (auto& background : Backgrounds)
	{
		MovementComponent.Move(dt, background, -1, 0);
	}
	const float rightSideFirstBackgroundPosition = Backgrounds.front().getGlobalBounds().left + Backgrounds.front().getGlobalBounds().width;
	if (rightSideFirstBackgroundPosition < 0)
	{
		Backgrounds.pop_front();
		AddBackground((float)Window.getSize().x);
	}
}

void CLevel::Update(const float& dt)
{
	UpdateMousePosition();
	UpdateInput(dt);
	UpdateBackground(dt);

	SpaceshipPlayer.Update(dt);
}

void CLevel::Render(sf::RenderTarget& target)
{
	for (auto& background : Backgrounds)
	{
		target.draw(background);
	}
	SpaceshipPlayer.Render(target);
}
