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

	virtual void Update(float pf_deltaTime) = 0;
	virtual void Draw() = 0;

	virtual void setNewstate(int pi_newState) = 0;

	bool getShutdown() { return mb_Shutdown; };

	std::string ms_statename;

protected:
	bool mb_Shutdown;

	float mf_stateClock;

	std::vector<GameObject*> mv_GameObjects;

	GameObjectManager *m_GameObjectManager;

	StateManager *m_StateManager;

	SpriteManager *m_SpriteManager;

	CollisionManager *m_CollisionManager;

	Engine *m_Engine;
};