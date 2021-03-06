#pragma once
#include <iostream>

#include "Engine.h"
#include "stdafx.h"
#include "State.h"
#include "GameState.h"

#include "GameObjectManager.h"
#include "StateManager.h"
#include "SpriteManager.h"
#include "CollisionManager.h"
#include "AsteroidManager.h"
#include "HUDManager.h"

#include "PlayerObject.h"
#include "PlayerShot.h"
#include "Asteroid.h"
#include "PowerUp.h"

GameState::GameState(GameObjectManager *p_GameObjectManager, StateManager *p_StateManager, SpriteManager *p_SpriteManager, CollisionManager *p_CollisionManager, Engine *p_Engine)
{
	m_GameObjectManager = p_GameObjectManager;
	m_StateManager = p_StateManager;
	m_SpriteManager = p_SpriteManager;
	m_CollisionManager = p_CollisionManager;
	m_Engine = p_Engine;

	mb_Shutdown = false;

	ms_statename = "GameState";
}

void GameState::Init()
{
	mi_score = 0;
	mi_lives = 3;

	mf_stateClock = 0.0f;

	addPlayer();
	
	m_AsteroidManager = new AsteroidManager(&mv_GameObjects, m_SpriteManager, this);
	m_HUDManager = new HUDManager(m_SpriteManager);
}

void GameState::Cleanup()
{
	if (m_AsteroidManager != nullptr)
	{
		delete m_AsteroidManager;
		m_AsteroidManager = nullptr;
	}
	if (m_HUDManager != nullptr)
	{
		delete m_AsteroidManager;
		m_AsteroidManager = nullptr;
	}
	for (auto object : mv_lifeObjs)
	{
		if (object != nullptr)
		{
			delete object;
			object = nullptr;
		}
	}

	for (auto object : mv_GameObjects)
	{
		object->mb_toBeRemoved = true;
	}
	//m_GameObjectManager->cleanObjects(&mv_GameObjects);
}


void GameState::Update(float pf_deltaTime)
{
	mf_stateClock += pf_deltaTime;

	m_AsteroidManager->update(pf_deltaTime);
	m_GameObjectManager->updateObjects(&mv_GameObjects, pf_deltaTime);
	m_HUDManager->Update(pf_deltaTime, mi_score);
	m_CollisionManager->getCollision(&mv_GameObjects);

	if (mv_lifeObjs.size() < mi_lives)
	{
		for (int i = mv_lifeObjs.size(); i < mi_lives; i++)
		{
			mv_lifeObjs.push_back(new GameObject(sf::Vector2f(435 + i * 35, 85), sf::Vector2f(32, 32), HUDLIFE, m_SpriteManager->loadSprite("player.png", 0, 0, 32, 32)));
		}
	}
	if (mv_lifeObjs.size() > mi_lives)
	{
		mv_lifeObjs.erase(mv_lifeObjs.begin() + mv_lifeObjs.size() -1);
	}

	//Pause the game.
	//Swapping between the game and pause state has a 1 second cooldown to prevent flickering when holding the button down for more than one frame
	if (getStateClock() > 1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			setNewstate(2);
			resetStateclock();
			return;
		}
	}
}

void GameState::Draw()
{
	m_GameObjectManager->drawObjects(&mv_GameObjects);
	m_GameObjectManager->drawObjects(&mv_lifeObjs);
	m_GameObjectManager->drawHUD(m_HUDManager->getHUDObjects());
}

void GameState::addPlayer()
{
	m_Player = new PlayerObject(sf::Vector2f(m_Engine->m_window->getSize().x / 2, m_Engine->m_window->getSize().y / 2), sf::Vector2f(32.0f, 32.0f), this, m_SpriteManager, PLAYER, m_SpriteManager->loadanimatedSprite("player_sheet.txt"/*, 0, 0, 32, 32*/));
	mv_GameObjects.push_back(m_Player);
}

void GameState::addShot(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Vector2f pv2f_Direction, float pf_Angle, int pi_specialType, sf::Sprite *p_Sprite)
{
	mv_GameObjects.push_back(new PlayerShot(pv2f_Position, pv2f_Size, pv2f_Direction, pf_Angle, pi_specialType, SHOT, p_Sprite));
}

void GameState::setNewstate(int pi_newState)
{
	m_Engine->mi_newstate = pi_newState;
}

int GameState::getScore()
{
	return mi_score;
}
void GameState::setScore(int pi_newScore)
{
	mi_score = pi_newScore;
}

void GameState::addToScore(int pi_newScore)
{
	mi_score += pi_newScore;
}

int GameState::getLives()
{
	return mi_lives;
}
void GameState::setLives(int pi_newLives)
{
	mi_lives = pi_newLives;
}

float GameState::getStateClock()
{
	return mf_stateClock;
}

void GameState::resetStateclock()
{
	mf_stateClock = 0.0f;
}