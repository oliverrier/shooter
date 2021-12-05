 #include "GameState.h"


GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states ) : State(window, states)
{
}

GameState::~GameState()
{
}


void GameState::endState()
{
	std::cout << "Ending GameState" << std::endl;
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();

	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		this->Player.move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->Player.move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		this->Player.move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->Player.move(dt, 0.f, 1.f);
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	
	this->Player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

    this->Player.render(target );	
}
