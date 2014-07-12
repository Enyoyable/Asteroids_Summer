#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "Asteroid.h"
#include "PlayerShot.h"

class CollisionManager
{
public:

	CollisionManager();

	void getCollision(std::vector<GameObject*> *p_collisionObjects);

private:

};