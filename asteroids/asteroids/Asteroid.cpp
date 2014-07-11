#include "Asteroid.h"
#include "GameObject.h"
#include "stdafx.h"
#include <time.h>

#include <math.h>
#include <iostream>

Asteroid::Asteroid(sf::Vector2f pv2f_position, int pi_size, EObjectType pe_ObjectType, sf::Sprite *p_Sprite)
:GameObject(pv2f_position, sf::Vector2f(100, 100), pe_ObjectType, p_Sprite)
{
	m_Sprite->setOrigin(50, 50);

	switch (pi_size)
	{
	case 1://small asteroid
		mf_speed = 0.5;
		break;
	case 2://Medium 
		mf_speed = 0.3;
		break;
	case 3://Large
		mf_speed = 0.1;
		break;
	}
	srand(time(NULL));

	mi_Direction = rand() % 361 + 0;

	setRotation(mi_Direction);

	mv2f_direction = sf::Vector2f(cosf(mi_Direction * 3.14159265 / 180) * mf_speed, sinf(mi_Direction * 3.14159265 / 180) * mf_speed);

	mb_HasAnimation = false;
	mb_toBeRemoved = false;
}

void Asteroid::update(float pf_deltaTime)
{
	//move, rotate and possibly check for collisions
	
	move(mv2f_direction);
	rotate(-0.1);

	//screen warping 2.0: Size based.
	if (getPosition().x > 1200 + mv2f_Size.x && mv2f_direction.x > 0.0f)
	{
		setPosition(-mv2f_Size.x, getPosition().y);
	}
	if (getPosition().x < -mv2f_Size.x && mv2f_direction.x < 0.0f)
	{
		setPosition(1200 + mv2f_Size.x, getPosition().y);
	}
	if (getPosition().y > 900 + mv2f_Size.y && mv2f_direction.y > 0.0f)
	{
		setPosition(getPosition().x, -mv2f_Size.y);
	}
	if (getPosition().y < -mv2f_Size.y && mv2f_direction.y < 0.0f)
	{
		setPosition(getPosition().x, 900 + mv2f_Size.y);
	}

	//Sprite
	if (m_Sprite->getPosition() != getPosition())
	{
		m_Sprite->setPosition(getPosition());
	}

	if (m_Sprite->getRotation() != getRotation())
	{
		m_Sprite->setRotation(getRotation());
	}
}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_Sprite != nullptr)
	{
		target.draw(*m_Sprite, states);
	}
}