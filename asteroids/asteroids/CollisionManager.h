#pragma once

#include "stdafx.h"
#include "GameObject.h"

class CollisionManager
{
public:

	CollisionManager();

	void getCollision(std::vector<GameObject*> *p_collisionObjects);

private:

};