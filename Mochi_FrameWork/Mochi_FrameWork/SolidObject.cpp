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
	SetPosition(10.0f, 10.0f, 0.0f);
	SetScale(10.0f, 10.0f, 0.0f);
	
	//	画像を突っ込む
	auto* ic = GetComponent<MochiFramework::Components::DX11Renderer2D>();
	if (!ic)return;

	ic->SetTexture("asset/test.png");	//	画像の位置を記述しよう



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
