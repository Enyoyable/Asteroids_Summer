#pragma once

#include "GameObject.h"
#include <iostream>

GameObject::GameObject(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Sprite *p_Sprite)
{
	setSprite(p_Sprite);

	setPosition(pv2f_Position);
	mv2f_Size = pv2f_Size;

	setOrigin(mv2f_Size.x / 2, mv2f_Size.y / 2);


}

void GameObject::update(float pf_deltaTime)
{
	
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	std::cout << "this shouldn't be shown\n";
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