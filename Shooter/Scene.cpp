#include "Scene.h"


CScene::CScene(sf::RenderWindow& window, std::stack<CScene*>& states): Window(window), Quit(false),States(states) {
}

CScene::~CScene() {

}

const bool& CScene::GetQuit() const
{
	return Quit;
}

void CScene::EndState()
{
	Quit = true;
}


void CScene::UpdateMousePosition()
{
	MousePosScreen = sf::Mouse::getPosition();
	MousePosWindow = sf::Mouse::getPosition(Window);
	MousePosView = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
}

