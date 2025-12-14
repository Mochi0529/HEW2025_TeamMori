#include "DX11Renderer2D.h"

#include "GameObject.h"
#include "Transform.h"

using namespace MochiFramework::GameObjects;

using namespace std;
using namespace DirectX::SimpleMath;

namespace MochiFramework::Components {
	DX11Renderer2D::DX11Renderer2D(GameObject* owner, Camera* camera)
		: ComponentBase<DX11Renderer2D>(owner)
		, mCamera(camera)
	{
	}

	void DX11Renderer2D::Init()
	{
		// 頂点データ
		mVertices.resize(4);

		mVertices[0].position = Vector3(-0.5f, 0.5f, 0);
		mVertices[1].position = Vector3(0.5f, 0.5f, 0);
		mVertices[2].position = Vector3(-0.5f, -0.5f, 0);
		mVertices[3].position = Vector3(0.5f, -0.5f, 0);

		mVertices[0].color = Color(1, 1, 1, 1);
		mVertices[1].color = Color(1, 1, 1, 1);
		mVertices[2].color = Color(1, 1, 1, 1);
		mVertices[3].color = Color(1, 1, 1, 1);

		mVertices[0].uv = Vector2(0, 0);
		mVertices[1].uv = Vector2(1, 0);
		mVertices[2].uv = Vector2(0, 1);
		mVertices[3].uv = Vector2(1, 1);

		// 頂点バッファ生成
		mVertexBuffer.Create(mVertices);

		// インデックスバッファ生成
		mIndices.resize(4);

		mIndices[0] = 0;
		mIndices[1] = 1;
		mIndices[2] = 2;
		mIndices[3] = 3;

		// インデックスバッファ生成
		mIndexBuffer.Create(mIndices);

		// シェーダオブジェクト生成
		mShader.Create("shader/unlitTextureVS.hlsl", "shader/unlitTexturePS.hlsl");

		// マテリアル情報取得
		m_Material = std::make_unique<Material>();
		MATERIAL mtrl;
		mtrl.Diffuse = Color(1, 1, 1, 1);
		mtrl.TextureEnable = true; // テクスチャを使うか否かのフラグ
		m_Material->Create(mtrl);
	}

	void DX11Renderer2D::Update(const float deltaTime)
	{
	}

	void DX11Renderer2D::Draw()
	{
		//カメラを選択する
		mCamera->SetCamera(1);

		Transform* tfComp = GetOwner()->GetComponent<Transform>();

		MochiFramework::Math::Vector3 pos = tfComp->GetWorldPosition();
		MochiFramework::Math::Vector3 rot = tfComp->GetWorldRotation();
		MochiFramework::Math::Vector3 scale = tfComp->GetWorldScale();

		// SRT情報作成
		Matrix r = Matrix::CreateFromYawPitchRoll(rot.y, rot.x, rot.z);
		Matrix t = Matrix::CreateTranslation(pos.x, pos.y, pos.z);
		Matrix s = Matrix::CreateScale(scale.x, scale.y, scale.z);

		Matrix worldmtx;
		worldmtx = s * r * t;
		Renderer::SetWorldMatrix(&worldmtx); // GPUにセット

		// 描画の処理
		ID3D11DeviceContext* devicecontext;
		devicecontext = Renderer::GetDeviceContext();

		// トポロジーをセット（プリミティブタイプ）
		devicecontext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

		mShader.SetGPU();
		mVertexBuffer.SetGPU();
		mIndexBuffer.SetGPU();

		mTexture.SetGPU();
		m_Material->SetGPU();

		// UVの設定を指定
		float u = mNumU - 1;
		float v = mNumV - 1;
		float uw = 1 / mSplitX;
		float vh = 1 / mSplitY;

		Renderer::SetUV(u, v, uw, vh);

		devicecontext->DrawIndexed(
			(UINT)mIndices.size(), // 描画するインデックス数
			0, // 最初のインデックスバッファの位置
			0);
	}

	void DX11Renderer2D::SetTexture(const char* imgname)
	{
		// テクスチャロード
		bool sts = mTexture.Load(imgname);
		assert(sts == true);
	}

	

} // namespace MochiFramework::Components