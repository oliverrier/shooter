#include "Level.h"
#include "PlayerController.h"
#include "MovementComponent.h"
#include "PauseMenu.h"

CLevel::CLevel(sf::RenderWindow& window, std::stack<CScene*>& states) : CScene(window, states),
PlayerEntity(CEntity("PLAYER", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_BASE_IDLE")))),
PlayerController(CPlayerController(Window, 250)),
MovementComponent(CMovementComponent(100.f))
{
	AddBackground(0.f);
	AddBackground((float)Window.getSize().x);

	InitMusic();
	PlayerEntity.GetSprite().setScale({ 0.5, 0.5 });
}

CLevel::~CLevel()
{
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

	PlayerController.UpdateLogic(dt, PlayerEntity);
}

void CLevel::Render(sf::RenderTarget& target)
{
	for (auto& background : Backgrounds)
	{
		target.draw(background);
	}
	PlayerEntity.Render(target);
}
