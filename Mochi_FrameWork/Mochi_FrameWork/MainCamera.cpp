#include "MainCamera.h"
#include"math.h"
#include<iostream>
//	î•ñ‚Ì‰Šú‰»‚ğ‚·‚é
void MainCamera::Init()
{
	auto* camera = AddComponent<MochiFramework::Components::Camera>();	//@ƒJƒƒ‰‚Ì’Ç‰Á
	if (!camera)return;

	SetPosition(0.0f, 0.0f, -0.1f);

	std::cout << "ƒJƒƒ‰‚Ìì¬" << std::endl;
}

void MainCamera::UpdateGameObject()
{

}


void MainCamera::SetPosition(float x, float y, float z)
{
	auto* ic = GetComponent<MochiFramework::Components::Transform>();
	if (!ic)return;
	//	ˆø”‚ğˆê‚Â‚Ì•Ï”‚É‚Ü‚Æ‚ß‚»‚ê‚ğ‘—‚é
	MochiFramework::Math::Vector3 newPosition;
	newPosition.x = x;
	newPosition.y = y;
	newPosition.z = z;
	ic->SetLocalPosition(newPosition);
}
