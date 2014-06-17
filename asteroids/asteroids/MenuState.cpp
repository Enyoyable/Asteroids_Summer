#pragma once

#include "stdafx.h"
#include "MenuState.h"
#include "State.h"
#include <iostream>

MenuState::MenuState()
{
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