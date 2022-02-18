#include "Level.h"
#include "PlayerController.h"
#include "MovementComponent.h"
#include "PauseMenu.h"

CLevel::CLevel(sf::RenderWindow& window, std::stack<CScene*>& states) : CScene(window, states),
PlayerEntity(CEntity("PLAYER", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_BASE_IDLE")))),
PlayerController(CPlayerController(Window, 250)),
MovementComponent(CMovementComponent(100.f))
{
	InitBackgrounds();
	InitMusic();
	InitWaves();
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

void CLevel::InitBackgrounds()
{
	for (auto& background : Backgrounds)
	{
		background.setSize(sf::Vector2f((float)Window.getSize().x, (float)Window.getSize().y));
		background.setTexture(&CTextureDictionary::GetTexture("BACKGROUND_SPACE"));
	}
	Backgrounds[0].setPosition({ 0.f, 0.f });
	Backgrounds[1].setPosition({ (float)Window.getSize().x, 0.f });
}

void CLevel::InitWaves()
{
	Waves.push_back(std::vector<CAiEntity>{ CAiEntity("AiTest", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_SLIME"))) });
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
		const float rightSideBackgroundPosition = background.getGlobalBounds().left + background.getGlobalBounds().width;
		if (rightSideBackgroundPosition < 0)
		{
			background.setPosition({ (float)Window.getSize().x, 0.f });
		}
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
	for (auto& wave : Waves[CurrentWave])
	{
		target.draw(wave.GetSprite());
	}
}
