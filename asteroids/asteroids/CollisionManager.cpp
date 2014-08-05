#include "CollisionManager.h"
#include <iostream>
//#include "stdafx.h"
//#include <math.h>

CollisionManager::CollisionManager()
{

}

void CollisionManager::getCollision(std::vector<GameObject*> *p_collisionObjects)
{
	int originalsize = p_collisionObjects->size();
	//if object in collisionObjects overlaps with other object in collisionObjects, handle collision
	//Can be adjusted to work differently depending on EObjectType, only distance related so far.
	for (auto object1 : *p_collisionObjects)
	{
		for (auto object2 : *p_collisionObjects)
		{
			if (object1 != object2)
			{
				if (std::abs((object1->getPosition().x) - (object2->getPosition().x)) < std::abs(object1->getSprite()->getGlobalBounds().width / 2 + object2->getSprite()->getGlobalBounds().width / 2)
					&& std::abs((object1->getPosition().y) - (object2->getPosition().y)) < std::abs(object1->getSprite()->getGlobalBounds().height / 2 + object2->getSprite()->getGlobalBounds().height / 2))
				{
					int xDiff = std::abs((object1->getPosition().x) - (object2->getPosition().x));
					int yDiff = std::abs((object1->getPosition().y) - (object2->getPosition().y));
					int textBuff = object1->getSprite()->getGlobalBounds().width + object2->getSprite()->getGlobalBounds().width;

					if (object1->getType() == PLAYER && object2->getType() == ROCK)
					{
						PlayerObject *pObj = static_cast<PlayerObject*>(object1);
						pObj->HandleCollision(object2);

						Asteroid *asObj = static_cast<Asteroid*>(object2);
						asObj->HandleCollision(object2);
						break;
					}
					else if (object1->getType() == ROCK && object2->getType() == SHOT)
					{
						Asteroid *asObj = static_cast<Asteroid*>(object1);
						asObj->HandleCollision(object2);

						PlayerShot *shotObj = static_cast<PlayerShot*>(object2);
						shotObj->HandleCollision(object1);
						break;
					}
					else if (object1->getType() == SHOT && object2->getType() == ROCK)
					{
						PlayerShot *shotObj = static_cast<PlayerShot*>(object1);
						shotObj->HandleCollision(object2);

						Asteroid *asObj = static_cast<Asteroid*>(object2);
						asObj->HandleCollision(object1);
						break;
					}
					else if (object1->getType() == PLAYER && object2->getType() == PWRUP)
					{
						PlayerObject *pObj = static_cast<PlayerObject*>(object1);
						PowerUp *puObj = static_cast<PowerUp*>(object2);
						
						pObj->HandleCollision(puObj);
						puObj->HandleCollision(object1);
					}
				}
			}
			if (originalsize != p_collisionObjects->size())
			{
				break;
			}
		}
		if (originalsize != p_collisionObjects->size())
		{
			break;
		}
	}
}