#pragma once

#include "stdafx.h"
#include "GameObject.h"

class Asteroid : public GameObject
{
public:

	Asteroid(sf::Vector2f pv2f_position, int pi_size, sf::Sprite *p_Sprite);

	void update(float pf_deltaTime);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	int mi_size;
	int mi_Direction;

	float mf_speed;

	sf::Vector2f mv2f_direction;
};