#pragma once
#include "ComponentBase.h"

#include	<SimpleMath.h>

namespace MochiFramework::GameObjects { class GameObject; }

namespace MochiFramework::Components {
	class Camera : public MochiFramework::Components::ComponentBase<Camera>
	{
	public:
		explicit Camera(MochiFramework::GameObjects::GameObject* owner);

		void Init() override;
		void Update(const float deltaTime) override;

		void SetCamera(const int& mode = 0);

	private:
		DirectX::SimpleMath::Vector3	m_Target{};
		DirectX::SimpleMath::Matrix		m_ViewMatrix{};

		float mCameraLateral;	//	ƒJƒƒ‰‚Ì‰¡•ûŒü
		float mCameraVertical;	//	ƒJƒƒ‰‚Ìc•ûŒü
	};
}


