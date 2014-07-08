#include "PlayerShot.h"
#include "GameObject.h"
#include "stdafx.h"
#include <math.h>
#include <iostream>

PlayerShot::PlayerShot(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Vector2f pv2f_direction, float pf_Angle, sf::Sprite *p_Sprite)
: GameObject(pv2f_Position, pv2f_Size, p_Sprite)
{
	mv2f_direction = pv2f_direction;
	mv2f_totalDistance = sf::Vector2f(0.0f, 0.0f);

	setRotation(pf_Angle);
	mb_HasAnimation = false;
	mb_toBeRemoved = false;
}

void PlayerShot::update(float pf_deltaTime)
{
	move(mv2f_direction.x * 2, mv2f_direction.y * 2);
	mv2f_totalDistance += mv2f_direction;
	
	if (std::abs(mv2f_totalDistance.x) + std::abs(mv2f_totalDistance.y) > 900)
	{
		mb_toBeRemoved = true;
	}

	if (getPosition().x > 1232 && mv2f_direction.x > 0.0f)
	{
		setPosition(-32, getPosition().y);
	}
	if (getPosition().x < -32 && mv2f_direction.x < 0.0f)
	{
		setPosition(1232, getPosition().y);
	}
	if (getPosition().y > 932 && mv2f_direction.y > 0.0f)
	{
		setPosition(getPosition().x, -32);
	}
	if (getPosition().y < -32 && mv2f_direction.y < 0.0f)
	{
		setPosition(getPosition().x, 932);
	}

	if (m_Sprite->getPosition() != getPosition())
	{
		m_Sprite->setPosition(getPosition());
	}

	if (m_Sprite->getRotation() != getRotation())
	{
		m_Sprite->setRotation(getRotation());
	}
}

void PlayerShot::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_Sprite != nullptr)
	{
		target.draw(*m_Sprite, states);
	}
}