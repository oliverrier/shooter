#include "Game.h"

// contructors - destructor
CGame::CGame():Window(*new sf::RenderWindow(sf::VideoMode(1920, 1080, DesktopMode.bitsPerPixel), "R-Type Final 2")) {
	InitWindow();
	InitStates();
}

CGame::~CGame() {
	delete &Window;

	while (!States.empty()) {
		delete States.top();
		States.pop();
	}
}


// functions

void CGame::InitWindow() {

	// retrieves information from the screen
	DesktopMode = sf::VideoMode::getDesktopMode();

	// create the window 
	Window.setVerticalSyncEnabled(true);
}

void CGame::InitStates()
{
	States.push(new CMainMenu(Window, States));
}

void CGame::EndApplication()
{
	std::cout << "Ending Application" << std::endl;
}

void CGame::UpdateDeltaTime() {
	// retrieves the time elapsed since the last restart and thus the last frame 
	DeltaTime = DeltaTimeClock.restart().asSeconds();
}

void CGame::UpdateSFMLEvents() {

	while (Window.pollEvent(SfEvent)) {
		if (SfEvent.type == sf::Event::Closed)
			Window.close();
	}
}



void CGame::Update() {
	UpdateSFMLEvents();

	if (!States.empty()) {
		States.top()->Update(DeltaTime);

		if (States.top()->GetQuit()) {
			States.top()->EndState();
			delete States.top();
			States.pop();
		}
	}
	//Application end
	else {
		EndApplication();
		Window.close();
	}

}

void CGame::Render() {
	Window.clear();

	// render items
	if (!States.empty())
		States.top()->Render(Window); 

	Window.display();
}


void CGame::Run() {
	while (Window.isOpen()) {
		UpdateDeltaTime();
		Update();
		Render();
	 }
}

