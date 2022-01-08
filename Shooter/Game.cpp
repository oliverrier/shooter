#include "Game.h"

// contructors - destructor
CGame::CGame() {
	this->InitWindow();
	this->InitStates();
}

CGame::~CGame() {
	delete this->Window;

	while (!this->States.empty()) {
		delete this->States.top();
		this->States.pop();
	}
}


// functions

void CGame::InitWindow() {

	// retrieves information from the screen
	this->DesktopMode = sf::VideoMode::getDesktopMode();

	// create the window 
	this->Window = new sf::RenderWindow(sf::VideoMode(1920, 1080, this->DesktopMode.bitsPerPixel), "DOOM 2D");
	this->Window->setVerticalSyncEnabled(true);
}

void CGame::InitStates()
{
	this->States.push(new CMainMenuState(this->Window, &this->States));
}

void CGame::EndApplication()
{
	std::cout << "Ending Application" << std::endl;
}

void CGame::UpdateDeltaTime() {
	// retrieves the time elapsed since the last restart and thus the last frame 
	this->DeltaTime = this->DeltaTimeClock.restart().asSeconds();
}

void CGame::UpdateSFMLEvents() {

	while (this->Window->pollEvent(this->SfEvent)) {
		if (this->SfEvent.type == sf::Event::Closed)
			this->Window->close();
	}
}



void CGame::Update() {
	this->UpdateSFMLEvents();

	if (!this->States.empty()) {
		this->States.top()->Update(this->DeltaTime);

		if (this->States.top()->GetQuit()) {
			this->States.top()->EndState();
			delete this->States.top();
			this->States.pop();
		}
	}
	//Application end
	else {
		this->EndApplication();
		this->Window->close();
	}

}

void CGame::Render() {
	this->Window->clear();

	// render items
	if (!this->States.empty())
		this->States.top()->Render(this->Window); 

	this->Window->display();
}


void CGame::Run() {
	while (this->Window->isOpen()) {
		this->UpdateDeltaTime();
		this->Update();
		this->Render();
	 }
}

