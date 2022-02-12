#ifndef GAME_H
#define GAME_H


#include "MainMenu.h"



class CGame
{

private:
	// variables 
	sf::VideoMode DesktopMode;
	sf::RenderWindow& Window;

	sf::Event SfEvent;

	sf::Clock DeltaTimeClock;
	float DeltaTime;

	std::stack<CScene*> States;
		
	// functions
	void InitWindow();
	void InitStates();

public:
	// constructors - destructor
	CGame();
	~CGame();

	// functions

	//regumar
	void EndApplication();


	//update
	void UpdateDeltaTime();
	void UpdateSFMLEvents();
	void Update();

	//render
	void Render();

	//core
	void Run();

};



#endif
