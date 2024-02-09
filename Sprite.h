#pragma once
#include "DirectXCommon.h"
#include <d3d12.h>
#include <wrl.h>

#include <DirectXMath.h>

#include "SpriteCommon.h"

class Sprite
{

private:
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

private:

	struct Transform {
		DirectX::XMFLOAT3 scale;
		DirectX::XMFLOAT3 rotation;
		DirectX::XMFLOAT3 translate;
	};

	struct VertexData {
		DirectX::XMFLOAT4 position;
		DirectX::XMFLOAT2 texcoord;
	};

	struct MaterialData {
		DirectX::XMFLOAT4 color;
		DirectX::XMMATRIX uvTransform;
	};

public:
	//������
	void Initialize(SpriteCommon* common, std::wstring textureFilePath);
	void Update();
	void Draw();

public:

	DirectX::XMFLOAT2 GetPosition() { return position; }
	float GetRotation() { return rotation; }
	DirectX::XMFLOAT4 GetColor() { return color_; }
	DirectX::XMFLOAT2 GetSize() { return size; }

	DirectX::XMFLOAT2 GetAnchorPoint() { return anchorPoint; }

	bool GetFlipX() { return isFlipX; }
	bool GetFlipY() { return isFlipY; }

	DirectX::XMFLOAT2 GetTextureLeftTop() { return textureLeftTop; }
	DirectX::XMFLOAT2 GetTextureSize() { return textureSize; }


	void SetPosition(DirectX::XMFLOAT2 pos) { position = pos; }
	void SetRotation(float rot) { rotation = rot; }
	void SetColor(DirectX::XMFLOAT4 color) { color_ = color; }
	void SetSize(DirectX::XMFLOAT2 size) { this->size = size; }

	void SetAnchorPoint(DirectX::XMFLOAT2 anchor) { anchorPoint = anchor; }

	void SetFlipX(bool isFlag) { isFlipX = isFlag; }

	void SetFlipY(bool isFlag) { isFlipY = isFlag; }

	void SetTextureLeftTop(DirectX::XMFLOAT2 value) { textureLeftTop = value; }
	void SetTextureSize(DirectX::XMFLOAT2 size) { textureSize = size; }


	void SetTexture(std::wstring textureFilePath);

private:
	//���_���쐬
	void CreateVertex();
	// �}�e���A�����쐬
	void CreateMaterial();
	// �s����쐬	
	void CreateWVP();

	void CreateIndex();

	void AdjustTextureSize();

private:
	DirectXCommon* dxCommon_ = nullptr;
	SpriteCommon* common_ = nullptr;

	ComPtr<ID3D12Resource> vertexResource;
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};
	VertexData* vertexData = nullptr;

	ComPtr<ID3D12Resource>indexResource;
	D3D12_INDEX_BUFFER_VIEW indexBufferView{};

	// �}�e���A�����
	ComPtr<ID3D12Resource> materialResource;
	MaterialData* materialData = nullptr;

	// �s����
	ComPtr<ID3D12Resource> wvpResource;
	DirectX::XMMATRIX* wvpData = nullptr;

	// �p�����[�^
	DirectX::XMFLOAT4 color_ = { 1.0f, 0.0f, 0.0f, 1.0f };
	Transform uvTransform = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };

	//scale			//Rotate		 //Translate
	Transform transform = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };

	DirectX::XMFLOAT2 position = { 0,0 };

	float rotation = 0;

	DirectX::XMFLOAT2 size = { 512,512 };

	DirectX::XMFLOAT2 anchorPoint = { 0.5f,0.5f };

	bool isFlipX = false;
	bool isFlipY = false;

	DirectX::XMFLOAT2 textureLeftTop = { 0,0 };

	DirectX::XMFLOAT2 textureSize = { 0,0 };

	uint32_t textureIndex_ = 0;

	// �J����
	Transform cameraTransform = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,-5.0f} };

};

