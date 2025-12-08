#pragma once
#include "ComponentBase.h" 

namespace MochiFramework::Components {
	class DX11Renderer2D : public MochiFramework::Components::ComponentBase<DX11Renderer2D> {
	public:
		explicit DX11Renderer2D(MochiFramework::GameObjects::GameObject* owner);



	};
} // namespace MochiFramework::Components

