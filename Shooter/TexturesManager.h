#ifndef TEXTURESMANAGER_H
#define TEXTURESMANAGER_H

#include<map>

//SFML
#include <SFML/Graphics.hpp>
class CTexturesManager
{
private:
	static std::map<std::string, sf::Texture> Textures;

public: 
	static sf::Texture getTexture();

};
#endif
