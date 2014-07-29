#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "AnimatedSprite.h"

class GameState;
class SpriteManager;
class AnimatedSprite;

class PlayerObject : public GameObject
{
public:

	PlayerObject(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, GameState *p_GameOState, SpriteManager *p_SpriteManager, EObjectType pe_ObjectType, AnimatedSprite *p_sprite);

	void update(float pf_deltaTime);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//void setType(EObjectType pe_ObjectType);
	//EObjectType getType();

	void HandleCollision(GameObject *p_GameObject);

private:
	sf::Vector2f mv2f_Speed;

	float mf_velocity;
	float mf_fireCooldown;

	GameState *m_GameState;
	SpriteManager *m_SpriteManager;

	AnimatedSprite *m_animatedSprite;
};