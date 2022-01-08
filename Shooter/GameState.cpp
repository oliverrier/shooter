 #include "GameState.h"



CGameState::CGameState(sf::RenderWindow* Window, std::stack<CState*>* States ) : CState(Window, States)
{
	this->InitTextures();
	this->InitPlayer();
}

CGameState::~CGameState()
{
	delete Spaceship;
}

//inits 
void CGameState::InitTextures()
{
	if(!this-> Textures["PLAYER_IDLE"].loadFromFile("asset/sprite/spaceship/spaceship-1.png"))
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
}


void CGameState::InitPlayer()
{
	Spaceship = new CSpaceship(0, 0, this->Textures["PLAYER_IDLE"]);
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
		this->EndState();
}

void CGameState::Update(const float& dt)
{
	this->UpdateMousePosition();
	this->UpdateInput(dt);
	
	Spaceship->Update(dt);
}

void CGameState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->Window;

	Spaceship->Render(target );
}
