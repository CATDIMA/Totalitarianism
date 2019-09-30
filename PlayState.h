#pragma once
#include "GameState.h"
#include "Player.h"
#include "EntityManager.h"
#include "SpriteManager.h"
#include "TmxLevel.h"
#include "WorldContainer.h"

class PlayState : public GameState
{
public:
	PlayState() {}
	PlayState(Game* game);

	virtual void HandleInput();
	virtual void Update(const float& dt);
	virtual void Draw(const float& dt);

private:
	void PauseGame();
	EntityManager& Entity_Manager = EntityManager::GetEntityManager();
	SpriteManager& Sprite_Manager = SpriteManager::GetSpriteManager();
	WorldContainer& worldContainer = WorldContainer::GetWorldContainer();
	TmxLevel Level;
};