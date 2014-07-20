#pragma once
#include <vector>
#include "State.h"

class StateManager
{
public:
	StateManager ();
	void AddState(State *p_newstate);

	void Init();
	void Update(float pf_deltatime, int pi_newstatenum);

	void Draw();
	void Cleanup();

	void Quit() { mb_running = false; }
	bool Running() { return mb_running; }
	
	State* getCurrectState();

	int mi_statenum;

private:

	std::vector<State*> mv_states;

	bool mb_running;
	
	State* ms_currentState;
};

