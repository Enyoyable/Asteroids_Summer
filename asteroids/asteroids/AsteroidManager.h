#pragma once
#include "stdafx.h"
#include "GameObject.h"

class GameObjectManager;
class SpriteManager;
class Asteroid;

class AsteroidManager
{
public:

	AsteroidManager(std::vector<GameObject*> *pv_GameObjects, SpriteManager* p_SpriteManager);

	void update(float pf_deltaTime);

	void addAsteroid(sf::Vector2f pv2f_position, sf::Vector2f pv2f_direction, int pi_Size, sf::Sprite *p_Sprite);

private:

	int mi_AsteroidAmount;
	int mi_Difficulty;

	float mf_spawnTimer;

	GameObjectManager* m_GameObjectManager;
	SpriteManager* m_SpriteManager;

	std::vector<GameObject*> *mv_GameObjects;
};
