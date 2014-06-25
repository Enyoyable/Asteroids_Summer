#pragma once
#include "StateManager.h"
#include "State.h"
#include <iostream>

StateManager::StateManager()
{
	mi_statenum = 0;
}

void StateManager::AddState(State *newstate)
{
	//set to go "Menu, Game, Pause, End"
	mv_states.push_back(newstate);
}

void StateManager::Init()
{
	ms_currentState = mv_states[mi_statenum];
	ms_currentState->Init();
}

void StateManager::Update(float pf_deltatime, int pi_newstatenum)
{
	ms_currentState->Update(pf_deltatime);

	if (mi_statenum != pi_newstatenum)
	{
		mi_statenum = pi_newstatenum;
		Init();
		
		//ms_currentState = states[mi_statenum];
		//ms_currentState->Init();
	}
}

void StateManager::Draw()
{
	ms_currentState->Draw();
}
void StateManager::Cleanup()
{

}