#pragma once
#include "ComponentBase.h" 
#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include "Material.h"
#include "Camera.h"

namespace MochiFramework::Components {
	class DX11Renderer2D : public MochiFramework::Components::ComponentBase<DX11Renderer2D> {
	public:
		explicit DX11Renderer2D(MochiFramework::GameObjects::GameObject* owner, Camera* camera);

		void Init() override;
		void Update(const float deltaTime) override;
		void Draw() override;

		// テクスチャを指定
		void SetTexture(const char* imgname);

	private:
		Shader mShader;

		// 頂点データ
		std::vector<VERTEX_3D> mVertices;

		//インデックスデータ
		std::vector<unsigned int> mIndices;


		// 描画の為の情報（メッシュに関わる情報）
		IndexBuffer mIndexBuffer; // インデックスバッファ
		VertexBuffer<VERTEX_3D> mVertexBuffer; // 頂点バッファ

		// 描画の為の情報（見た目に関わる部分）
		Texture mTexture; // テクスチャ
		std::unique_ptr<Material> m_Material; //マテリアル

		// UV座標の情報
		float mNumU = 1;
		float mNumV = 1;
		float mSplitX = 1;
		float mSplitY = 1;

		Camera* mCamera;
	};
} // namespace MochiFramework::Components

