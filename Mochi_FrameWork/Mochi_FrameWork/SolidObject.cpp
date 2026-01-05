#include "SolidObject.h"
#include<iostream>

//	コンポーネント
#include"DX11Renderer2D.h"	//	テクスチャ関係の追加
#include"Transform.h"		//	座標関係


int  SolidObject::m_objectCounter = 0;	//	現在のオブジェクトの数を代入

//	オブジェクトの数を描画
void SolidObject::SolidObjectCounter()
{
	system("cls");
	std::cout <<"ソリッドオブジェクト数:" << m_objectCounter;

}

//	情報の初期化
void SolidObject::Init()
{
	//	コンポーネントの追加
	auto* texture =AddComponent<MochiFramework::Components::DX11Renderer2D>();	//　テクスチャ関係
	if (!texture)return;
	texture->Init();
	texture->SetTexture("asset/test.png");

	SetScale(100.0f, 100.0f, 0.0f);
	SetPosition(0.0f, 0.0f, 0.0f);

	std::cout << "ソリッドオブジェクトの作成" << std::endl;
	
}

//	アップデート
void SolidObject::UpdateGameObject()
{





}

//	座標の変更
void SolidObject::SetPosition(float x, float y, float z)
{	
	auto* transCom = GetComponent<MochiFramework::Components::Transform>();
	if (!transCom)return;
	//	引数を一つの変数にまとめそれを送る
	MochiFramework::Math::Vector3 newPosition;
	newPosition.x = x;
	newPosition.y = y;
	newPosition.z = z;
	transCom->SetLocalPosition(newPosition);
	
}

//	オブジェクトの大きさを変更する
void SolidObject::SetScale(float x, float y, float z)
{
	auto* transCom = GetComponent<MochiFramework::Components::Transform>();
	if (!transCom)return;
	//	引数を一つの変数にまとめそれを送る
	MochiFramework::Math::Vector3 newScale;
	newScale.x = x;
	newScale.y = y;
	newScale.z = z;
	transCom->SetLocalScale(newScale);

}

//	メンバーの当たり判定のフラグを変更し
//	切り替え時の処理をする
void SolidObject::SetIsCollision(bool isCollision)
{
	m_isCollision = isCollision;
	ChangeCollision();
	ChangeColor();
}

//	現在のオブジェクトの当たり判定の状況を渡す
bool SolidObject::GetIsCollision()
{
	return m_isCollision;
}

//	当たり判定の変更
void SolidObject::ChangeCollision()
{
	//	当たり判定を切り替える
	
	//	Box2Dなどで当たり判定を切り替える
	
}

//	色の切り替え
void SolidObject::ChangeColor()
{
	auto* ic = GetComponent<MochiFramework::Components::DX11Renderer2D>();
	if (!ic)return;

	//	todo: 持木にDX11Renderer2Dのカラーを変更できる関数を作っていいかを聞く
	

	

}
