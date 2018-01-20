#pragma once
#include <map>
#include "GameObject.h"
#include <vector>
#include "TransformComponent.h"
#include "Camera.h"


class InputCommand
{
public:
	virtual ~InputCommand() {}
	virtual void execute(std::vector<GameObject*>& m_inCubes) = 0;
	
};


class RotateLeftCommand : public InputCommand
{

public: 

	void execute(std::vector<GameObject*>& m_inCubes) override{
		if (m_inCubes[0]->getComponent<TransformComponent>())
			m_inCubes[0]->getComponent<TransformComponent>()->OnMessage("rotateLeft");
	

	}

};

class RotateRightCommand : public InputCommand
{

public:

	void execute(std::vector<GameObject*>& m_inCubes) override {
		if (m_inCubes[0]->getComponent<TransformComponent>())
			m_inCubes[0]->getComponent<TransformComponent>()->OnMessage("rotateRight");
		

	}

};

class RotateUpCommand : public InputCommand
{

public:

	void execute(std::vector<GameObject*>& m_inCubes) override {
		if (m_inCubes[0]->getComponent<TransformComponent>())
			m_inCubes[0]->getComponent<TransformComponent>()->OnMessage("translateRight");


	}

};

class RotateDownCommand : public InputCommand
{

public:

	void execute(std::vector<GameObject*>& m_inCubes) override {
		if (m_inCubes[0]->getComponent<TransformComponent>())
			m_inCubes[0]->getComponent<TransformComponent>()->OnMessage("translateLeft");
	}

};

class TranslateUpCommand : public InputCommand
{

public:

	void execute(std::vector<GameObject*>& m_inCubes) override {
		if (m_inCubes[0]->getComponent<TransformComponent>())
			m_inCubes[0]->getComponent<TransformComponent>()->OnMessage("translateUp");
	
	}

};

class TranslateDownCommand : public InputCommand
{

public:

	void execute(std::vector<GameObject*>& m_inCubes) override {
		if (m_inCubes[0]->getComponent<TransformComponent>())
			m_inCubes[0]->getComponent<TransformComponent>()->OnMessage("translateDown");
	
	}

};

class ResetCommand : public InputCommand
{

public:

	void execute(std::vector<GameObject*>& m_inCubes) override {
		if (m_inCubes[0]->getComponent<TransformComponent>())
			m_inCubes[0]->getComponent<TransformComponent>()->OnMessage("reset");

	}

};



struct InputHandler
{	
	

	std::map<int, InputCommand*> m_controlMapping;

	InputHandler(std::vector<GameObject*> m_inCubes)
	{
		// the idea will be to map the keys directly from a config file that can be loaded in
		// and changed on the fly
		m_controlMapping[81] = new RotateLeftCommand;
		m_controlMapping[69] = new RotateRightCommand;
		m_controlMapping[87] = new TranslateUpCommand;
		m_controlMapping[83] = new TranslateDownCommand;
		m_controlMapping[65] = new RotateUpCommand;
		m_controlMapping[68] = new RotateDownCommand;
		m_controlMapping[90] = new ResetCommand;
		
		
	};

	void handleInputs(const std::vector<bool>& keyBuffer, std::vector<GameObject*> m_inCubes)
	{
		for(const auto& mapEntry : m_controlMapping)
		{
			if(keyBuffer[mapEntry.first])
			{
				mapEntry.second->execute(m_inCubes);
			}
		}

	}
};
