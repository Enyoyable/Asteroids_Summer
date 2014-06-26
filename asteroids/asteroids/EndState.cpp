#pragma once
#include <iostream>
#include "stdafx.h"
#include "EndState.h"
#include "State.h"

EndState::EndState(GameObjectManager *p_GameObjectManager, StateManager *p_StateManager, SpriteManager *p_SpriteManager, CollisionManager *p_CollisionManager, Engine *p_Engine)
{
	m_GameObjectManager = p_GameObjectManager;
	m_StateManager = p_StateManager;
	m_SpriteManager = p_SpriteManager;
	m_CollisionManager = p_CollisionManager;
	m_Engine = p_Engine;

	ms_statename = "EndState";
}

void EndState::Init()
{
	std::cout << "Initialized ";
	std::cout << ms_statename << std::endl;
}

void EndState::Cleanup()
{

}


void EndState::Pause()
{

}

void EndState::Resume()
{

}


void EndState::Update(float pf_deltaTime)
{

}

void EndState::Draw()
{

}