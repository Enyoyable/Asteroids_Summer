#pragma once
#include <iostream>

#include "stdafx.h"
#include "GameState.h"
#include "State.h"

GameState::GameState()
{
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

}