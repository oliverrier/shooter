#ifndef GAME_H
#define GAME_H


#include "MainMenuState.h"



class Game
{

private:
	// variables 
	sf::VideoMode desktopMode;
	sf::RenderWindow* window;

	sf::Event sfEvent;

	sf::Clock deltaTimeClock;
	float deltaTime;

	std::stack<State*> states;
		
	// functions
	void initWindow();
	void initStates();

public:
	// constructors - destructor
	Game();
	~Game();

	// functions

	//regumar
	void endApplication();


	//update
	void updateDeltaTime();
	void updateSFMLEvents();
	void update();

	//render
	void render();

	//core
	void run();

};



#endif
