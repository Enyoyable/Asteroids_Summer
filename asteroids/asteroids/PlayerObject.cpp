#include "PlayerObject.h"
#include "GameObject.h"
#include "GameState.h"
#include "SpriteManager.h"

#include "stdafx.h"
#include <iostream>
#include <math.h>

PlayerObject::PlayerObject(sf::Vector2f position, sf::Vector2f pv2f_Size, GameState *p_GameState, SpriteManager *p_SpriteManager, EObjectType pe_ObjectType, sf::Sprite *sprite)
: GameObject(position, pv2f_Size, pe_ObjectType, sprite)
{
	mv2f_Speed = sf::Vector2f(0.0f, 0.0f);
	mf_velocity = 0.0f;
	mf_fireCooldown = 0.0f;

	m_GameState = p_GameState;
	m_SpriteManager = p_SpriteManager;

	mb_HasAnimation = false;
}

void PlayerObject::update(float pf_deltaTime)
{
	mv2f_Speed = sf::Vector2f((cosf((getRotation() - 90)*3.14159265 / 180) * mf_velocity), (sinf((getRotation() - 90)*3.14159265 / 180)* mf_velocity));
	
	//shoot
	mf_fireCooldown += pf_deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && mf_fireCooldown > 0.2f)
	{
		m_GameState->addShot(sf::Vector2f(getPosition().x + (cosf((getRotation() - 90)*3.14159265 / 180) * mv2f_Size.x / 2), getPosition().y + (sinf((getRotation() - 90)*3.14159265 / 180)* mv2f_Size.y/2)), sf::Vector2f(7.0f, 21.0f), sf::Vector2f((cosf((getRotation() - 90)*3.14159265 / 180)), (sinf((getRotation() - 90)*3.14159265 / 180))), getRotation(), m_SpriteManager->loadSprite("PlaceholderShot.png", 0, 0, 7, 21));
		mf_fireCooldown = 0.0f;
	}

	//Move the player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && mf_velocity < 1.5f)
	{
		mf_velocity += 0.01f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && mf_velocity > -1.5f)
	{
		mf_velocity -= 0.01f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rotate(-0.5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rotate(0.5);
	}

	move(mv2f_Speed);

	if (mf_velocity > 0.00f)
		mf_velocity -= 0.001f;
	else if (mf_velocity < 0.00f)
		mf_velocity += 0.001f;


	//Screen warp
	if (getPosition().x > 1232 && mv2f_Speed.x > 0.0f)
	{
		setPosition(-32, getPosition().y);
	}
	if (getPosition().x < -32 && mv2f_Speed.x < 0.0f)
	{
		setPosition(1232, getPosition().y);
	}
	if (getPosition().y > 932 && mv2f_Speed.y > 0.0f)
	{
		setPosition(getPosition().x, -32);
	}
	if (getPosition().y < -32 && mv2f_Speed.y < 0.0f)
	{
		setPosition(getPosition().x, 932);
	}

		//Sprite does not move without these. Is it not linked to the game object?

	if (m_Sprite->getPosition() != getPosition())
	{
		m_Sprite->setPosition(getPosition());
	}

	if (m_Sprite->getRotation() != getRotation())
	{
		m_Sprite->setRotation(getRotation());
	}
}

void PlayerObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_Sprite != nullptr)
	{
		target.draw(*m_Sprite, states);
	}
}

void PlayerObject::HandleCollision(GameObject *p_GameObject)
{
	if (p_GameObject->getType() == ROCK)
	{
		std::cout << "player hit" << std::endl;
		setPosition(600, 450);
		mv2f_Speed = sf::Vector2f(0, 0);
		mf_velocity = 0;
		m_GameState->setScore(m_GameState->getScore() -1);
		if (m_GameState->getLives() <= 0)
		{
			std::cout << "DEAD" << std::endl;
			m_GameState->setNewstate(3);
		}
		
	}
}