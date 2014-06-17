#pragma once

#include "stdafx.h"

class Engine
{
public:
	Engine();
	~Engine();

	void initialize();
	void run();
	void cleanup();

	sf::RenderWindow *m_window;

	int mi_newstate;
};