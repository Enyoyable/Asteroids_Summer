#include "GameObjectManager.h"

GameObjectManager::GameObjectManager(sf::RenderWindow *p_window)
{
	m_window = p_window;
}

void GameObjectManager::updateObjects(std::vector<GameObject*> *pv_Objects, float pf_DeltaTime)
{

}

void GameObjectManager::drawObjects(std::vector<GameObject*> *pv_Objects)
{
	for (auto object : *pv_Objects)
	{
		m_window->draw(*object);
	}
}

void GameObjectManager::removeObject(std::vector<GameObject*> *pv_Objects, GameObject *p_Object)
{

}

void GameObjectManager::cleanObjects(std::vector<GameObject*> *pv_Objects)
{

}