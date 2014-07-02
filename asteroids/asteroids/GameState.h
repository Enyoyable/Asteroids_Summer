#pragma once

#include "stdafx.h"
#include "State.h"

class PlayerObject;

class GameState : public State
{
public:

	GameState(GameObjectManager *p_GameObjectManager, StateManager *p_StateManager, SpriteManager *p_SpriteManager, CollisionManager *p_CollisionManager, Engine *p_Engine);

	void Init();
	void Update(float pf_deltaTime);

	void Cleanup();
	void Pause();
	void Resume();

	void quit();
	void Draw();

private:

	PlayerObject *m_Player;

};