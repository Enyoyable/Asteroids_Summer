#pragma once

#include "Engine.h"
#include "stdafx.h"
#include "MenuState.h"
#include "State.h"
#include "SpriteManager.h"
#include "DrawManager.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include <iostream>

MenuState::MenuState(GameObjectManager *p_GameObjectManager, StateManager *p_StateManager, SpriteManager *p_SpriteManager, CollisionManager *p_CollisionManager, Engine *p_Engine)
{
	m_GameObjectManager = p_GameObjectManager;
	m_StateManager = p_StateManager;
	m_SpriteManager = p_SpriteManager;
	m_CollisionManager = p_CollisionManager;
	m_Engine = p_Engine;

	mb_Shutdown = false;

	ms_statename = "MenuState";
}

void MenuState::Init()
{
	mo_Background = new GameObject(sf::Vector2f(0,0), sf::Vector2f(1200, 900), BACK, m_SpriteManager->loadSprite("BG01.png", 0,0,1200,900));
	mo_Background->getSprite()->setOrigin(0, 0);
	mv_GameObjects.push_back(mo_Background);
}

void MenuState::Cleanup()
{
	m_GameObjectManager->removeObject(&mv_GameObjects, mo_Background);
}


void MenuState::Pause()
{

}

void MenuState::Resume()
{

}


void MenuState::Update(float pf_deltaTime)
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

void MenuState::Draw()
{
	m_GameObjectManager->drawObjects(&mv_GameObjects);
}

void MenuState::setNewstate(int pi_newState)
{
	m_Engine->mi_newstate = pi_newState;
}