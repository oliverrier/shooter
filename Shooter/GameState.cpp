 #include "GameState.h"
#include "PlayerController.h"


CGameState::CGameState(sf::RenderWindow* window, std::stack<CState*>* states ) : CState(window, states), SpaceshipPlayer()
{
	InitMusic();
	InitPlayer();
}

CGameState::~CGameState()
{
	delete SpaceshipPlayer;
}

void CGameState::InitMusic() {
	// Load a music to play
	if (!Music.openFromFile("asset/musics/r-type-final-2-ost-investigation-abandoned-space-city.wav"))
		throw "ERROR:MAIN_MENU_STATE::FAILED_TO_LOAD_MUSIC";
	Music.setLoop(true);
	Music.play();
}

void CGameState::InitPlayer()
{
	SpaceshipPlayer = new CEntity("PLAYER", * new CPlayerController(50), *new CSpriteComponent(*new sf::Sprite(*CTextureDictionary::GetTexture("SPACESHIP_BASE_IDLE")), 0.5, 0.5));
}


//functions
void CGameState::UpdateInput(const float& dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		EndState();
}

void CGameState::Update(const float& dt)
{
	UpdateMousePosition();
	UpdateInput(dt);
	
	SpaceshipPlayer->Update(dt);
}

void CGameState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = Window;

	SpaceshipPlayer->Render(target);
}
