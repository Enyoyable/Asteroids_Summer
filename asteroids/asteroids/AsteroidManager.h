//This class have been upfraded to handle powerups and eventual enemies.
#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "GameState.h"

class GameObjectManager;
class SpriteManager;
class Asteroid;

class AsteroidManager
{
public:
	
	AsteroidManager(std::vector<GameObject*> *pv_GameObjects, SpriteManager* p_SpriteManager, GameState *p_GameState);

	void update(float pf_deltaTime);

	void addAsteroid(sf::Vector2f pv2f_position, sf::Vector2f pv2f_direction, int  pi_direction, int pi_Size, sf::Sprite *p_Sprite);

	void addPowerUp(sf::Vector2f pv2f_position, EObjectType pe_objectType);

	GameState* getGameState();

private:

	int mi_AsteroidAmount;
	int mi_PowerUpsAmount;
	int mi_Difficulty;

	float mf_spawnTimer;

	GameObjectManager* m_GameObjectManager;
	SpriteManager* m_SpriteManager;
	GameState* m_GameState;

	std::vector<GameObject*> *mv_GameObjects;
};
