#pragma once
/********************************************************/
//	プレイヤーキャラクター
//	ユーザーが操作できるキャラを作る
/********************************************************/
#include"GameObjectBase.h"
#include "DefaultPlayerProfile.h"

//	コンポーネント
#include"DX11Renderer2D.h"
#include"Transform.h"
#include"InputComponent.h"

class PlayerCharacter:public MochiFramework::GameObjects::GameObjectBase<PlayerCharacter>
{
private:

public:
	explicit PlayerCharacter(MochiFramework::SceneSystem::Scene* scene) : GameObjectBase(scene)
	{

		//	コンポーネントの追加
		AddComponent<MochiFramework::Components::DX11Renderer2D>();	//　テクスチャ関係
		AddComponent<MochiFramework::Components::Transform>();		//	座標関係の追加
		//	入力の追加
		auto* ic = AddComponent<MochiFramework::Components::InputComponent>();
		auto map = std::make_unique<MochiFramework::InputSystem::InputMap>();
		MochiFramework::InputSystem::DefaultPlayerProfile profile;
		profile.Apply(*map);          // 既定バインドをコピー
		ic->SetInputMap(std::move(map));

	}
	~PlayerCharacter()
	{
		RequestDestroy();	//	コンポーネントの削除処理

	}

	void UpdateGameObject() override;

	void MoveRaght();	//	右移動
	void MoveLeft();	//	左移動

};

