#pragma once
#include <iostream>

#include "stdafx.h"
#include "PauseState.h"
#include "Engine.h"
#include "State.h"

#include "GameObjectManager.h"
#include "SpriteManager.h"

PauseState::PauseState(GameObjectManager *p_GameObjectManager, StateManager *p_StateManager, SpriteManager *p_SpriteManager, CollisionManager *p_CollisionManager, Engine *p_Engine)
{
	m_GameObjectManager = p_GameObjectManager;
	m_StateManager = p_StateManager;
	m_SpriteManager = p_SpriteManager;
	m_CollisionManager = p_CollisionManager;
	m_Engine = p_Engine;

	mb_Shutdown = false;

	ms_statename = "PauseState";
}

void PauseState::Init()
{
	std::cout << "Initialized ";
	std::cout << ms_statename << std::endl;

	mf_stateClock = 0.0f;

	mo_pausedText = new GameObject(sf::Vector2f(200, 200), sf::Vector2f(800, 413), BACK, m_SpriteManager->loadSprite("pause.png", 0, 0, 800, 413));
	mo_pausedText->setOrigin(0, 0);
	mo_pausedText->getSprite()->setOrigin(0, 0);
	mv_GameObjects.push_back(mo_pausedText);
}

void PauseState::Cleanup()
{
	mv_GameObjects.clear();
}


void PauseState::Pause()
{

}

void PauseState::Resume()
{

}


void PauseState::Update(float pf_deltaTime)
{
	mf_stateClock += pf_deltaTime;

	if (mf_stateClock > 1.0f)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			setNewstate(1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			mb_Shutdown = true;
			Cleanup();
		}
	}
	
}

void PauseState::Draw()
{
	m_GameObjectManager->drawObjects(&mv_GameObjects);
}

void PauseState::setNewstate(int pi_newState)
{
	m_Engine->mi_newstate = pi_newState;
}