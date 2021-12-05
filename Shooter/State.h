#ifndef STATE_H
#define STATE_H


#include "Entity.h"

class State
{

protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;


	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateMousePosition();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;

};

#endif