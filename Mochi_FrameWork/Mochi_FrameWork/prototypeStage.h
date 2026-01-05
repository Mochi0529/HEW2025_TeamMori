#pragma once
/***************************************************/
//	シーンを継承し、描画などの確認を行う
/***************************************************/
#include"Scene.h"

class PrototypeStage:public MochiFramework::SceneSystem::Scene
{

public:
    explicit PrototypeStage(MochiFramework::Core::FrameworkFacade& facade);

    void Init() override;
    void SceneUpdate() override;

    

    std::string GetName() const override;



};

