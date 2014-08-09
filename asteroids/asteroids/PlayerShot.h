#pragma once

#include "stdafx.h"
#include "GameObject.h"

class PlayerShot : public GameObject
{
public:
	//create instance of shot
	PlayerShot(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Vector2f pv2f_direction, float pf_angle, int pi_specialType, EObjectType pe_ObjectType, sf::Sprite *p_Sprite);
	
	//update shot
	void update(float pf_deltaTime);
	
	//draw shot
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	//what to do when hitting another object
	void HandleCollision(GameObject* p_gameObject);

private:

	int mi_specialType;

	sf::Vector2f mv2f_direction;

	sf::Vector2f mv2f_totalDistance;
};