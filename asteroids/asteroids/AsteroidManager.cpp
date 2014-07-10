#include "AsteroidManager.h"
#include "Asteroid.h"
#include "GameObjectManager.h"
#include "SpriteManager.h"
#include <time.h>

AsteroidManager::AsteroidManager(std::vector<GameObject*> *pv_GameObjects, SpriteManager* p_SpriteManager)
{
	m_SpriteManager = p_SpriteManager;
	mv_GameObjects = pv_GameObjects;

	mi_AsteroidAmount = 0;
	mi_Difficulty = 1;

	mf_spawnTimer = 0.0f;
}

void AsteroidManager::update(float pf_deltaTime)
{
	srand(time(NULL));
	mf_spawnTimer += pf_deltaTime;
	if (mf_spawnTimer > 1 * mi_Difficulty && mi_AsteroidAmount < 10)
	{
		float posX = rand() % 1201 + 0;
		float posY = rand() % 901 + 0;

		if (posX > 0 - 50 && posX <= 600)
		{
			posX = 0 - 50;
		}
		if (posX > 600 && posX < 1250)
		{
			posX = 1250;
		}

		addAsteroid(sf::Vector2f(posX, posY), 3, m_SpriteManager->loadSprite("asteroid01.png", 0, 0, 100, 100));
		mf_spawnTimer = 0.0f;
	}
}

void AsteroidManager::addAsteroid(sf::Vector2f pv2f_Position, int pi_Size, sf::Sprite *p_Sprite)
{
	mv_GameObjects->push_back(new Asteroid(pv2f_Position, pi_Size, p_Sprite));
	mi_AsteroidAmount += 1;
}