#include "Level.h"
#include "PauseMenu.h"
#include <string>
CLevel::CLevel(sf::RenderWindow& window, std::stack<CScene*>& states) : CScene(window, states),
PlayerEntity(CPlayerEntity("PLAYER", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_BASE_IDLE")), *this)),
PlayerController(CPlayerController(Window, 250)),
ProjectileController(CBaseProjectileController(500)),
AiController(CAiController(Window, 200)),
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

	Font.loadFromFile("asset/font/Space.ttf");

	TextLife.setFont(Font);
	TextLife.setString( to_string(PlayerEntity.GetCurrentLife()) + "/" + to_string(PlayerEntity.GetMaxLife()) + "pv");
	TextLife.setFillColor(sf::Color::Green);
	TextLife.setCharacterSize(50);

	TextEnd.setFont(Font);
	TextEnd.setCharacterSize(300);
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
	Waves.push_back(std::vector<CAiEntity*>{ 
		new CAiEntity("AiSlime", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_SLIME")), *this),
			new CAiEntity("AiRed", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_RED")), *this),
			new CAiEntity("AiGreen", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_GREEN")), *this),
	});
	Waves.push_back(std::vector<CAiEntity*>{
		new CAiEntity("AiPurple", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_PURPLE")), *this),
			new CAiEntity("AiPink", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_PINK")), *this),
			new CAiEntity("AiDark", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_DARK")), *this),
			new CAiEntity("AiBlack", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_BLACK")), *this),
	});
	Waves.push_back(std::vector<CAiEntity*>{
		new CAiEntity("AiSlime2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_SLIME")), *this),
			new CAiEntity("AiRed2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_RED")), *this),
			new CAiEntity("AiGreen2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_GREEN")), *this),
			new CAiEntity("AiPurple2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_PURPLE")), *this),
			new CAiEntity("AiPink2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_PINK")), *this),
			new CAiEntity("AiDark2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_DARK")), *this),
			new CAiEntity("AiBlack2", sf::Sprite(CTextureDictionary::GetTexture("SPACESHIP_BLACK")), *this),
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

void CLevel::UpdateControllers(const float& dt)
{
	PlayerController.UpdateLogic(dt, PlayerEntity);

	for (int i = 0; i < Waves[CurrentWave].size(); i++)
	{
		CAiEntity* wave = Waves[CurrentWave][i];

		if (wave->GetCurrentLife() <= 0)
		{
			auto it = std::next(Waves[CurrentWave].begin(), i);
			if (it != Waves[CurrentWave].end())
			{
				delete wave;
				wave = nullptr;
				Waves[CurrentWave].erase(it);
			}
			continue;
		}
		AiController.UpdateLogic(dt, *wave, PlayerEntity);
	}

	for (int i = 0; i < PlayerProjectiles.size(); i++)
	{
		ProjectileController.UpdateLogic(dt, PlayerProjectiles[i], Waves[CurrentWave], PlayerEntity, PlayerProjectiles, i);
	}
}

void CLevel::Update(const float& dt)
{
	if (IsEnd)
	{
		DelayToEndGame += dt;
		if (DelayToEndGame >= 3)
		{
			SetNumberOfTopScenesToDelete(1);
		}
		return;
	}

	UpdateMousePosition();
	UpdateInput(dt);
	UpdateBackground(dt);
	UpdateControllers(dt);

	TextLife.setString(to_string(PlayerEntity.GetCurrentLife()) + "/" + to_string(PlayerEntity.GetMaxLife()) + "pv");

	if (PlayerEntity.GetCurrentLife() <= 0)
	{
		FinishGame("DEFAITE", sf::Color::Red);
	}

	if (Waves[CurrentWave].size() == 0)
	{
		if (++CurrentWave > Waves.size() - 1)
		{
		    FinishGame("VICTOIRE", sf::Color::Green);
		}
	}

}

void CLevel::SpawnProjectile(CEntity& entity, sf::Vector2f direction, sf::Color color) {
	CBaseProjectileEntity* projectile = new CBaseProjectileEntity("BASE_PROJECTILE", sf::Sprite(CTextureDictionary::GetTexture("BASE_PROJECTILE")), direction);
	projectile->GetSprite().setColor(color);
	projectile->GetSprite().setPosition(GetPositionMiddleRight(projectile->GetSprite(), entity.GetSprite()));

	const sf::Vector2f projectilePosition = projectile->GetSprite().getPosition();
	if (color == sf::Color::Red && (projectilePosition.x != 0.f || projectilePosition.y != 0.f) && (direction.x != 0.f || direction.y != 0.f)) {
		const float angle = GetAngleBetweenVector(direction, projectilePosition);
		projectile->GetSprite().setRotation(angle);
	}

	PlayerProjectiles.push_back(projectile);

}

void CLevel::FinishGame(const char* string, sf::Color color)
{
	TextEnd.setString(string);
	TextEnd.setFillColor(color);
	const sf::FloatRect viewport = (sf::FloatRect)Window.getViewport(Window.getView());
	const auto textEndGlobalBound = TextEnd.getGlobalBounds();
	const float centerXOfWindow = viewport.width / 2.f - textEndGlobalBound.width / 2;
	const float centerYOfWindow = viewport.height / 2.f - textEndGlobalBound.height;
	TextEnd.setPosition({ centerXOfWindow, centerYOfWindow });
	IsEnd = true;
}


void CLevel::Render(sf::RenderTarget& target)
{
	for (auto& background : Backgrounds)
	{
		target.draw(background);
	}

	if (!IsEnd)
	{
		PlayerEntity.Render(target);

		for (auto& wave : Waves[CurrentWave])
		{
			target.draw(wave->GetSprite());
		}
		for (auto& projectile : PlayerProjectiles)
		{
			if (projectile != nullptr) {
				target.draw(projectile->GetSprite());
			}
		}
		target.draw(TextLife);
	}
	else {
		target.draw(TextEnd);
	}

}