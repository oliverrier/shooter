#ifndef STATE_H
#define STATE_H


#include "Spaceship.h"

class CState
{

protected:
	std::stack<CState*>* States;
	sf::RenderWindow* Window;
	std::map<std::string, sf::Texture> Textures;
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
	virtual void Render(sf::RenderTarget* target = NULL) = 0;

};

#endif