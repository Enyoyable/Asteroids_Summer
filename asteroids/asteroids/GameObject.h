#pragma once

#include "stdafx.h"

enum EObjectType
{
	PLAYER,
	ROCK,
	SHOT,
	BACK,
	HUDLIFE,
	PWRUP
};

class GameObject : public sf::Drawable, public sf::Transformable
{
public:
	
	GameObject(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, EObjectType pe_ObjectType,sf::Sprite *p_Sprite = nullptr);

	virtual void update(float pf_deltaTime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setSprite(sf::Sprite *p_Sprite);
	sf::Sprite *getSprite();

	//void setType(EObjectType pe_ObjectType);
	//EObjectType getType();

	virtual void HandleCollision(GameObject *p_GameObject);

	EObjectType getType();

	bool mb_toBeRemoved;

protected:
	sf::Sprite *m_Sprite;
	sf::Vector2f mv2f_Size;

	EObjectType me_ObjectType;

	bool mb_HasAnimation;
};