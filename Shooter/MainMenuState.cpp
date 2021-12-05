
#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
	this->initFonts();
	this->initButtons();


	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
	auto iterator = this->buttons.begin();

	for (iterator = this->buttons.begin(); iterator != this->buttons.end(); ++iterator)
	{
		delete iterator->second;
	}
}

void MainMenuState::endState()
{
	std::cout << "Ending MainMenuState" << std::endl;
}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50, &this->font, "Jouer", 
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(100, 300, 150, 50, &this->font, "Quitter", 
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

void MainMenuState::updateButtons()
{

	// Update all the buttons in the  state and handles their functionality
	for (auto  &iterator : this->buttons)
	{
		iterator.second->update(this->mousePosView);
	}

	//Play
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->states));
	}

	//Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->quit = true;
	}
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& iterator : this->buttons)
	{
		iterator.second->render(target);
	}
}



void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("asset/font/Doom2016Text.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}



void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		//to do
	}

}

void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);
	this->updateMousePosition();

	this->updateButtons();


}



void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->renderButtons(target);
}
