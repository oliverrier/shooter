#include "State.h"


CState::CState(sf::RenderWindow* window, std::stack<CState*>* states): Window(window), Quit(false),States(states) {
}

CState::~CState() {

}

const bool& CState::GetQuit() const
{
	return Quit;
}

void CState::EndState()
{
	Quit = true;
}


void CState::UpdateMousePosition()
{
	MousePosScreen = sf::Mouse::getPosition();
	MousePosWindow = sf::Mouse::getPosition(*Window);
	MousePosView = Window->mapPixelToCoords(sf::Mouse::getPosition(*Window));
}

