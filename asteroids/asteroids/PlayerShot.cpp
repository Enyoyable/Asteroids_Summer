#include "PlayerShot.h"
#include "GameObject.h"
#include "stdafx.h"
#include <math.h>
#include <iostream>

PlayerShot::PlayerShot(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Vector2f pv2f_direction, float pf_Angle, int pi_specialtype, EObjectType pe_ObjectType, sf::Sprite *p_Sprite)
: GameObject(pv2f_Position, pv2f_Size, pe_ObjectType, p_Sprite)
{
	//Variables for type and direction set
	mi_specialType = pi_specialtype;
	mv2f_direction = pv2f_direction;
	setRotation(pf_Angle);

	//Variable for distance moved set to zero
	mv2f_totalDistance = sf::Vector2f(0.0f, 0.0f);
}

void PlayerShot::update(float pf_deltaTime)
{
	//Same move function as the player class but direction is set when created as the angles are calculated based on the player's direction.
	move(mv2f_direction.x * 2, mv2f_direction.y * 2);
	
	//adds moved distance to total
	mv2f_totalDistance += mv2f_direction;
	
	//remove shot if it has moved a certain leght without hitting something. Avoids infinite shots on screen at once
	if (std::abs(mv2f_totalDistance.x) + std::abs(mv2f_totalDistance.y) > 900)
	{
		mb_toBeRemoved = true;
	}

	//Screen warping. Standard.
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

	//Sprite moving. Standard.
	if (m_Sprite->getPosition() != getPosition())
	{
		m_Sprite->setPosition(getPosition());
	}

	if (m_Sprite->getRotation() != getRotation())
	{
		m_Sprite->setRotation(getRotation());
	}
}

void PlayerShot::HandleCollision(GameObject* p_gameObject)
{
	//What to do when hittign an asteroid
	if (p_gameObject->getType() == ROCK)
	{
		//Special type 1 is a piercing shot which does not dissapear when hitting an asteroid
		if (mi_specialType != 1)
		{
			mb_toBeRemoved = true;
		}
		
	}
}

void PlayerShot::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//Draw the shot
	if (m_Sprite != nullptr)
	{
		target.draw(*m_Sprite, states);
	}
}