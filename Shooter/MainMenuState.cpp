#include "MainMenuState.h"

CMainMenuState::CMainMenuState(sf::RenderWindow* Window, std::stack<CState*>* States) : CState(Window, States)
{
	this->InitVariables();
	this->InitBackground();
	this->InitFonts();
	this->InitButtons();


}

CMainMenuState::~CMainMenuState()
{
	auto iterator = this->Buttons.begin();

	for (iterator = this->Buttons.begin(); iterator != this->Buttons.end(); ++iterator)
	{
		delete iterator->second;
	}
}


void CMainMenuState::InitVariables()
{
}

void CMainMenuState::InitBackground()
{
	this->Background.setSize(sf::Vector2f(Window->getSize().x, Window->getSize().y));

	if (!TextureBackground.loadFromFile("asset/sprite/menu/mainMenu/wallpaper.png"))
		throw "ERROR:MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";

	this->Background.setTexture(&this->TextureBackground);
	
}


void CMainMenuState::InitFonts()
{
	if (!this->Font.loadFromFile("asset/font/Space.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void CMainMenuState::InitButtons()
{
	this->Buttons["GAME_STATE"] = new CButton(1500, 400, 150, 50, &this->Font, "Jouer",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->Buttons["EXIT_STATE"] = new CButton(1500, 600, 150, 50, &this->Font, "Quitter",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}


void CMainMenuState::UpdateButtons()
{

	// Update all the buttons in the  state and handles their functionality
	for (auto  &iterator : this->Buttons)
	{
		iterator.second->Update(this->MousePosView);
	}

	//Play
	if (this->Buttons["GAME_STATE"]->IsPressed())
	{
		this->States->push(new CGameState(this->Window, this->States));
	}

	//Quit the game
	if (this->Buttons["EXIT_STATE"]->IsPressed())
	{
		this->EndState();
	}
}

void CMainMenuState::RenderButtons(sf::RenderTarget* target)
{
	for (auto& iterator : this->Buttons)
	{
		iterator.second->Render(target);
	}
}



void CMainMenuState::UpdateInput(const float& dt)
{


}

void CMainMenuState::Update(const float& dt)
{
	this->UpdateInput(dt);
	this->UpdateMousePosition();

	this->UpdateButtons();


}



void CMainMenuState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->Window;

	target->draw(this->Background);

	this->RenderButtons(target);
}
