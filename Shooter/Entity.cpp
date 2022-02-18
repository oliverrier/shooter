#include "BaseWeaponEntity.h"
#include <iostream>

CEntity::CEntity(const char* name, sf::Sprite sprite): Name(name), Sprite(sprite), ParentEntity(nullptr)
{
}

CEntity::~CEntity()
{
	if (ParentEntity != nullptr)
	{
		DetachFromParentEntity();
	}
	ChildEntities.clear();
}


sf::Sprite& CEntity::GetSprite()
{
	return Sprite;
}

CEntity* CEntity::GetChildEntity(const char* name) 
{
	return ChildEntities[name];
}

std::map<const char*, CEntity*>& CEntity::GetChildEntities()
{
	return ChildEntities;
}

const char* CEntity::GetName() {
	return Name;
}


void CEntity::SetParentEntity(CEntity* parentEntity)
{
	ParentEntity = parentEntity;
	parentEntity->ChildEntities[Name] = this;
}


void CEntity::SetChildEntity(CEntity* childEntity)
{
	childEntity->SetParentEntity(this);
}

void CEntity::DetachFromParentEntity()
{
	auto removed = ParentEntity->ChildEntities.erase(Name);
	std::cout << "removed : " << removed << std::endl;
	ParentEntity = nullptr;
}

void CEntity::DetachChildEntity(const char* childKey)
{
	ChildEntities[childKey]->DetachFromParentEntity();
}

void CEntity::DetachChildEntities()
{
	for (auto& child : ChildEntities)
	{
		child.second->DetachFromParentEntity();
	}
}

void CEntity::Render(sf::RenderTarget& target)
{
	target.draw(Sprite);
	for (auto& child : ChildEntities)
	{
		if (child.second != nullptr)
		{
			child.second->Render(target);
		}
			

	}
}


