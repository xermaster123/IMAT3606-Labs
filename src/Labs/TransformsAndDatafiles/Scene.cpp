#include "Scene.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "TransformComponent.h"
#include "ColourComponent.h"
#include "InputHandler.h"
#include "ModelComponent.h"
using namespace std;

void Scene::loadTextLevel(string s)
{
	/*ifstream myInputText;
	myInputText.open(txtFilename, ios_base::in);

	if (myInputText.is_open())
	{
		cout << "yay the file is open!!!\n";
		getline(myInputText, s);
		ss.clear();
		ss.str(s);
		ss.ignore(17);
		ss >> elementsToRead;
		cout << elementsToRead << endl;
		m_inCubes.resize(elementsToRead);


		for (int i = 0; i<elementsToRead; i++)
		{
			float tx, ty, tz, rx, ry, rz, rw, sx, sy, sz;
			getline(myInputText, s);
			getline(myInputText, s);
			ss.clear();
			ss.str(s);
			ss >> tx >> ty >> tz;
			glm::vec3 pos(tx, ty, tz);

			getline(myInputText, s);
			ss.clear();
			ss.str(s);
			ss >> rx >> ry >> rz >> rw;
			glm::quat rot(rx, ry, rz, rw);

			getline(myInputText, s);
			ss.clear();
			ss.str(s);
			ss >> sx >> sy >> sz;
			glm::vec3 scale(sx, sy, sz);
			m_inCubes[i].addComponent(new TransformComponent(pos, rot, scale));

		}

	}*/
}
void Scene::Render(IEngineCore * engineInterfacePtr)
{
	//m_playerBackground = new GameObject();
	

		engineInterfacePtr->renderColouredBackground(0.5, 0.5, 0.5);


	
		
		engineInterfacePtr->drawModel(this->m_inCubes.at(0)->getComponent<ModelComponent>()->getModel(),
			this->m_inCubes.at(0)->getComponent<TransformComponent>()->getModelMatrix());

	


	// update the camera (probably don't need to do this each frame)

	engineInterfacePtr->setCamera(m_inCubes[0]->getComponent<Camera>());
	glm::vec3 CubePos = m_inCubes[0]->getComponent<TransformComponent>()->position();
	m_inCubes[0]->getComponent<Camera>()->setPos(-CubePos.x, -CubePos.y, CubePos.z);
	

	// draw the cube
	//m_inCubes[0]->getComponent<ModelComponent>()->m_model->render(1);
}
void Scene::LoadJson(std::string levelJSONFile)
{
	Model* TestModel = new Model("assets/models/face/face.obj");
	ModelComponent* Model = new ModelComponent(TestModel);
	int elementsToRead;

	stringstream ss;

	std::fstream jsonData;
	Json::Value root;
	Json::Reader reader;
	jsonData.open(levelJSONFile.c_str());
	GameObject* game_obj = new GameObject();
	// check for errors
	if (!reader.parse(jsonData, root))
	{
		std::cout << "Failed to parse data from: "
			<< levelJSONFile
			<< reader.getFormattedErrorMessages();
	}
	const Json::Value gameObjects = root["GameObjects"];
	// size() tells us how large the array is
	for (int i = 0; i < gameObjects.size(); i++)
	{
		TransformComponent* transform = new TransformComponent();
		// get string
		std::cout << gameObjects[i]["name"].asString() << " loaded\n";
		// get the position node
		const Json::Value posNode = gameObjects[i]["position"];
		transform->m_position.x = posNode[0].asFloat(); // get float
		transform->m_position.y = posNode[1].asFloat();
		transform->m_position.z = posNode[2].asFloat();


		const Json::Value orientNode = gameObjects[i]["orientation"];
		transform->m_orientation.x = orientNode[0].asFloat(); // get float
		transform->m_orientation.y = orientNode[1].asFloat();
		transform->m_orientation.z = orientNode[2].asFloat();
		transform->m_orientation.w = orientNode[3].asFloat();

		const Json::Value scaleNode = gameObjects[i]["scale"];
		transform->m_scale.x = scaleNode[0].asFloat(); // get float
		transform->m_scale.y = scaleNode[1].asFloat();
		transform->m_scale.z = scaleNode[2].asFloat();

		
		
		game_obj->addComponent(transform);
		game_obj->addComponent(Model); 
		//m_inCubes[0] = game_obj;
		m_inCubes.push_back(game_obj);

	}
}
Scene::Scene() 
{
	
	string jsonFilenames = "assets/levels/myCubeLevel.json";
	LoadJson(jsonFilenames);
	
	m_inCubes[0]->addComponent(new Camera());

};