#include "BaseWeaponEntity.h"

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

std::map<const char*, CEntity*>& CEntity::GetChildEntities()
{
	return ChildEntities;
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
	ParentEntity->ChildEntities.erase(Name);
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
		child.second->Render(target);
	}
}


