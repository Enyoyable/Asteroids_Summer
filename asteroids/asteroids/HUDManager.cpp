#include "HUDManager.h"
#include "stdafx.h"
#include <iostream>

HUDManager::HUDManager(SpriteManager *p_SpriteManager)
{
	mfo_HUDone.loadFromFile("arial.ttf");

	mt_Score.setFont(mfo_HUDone);
	mt_Score.setCharacterSize(50);
	mt_Score.setPosition(500, 50);
	mt_Score.setColor(sf::Color::White);

	mv_HUDObjects.push_back(&mt_Score);
}

void HUDManager::Update(float pf_deltaTime, int pi_score)
{
	//setString can't take an int. Why not?
	std::stringstream sstream;
	sstream << (int)pi_score;
	mt_Score.setString("Score: " + sstream.str());
}

std::vector<sf::Text*> *HUDManager::getHUDObjects()
{
	return &mv_HUDObjects;
}