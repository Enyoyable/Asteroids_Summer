#pragma once
#include <iostream>
#include "stdafx.h"
#include "EndState.h"
#include "State.h"

EndState::EndState()
{
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