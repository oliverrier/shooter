#include "State.h"


State::State(sf::RenderWindow* window, std::stack<State*>* states) {
	this->window = window;
	this->quit = false;
	this->states = states;
}

State::~State() {

}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}

void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

const bool& State::getQuit() const
{
	return this->quit;
}
