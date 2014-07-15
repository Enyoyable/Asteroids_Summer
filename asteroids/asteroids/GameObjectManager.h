#pragma once

#include "stdafx.h"
#include "GameObject.h"

class GameObjectManager
{
public:
	GameObjectManager(sf::RenderWindow *p_window);

	void updateObjects(std::vector<GameObject*> *pv_Objects, float pf_DeltaTime);
	
	void drawObjects(std::vector<GameObject*> *pv_Objects);
	void drawHUD(std::vector<sf::Text*> *pv_HUD);

	void removeObject(std::vector<GameObject*> *pv_Objects, GameObject *p_Object);

	void cleanObjects(std::vector<GameObject*> *pv_Objects);

private:

	sf::RenderWindow *m_window;
};