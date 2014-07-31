#pragma once

#include "GameObject.h"
#include <iostream>

GameObject::GameObject(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, EObjectType pe_ObjectType, sf::Sprite *p_Sprite)
{

	setPosition(pv2f_Position);
	mv2f_Size = pv2f_Size;

	setSprite(p_Sprite);
	if (m_Sprite != nullptr)
	{
		m_Sprite->setOrigin(mv2f_Size.x / 2, mv2f_Size.y / 2);

		m_Sprite->setPosition(getPosition());
	}
	

	setOrigin(mv2f_Size.x / 2, mv2f_Size.y / 2);

	me_ObjectType = pe_ObjectType;

	mb_toBeRemoved = false;
}

void GameObject::update(float pf_deltaTime)
{
	if (m_Sprite != nullptr)
	{
		if (m_Sprite->getOrigin() != getOrigin())
		{
			m_Sprite->setOrigin(getOrigin());
		}
		if (m_Sprite->getPosition() != getPosition())
		{
			m_Sprite->setPosition(getPosition());
		}
	}
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_Sprite != nullptr)
	{
		target.draw(*m_Sprite, states);
	}
}

void GameObject::setSprite(sf::Sprite *p_Sprite)
{
	m_Sprite = p_Sprite;
}

sf::Sprite *GameObject::getSprite()
{
	return m_Sprite;
}



//void GameObject::setType(EObjectType pe_ObjectType)
//{

//}

//EObjectType GameObject::getType()
//{

//}

void GameObject::HandleCollision(GameObject *pp_GameObject)
{

}

EObjectType GameObject::getType()
{
	return me_ObjectType;
}