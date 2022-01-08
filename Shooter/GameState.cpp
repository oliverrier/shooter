 #include "GameState.h"



CGameState::CGameState(sf::RenderWindow* window, std::stack<CState*>* states ) : CState(window, states)
{
	InitTextures();
	InitPlayer();
}

CGameState::~CGameState()
{
	delete Spaceship;
}

//inits 
void CGameState::InitTextures()
{
	if(! Textures["PLAYER_IDLE"].loadFromFile("asset/sprite/spaceship/spaceship-1.png"))
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
}


void CGameState::InitPlayer()
{
	Spaceship = new CSpaceship(0, 0, Textures["PLAYER_IDLE"]);
}


//functions
void CGameState::UpdateInput(const float& dt)
{

	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		Spaceship->Move(dt, -5.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		Spaceship->Move(dt, 5.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		Spaceship->Move(dt, 0.f, -5.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		Spaceship->Move(dt, 0.f, 5.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		EndState();
}

void CGameState::Update(const float& dt)
{
	UpdateMousePosition();
	UpdateInput(dt);
	
	Spaceship->Update(dt);
}

void CGameState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = Window;

	Spaceship->Render(target );
}
