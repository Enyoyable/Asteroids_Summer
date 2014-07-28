#include "PowerUp.h"
#include "GameObject.h"
#include "SpriteManager.h"
#include "stdafx.h"

PowerUp::PowerUp(sf::Vector2f pv2f_position, SpriteManager p_SpriteManager, EObjectType pe_ObjectType)
:GameObject(pv2f_position, sf::Vector2f(32,32), PWRUP, nullptr)
{
	srand(time(NULL));
	mi_powerType = rand() % 3 + 0;

	switch (mi_powerType)
	{
	case 1:
		{
			//set to specific powerup
		}
	case 2:
		{
			  //set to specific powerup
		}
	case 3:
		{
			  //set to specific powerup
		}
	}
}

void PowerUp::update(float pf_deltatime)
{
	//Animate sprite
}

void PowerUp::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_sprite != nullptr)
	{
		target.draw(*m_Sprite, states);
	}
}

void HandleCollision(GameObject *p_GameObject)
{

}