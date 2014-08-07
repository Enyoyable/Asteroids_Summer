#include "PowerUp.h"
#include "GameObject.h"
#include "SpriteManager.h"
#include "stdafx.h"

PowerUp::PowerUp(sf::Vector2f pv2f_position, SpriteManager *p_SpriteManager, EObjectType pe_ObjectType)
:GameObject(pv2f_position, sf::Vector2f(32,32), PWRUP, nullptr)
{
	
	srand(time(NULL));
	//mi_powerType = rand() % 3 + 0;
	mi_powerType = 3;
	m_SpriteManager = p_SpriteManager;
	


	switch (mi_powerType)
	{
	case 1://set to specific powerup (piercing shot)
		m_animatedSprite = m_SpriteManager->loadanimatedSprite("powerup1.txt");
		break;
	case 2://set to specific powerup (scatter shot)
    	m_animatedSprite = m_SpriteManager->loadanimatedSprite("powerup2.txt");
		break;
	case 3://set to specific powerup
		m_animatedSprite = m_SpriteManager->loadanimatedSprite("powerup3.txt");
		break;
	}

	//This is just to allow the collision to measure it's size.
	m_Sprite = m_SpriteManager->loadSprite("player.png");
}

void PowerUp::update(float pf_deltatime)
{
	m_animatedSprite->update(pf_deltatime);

	if(m_animatedSprite->getPosition() != getPosition())
	{
		m_animatedSprite->setPosition(getPosition());
	}
}

int PowerUp::getPowerType()
{
	return mi_powerType;
}

void PowerUp::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_animatedSprite != nullptr)
	{
		target.draw(*m_animatedSprite, states);
	}
}

void PowerUp::HandleCollision(GameObject *p_GameObject)
{
	if (p_GameObject->getType() == PLAYER)
	{
		mb_toBeRemoved = true;
	}
}