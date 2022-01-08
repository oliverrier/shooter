#include "MainMenuState.h"

CMainMenuState::CMainMenuState(sf::RenderWindow* window, std::stack<CState*>* states) : CState(window, states)
{
	InitVariables();
	InitBackground();
	InitFonts();
	InitButtons();


}

CMainMenuState::~CMainMenuState()
{
	auto iterator = Buttons.begin();

	for (iterator = Buttons.begin(); iterator != Buttons.end(); ++iterator)
	{
		delete iterator->second;
	}
}


void CMainMenuState::InitVariables()
{
}

void CMainMenuState::InitBackground()
{
	Background.setSize(sf::Vector2f(Window->getSize().x, Window->getSize().y));

	if (!TextureBackground.loadFromFile("asset/sprite/menu/mainMenu/wallpaper.png"))
		throw "ERROR:MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";

	Background.setTexture(&TextureBackground);
	
}


void CMainMenuState::InitFonts()
{
	if (!Font.loadFromFile("asset/font/Space.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void CMainMenuState::InitButtons()
{
	Buttons["GAME_STATE"] = new CButton(1500, 400, 150, 50, &Font, "Jouer",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	Buttons["EXIT_STATE"] = new CButton(1500, 600, 150, 50, &Font, "Quitter",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}


void CMainMenuState::UpdateButtons()
{

	// Update all the buttons in the  state and handles their functionality
	for (auto  &iterator : Buttons)
	{
		iterator.second->Update(MousePosView);
	}

	//Play
	if (Buttons["GAME_STATE"]->IsPressed())
	{
		States->push(new CGameState(Window, States));
	}

	//Quit the game
	if (Buttons["EXIT_STATE"]->IsPressed())
	{
		EndState();
	}
}

void CMainMenuState::RenderButtons(sf::RenderTarget* target)
{
	for (auto& iterator : Buttons)
	{
		iterator.second->Render(target);
	}
}



void CMainMenuState::UpdateInput(const float& dt)
{


}

void CMainMenuState::Update(const float& dt)
{
	UpdateInput(dt);
	UpdateMousePosition();

	UpdateButtons();


}



void CMainMenuState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = Window;

	target->draw(Background);

	RenderButtons(target);
}
