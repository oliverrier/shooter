#ifndef ENTITY_H
#define ENTITY_H

#include "PlayerController.h"
 

class CEntity
{
protected:
	std::map<std::string, CSpriteComponent> SpritesComponent;


	CController& Controller;
public:
	CEntity(CController& controller, std::map<std::string, CSpriteComponent> spritesComponent);
	CEntity(CController& controller,CSpriteComponent spriteComponent);
	CEntity(CController& controller, sf::Sprite sprite);
	virtual ~CEntity();

	// intits
	virtual void InitSprites();

	//Functions

	virtual void Update(const float& dt);
	virtual void RecursiveSpriteRender(sf::RenderTarget* target, CSpriteComponent& spriteComponent);
	virtual void Render(sf::RenderTarget* target);

};

#endif