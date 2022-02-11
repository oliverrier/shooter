#ifndef TEXTUREDICTIONARY_H
#define TEXTUREDICTIONARY_H


#include<iostream>
#include<stack>
#include<vector>
#include<map>

//SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "TexturesManager.h"

class CTextureDictionary
{

private:
	static std::map<const char*, sf::Texture> Textures;

	static bool TextureExists(const char* textureName);


public:
	static const sf::Texture* GetTexture(const char* textureName);
};

#endif