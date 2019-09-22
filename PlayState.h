#pragma once
#include "GameState.h"
#include "Player.h"
#include "EntityManager.h"

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
	Entity e;
	EntityManager& Entity_Manager = EntityManager::GetEntityManager();
};