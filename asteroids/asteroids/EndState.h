#pragma once

#include "stdafx.h"
#include "State.h"

class GameObjectManager;
class StateManager;
class Engine;
class GameObject;

class EndState : public State
{
public:

	EndState();

	void Init();
	void Update(float pf_deltaTime);

	void Cleanup();
	void Pause();
	void Resume();

	void quit();
	void Draw();



private:

};