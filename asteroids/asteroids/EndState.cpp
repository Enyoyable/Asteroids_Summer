#pragma once
#include <iostream>
#include "stdafx.h"
#include "Engine.h"
#include "EndState.h"
#include "State.h"

#include "GameObjectManager.h"
#include "StateManager.h"
#include "SpriteManager.h"
#include "CollisionManager.h"
#include "HUDManager.h"

EndState::EndState(GameObjectManager *p_GameObjectManager, StateManager *p_StateManager, SpriteManager *p_SpriteManager, CollisionManager *p_CollisionManager, Engine *p_Engine)
{
	m_GameObjectManager = p_GameObjectManager;
	m_StateManager = p_StateManager;
	m_SpriteManager = p_SpriteManager;
	m_CollisionManager = p_CollisionManager;
	m_Engine = p_Engine;

	mb_Shutdown = false;

	ms_statename = "EndState";
}

void EndState::Init()
{
	std::cout << "Initialized ";
	std::cout << ms_statename << std::endl;

	mo_youDiedText = new GameObject(sf::Vector2f(200, 200), sf::Vector2f(800, 413), BACK, m_SpriteManager->loadSprite("gameover.png", 0, 0, 800, 413));
	mo_youDiedText->setOrigin(0,0);
	mo_youDiedText->getSprite()->setOrigin(0,0);
	mv_GameObjects.push_back(mo_youDiedText);
}

void EndState::Cleanup()
{
	mv_GameObjects.clear();
}


void EndState::Pause()
{

}

void EndState::Resume()
{

}


void EndState::Update(float pf_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		setNewstate(1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		mb_Shutdown = true;
	}
}

void EndState::Draw()
{
	m_GameObjectManager->drawObjects(&mv_GameObjects);
}

void EndState::setNewstate(int pi_newState)
{
	m_Engine->mi_newstate = pi_newState;
}