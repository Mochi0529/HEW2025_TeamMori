#include "Camera.h"
#include "Renderer.h"
#include "Application.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector3.h"

#include	<SimpleMath.h>

using namespace DirectX::SimpleMath;

using namespace MochiFramework::GameObjects;
using namespace MochiFramework::Components;

Camera::Camera(GameObject* owner)
	: ComponentBase(owner)
	, mCameraLateral(0)
	, mCameraVertical(0)
{

}

void Camera::Init()
{

}

void Camera::Update(const float deltaTime)
{
}

void Camera::SetCamera(const int& mode)
{
	//	3Dカメラ
	if (mode == 0)
	{
		// ビュー変換後列作成
		Vector3 up = Vector3(0.0f, 1.0f, 0.0f);

		Vector3 pos = GetOwner()->GetComponent<Transform>()->GetWorldPosition().ToDirectX();

		m_ViewMatrix = DirectX::XMMatrixLookAtLH(pos, m_Target, up); //左手系

		Renderer::SetViewMatrix(&m_ViewMatrix);

		//プロジェクション行列の生成
		constexpr float fieldOfView = DirectX::XMConvertToRadians(45.0f);    // 視野角

		float aspectRatio = static_cast<float>(Application::GetWidth()) / static_cast<float>(Application::GetHeight());	// アスペクト比	
		float nearPlane = 1.0f;       // ニアクリップ
		float farPlane = 1000.0f;      // ファークリップ

		//プロジェクション行列の生成
		Matrix projectionMatrix;
		projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(fieldOfView, aspectRatio, nearPlane, farPlane);	//左手系

		Renderer::SetProjectionMatrix(&projectionMatrix);
	}//	2Dカメラ
	else if (mode == 1)
	{
		// ビュー変換後列作成
		Vector3 pos = Vector3(0.0f, 0.0f, -10.0f);
		Vector3 tgt = Vector3(0.0f, 0.0f, 1.0f);
		Vector3 up = Vector3(0.0f, 1.0f, 0.0f);
		m_ViewMatrix = DirectX::XMMatrixLookAtLH(pos, tgt, up); //左手系
		Renderer::SetViewMatrix(&m_ViewMatrix);

		//	プロジェクション行列の作成
		float nearPlane = 1.0f;		//	ニアクリップ
		float farPlane = 1000.0f;	//	ファークリップ

		//プロジェクション行列の生成
		Matrix projectionMatrix = DirectX::XMMatrixOrthographicLH(static_cast<float>(Application::GetWidth()),
			static_cast<float>(Application::GetHeight()),
			nearPlane, farPlane);
		projectionMatrix = DirectX::XMMatrixTranspose(projectionMatrix);
		Renderer::SetProjectionMatrix(&projectionMatrix);

	}
}
