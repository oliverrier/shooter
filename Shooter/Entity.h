#ifndef ENTITY_H
#define ENTITY_H

#include "PlayerController.h"
class CEntity
{
protected:
	const char* Name;
	sf::Sprite Sprite;
	CEntity* ParentEntity;
	std::map<const char*, CEntity*> ChildEntities;


public:
	CEntity(const char* Name, sf::Sprite sprite);
	virtual ~CEntity();


	//getter and setters
	sf::Sprite& GetSprite();
	std::map<const char*, CEntity*>& GetChildEntities();

	//Functions
	virtual void SetParentEntity(CEntity* parentEntity);
	virtual void SetChildEntity(CEntity* childEntity);
	virtual void DetachFromParentEntity();
	virtual void DetachChildEntity(const char* childKey);
	virtual void DetachChildEntities();

	virtual void Render(sf::RenderTarget& target);

};

#endif