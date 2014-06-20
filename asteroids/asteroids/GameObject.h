#pragma once

#include "stdafx.h"

class GameObject : public sf::Drawable, public sf::Transformable
{
public:
	
	GameObject(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Sprite *p_Sprite = nullptr);

	virtual void update(float pf_deltaTime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setSprite(sf::Sprite *p_Sprite);
	sf::Sprite *getSprite();

	void setSize(sf::Vector2f pv2f_Size);
	sf::Vector2f getSize();

	//void setType(EObjectType pe_ObjectType);
	//EObjectType getType();

	void HandleCollision(GameObject *p_GameObject);

private:
	sf::Sprite *m_Sprite;

	sf::Vector2f mv2f_Size;

	bool mb_HasAnimation;
};