#include "CollisionManager.h"
//#include "stdafx.h"
//#include <math.h>

CollisionManager::CollisionManager()
{

}

void CollisionManager::getCollision(std::vector<GameObject*> *p_collisionObjects)
{
	//if object in collisionObjects overlaps with other object in collisionObjects, handle collision
	//Can be adjusted to work differently depending on EObjectType, only distance related so far.
	for (auto object1 : *p_collisionObjects)
	{
		for (auto object2 : *p_collisionObjects)
		{
			if ((std::abs(object1->getPosition().x) - std::abs(object2->getPosition().x)) < (object1->getSprite()->getGlobalBounds().width + object2->getSprite()->getGlobalBounds().width) 
				&& (std::abs(object1->getPosition().y) - std::abs(object2->getPosition().y)) < (object1->getSprite()->getGlobalBounds().height + object2->getSprite()->getGlobalBounds().height))
			{
				object1->HandleCollision(object2);
			}
		}
	}

}