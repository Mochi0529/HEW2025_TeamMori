#pragma once
#include "SolidObject.h"
#include <vector>
#include"Scene.h"

class Layer : public  MochiFramework::SceneSystem::Scene
{
private:
	std::vector<SolidObject> Objects;
public:
	void AddObject(float posX, float posY, float ScaleX, float ScaleY);
	void LayerUpdate();
	std::vector<SolidObject>& GetObjects();
	std::string GetName() const override;
};