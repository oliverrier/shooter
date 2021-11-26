
#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window) : State(window)
{

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
}


void MainMenuState::endState()
{
	std::cout << "Ending GameState" << std::endl;
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		//to do
	}

}

void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);

}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
}
