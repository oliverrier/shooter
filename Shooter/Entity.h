#ifndef ENTITY_H
#define ENTITY_H

#include "PlayerController.h"
 

class CEntity
{
protected:
	const char* Name;
	CController& Controller;
	std::map<const char*, CSpriteComponent> SpritesComponent;
	CEntity* ParentEntity;
	std::map<const char*, CEntity*> ChildEntities;

	void RemoveKeyChildFromParent(const char* childKey, const char* parentKey);

public:
	CEntity(const char* Name, CController& controller, std::map<const char*, CSpriteComponent> spritesComponent);
	CEntity(const char* Name, CController& controller,CSpriteComponent spriteComponent);
	CEntity(const char* Name, CController& controller, sf::Sprite sprite);
	virtual ~CEntity();

	// intits
	void InitSprites();

	//Functions
	virtual void SetChildSprite(const char* keyName, CSpriteComponent& spriteComponent, const char* parentKey = "root");
	virtual void SetChildSprite(const char* keyName, sf::Sprite& sprite, const char* parentKey = "root");
	virtual void RemoveSprite(const char* keyName);

	virtual void SetParentEntity(CEntity* parentEntity);
	virtual void SetChildEntity(CEntity* childEntity);
	virtual void DetacheFromParentEntity();
	virtual void DetacheChildEntity(const char* childKey);
	virtual void DetacheChildEntities();

	virtual void Update(const float& dt);
	virtual void RecursiveSpriteRender(sf::RenderTarget* target, CSpriteComponent& spriteComponent);
	virtual void Render(sf::RenderTarget* target);

};

#endif