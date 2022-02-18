#ifndef STATE_H
#define STATE_H

#include<stack>
#include "TextureDictionary.h"


class CScene
{

protected:
	std::stack<CScene*>& Scenes;
	sf::RenderWindow& Window;
	int NumberOfTopScenesToDelete;

	sf::Vector2i MousePosScreen;
	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;

public:
	CScene(sf::RenderWindow& window, std::stack<CScene*>& states);
	virtual ~CScene();

	const int& GetNumberOfTopScenesToDelete() const;

	void SetNumberOfTopScenesToDelete(int number);

	virtual void UpdateMousePosition();
	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget& target) = 0;

};

#endif