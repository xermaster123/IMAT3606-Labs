#pragma once
#include "IEngineCore.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "Camera.h"
#include "Scene.h"


class Game
{
public:
	Game();
	IEngineCore* m_engineInterfacePtr;
	InputHandler* m_inputHandler;
	Scene* currentScene;
	GameObject m_playerBackground;
	
	void update();
	void render();

private:
	
};
