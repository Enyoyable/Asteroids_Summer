#pragma once

#include "stdafx.h"
#include "GameObject.h"

class PlayerObject : public GameObject
{
public:

	PlayerObject(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Sprite *p_Sprite = nullptr);

	void update(float pf_deltaTime);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//void setType(EObjectType pe_ObjectType);
	//EObjectType getType();

	void HandleCollision(GameObject *p_GameObject);

private:

	sf::Sprite *m_Sprite;

	sf::Vector2f mv2f_Size;
};