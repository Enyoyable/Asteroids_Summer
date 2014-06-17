#pragma once

#include "stdafx.h"
#include "Engine.h"

int main()
{
	Engine engine;
	engine.initialize();
	engine.run();
	engine.cleanup();
};