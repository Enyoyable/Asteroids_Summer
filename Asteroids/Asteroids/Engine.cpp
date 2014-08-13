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

		//Update the game
		sm_Statemanager->Update(fDeltaTime, mi_newstate);
		
		//remove visuals from the last screen
		m_window->clear();

		//draw objects
		sm_Statemanager->Draw();

		//display objects
		m_window->display();

		//Check for events.
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			//End of the the game
			if (event.type == sf::Event::Closed || sm_Statemanager->getCurrectState()->getShutdown())
			{
				sm_Statemanager->Cleanup();
				sm_Statemanager->Quit();


				if (m_Gameobjectmanager != nullptr)
				{
					delete m_Gameobjectmanager;
					m_Gameobjectmanager = nullptr;
				}
				if (sm_Statemanager != nullptr)
				{
					delete sm_Statemanager;
					m_Gameobjectmanager = nullptr;
				}
				if (m_CollisionManager != nullptr)
				{
					delete m_CollisionManager;
					m_CollisionManager = nullptr;
				}
				m_window->close();

				if (m_window != nullptr)
				{
					delete m_window;
					m_window = nullptr;
				}
			}
		}
	}
}