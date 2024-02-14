#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include "SpriteCommon.h"
#include "Sprite.h"

#include "ImGuiManager.h"

#include <vector>

#include "TextureManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	Input* input_ = nullptr;
	WinApp* winApp_ = nullptr;
	DirectXCommon* dxCommon_ = nullptr;

	//WindowsAPI初期化処理
	winApp_ = new WinApp;
	winApp_->Initialize();

	//DirectX初期化処理
	dxCommon_ = new DirectXCommon;
	dxCommon_->Initialize(winApp_);

	//Input生成、初期化
	input_ = new Input();
	input_->Initialize(winApp_);

	ImGuiManager* imgui_ = ImGuiManager::Create();
	ImGuiManager::Initialize(winApp_->GetHwnd(), dxCommon_);

	// スプライトコモン
	SpriteCommon* spriteCommon_ = new SpriteCommon;
	spriteCommon_->Initialize(dxCommon_);

	// テクスチャマネージャー
	TextureManager::GetInstance()->Initialize(dxCommon_);
	TextureManager::GetInstance()->LoadTexture(L"Resources/texture.png");
	TextureManager::GetInstance()->LoadTexture(L"Resources/mario.jpg");

	// 画像
	std::vector<Sprite*> sprite_;
	for (int i = 0; i < 5; i++) {
		Sprite* temp = new Sprite();
		if (i % 2 == 0)
		{
			temp->Initialize(spriteCommon_, L"Resources/mario.jpg");
		}
		else if (i % 2 == 1)
		{
			temp->Initialize(spriteCommon_, L"Resources/texture.png");
		}

		temp->SetPosition({ (float)i * 120, 0 });
		sprite_.push_back(temp);
	}

	// ゲームループ
	while (true) {
		if (winApp_->Update() == true) {
			break;
		}

		ImGuiManager::NewFrame();
		imgui_->ShowDemo();

		//入力
		input_->Update();

		//// 移動
		//DirectX::XMFLOAT2 pos = sprite_->GetPosition();
		//pos.x += 0.01;
		//sprite_->SetPosition(pos);

		//// 回転
		//float rot = sprite_->GetRotation();
		//rot += 0.005f;
		//sprite_->SetRotation(rot);

		//// 色
		//DirectX::XMFLOAT4 color = sprite_->GetColor();
		//color.x -= 0.01f;
		//if (color.x < 0) {
		//	color.x = 1.0f;
		//}
		//sprite_->SetColor(color);

		//// サイズ
		//DirectX::XMFLOAT2 size = sprite_->GetSize();
		//size.y += 0.01f;
		//sprite_->SetSize(size);

		for (int i = 0; i < 5; i++) {
			sprite_[i]->Updete();
		}

		//更新前処理
		ImGuiManager::CreateCommand();
		dxCommon_->PreDraw();
		spriteCommon_->SpritePreDraw();

		for (int i = 0; i < 5; i++) {
			sprite_[i]->Draw();
		}

		//更新後処理
		ImGuiManager::CommandsExcute(dxCommon_->GetCommandList());
		dxCommon_->PosDraw();
	}

	for (int i = 0; i < 5; i++) {
		delete sprite_[i];
	}

	TextureManager::GetInstance()->Finalize();

	delete spriteCommon_;

	delete imgui_;

	delete input_;

	delete dxCommon_;

	winApp_->Finalize();
	delete winApp_;

	return 0;
}
