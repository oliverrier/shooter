#include "PlayerController.h"
#include "BaseWeaponEntity.h"

CPlayerController::CPlayerController(sf::RenderWindow& window, float maxVelocity):CController(maxVelocity), Window(window)
{
}

void CPlayerController::UpdateLogic(const float& dt, CEntity& entity)
{
	const sf::FloatRect globalBounds = entity.GetSprite().getGlobalBounds();
	const sf::FloatRect viewport = (sf::FloatRect) Window.getViewport(Window.getView());

	float directionX = 0.f, directionY = 0.f;
	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && globalBounds.left > viewport.left)
		--directionX;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && globalBounds.left + globalBounds.width < viewport.left + viewport.width)
		++directionX;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && globalBounds.top > viewport.top)
		--directionY;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && globalBounds.top + globalBounds.height < viewport.top + viewport.height)
		++directionY;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && entity.GetChildEntities()["SOLAR_WEAPON"] != nullptr)
		((CBaseWeaponEntity*)entity.GetChildEntities()["SOLAR_WEAPON"])->Use();

	Move(dt, entity.GetSprite(), directionX, directionY);

	for (auto& child : entity.GetChildEntities())
	{
		if(std::string(child.first).find("_PROJECTILE") == std::string::npos)
			Move(dt, child.second->GetSprite(), directionX, directionY);
	}
}
