#include "PlayerObject.h"
#include "GameObject.h"
#include "GameState.h"
#include "SpriteManager.h"
#include "AnimatedSprite.h"

#include "stdafx.h"
#include <iostream>
#include <math.h>

PlayerObject::PlayerObject(sf::Vector2f position, sf::Vector2f pv2f_Size, GameState *p_GameState, SpriteManager *p_SpriteManager, EObjectType pe_ObjectType, AnimatedSprite *p_sprite)
: GameObject(position, pv2f_Size, pe_ObjectType, nullptr)
{
	mv2f_Speed = sf::Vector2f(0.0f, 0.0f);
	mf_velocity = 0.0f;
	mf_fireCooldown = 0.0f;
	mi_currentPowerUp = 0;

	m_GameState = p_GameState;
	m_SpriteManager = p_SpriteManager;
	
	mb_inDeathCycle = false;
	m_animatedSprite = p_sprite;
	m_animatedSprite->pause();
	m_Sprite = m_SpriteManager->loadSprite("player.png");
	
	m_animatedSprite->setOrigin(mv2f_Size.x / 2, mv2f_Size.y / 2);
	m_animatedSprite->setPosition(getPosition());
}

void PlayerObject::update(float pf_deltaTime)
{
	if (mb_inDeathCycle)
	{
		m_animatedSprite->play();
		m_animatedSprite->update(pf_deltaTime);

		mv2f_Speed = sf::Vector2f(0, 0);
		mf_velocity = 0;
		
		m_animatedSprite->play();
		if (m_animatedSprite->getCurrentFrame() == 0)
		{
			if (m_GameState->getLives() <= 0)
			{
				std::cout << "DEAD" << std::endl;
				m_GameState->setNewstate(3);
			}
			else
			{
				setPosition(600, 450);
				m_animatedSprite->pause();
				mb_inDeathCycle = false;
			}
		}
		return;
	}

	mv2f_Speed = sf::Vector2f((cosf((getRotation() - 90)*3.14159265 / 180) * mf_velocity), (sinf((getRotation() - 90)*3.14159265 / 180)* mf_velocity));
	
	//Pause (Might movie this into gamestate)
	if (m_GameState->getStateClock() > 1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			m_GameState->setNewstate(2);
			m_GameState->resetStateclock();
			return;
		}
	}

	//shoot
	mf_fireCooldown += pf_deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && mf_fireCooldown > 0.2f)
	{
		sf::Vector2f position = sf::Vector2f(getPosition().x + (cosf((getRotation() - 90)*3.14159265 / 180) * mv2f_Size.x / 2), 
											getPosition().y + (sinf((getRotation() - 90)*3.14159265 / 180)* mv2f_Size.y / 2));

		sf::Vector2f direction = sf::Vector2f((cosf((getRotation() - 90)*3.14159265 / 180)), (sinf((getRotation() - 90)*3.14159265 / 180)));

		float rotation = getRotation();

		if (mi_currentPowerUp == 0)
		{
			m_GameState->addShot(position, sf::Vector2f(7.0f, 21.0f), direction, rotation, mi_currentPowerUp, m_SpriteManager->loadSprite("shot0.png", 0, 0, 7, 21));
		}
		else if (mi_currentPowerUp == 1)
		{
 			m_GameState->addShot(position, sf::Vector2f(7.0f, 21.0f), direction, getRotation(), mi_currentPowerUp, m_SpriteManager->loadSprite("shot1.png", 0, 0, 7, 21));
		}
		mf_fireCooldown = 0;
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

		//Sprite does not move without these.

	if (m_animatedSprite->getPosition() != getPosition())
	{
		m_animatedSprite->setPosition(getPosition());
	}

	if (m_animatedSprite->getRotation() != getRotation())
	{
		m_animatedSprite->setRotation(getRotation());
	}

	m_animatedSprite->update(pf_deltaTime);
}

void PlayerObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_Sprite != nullptr)
	{
		target.draw(*m_animatedSprite, states);
	}
}

void PlayerObject::HandleCollision(GameObject *p_GameObject)
{
	if (p_GameObject->getType() == ROCK && mb_inDeathCycle == false)
	{
		std::cout << "player hit" << std::endl;
		mb_inDeathCycle = true;
		m_GameState->setLives(m_GameState->getLives() - 1);
		m_animatedSprite->setCurrentframe(1);
	}
	else if (p_GameObject->getType() == PWRUP && mb_inDeathCycle == false)
	{
		
	}
}

void PlayerObject::HandleCollision(PowerUp *p_PowerUp)
{
	mi_currentPowerUp = p_PowerUp->getPowerType();
	std::cout << "Picked up PowerUp" + mi_currentPowerUp << std::endl;
}