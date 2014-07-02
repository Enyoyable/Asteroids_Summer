#pragma once
#include <iostream>

#include "stdafx.h"
#include "GameState.h"
#include "GameObjectManager.h"
#include "StateManager.h"
#include "SpriteManager.h"
#include "CollisionManager.h"
#include "Engine.h"
#include "PlayerObject.h"
#include "State.h"

GameState::GameState(GameObjectManager *p_GameObjectManager, StateManager *p_StateManager, SpriteManager *p_SpriteManager, CollisionManager *p_CollisionManager, Engine *p_Engine)
{
	m_GameObjectManager = p_GameObjectManager;
	m_StateManager = p_StateManager;
	m_SpriteManager = p_SpriteManager;
	m_CollisionManager = p_CollisionManager;
	m_Engine = p_Engine;

	ms_statename = "GameState";
}

void GameState::Init()
{
	std::cout << "Initialized ";
	std::cout << ms_statename << std::endl;

	m_Player = new PlayerObject(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(32.0f, 32.0f), m_SpriteManager->loadSprite("player.png", 0,0,32,32));
	mv_GameObjects.push_back(m_Player);
}

void GameState::Cleanup()
{

}


void GameState::Pause()
{

}

void GameState::Resume()
{

}


void GameState::Update(float pf_deltaTime)
{
	m_GameObjectManager->updateObjects(&mv_GameObjects, pf_deltaTime);
}

void GameState::Draw()
{
	m_GameObjectManager->drawObjects(&mv_GameObjects);

	/*for (auto vGameObjects : mv_GameObjects)
	{
		m_GameObjectManager->drawObjects(&mv_GameObjects);
	}*/
}