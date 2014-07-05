#include "PlayerObject.h"
#include "GameObject.h"
#include "stdafx.h"
#include <iostream>
#include <math.h>

PlayerObject::PlayerObject(sf::Vector2f position, sf::Vector2f pv2f_Size, sf::Sprite *sprite)
: GameObject(position, pv2f_Size, sprite)
{
	//Why is the sprite separate from the game object?
	m_Sprite->setOrigin(mv2f_Size.x / 2, mv2f_Size.y / 2);

	mv2f_Speed = sf::Vector2f(0.0f, 0.0f);
	mf_velocity = 0.0f;
}

void PlayerObject::update(float pf_deltaTime)
{
	std::cout << mv2f_Speed.y << std::endl;
	mv2f_Speed = sf::Vector2f((cosf((getRotation() - 90)*3.14159265 / 180) * mf_velocity), (sinf((getRotation() - 90)*3.14159265 / 180)* mf_velocity));
	
	//Move the player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && mf_velocity < 1.5f)
	{
		mf_velocity += 0.01f;

		//move(cosf((getRotation() -90)*3.14159265 / 180), sinf((getRotation() - 90)*3.14159265 / 180)/2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && mf_velocity > -1.5f)
	{
		mf_velocity -= 0.01f;

		//move(-cosf((getRotation() - 90)*3.14159265 / 180)/2, -sinf((getRotation() - 90)*3.14159265 / 180) /2);
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

}