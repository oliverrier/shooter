#ifndef STATE_H
#define STATE_H


#include "Entity.h"
class CScene
{

protected:
	std::stack<CScene*>& States;
	sf::RenderWindow& Window;
	bool Quit;

	sf::Vector2i MousePosScreen;
	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;

public:
	CScene(sf::RenderWindow& window, std::stack<CScene*>& states);
	virtual ~CScene();

	const bool& GetQuit() const;

	void EndState();

	virtual void UpdateMousePosition();
	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget& target) = 0;

};

#endif