#pragma once
#include "GameObject.h"
#include "IEngineCore.h"
#include "InputHandler.h"
#include "Camera.h"
#include "json.h"
#include "Model.h"

class Scene
{
public:
	Scene() ;
	void LoadJson(std::string levelFile);
	void LoadModel(std::string levelFile);
	void loadTextLevel(std::string levelFile);
	
	void Render(IEngineCore* engineInterfacePtr);
	void Update(IEngineCore* engineInterfacePtr);

	std::vector<GameObject*> m_inCubes;
	GameObject* m_playerBackground;
private:
	
	

};
