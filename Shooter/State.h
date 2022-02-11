#ifndef STATE_H
#define STATE_H


#include "Entity.h"
class CState
{

protected:
	std::stack<CState*>* States;
	sf::RenderWindow* Window;
	bool Quit;

	sf::Vector2i MousePosScreen;
	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;

public:
	CState(sf::RenderWindow* window, std::stack<CState*>* states);
	virtual ~CState();

	const bool& GetQuit() const;

	void EndState();

	virtual void UpdateMousePosition();
	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;

};

#endif