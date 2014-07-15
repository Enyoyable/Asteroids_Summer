#pragma once

#include "stdafx.h"
#include "State.h"

class PlayerObject;
class Asteroid;
class AsteroidManager;
class HUDManager;

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

	void addPlayer();
	void addShot(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Vector2f pv2f_Direction, float pf_Angle, sf::Sprite *p_Sprite);
	

private:

	int mi_score;

	PlayerObject *m_Player;

	AsteroidManager *m_AsteroidManager;

	HUDManager *m_HUDManager;
};