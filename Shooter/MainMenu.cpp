#include "MainMenu.h"

CMainMenu::CMainMenu(sf::RenderWindow& window, std::stack<CScene*>& states) : CScene(window, states)
{
	InitBackground();
	InitMusic();
	InitFonts();
	InitButtons();

}

CMainMenu::~CMainMenu()
{
	auto iterator = Buttons.begin();

	for (iterator = Buttons.begin(); iterator != Buttons.end(); ++iterator)
	{
		delete iterator->second;
	}
}



void CMainMenu::InitBackground()
{
	Background.setSize(sf::Vector2f((float) Window.getSize().x, (float)Window.getSize().y));

	Background.setTexture(&CTextureDictionary::GetTexture("WALLPAPER"));
}

void CMainMenu::InitMusic() {
	// Load a music to play
	if (!Music.openFromFile("asset/musics/R-Type_Final_2_Main_Menu.wav"))
		throw "ERROR:MAIN_MENU_STATE::FAILED_TO_LOAD_MUSIC";
	Music.setLoop(true);
}


void CMainMenu::InitFonts()
{
	if (!Font.loadFromFile("asset/font/Space.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void CMainMenu::InitButtons()
{
	Buttons["GAME_STATE"] = new CButton(1500, 400, 150, 50, Font, "Jouer",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	Buttons["EXIT_STATE"] = new CButton(1500, 600, 150, 50, Font, "Quitter",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}


void CMainMenu::UpdateButtons()
{

	// Update all the buttons in the  state and handles their functionality
	for (auto  &iterator : Buttons)
	{
		iterator.second->Update(MousePosView);
	}

	//Play
	if (Buttons["GAME_STATE"]->IsPressed())
	{
		Music.stop();
		Scenes.push(new CLevel(Window, Scenes));
	}

	//Quit the game
	if (Buttons["EXIT_STATE"]->IsPressed())
	{
		SetNumberOfTopScenesToDelete(1);
	}
}

void CMainMenu::RenderButtons(sf::RenderTarget& target)
{
	for (auto& iterator : Buttons)
	{
		iterator.second->Render(target);
	}
}



void CMainMenu::UpdateInput(const float& dt)
{

}

void CMainMenu::Update(const float& dt)
{
	if (Music.getStatus() == sf::SoundSource::Status::Stopped)
	{
		Music.play();
	}

	UpdateInput(dt);
	UpdateMousePosition();

	UpdateButtons();
}



void CMainMenu::Render(sf::RenderTarget& target)
{

	target.draw(Background);
	RenderButtons(target);
}
