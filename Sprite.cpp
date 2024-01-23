#include "Sprite.h"
#include "BufferResource.h"

#include <DirectXMath.h>

using namespace Microsoft::WRL;
using namespace DirectX;

void Sprite::Initialize(DirectXCommon* dxCommon, SpriteCommon* common)
{

	dxCommon_ = dxCommon;
	common_ = common;

	vertexResource= CreateBufferResouce

	vertexBufferView.BufferLocation = vertexResource->GetGPUVirtualAddress();
	vertexBufferView.SizeInBytes = sizeof(DirectX::XMFLOAT4) * 3;
	vertexBufferView.StrideInBytes = sizeof(DirectX::XMFLOAT4);

}

void Sprite::Draw()
{
	XMFLOAT4* vertexData = nullptr;
	vertexResource->Map(0, nullptr, reinterpret_cast<void**>(&vertexData));

	vertexData[0] = { -0.5f,-0.5f,0.0f,1.0f };
	vertexData[1] = { 0.0f,+0.5f,0.0f,1.0f };
	vertexData[2] = { +0.5f,-0.5f,0.0f,1.0f };

	dxCommon_->GetCommandList()->SetGraphicsRootSignature(common_->GetRootSignature());
	dxCommon_->GetCommandList()->SetPipelineState(common_->GetPipelineState());

	dxCommon_->GetCommandList()->IASetVertexBuffers(0, 1, &vertexBufferView);

	dxCommon_->GetCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	dxCommon_->GetCommandList()->DrawInstanced(3, 1, 0, 0);

}

void Sprite::CreateVertex()
{
}

void Sprite::CreateMaterial()
{
	materialResource



}
