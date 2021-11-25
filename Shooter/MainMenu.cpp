#include "MainMenu.h"
#include "Button.h"
#include <iostream>

//SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


int createMainMenu() {
    //// Retrieves information from the screen
    //sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    //sf::RenderWindow window(sf::VideoMode(1920, 1080, desktop.bitsPerPixel), "SFML window");

    //// Load a sprite to display
    //sf::Texture textureBackground;
    //if (!textureBackground.loadFromFile("asset/sprite/menu/mainMenu/wallpaper.png"))
    //    return EXIT_FAILURE;
    //sf::Sprite spriteBackground(textureBackground);



    //// Create a graphical text to display
    //sf::Font font;
    //if (!font.loadFromFile("asset/font/Doom2016Text.ttf"))
    //    return EXIT_FAILURE;

    //sf::Text textPlay("JOUER", font, 50);
    //sf::Text textLeave("QUITTER", font, 50);

    ////create buttons

    //Button buttonPlay(window, textPlay);
    //Button buttonLeave(window, textLeave);

    ////creation vector for buttons position
    //sf::Vector2f positionButtonPlay(1440.f, 440.f);
    //sf::Vector2f positionButtonLeave(1440.f, 540.f);

    //buttonPlay.setPosition(positionButtonPlay);
    //buttonLeave.setPosition(positionButtonLeave);

    //// Load a music to play
    //sf::Music music;
    //if (!music.openFromFile("asset/music/Doom_Eternal_Main_Theme_Official_Version.wav"))
    //    return EXIT_FAILURE;
    //// Play the music
    //music.play();
    //music.setLoop(true);

    //// Start the game loop
    //while (window.isOpen())
    //{
    //    // Process events
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        // Close window: exit
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }
    //    // Clear screen
    //    window.clear();
    //    // Draw the sprite
    //    window.draw(spriteBackground);
    //    // Draw the buttons
    //    buttonPlay.(window);
    //    buttonLeave.drawInTheWindow(window);

    //    // Update the window
    //    window.display();
    //}
    return EXIT_SUCCESS;
}