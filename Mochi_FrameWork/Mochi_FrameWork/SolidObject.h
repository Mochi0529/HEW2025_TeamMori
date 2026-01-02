#pragma once
/***********************************************************************************************/
//	ソリッドオブジェクト
//	実態のあるオブジェクト。当たり判定を追加する
//	地面などに使う
/***********************************************************************************************/
#include"GameObjectBase.h"

#include "DefaultPlayerProfile.h"
#include"Texture.h"
//	コンポーネント
#include"DX11Renderer2D.h"	//	テクスチャ関係の追加
#include"Transform.h"		//	座標関係


class SolidObject :public MochiFramework::GameObjects::GameObjectBase<SolidObject>
{
private:
	static int m_objectCounter;	//	オブジェクトの数をカウントする
	bool m_isCollision = false;	//	当たり判定をつけるかどうかフラグ

public:

	explicit SolidObject(MochiFramework::SceneSystem::Scene* scene) : GameObjectBase(scene)
	{
		
		m_objectCounter++;
		//	コンポーネントの追加
		AddComponent<MochiFramework::Components::DX11Renderer2D>();	//　テクスチャ関係
		AddComponent<MochiFramework::Components::Transform>();		//	座標関係の追加

		
	
		
	}
	~SolidObject()
	{
		m_objectCounter--;
		RequestDestroy();	//	コンポーネントの削除処理

	}

	void Init();	//	情報の初期化

	void UpdateGameObject() override;	//	更新処理

	static void SolidObjectCounter();	//	オブジェクトの個数を数える

	//	情報を変更する
	void SetPosition(float x, float y, float z);	//	座標変更
	void SetScale(float x, float y, float z);	//	サイズ変更
	

	
};