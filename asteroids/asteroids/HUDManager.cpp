#include "HUDManager.h"
#include "stdafx.h"
#include <iostream>

HUDManager::HUDManager(SpriteManager *p_SpriteManager)
{
	mfo_HUDone.loadFromFile("fonts/tahoma.ttf");


	mt_Score.setFont(mfo_HUDone);
	mt_Score.setCharacterSize(50);
	mt_Score.setPosition(700, 50);
	mt_Score.setColor(sf::Color::White);

	mt_Lives.setFont(mfo_HUDone);
	mt_Lives.setCharacterSize(50);
	mt_Lives.setPosition(300, 50);
	mt_Lives.setColor(sf::Color::White);
	mt_Lives.setString("Lives");

	mv_HUDObjects.push_back(&mt_Score);
	mv_HUDObjects.push_back(&mt_Lives);
}

void HUDManager::Update(float pf_deltaTime, int pi_score)
{
	//setString can't take an int. Why not?
	std::stringstream sstream;
	sstream << (int)pi_score;
	mt_Score.setString("Score " + sstream.str());
}

void HUDManager::Clear()
{
	mv_HUDObjects.clear();
}

std::vector<sf::Text*> *HUDManager::getHUDObjects()
{
	return &mv_HUDObjects;
}