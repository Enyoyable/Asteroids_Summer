#pragma once

#include "stdafx.h"
#include "MenuState.h"
#include "State.h"
#include <iostream>

MenuState::MenuState(GameObjectManager *p_GameObjectManager, StateManager *p_StateManager, SpriteManager *p_SpriteManager, CollisionManager *p_CollisionManager, Engine *p_Engine)
{
	m_GameObjectManager = p_GameObjectManager;
	m_StateManager = p_StateManager;
	m_SpriteManager = p_SpriteManager;
	m_CollisionManager = p_CollisionManager;
	m_Engine = p_Engine;

	ms_statename = "MenuState";
}

void MenuState::Init()
{
	std::cout << "Initialized ";
	std::cout << ms_statename << std::endl;
}

void MenuState::Cleanup()
{

}


void MenuState::Pause()
{

}

void MenuState::Resume()
{

}


void MenuState::Update(float pf_deltaTime)
{

}

void MenuState::Draw()
{

}