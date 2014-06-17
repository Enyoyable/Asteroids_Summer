#pragma once
#include <iostream>

#include "stdafx.h"
#include "PauseState.h"
#include "State.h"

PauseState::PauseState()
{
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