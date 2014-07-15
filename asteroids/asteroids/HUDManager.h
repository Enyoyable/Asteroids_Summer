#pragma once

#include "stdafx.h"
#include "SpriteManager.h"

class HUDManager
{
public:
	HUDManager(SpriteManager *p_SpriteManager);

	void Update(float pf_deltaTime, int pi_score);

	std::vector<sf::Text*> *getHUDObjects();

private:

	sf::Text mt_Score;

	sf::Font mfo_HUDone;

	std::vector<sf::Text*> mv_HUDObjects;
};