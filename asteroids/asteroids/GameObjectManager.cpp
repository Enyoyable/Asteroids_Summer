#include "GameObjectManager.h"
#include <iostream>

GameObjectManager::GameObjectManager(sf::RenderWindow *p_window)
{
	m_window = p_window;
}

void GameObjectManager::updateObjects(std::vector<GameObject*> *pv_Objects, float pf_DeltaTime)
{
	int startObjectAmount = pv_Objects->size();

	for (auto object : *pv_Objects)
	{
		object->update(pf_DeltaTime);
		if (pv_Objects->size() != startObjectAmount)
		{
			break;
		}
	}

	for (auto object : *pv_Objects)
		{
			if (object->mb_toBeRemoved)
			{
				removeObject(pv_Objects, object);
			}

			if (pv_Objects->size() != startObjectAmount)
			{
				break;
			}
		}
}

void GameObjectManager::drawObjects(std::vector<GameObject*> *pv_Objects)
{
	for (auto object : *pv_Objects)
	{
		if (object->getSprite() != nullptr)
		{
			//std::cout << object->getSprite()->getTextureRect().height << " " << object->getSprite()->getTextureRect().width << std::endl;
			m_window->draw(*object);
		}
	}
}

void GameObjectManager::removeObject(std::vector<GameObject*> *pv_Objects, GameObject *p_Object)
{
	for (auto iter = pv_Objects->begin(); iter != pv_Objects->end(); ++iter)
	{
		if (*iter == p_Object)
		{
			delete *iter;
			*iter = nullptr;
			pv_Objects->erase(iter);
			return;
		}
	}
}

void GameObjectManager::cleanObjects(std::vector<GameObject*> *pv_Objects)
{

}