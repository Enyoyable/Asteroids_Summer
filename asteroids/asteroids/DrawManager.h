#pragma once

#include "stdafx.h"
#include "GameObject.h"

class DrawManager
{
	DrawManager(sf::RenderWindow *p_window);

	void draw(std::vector<GameObject*> *pv_Objects);

private:
	sf::RenderWindow *m_window;
};