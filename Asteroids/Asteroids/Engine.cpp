#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engine.h"

#include "StateManager.h"
#include "GameObjectManager.h"
#include "CollisionManager.h"
#include "SpriteManager.h"

#include "MenuState.h"
#include "GameState.h"
#include "PauseState.h"
#include "EndState.h"

//Create Engine
Engine::Engine()
{

}

Engine::~Engine()
{

}

//Initialize the engine
void Engine::initialize()
{
	std::cout << "Program start" << std::endl;

	//Set up the window
	m_window = new sf::RenderWindow(sf::VideoMode(1200, 900), "Asteroids");
	sf::Vector2u size = m_window->getSize();
	
	//Not actuall used, subject to be removed
	unsigned int width = size.x;
	unsigned int height = size.y;
	
	mi_newstate = 0;
}

//The main part of the game
void Engine::run()
{
	//Used to calculate deltatime between updates.
	sf::Clock timer;

	//Managers set up
	GameObjectManager *m_Gameobjectmanager = new GameObjectManager(m_window);
	StateManager *sm_Statemanager = new StateManager();
	CollisionManager *m_CollisionManager = new CollisionManager();
	SpriteManager m_SpriteManager = SpriteManager("../resources/sprites/");

	//States added to Statemanager before initialization
	sm_Statemanager->AddState(new MenuState(m_Gameobjectmanager, sm_Statemanager, &m_SpriteManager, m_CollisionManager, this));
	sm_Statemanager->AddState(new GameState(m_Gameobjectmanager, sm_Statemanager, &m_SpriteManager, m_CollisionManager, this));
	sm_Statemanager->AddState(new PauseState(m_Gameobjectmanager, sm_Statemanager, &m_SpriteManager, m_CollisionManager, this));
	sm_Statemanager->AddState(new EndState(m_Gameobjectmanager, sm_Statemanager, &m_SpriteManager, m_CollisionManager, this));

	sm_Statemanager->Init();

	//The mai loop of the game, the parts before this is only run at the start of the program
	while (m_window->isOpen())
	{
		//Deltatime calcylated
		float fDeltaTime = timer.restart().asSeconds();
		if (fDeltaTime > 0.1)
			fDeltaTime = 0.1;

		//Check for events.
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			//Debug function for switching between states manually. NOTE: remove these.
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

			//End othe the game
			if (event.type == sf::Event::Closed || sm_Statemanager->getCurrectState()->getShutdown())
			{
				sm_Statemanager->Cleanup();
				sm_Statemanager->Quit();
				m_window->close();
			}
		}
		
		//Update the game
		sm_Statemanager->Update(fDeltaTime, mi_newstate);
		
		//remove visuals from the last screen
		m_window->clear();

		//draw objects
		sm_Statemanager->Draw();

		//display objects
		m_window->display();
	}
}

//Remove everything that's left
void Engine::cleanup()
{

}