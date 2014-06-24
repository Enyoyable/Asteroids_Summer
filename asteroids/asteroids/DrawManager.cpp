#include "DrawManager.h"
#include "GameObject.h"

DrawManager::DrawManager(sf::RenderWindow *p_window)
{
	m_window = p_window;
}

void DrawManager::draw(std::vector<GameObject*> *p_objects)
{
	for (auto object : *p_objects)
	{
		m_window->draw(*object);
	}
}