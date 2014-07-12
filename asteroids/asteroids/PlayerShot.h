#pragma once

#include "stdafx.h"
#include "GameObject.h"

class PlayerShot : public GameObject
{
public:

	PlayerShot(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Vector2f pv2f_direction, float pf_angle, EObjectType pe_ObjectType, sf::Sprite *p_Sprite);

	void update(float pf_deltaTime);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void HandleCollision(GameObject* p_gameObject);

private:

	sf::Vector2f mv2f_direction;

	sf::Vector2f mv2f_totalDistance;
};