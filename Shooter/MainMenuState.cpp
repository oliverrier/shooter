
#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initButtons();


}

MainMenuState::~MainMenuState()
{
	auto iterator = this->buttons.begin();

	for (iterator = this->buttons.begin(); iterator != this->buttons.end(); ++iterator)
	{
		delete iterator->second;
	}
}


void MainMenuState::initVariables()
{
}

void MainMenuState::initBackground()
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));

	if (!textureBackground.loadFromFile("asset/sprite/menu/mainMenu/wallpaper.png"))
		throw "ERROR:MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";

	this->background.setTexture(&this->textureBackground);
	
}


void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("asset/font/Space.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(1500, 400, 150, 50, &this->font, "Jouer",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(1500, 600, 150, 50, &this->font, "Quitter",
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
		this->endState();
	}
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& iterator : this->buttons)
	{
		iterator.second->render(target);
	}
}



void MainMenuState::updateInput(const float& dt)
{


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
