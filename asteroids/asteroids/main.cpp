//Asteroids Summer Project 
#pragma once

#include "stdafx.h"
#include "Engine.h"

//Runs the Engine class in which everything is located
int main()
{
	Engine engine;
	engine.initialize();
	engine.run();
};