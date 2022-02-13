#include "Scene.h"


CScene::CScene(sf::RenderWindow& window, std::stack<CScene*>& states): Window(window), NumberOfTopScenesToDelete(0),Scenes(states) {
}

CScene::~CScene() {

}

const int& CScene::GetNumberOfTopScenesToDelete() const
{
	return NumberOfTopScenesToDelete;
}

void CScene::SetNumberOfTopScenesToDelete(int number)
{
	NumberOfTopScenesToDelete = number;
}


void CScene::UpdateMousePosition()
{
	MousePosScreen = sf::Mouse::getPosition();
	MousePosWindow = sf::Mouse::getPosition(Window);
	MousePosView = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
}

