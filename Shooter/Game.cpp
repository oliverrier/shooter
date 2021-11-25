#include "Game.h"

// contructors - destructor
Game::Game() {
	this->initWindow();
	this->initStates();
}

Game::~Game() {
	delete this->window;

	while (this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}


// functions

void Game::initWindow() {

	// retrieves information from the screen
	this->desktopMode = sf::VideoMode::getDesktopMode();

	// create the window 
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080, this->desktopMode.bitsPerPixel), "DOOM 2D");
	this->window->setVerticalSyncEnabled(true);
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window));
	this->states.push(new GameState(this->window));
}

void Game::endApplication()
{
	std::cout << "Ending Application" << std::endl;
}

void Game::updateDeltaTime() {
	// retrieves the time elapsed since the last restart and thus the last frame 
	this->deltaTime = this->deltaTimeClock.restart().asSeconds();
}

void Game::updateSFMLEvents() {

	while (this->window->pollEvent(this->sfEvent)) {
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}



void Game::update() {
	this->updateSFMLEvents();

	if (!this->states.empty()) {
		this->states.top()->update(this->deltaTime);

		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Application end
	else {
		this->endApplication();
		this->window->close();
	}

}

void Game::render() {
	this->window->clear();

	// render items
	if (!this->states.empty())
		this->states.top()->render(this->window); 

	this->window->display();
}


void Game::run() {
	while (this->window->isOpen()) {
		this->updateDeltaTime();
		this->update();
		this->render();
	 }
}

