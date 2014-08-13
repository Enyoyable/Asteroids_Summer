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

	void quit();
	void Draw();

	void setNewstate(int pi_newState);

	void addPlayer();
	void addShot(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Vector2f pv2f_Direction, float pf_Angle, int pi_specialType, sf::Sprite *p_Sprite);
	
	int getScore();
	void setScore(int pi_newScore);
	void addToScore(int pi_newScore);
	
	int getLives();
	void setLives(int pi_newLives);

	float getStateClock();
	void resetStateclock();

private:

	int mi_score;
	int mi_lives;

	PlayerObject *m_Player;

	AsteroidManager *m_AsteroidManager;

	HUDManager *m_HUDManager;

	std::vector<GameObject*> mv_lifeObjs;
};