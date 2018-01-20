#pragma once
#include "Component.h"
#include "Model.h"
using namespace std;

class ModelComponent : public Component
{
public:
	void OnUpdate(float dt) override {};
	void OnMessage(const std::string m) override
	{};

	Model* m_model;
	ModelComponent() {};
	ModelComponent(Model* m) { m_model = m; };
	Model* getModel() { return m_model;}
};