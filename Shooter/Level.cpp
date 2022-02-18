#include "Level.h"
#include "PauseMenu.h"

CLevel::CLevel(sf::RenderWindow& window, std::stack<CScene*>& states) : CScene(window, states),
PlayerEntity(CPlayerEntity("PLAYER", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_BASE_IDLE")), *this)),
PlayerController(CPlayerController(Window, 250)),
ProjectileController(CBaseProjectileController(500)),
AiController(CAiController(Window, 150)),
MovementComponent(CMovementComponent(100.f))
{
	InitBackgrounds();
	InitMusic();
	InitWaves();
	PlayerEntity.GetSprite().setScale({ 0.25f, 0.25f });
	CBaseWeaponEntity* weapon = new CBaseWeaponEntity("SOLAR_WEAPON", sf::Sprite(CTextureDictionary::GetTexture("SOLAR_WEAPON")));
	PlayerEntity.SetChildEntity(weapon);
	weapon->GetSprite().setScale({ 0.4f, 0.4f });
	weapon->GetSprite().setPosition(GetPositionMiddleRight(weapon->GetSprite(), PlayerEntity.GetSprite()));
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
	Waves.push_back(std::vector<CAiEntity>{ 
		CAiEntity("AiSlime", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_SLIME"))),
		CAiEntity("AiRed", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_RED"))),
		CAiEntity("AiGreen", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_GREEN"))),
	});
	Waves.push_back(std::vector<CAiEntity>{
		CAiEntity("AiPurple", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_PURPLE"))),
		CAiEntity("AiPink", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_PINK"))),
		CAiEntity("AiDark", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_DARK"))),
		CAiEntity("AiBlack", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_BLACK"))),
	});
	Waves.push_back(std::vector<CAiEntity>{
		CAiEntity("AiSlime2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_SLIME"))),
		CAiEntity("AiRed2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_RED"))),
		CAiEntity("AiGreen2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_GREEN"))),
		CAiEntity("AiPurple2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_PURPLE"))),
		CAiEntity("AiPink2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_PINK"))),
		CAiEntity("AiDark2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_DARK"))),
		CAiEntity("AiBlack2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_BLACK"))),
	});
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

	for (auto& wave : Waves[CurrentWave])
	{
		AiController.UpdateLogic(dt, wave, PlayerEntity);
	}
	for (CBaseProjectileEntity* playerProjectile : PlayerProjectiles)
	{
		ProjectileController.UpdateLogic(dt, *playerProjectile);
	}
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
	for (auto& projectile : PlayerProjectiles)
	{
		std::cout << projectile->GetSprite().getPosition().x << std::endl;
		target.draw(projectile->GetSprite());
	}
}

void CLevel::SpawnProjectile(CEntity& entity) {
	CBaseProjectileEntity* projectile = new CBaseProjectileEntity("BASE_PROJECTILE", sf::Sprite(CTextureDictionary::GetTexture("BASE_PROJECTILE")));
	projectile->GetSprite().setPosition(GetPositionMiddleRight(projectile->GetSprite(), entity.GetSprite()));
	PlayerProjectiles.push_back(projectile);

}
