#pragma once

#include "stdafx.h"

//Objects type for easier itentification. Mostly used in collision.
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
	
	//Create new instance of GameObject. Many other lcasses inherit from this class.
	GameObject(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, EObjectType pe_ObjectType,sf::Sprite *p_Sprite = nullptr);

	//Update object
	virtual void update(float pf_deltaTime);

	//Draw object
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//GameObject is sometimes set without a sprite and assigned a sprite later.
	void setSprite(sf::Sprite *p_Sprite);
	sf::Sprite *getSprite();

	//setType for changing the object type may not be needed NOTE: potentially remove
	//void setType(EObjectType pe_ObjectType);

	//What to do when colliding with another object
	virtual void HandleCollision(GameObject *p_GameObject);

	//Check the kind of object
	EObjectType getType();

	//Used in collision. Returns the longer of globalBounds.x and globalBounds.y
	float getSize();

	//checks whether the object is due to be removed in the next frame
	bool mb_toBeRemoved;

protected:
	sf::Sprite *m_Sprite;
	sf::Vector2f mv2f_Size;

	EObjectType me_ObjectType;
};