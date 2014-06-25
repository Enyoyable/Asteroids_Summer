#include "PlayerObject.h"
#include "GameObject.h"
#include "stdafx.h"

PlayerObject::PlayerObject(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Sprite *p_sprite)
: GameObject(pv2f_Position, pv2f_Size, p_sprite)
{
	
}

void PlayerObject::update(float pf_deltaTime)
{
	//Move the player
}

void PlayerObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void PlayerObject::HandleCollision(GameObject *p_GameObject)
{

}