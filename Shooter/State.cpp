#include "State.h"


CState::CState(sf::RenderWindow* Window, std::stack<CState*>* States) {
	this->Window = Window;
	this->Quit = false;
	this->States = States;
}

CState::~CState() {

}

const bool& CState::GetQuit() const
{
	return this->Quit;
}

void CState::EndState()
{
	this->Quit = true;
}


void CState::UpdateMousePosition()
{
	this->MousePosScreen = sf::Mouse::getPosition();
	this->MousePosWindow = sf::Mouse::getPosition(*this->Window);
	this->MousePosView = this->Window->mapPixelToCoords(sf::Mouse::getPosition(*this->Window));
}

