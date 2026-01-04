#include "Layer.h"
#include "Scene.h"

using namespace MochiFramework::GameObjects;

std::vector<SolidObject>& Layer::GetObjects()
{
    return Objects;
}

void Layer::AddObject(float posX,float posY,float ScaleX, float ScaleY)
{
    auto obj = CreateGameObject<SolidObject>();
    obj->SetPosition(posX,posY,1);
    obj->SetScale(ScaleX,ScaleY,1);
}

std::string Layer::GetName() const
{
    return "Layer";
}
