#pragma once
/***********************************************************************************************/
//	ソリッドオブジェクト
//	実態のあるオブジェクト。当たり判定を追加する
//	地面などに使う
/***********************************************************************************************/
#include"GameObjectBase.h"

//	コンポーネント
#include"DX11Renderer2D.h"	//	テクスチャ関係の追加
#include"Transform.h"		//	座標関係


class SolidObject :public MochiFramework::GameObjects::GameObjectBase<SolidObject>
{
private:
	static int m_objectCounter;	//	オブジェクトの数をカウントする


public:
	explicit SolidObject(MochiFramework::SceneSystem::Scene* scene) : GameObjectBase(scene)
	{
		
		m_objectCounter++;
		//	コンポーネントの追加
		AddComponent<MochiFramework::Components::DX11Renderer2D>();	//	コンポーネント機能の追加
		AddComponent<MochiFramework::Components::Transform>();		//	座標関係の追加

		
		
	}
	~SolidObject()
	{
		m_objectCounter--;
		RequestDestroy();	//	コンポーネントの削除処理

	}

	void UpdateGameObject() override;

	static void SolidObjectCounter();
	
};