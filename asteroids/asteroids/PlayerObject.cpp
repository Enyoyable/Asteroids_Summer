#include "PlayerObject.h"
#include "GameObject.h"
#include "stdafx.h"
#include <iostream>

PlayerObject::PlayerObject(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Sprite *p_sprite)
: GameObject(pv2f_Position, pv2f_Size, p_sprite)
{
	
}

void PlayerObject::update(float pf_deltaTime)
{
	std::cout << getPosition().x << std::endl;
	//Move the player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		move(1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		move(-1,0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		setPosition(100.0f, 100.0f);
		//mv2f_Pos.x = (100.0f, 100.0f);
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