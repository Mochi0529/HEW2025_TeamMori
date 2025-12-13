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
	if (map->WasActionTriggered("ESC"))
	{

	}
	if (map->WasActionTriggered("ESC"))
	{

	}
	if (map->WasActionTriggered("ESC"))
	{

	}


	//	当たり判定の更新


}

void PlayerCharacter::MoveRaght()
{
	auto* ic = GetComponent<MochiFramework::Components::Transform>();
	if (!ic) { return; }

	

}

void PlayerCharacter::MoveLeft()
{
	auto* ic = GetComponent<MochiFramework::Components::Transform>();
	if (!ic) { return; }
}

