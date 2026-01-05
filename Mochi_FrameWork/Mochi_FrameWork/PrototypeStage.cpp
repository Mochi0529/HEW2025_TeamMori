#include "PrototypeStage.h"


#include "EventQueue.h"
#include "KadaiGameObject2.h"
#include "FrameworkFacade.h"

//	オブジェクトインクルード
#include"SolidObject.h"
#include"MainCamera.h"

PrototypeStage::PrototypeStage(MochiFramework::Core::FrameworkFacade& facade) :Scene(facade)
{
}
/***************************************************/
//	初期化
/***************************************************/
void PrototypeStage::Init()
{
	auto* mainCamera = CreateGameObject<MainCamera>();
	mainCamera->SetName("MainCamera");
	//	使うオブジェクトを初期化
	auto* solidObject = CreateGameObject<SolidObject>();
	solidObject->SetName("object");

	

}
/***************************************************/
//	シーンの更新
/***************************************************/
void PrototypeStage::SceneUpdate()
{



}
/***************************************************/
//	このシーンの名前を返す
/***************************************************/
std::string PrototypeStage::GetName() const
{
	return "PrototypeStage";
}