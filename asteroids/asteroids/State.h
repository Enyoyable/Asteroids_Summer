#pragma once

class GameObject;
class GameObjectManager;
class StateManager;
class SpriteManager;
class CollisionManager;
class Engine;

class State
{
public:
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void Update(float pf_deltaTime) = 0;
	virtual void Draw() = 0;

	std::string ms_statename;

protected:
	std::vector<GameObject*> mv_GameObjects;

	GameObjectManager *m_GameObjectManager;

	StateManager *m_StateManager;

	SpriteManager *m_SpriteManager;

	CollisionManager *m_CollisionManager;

	Engine *m_Engine;
};