#pragma once

#include "GameObject.h"
#include <iostream>

GameObject::GameObject(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, EObjectType pe_ObjectType, sf::Sprite *p_Sprite)
{
	//Position and size
	setPosition(pv2f_Position);
	mv2f_Size = pv2f_Size;

	//Sets the origin and position of the sprite to the same as the object. Seperate from the object's own setOrigin.
	setSprite(p_Sprite);
	if (m_Sprite != nullptr)
	{
		m_Sprite->setOrigin(mv2f_Size.x / 2, mv2f_Size.y / 2);

		m_Sprite->setPosition(getPosition());
	}
	
	//Centers the origin of the object
	setOrigin(mv2f_Size.x / 2, mv2f_Size.y / 2);

	//Sets Object type
	me_ObjectType = pe_ObjectType;

	//All objects are not to be removed by deafault
	mb_toBeRemoved = false;
}

GameObject::~GameObject()
{

}

void GameObject::update(float pf_deltaTime)
{
	//If the object moves or rotates, move the sprite along with it
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

//draw the object's sprite
void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_Sprite != nullptr)
	{
		target.draw(*m_Sprite, states);
	}
}

//Sets the object's sprite
void GameObject::setSprite(sf::Sprite *p_Sprite)
{
	m_Sprite = p_Sprite;
}

//Gets the object's sprite
sf::Sprite *GameObject::getSprite()
{
	return m_Sprite;
}

//handle collision with other objects. Virtaul void. inheriting classes do the handling
void GameObject::HandleCollision(GameObject *pp_GameObject)
{

}

float GameObject::getSize()
{
	//Gets the size of the sprite accounting scale and returns the largest dimension
	float xSize = m_Sprite->getGlobalBounds().width;
	float ySize = m_Sprite->getGlobalBounds().height;
	if (ySize > xSize)
	{
		return ySize;
	}
	else
	{
		return xSize;
	}
}

//returns object type
EObjectType GameObject::getType()
{
	return me_ObjectType;
}