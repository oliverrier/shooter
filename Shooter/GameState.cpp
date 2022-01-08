 #include "GameState.h"



GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states ) : State(window, states)
{
	this->initTextures();
	this->initPlayer();
}

GameState::~GameState()
{
	delete this->player;
}

//inits 
void GameState::initTextures()
{
	if(!this-> textures["PLAYER_IDLE"].loadFromFile("asset/sprite/spaceship/spaceship-1.png"))
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
}


void GameState::initPlayer()
{
	this->player = new Player(0, 0, this->textures["PLAYER_IDLE"]);
}


//functions
void GameState::updateInput(const float& dt)
{

	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		this->player->move(dt, -5.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(dt, 5.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		this->player->move(dt, 0.f, -5.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(dt, 0.f, 5.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->endState();
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	
	this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

    this->player->render(target );
}
