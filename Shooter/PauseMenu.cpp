#include "PauseMenu.h"

CPauseMenu::CPauseMenu(sf::RenderWindow& window, std::stack<CScene*>& states) : CScene(window, states)
{
	InitBackground();
	InitFonts();
	InitTitlePauseMenu();
	InitButtons();
}

CPauseMenu::~CPauseMenu()
{
	auto iterator = Buttons.begin();

	for (iterator = Buttons.begin(); iterator != Buttons.end(); ++iterator)
	{
		delete iterator->second;
	}
}



void CPauseMenu::InitBackground()
{
	Background.setSize(sf::Vector2f((float)Window.getSize().x, (float)Window.getSize().y));

	Background.setTexture(&CTextureDictionary::GetTexture("BACKGROUND_PAUSE"));
}


void CPauseMenu::InitFonts()
{
	if (!Font.loadFromFile("asset/font/Space.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void CPauseMenu::InitTitlePauseMenu()
{
	TitlePauseMenu.setFont(Font);
	TitlePauseMenu.setString("Menu Pause");
	TitlePauseMenu.setFillColor(sf::Color::White);
	TitlePauseMenu.setCharacterSize(50);

	const float middleXOfWindow = (float)Window.getSize().x / 2 - TitlePauseMenu.getGlobalBounds().width / 2.f;
	TitlePauseMenu.setPosition(middleXOfWindow, 100);
}

void CPauseMenu::InitButtons()
{
	const float widthButtons = 400, heightButtons = 50;
	const float middleXOfWindow = (float)Window.getSize().x / 2 - widthButtons / 2;
	const float positionYButtonContinue = 600, positionYButtonBackToMainMenu = 700;

	Buttons["CONTINUE"] = new CButton(middleXOfWindow, positionYButtonContinue, widthButtons, heightButtons, Font, "Continuer",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	Buttons["BACK_TO_MAIN_MENU"] = new CButton(middleXOfWindow, positionYButtonBackToMainMenu, widthButtons, heightButtons, Font, "Retour au menu principal",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

}



void CPauseMenu::UpdateButtons()
{

	// Update all the buttons in the  state and handles their functionality
	for (auto& iterator : Buttons)
	{
		iterator.second->Update(MousePosView);
	}

	//Play
	if (Buttons["CONTINUE"]->IsPressed())
	{
		SetNumberOfTopScenesToDelete(1);
	}

	//Quit the game
	if (Buttons["BACK_TO_MAIN_MENU"]->IsPressed())
	{
		SetNumberOfTopScenesToDelete(2);
	}
}

void CPauseMenu::RenderButtons(sf::RenderTarget& target)
{
	for (auto& iterator : Buttons)
	{
		iterator.second->Render(target);
	}
}



void CPauseMenu::UpdateInput(const float& dt)
{

}

void CPauseMenu::Update(const float& dt)
{
	UpdateInput(dt);
	UpdateMousePosition();

	UpdateButtons();
}



void CPauseMenu::Render(sf::RenderTarget& target)
{

	target.draw(Background);
	RenderButtons(target);
	target.draw(TitlePauseMenu);

}
