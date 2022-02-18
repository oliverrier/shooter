#ifndef ENTITY_H
#define ENTITY_H

#include "MathUtils.h"


class CEntity
{
protected:
	const char* Name;
	sf::Sprite Sprite;
	CEntity* ParentEntity;
	std::map<const char*, CEntity*> ChildEntities;


public:
	CEntity(const char* name, sf::Sprite sprite);
	virtual ~CEntity();


	//getter and setters
	sf::Sprite& GetSprite();
	CEntity* GetChildEntity(const char* name);
	std::map<const char*, CEntity*>& GetChildEntities();
	const char* GetName();

	//Functions
	virtual void SetParentEntity(CEntity* parentEntity);
	virtual void SetChildEntity(CEntity* childEntity);
	virtual void DetachFromParentEntity();
	virtual void DetachChildEntity(const char* childKey);
	virtual void DetachChildEntities();

	virtual void Render(sf::RenderTarget& target);

};

#endif