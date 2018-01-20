#include "Game.h"
#include "Scene.h"
#include "TransformComponent.h"
#include "ColourComponent.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "GameObject.h"

using namespace std;

int elementsToRead;
stringstream ss;


Game::Game()
{
	currentScene = new Scene();
	m_engineInterfacePtr = nullptr;
	m_inputHandler = new InputHandler(currentScene->m_inCubes);
}

void Game::update()
{

}

void Game::render()
{
	currentScene->Render(m_engineInterfacePtr);
}

