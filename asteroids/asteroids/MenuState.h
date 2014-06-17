#pragma once

#include "stdafx.h"
#include "State.h"

class MenuState : public State
{
public:

	MenuState();

	void Init();
	void Update(float pf_deltaTime);

	void Cleanup();
	void Pause();
	void Resume();

	void quit();
	void Draw();



private:

};