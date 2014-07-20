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
	mi_score = 110;

	std::cout << "Initialized ";
	std::cout << ms_statename << std::endl;

	addPlayer();
	
	m_AsteroidManager = new AsteroidManager(&mv_GameObjects, m_SpriteManager);
	m_HUDManager = new HUDManager(m_SpriteManager);
	//addAsteroid(sf::Vector2f(200, 200), 3, m_SpriteManager->loadSprite("asteroid01.png", 0, 0, 100, 100));
}

void GameState::Cleanup()
{
	mv_GameObjects.clear();
	m_HUDManager->Clear();
}


void GameState::Pause()
{

}

void GameState::Resume()
{

}


void GameState::Update(float pf_deltaTime)
{
	m_AsteroidManager->update(pf_deltaTime);
	m_GameObjectManager->updateObjects(&mv_GameObjects, pf_deltaTime);
	m_HUDManager->Update(pf_deltaTime, mi_score);
	m_CollisionManager->getCollision(&mv_GameObjects);
}

void GameState::Draw()
{
	m_GameObjectManager->drawObjects(&mv_GameObjects);
	m_GameObjectManager->drawHUD(m_HUDManager->getHUDObjects());
	//m_HUDManager->Draw();

	/*for (auto vGameObjects : mv_GameObjects)
	{
		m_GameObjectManager->drawObjects(&mv_GameObjects);
	}*/
}

void GameState::addPlayer()
{
	m_Player = new PlayerObject(sf::Vector2f(m_Engine->m_window->getSize().x / 2, m_Engine->m_window->getSize().y / 2), sf::Vector2f(32.0f, 32.0f), this, m_SpriteManager, PLAYER, m_SpriteManager->loadSprite("player.png", 0, 0, 32, 32));
	mv_GameObjects.push_back(m_Player);
}

void GameState::addShot(sf::Vector2f pv2f_Position, sf::Vector2f pv2f_Size, sf::Vector2f pv2f_Direction, float pf_Angle, sf::Sprite *p_Sprite)
{
	mv_GameObjects.push_back(new PlayerShot(pv2f_Position, pv2f_Size, pv2f_Direction, pf_Angle, SHOT, p_Sprite));
}

void GameState::setNewstate(int pi_newState)
{
	m_Engine->mi_newstate = pi_newState;
}