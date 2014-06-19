#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engine.h"
#include "StateManager.h"
#include "GameObjectManager.h"
#include "MenuState.h"
#include "GameState.h"
#include "PauseState.h"
#include "EndState.h"

Engine::Engine()
{

}

Engine::~Engine()
{

}

void Engine::initialize()
{
	std::cout << "Program start" << std::endl;
	m_window = new sf::RenderWindow(sf::VideoMode(1200, 900), "Asteroids");

	sf::Vector2u size = m_window->getSize();
	unsigned int width = size.x;
	unsigned int height = size.y;
	mi_newstate = 0;
}

void Engine::run()
{
	sf::Clock timer;

	GameObjectManager m_Gameobjectmanager = GameObjectManager(m_window);

	StateManager sm_Statemanager = StateManager();

	sm_Statemanager.AddState(new MenuState());
	sm_Statemanager.AddState(new GameState());
	sm_Statemanager.AddState(new PauseState());
	sm_Statemanager.AddState(new EndState());

	sm_Statemanager.Init();

	while (m_window->isOpen())
	{
		float fDeltaTime = timer.restart().asSeconds();

		if (fDeltaTime > 0.1)
			fDeltaTime = 0.1;

		sm_Statemanager.Update(fDeltaTime, mi_newstate);
		sm_Statemanager.Draw();

		sf::Event event;

		while (m_window->pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				mi_newstate = 0;
				//change to state zero(menu) if current state is not menu
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				mi_newstate = 1;
				//change to state one(Game) if current state is not game
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			{
				mi_newstate = 2;
				//change to state two(Pause) if current state is not pause
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				mi_newstate = 3;
				//change to state three(End) if current state is not end
			}

			if (event.type == sf::Event::Closed)
			{
				sm_Statemanager.Cleanup();
				sm_Statemanager.Quit();
				m_window->close();
			}
		}
		m_window->clear();
		m_window->display();
	}
}

void Engine::cleanup()
{

}