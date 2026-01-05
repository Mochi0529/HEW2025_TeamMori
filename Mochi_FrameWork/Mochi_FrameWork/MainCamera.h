#pragma once

#include"GameObjectBase.h"

//	コンポーネント群
#include"Camera.h"
#include"Transform.h"

class MainCamera:public MochiFramework::GameObjects::GameObjectBase<MainCamera>
{

public:
	explicit MainCamera(MochiFramework::SceneSystem::Scene* scene) : GameObjectBase(scene)
	{
		


	}
	~MainCamera() = default;

	void Init()override;
	void UpdateGameObject()override;

	void SetPosition(float x, float y, float z);//	座標変更




};

