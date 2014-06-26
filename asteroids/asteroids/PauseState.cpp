#pragma once
#include <iostream>

#include "stdafx.h"
#include "PauseState.h"
#include "State.h"

PauseState::PauseState(GameObjectManager *p_GameObjectManager, StateManager *p_StateManager, SpriteManager *p_SpriteManager, CollisionManager *p_CollisionManager, Engine *p_Engine)
{
	m_GameObjectManager = p_GameObjectManager;
	m_StateManager = p_StateManager;
	m_SpriteManager = p_SpriteManager;
	m_CollisionManager = p_CollisionManager;
	m_Engine = p_Engine;

	ms_statename = "PauseState";
}

void PauseState::Init()
{
	std::cout << "Initialized ";
	std::cout << ms_statename << std::endl;
}

void PauseState::Cleanup()
{

}


void PauseState::Pause()
{

}

void PauseState::Resume()
{

}


void PauseState::Update(float pf_deltaTime)
{

}

void PauseState::Draw()
{

}