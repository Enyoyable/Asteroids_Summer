// More of a text manager
#pragma once

#include "stdafx.h"
#include "SpriteManager.h"

class HUDManager
{
public:
	HUDManager(SpriteManager *p_SpriteManager);

	void Update(float pf_deltaTime, int pi_score);

	void Clear();

	std::vector<sf::Text*> *getHUDObjects();

private:

	sf::Text mt_Score;
	sf::Text mt_Lives;

	sf::Font mfo_HUDone;

	std::vector<sf::Text*> mv_HUDObjects;
};