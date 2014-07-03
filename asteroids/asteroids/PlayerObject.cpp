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
}

void PlayerObject::update(float pf_deltaTime)
{
	//std::cout << getPosition().x << std::endl;
	//std::cout << sinf(getRotation()) << std::endl;
	//Move the player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		std::cout << "Rotation: " << getRotation() << std::endl;
		//std::cout << "Cos: " << cosf(getRotation()) << std::endl;
		//std::cout << "Sin: " << sinf(getRotation()) << std::endl;
		move(cosf((getRotation() -90)*3.14159265 / 180) /2, sinf((getRotation() - 90)*3.14159265 / 180)/2);

		//m_Sprite->move(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//m_Sprite->move(0, 1);
		move(-cosf((getRotation() - 90)*3.14159265 / 180)/2, -sinf((getRotation() - 90)*3.14159265 / 180) /2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rotate(-0.5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rotate(0.5);
	}

	//Sprite does not move without these. Why not?

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