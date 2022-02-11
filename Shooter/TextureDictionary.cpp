#include "TextureDictionary.h"

std::map<const char*, sf::Texture> CTextureDictionary::Textures;

bool CTextureDictionary::TextureExists(const char* textureName)
{
	return  Textures.find(textureName) != Textures.end();
}

const sf::Texture* CTextureDictionary::GetTexture(const char* textureName)
{
	if (!TextureExists(textureName))
	{
		Textures[textureName].loadFromFile("asset/textures/" + std::string(textureName) + ".png");
	}
	return &Textures[textureName];
}
