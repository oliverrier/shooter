 #include "GameState.h"



CGameState::CGameState(sf::RenderWindow* window, std::stack<CState*>* states ) : CState(window, states), SpaceshipPlayer()
{
	InitTextures();
	InitMusic();
	InitPlayer();
}

CGameState::~CGameState()
{
	delete SpaceshipPlayer;
}

//inits 
void CGameState::InitTextures()
{
	if(!Textures["PLAYER_IDLE"].loadFromFile("asset/sprite/spaceship/spaceship-1.png"))
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
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
	SpaceshipPlayer = new CEntity(*new CPlayerController(50), *new sf::Sprite(Textures["PLAYER_IDLE"]), 0, 0);
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
