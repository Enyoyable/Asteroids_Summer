#pragma once 

#include "stdafx.h"
#include "GameObject.h"
#include "SpriteManager.h"
#include "AnimatedSprite.h"

class GameState;
class SpriteManager;

class PowerUp : public GameObject
{
public:
	PowerUp(sf::Vector2f pv2f_position, SpriteManager *p_SpriteManager, EObjectType pe_ObjectType);
	
	void update(float pf_deltatime);
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void HandleCollision(GameObject *p_GameObject);

	int getPowerType();

private:

	int mi_powerType;

	SpriteManager *m_SpriteManager;

	AnimatedSprite *m_animatedSprite;
};