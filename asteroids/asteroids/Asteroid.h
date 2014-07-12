#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "AsteroidManager.h"

class AsteroidManager;

class Asteroid : public GameObject
{
public:

	Asteroid(sf::Vector2f pv2f_position, sf::Vector2f pv2f_direction,  int pi_size, AsteroidManager* p_AsteroidManager, EObjectType pe_ObjectType, sf::Sprite *p_Sprite);
	
	void update(float pf_deltaTime);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void HandleCollision(GameObject *p_GameObject);

private:
	int mi_size;
	int mi_Direction;

	float mf_speed;

	AsteroidManager *m_AsteroidManager;

	sf::Vector2f mv2f_direction;
};