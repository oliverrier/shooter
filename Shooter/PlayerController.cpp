#include "PlayerController.h"
#include "BaseWeaponEntity.h"
#include "Level.h"
#include "PlayerEntity.h"

CPlayerController::CPlayerController(sf::RenderWindow& window, float maxVelocity):CController(maxVelocity), Window(window)
{
}

void CPlayerController::UpdateLogic(const float& dt, CPlayerEntity& player)
{
	const sf::FloatRect globalBounds = player.GetSprite().getGlobalBounds();
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

	if (!canShoot) {
		delayToShootAgain += dt;
		if (delayToShootAgain > 0.5f) {
			canShoot = true;
			delayToShootAgain = 0.f;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.GetChildEntities()["SOLAR_WEAPON"] != nullptr && canShoot) {
		player.GetCurrentLevel().SpawnProjectile(player);
		canShoot = false;
	}

	Move(dt, player.GetSprite(), directionX, directionY);

	for (auto& child : player.GetChildEntities())
	{
		if(child.second != nullptr)
			Move(dt, child.second->GetSprite(), directionX, directionY);
	}
}
