#include "Game.h"

// contructors - destructor
CGame::CGame() :Window(*new sf::RenderWindow(sf::VideoMode(1920, 1080, DesktopMode.bitsPerPixel), "R-Type Final 2")) {
	InitWindow();
	InitStates();
}

CGame::~CGame() {
	delete &Window;

	while (!Scenes.empty()) {
		delete Scenes.top();
		Scenes.pop();
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
	Scenes.push(new CMainMenu(Window, Scenes));
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

	if (!Scenes.empty()) {
		Scenes.top()->Update(DeltaTime);
		const int numberOfSceneToDelete = Scenes.top()->GetNumberOfTopScenesToDelete();
		if (numberOfSceneToDelete > 0) {
			for (int i = 0; i < numberOfSceneToDelete; ++i)
			{
				delete Scenes.top();
				Scenes.pop();
			}
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
	if (!Scenes.empty())
		Scenes.top()->Render(Window); 

	Window.display();
}


void CGame::Run() {
	while (Window.isOpen()) {
		UpdateDeltaTime();
		Update();
 		Render();
	 }
}

