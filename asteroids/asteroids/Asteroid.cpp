#include "Asteroid.h"
#include "GameObject.h"
#include "stdafx.h"
#include <time.h>

#include <math.h>
#include <iostream>

Asteroid::Asteroid(sf::Vector2f pv2f_position, sf::Vector2f pv2f_direction, int pi_size, AsteroidManager *p_AsteroidManager, EObjectType pe_ObjectType, sf::Sprite *p_Sprite)
:GameObject(pv2f_position, sf::Vector2f(100, 100), pe_ObjectType, p_Sprite)
{
	mi_size = pi_size;

	m_AsteroidManager = p_AsteroidManager;

	switch (mi_size)
	{
		//speed does not set properly
	case 1://small asteroid
		mf_speed = 0.1f;
		mv2f_Size = sf::Vector2f(25, 25);
		m_Sprite->setScale(0.25f, 0.25f);
		break;
	case 2://Medium 
		mf_speed = 0.1f;
		mv2f_Size = sf::Vector2f(50, 50);
		m_Sprite->setScale(0.5f, 0.5f);
		break;
	case 3://Large
		mf_speed = 0.1f;
		mv2f_Size = sf::Vector2f(100, 100);
		m_Sprite->setScale(1,1);
		break;
	}

	if (pv2f_direction == sf::Vector2f(0.0f, 0.0f))
	{
		srand(time(NULL));

		mi_Direction = rand() % 361 + 0;

		setRotation(mi_Direction);

		mv2f_direction = sf::Vector2f(cosf(mi_Direction * 3.14159265 / 180) * mf_speed, sinf(mi_Direction * 3.14159265 / 180) * mf_speed);
	}
	else
	{
		mv2f_direction = pv2f_direction;
	}
	

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

void Asteroid::HandleCollision(GameObject* p_GameObject)
{
	if (p_GameObject->getType() == PLAYER || p_GameObject->getType() == SHOT)
	{
		mb_toBeRemoved = true;
		m_AsteroidManager->addAsteroid(getPosition(), sf::Vector2f(cosf(mi_Direction + 30 * 3.14159265 / 180), sinf(mi_Direction + 30 * 3.14159265 / 180)), mi_size - 1, m_Sprite);
		m_AsteroidManager->addAsteroid(getPosition(), sf::Vector2f(cosf(mi_Direction - 30 * 3.14159265 / 180), sinf(mi_Direction - 30 * 3.14159265 / 180)), mi_size - 1, m_Sprite);
	}
}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_Sprite != nullptr)
	{
		target.draw(*m_Sprite, states);
	}
}

