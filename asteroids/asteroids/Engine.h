#pragma once

#include "stdafx.h"

class Engine
{
public:
	//Create, initialize and remove the Engine
	Engine();
	~Engine();

	void initialize();
	void run();

	//The window the game uses
	sf::RenderWindow *m_window;

	//Used for switching between states
	int mi_newstate;
};