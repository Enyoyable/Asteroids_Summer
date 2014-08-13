#include "AsteroidManager.h"

#include "Asteroid.h"
#include "PowerUp.h"

#include "GameObjectManager.h"
#include "SpriteManager.h"
#include <iostream>
#include <time.h>

AsteroidManager::AsteroidManager(std::vector<GameObject*> *pv_GameObjects, SpriteManager* p_SpriteManager, GameState* p_GameState)
{
	m_SpriteManager = p_SpriteManager;
	mv_GameObjects = pv_GameObjects;
	m_GameState = p_GameState;

	mi_AsteroidAmount = 0;
	mi_PowerUpsAmount = 0;
	mi_Difficulty = 1;

	mf_spawnTimer = 0.0f;
}

void AsteroidManager::update(float pf_deltaTime)
{
	srand(time(NULL));
	mf_spawnTimer += pf_deltaTime;
	if (mf_spawnTimer > 2 * mi_Difficulty && mi_AsteroidAmount < 5)
	{
		int Side = rand() % 4 + 0;
		float posX;
		float posY;
	
		switch (Side)
		{
		case 0://Top
			posX = rand() % 1201 + 0;
			posY = -100;
			break;
		case 1://Bottom
			posX = rand() % 1201 + 0;
			posY = 1000;
			break;
		case 2://Right
			posX = 1300;
			posY = rand() % 901 + 0;
			break;
		case 3://Left
			posX = -100;
			posY = rand() % 901 + 0;
			break;
		}
		
		addAsteroid(sf::Vector2f(posX, posY), sf::Vector2f(0.0f, 0.0f), 0, 3, m_SpriteManager->loadSprite("asteroid01.png", 0, 0, 100, 100));
		mi_AsteroidAmount += 1;
		mf_spawnTimer = 0.0f;
	}
}

void AsteroidManager::addAsteroid(sf::Vector2f pv2f_position, sf::Vector2f pv2f_direction, int pi_direction, int pi_Size, sf::Sprite *p_Sprite)
{
	if (pi_Size > 0)
	{
		mv_GameObjects->push_back(new Asteroid(pv2f_position, pv2f_direction, pi_direction, pi_Size, this, ROCK, p_Sprite, m_SpriteManager));
		mi_AsteroidAmount += 1;
	}
	else
	{
		mi_AsteroidAmount -= 1;
	}
	
}

void AsteroidManager::addPowerUp(sf::Vector2f pv2f_position, EObjectType pe_objectType)
{
	int spawn = rand() % 10 + 1;

	if (spawn > 3)
	{
		return;
	}

	if (mi_PowerUpsAmount < 3)
	{
		mv_GameObjects->push_back(new PowerUp(pv2f_position, m_SpriteManager, spawn, pe_objectType));
		mi_PowerUpsAmount;
	}
}

GameState* AsteroidManager::getGameState()
{
	return m_GameState;
}