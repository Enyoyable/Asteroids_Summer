#pragma once
#include <iostream>

#include "stdafx.h"
#include "GameState.h"
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

}

void GameState::Draw()
{
	for (auto vGameObjects : mv_GameObjects)
	{
		
	}
}