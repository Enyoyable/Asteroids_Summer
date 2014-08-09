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
	//set movement related variables
	mv2f_Speed = sf::Vector2f(0.0f, 0.0f);
	mf_velocity = 0.0f;
	
	//set other simple variables
	mf_fireCooldown = 0.0f;
	mf_powerupTimer = 0.0f;
	mi_currentPowerUp = 0;

	//set pointer variables
	m_GameState = p_GameState;
	m_SpriteManager = p_SpriteManager;
	
	//set sprites
	mb_inDeathCycle = false;
	m_animatedSprite = p_sprite;
	m_animatedSprite->pause();
	m_animatedSprite->setOrigin(mv2f_Size.x / 2, mv2f_Size.y / 2);
	m_animatedSprite->setPosition(getPosition());
}

void PlayerObject::update(float pf_deltaTime)
{
	//Player does not collide with objects if in the death animation
	if (mb_inDeathCycle)
	{
		//Start the animated sprite containing the death animation
		m_animatedSprite->play();
		m_animatedSprite->update(pf_deltaTime);

		//The player cannot move when in the death cycle
		mv2f_Speed = sf::Vector2f(0, 0);
		mf_velocity = 0;
		
		//The frame 0 is the base frame, checks if the animation is looped
		if (m_animatedSprite->getCurrentFrame() == 0)
		{
			//checks if the player has run out of lives
			if (m_GameState->getLives() <= 0)
			{
				//Exits the game state
				std::cout << "DEAD" << std::endl;
				m_GameState->setNewstate(3);
			}
			else
			{
				//resets player to middle of the screen and stops the sprite. breaks the deathcycle loop. NOTE: needs invincibility frames
				setPosition(600, 450);
				m_animatedSprite->pause();
				mb_inDeathCycle = false;
			}
		}
		return;
	}

	
	//Pause the game NOTE: Might movie this into gamestate
	//Swapping between the game and pause state has a 1 second cooldown to prevent flickering when holding the button down for more than one frame
	if (m_GameState->getStateClock() > 1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			m_GameState->setNewstate(2);
			m_GameState->resetStateclock();
			return;
		}
	}

	//Shoots if the cooldown is finished
	mf_fireCooldown += pf_deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && mf_fireCooldown > 0.2f)
	{
		//Gets the different variables needed to create a shot and determind it's direction.
		sf::Vector2f position = sf::Vector2f(getPosition().x + (cosf((getRotation() - 90)*3.14159265 / 180) * mv2f_Size.x / 2), 
											getPosition().y + (sinf((getRotation() - 90)*3.14159265 / 180)* mv2f_Size.y / 2));
		sf::Vector2f direction = sf::Vector2f((cosf((getRotation() - 90)*3.14159265 / 180)), (sinf((getRotation() - 90)*3.14159265 / 180)));
		
		float rotation = getRotation();

		//creates shot depending on current powerup. standard is 0
		if (mi_currentPowerUp == 0)
		{
			m_GameState->addShot(position, sf::Vector2f(7.0f, 21.0f), direction, rotation, mi_currentPowerUp, m_SpriteManager->loadSprite("shot0.png", 0, 0, 7, 21));
		}
		else if (mi_currentPowerUp == 1)
		{
 			m_GameState->addShot(position, sf::Vector2f(7.0f, 21.0f), direction, getRotation(), mi_currentPowerUp, m_SpriteManager->loadSprite("shot1.png", 0, 0, 7, 21));
		}
		else if (mi_currentPowerUp == 2)
		{
			//powerup 2 fires three shots in a spread rather than one.
			m_GameState->addShot(position, sf::Vector2f(7.0f, 21.0f), sf::Vector2f((cosf((getRotation() - 70)*3.14159265 / 180)), (sinf((getRotation() - 70)*3.14159265 / 180))), getRotation() + 20, mi_currentPowerUp, m_SpriteManager->loadSprite("shot2.png", 0, 0, 7, 21));
			m_GameState->addShot(position, sf::Vector2f(7.0f, 21.0f), direction, getRotation(), mi_currentPowerUp, m_SpriteManager->loadSprite("shot2.png", 0, 0, 7, 21));
			m_GameState->addShot(position, sf::Vector2f(7.0f, 21.0f), sf::Vector2f((cosf((getRotation() - 110)*3.14159265 / 180)), (sinf((getRotation() - 110)*3.14159265 / 180))), getRotation() - 20, mi_currentPowerUp, m_SpriteManager->loadSprite("shot2.png", 0, 0, 7, 21));
		}
		//restes cooldown
		mf_fireCooldown = 0;
	}

	//Checks if the powerup time is over and reverts to standard shots if it is
	if (mf_powerupTimer > 0 && mi_currentPowerUp != 0)
	{
		mf_powerupTimer -= pf_deltaTime;
	}
	else if (mf_powerupTimer < 0)
	{
		mf_powerupTimer = 0.0f;
		mi_currentPowerUp = 0;
	}

	//Player movement

	//Uses the rotational angle of the player to calulate the direction to move in.
	//Variable mf_velocity multiplies the speed
	mv2f_Speed = sf::Vector2f((cosf((getRotation() - 90)*3.14159265 / 180) * mf_velocity), (sinf((getRotation() - 90)*3.14159265 / 180)* mf_velocity));
	move(mv2f_Speed);
	
	//Adjusts the speed and direction of the player depending on input
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

	//max and minimum for player speed
	if (mf_velocity > 0.00f)
		mf_velocity -= 0.001f;
	else if (mf_velocity < 0.00f)
		mf_velocity += 0.001f;


	//Screen warp. makes sure the player reappears on the right parts of the screen. Same code used in asteroids and player shots.
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
	//Makes sure the sprite is allways has the same position and rotation as the player
	if (m_animatedSprite->getPosition() != getPosition())
	{
		m_animatedSprite->setPosition(getPosition());
	}

	if (m_animatedSprite->getRotation() != getRotation())
	{
		m_animatedSprite->setRotation(getRotation());
	}
}

void PlayerObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//draw the animatedsprite which is set to not animate unless player is in death cycle.
	//basically the same as drawing a single sprite
	if (m_Sprite != nullptr)
	{
		target.draw(*m_animatedSprite, states);
	}
}

void PlayerObject::HandleCollision(GameObject *p_GameObject)
{
	//what to do when player hits an asteroid and isn't in the death cycle
	if (p_GameObject->getType() == ROCK && mb_inDeathCycle == false)
	{
		std::cout << "player hit" << std::endl;
		//Puts player in death cycle, decreases lives by one and sets the current frame to 1
		mb_inDeathCycle = true;
		m_GameState->setLives(m_GameState->getLives() - 1);
		m_animatedSprite->setCurrentframe(1);
	}
}

void PlayerObject::HandleCollision(PowerUp *p_PowerUp)
{
	//What to do when hittign a powerup.
	//sets current powerup to the corresponding number in the other object
	mi_currentPowerUp = p_PowerUp->getPowerType();
	//sets the time the specific powerups will be active. NOTE: Is reset when picking up an extra life
	if (mi_currentPowerUp == 1)
	{
		mf_powerupTimer = 3;
	}
	else if (mi_currentPowerUp == 2)
	{
		mf_powerupTimer = 10;
	}
	else if (mi_currentPowerUp == 3)
	{
		//number 3 is an extra life and therefore does not modify current powerup or timer
		m_GameState->setLives(m_GameState->getLives() + 1);
		mi_currentPowerUp = 0;
	}
}