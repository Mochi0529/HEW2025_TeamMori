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
	std::cout << m_objectCounter;

}

//	情報の初期化
void SolidObject::Init()
{
	SetPosition(10.0f, 10.0f, 0.0f);
	SetScale(10.0f, 10.0f, 0.0f);
	
}


void SolidObject::SetPosition(float x, float y, float z)
{
	auto* ic = GetComponent<MochiFramework::Components::Transform>();
	if (!ic)return;

	//	引数を一つの変数にまとめそれを送る
	MochiFramework::Math::Vector3 newPosition;
	newPosition.x = x;
	newPosition.y = y;
	newPosition.z = z;
	ic->SetLocalPosition(newPosition);
}

//	オブジェクトの大きさを変更する
void SolidObject::SetScale(float x, float y, float z)
{
	auto* ic = GetComponent<MochiFramework::Components::Transform>();
	if (!ic)return;
	
	//	引数を一つの変数にまとめそれを送る
	MochiFramework::Math::Vector3 newScale;
	newScale.x = x;
	newScale.y = y;
	newScale.z = z;
	ic->SetLocalScale(newScale);

}