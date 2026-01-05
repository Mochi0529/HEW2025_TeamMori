#include "PlayerCharacter.h"

#include "Scene.h"
#include "EventQueue.h"	//	イベントを送り付ける

//	コンポーネント
#include"DX11Renderer2D.h"
#include"Transform.h"
#include"InputComponent.h"

void PlayerCharacter::UpdateGameObject()
{
	auto* ic = GetComponent<MochiFramework::Components::InputComponent>();
	if (!ic) return;
	auto* map = ic->GetInputMap();

	MochiFramework::SceneSystem::Scene* scene = GetScene();


	//	移動　ジャンプボタン
	if (map->WasActionTriggered("ESC"))	//	右移動
	{
		MoveRaght();
	}
	if (map->WasActionTriggered("ESC"))	//	左移動
	{
		MoveLeft();
	}
	if (map->WasActionTriggered("ESC"))
	{

	}


	Draw();	//	
}

void PlayerCharacter::Draw()
{
	auto* ic = GetComponent<MochiFramework::Components::DX11Renderer2D>();
	if (!ic) return;

	ic->Draw();
}

void PlayerCharacter::MoveRaght()
{
	auto* ic = GetComponent<MochiFramework::Components::Transform>();
	if (!ic) { return; }

	//	移動する変数を描く

}

void PlayerCharacter::MoveLeft()
{
	auto* ic = GetComponent<MochiFramework::Components::Transform>();
	if (!ic) { return; }

	//	移動する変数を描く

}

