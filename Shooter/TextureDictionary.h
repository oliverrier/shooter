#ifndef TEXTUREDICTIONARY_H
#define TEXTUREDICTIONARY_H


#include "Common.h"

class CTextureDictionary
{

private:
	static std::map<const char*, sf::Texture> Textures;

	static bool TextureExists(const char* textureName);


public:
	static const sf::Texture* GetTexture(const char* textureName);
};

#endif