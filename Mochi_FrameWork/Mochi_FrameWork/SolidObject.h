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
#include"Camera.h"


class SolidObject :public MochiFramework::GameObjects::GameObjectBase<SolidObject>
{
private:
	static int m_objectCounter;	//	オブジェクトの数をカウントする
	bool m_isCollision = true;	//	当たり判定をつけるかどうかフラグ


	//	todo: コンポーネントTransformが解決したら削除する


public:
	explicit SolidObject(MochiFramework::SceneSystem::Scene* scene) : GameObjectBase(scene)
	{
		
		m_objectCounter++;
		//	コンポーネントの追加
		
		
	}
	~SolidObject()
	{
		m_objectCounter--;
		RequestDestroy();	//	コンポーネントの削除処理

	}

	void Init()override;	//	情報の初期化
	void UpdateGameObject() override;	//	更新処理


	static void SolidObjectCounter();	//	オブジェクトの個数を数える

	void SetIsCollision(bool isCollision);
	bool GetIsCollision();

	//	情報を変更する
	void SetPosition(float x, float y, float z);//	座標変更
	void SetScale(float x, float y, float z);	//	サイズ変更
	
	void ChangeCollision();	//	当たり判定の変更
	void ChangeColor();		//	色の変更
	
};