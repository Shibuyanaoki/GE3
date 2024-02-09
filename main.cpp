#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include "SpriteCommon.h"
#include "Sprite.h"

#include "ImGuiManager.h"
#include<vector>

#include"TextureManager.h"

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

	SpriteCommon* spriteCommon_ = nullptr;
	//スプライトの共通部分の生成と初期化
	spriteCommon_ = new SpriteCommon;
	spriteCommon_->Initialize(dxCommon_);

	//スプライトの生成と初期化
	SpriteCommon* common = new SpriteCommon();
	common->Initialize(dxCommon_);

	std::vector<Sprite*> sprite;
	for (int i = 0; i < 1; i++) {
		Sprite* temp = new Sprite();
		if (i % 2 == 0) temp->Initialize(common, L"Resources/mario.jpg");
		else if (i % 2 == 1)temp->Initialize(common, { L"Resources/reimu.png" });
		temp->SetPosition({ 400,200 });
		sprite.push_back(temp);
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

		for (int i = 0; i < 1; i++)
		{
			sprite[i]->Update();
		}

		//更新前処理
		ImGuiManager::CreateCommand();
		dxCommon_->PreDraw();
		common->SpritePreDraw();

		for (int i = 0; i < 1; i++) {
			sprite[i]->Draw();
		}

		//更新後処理
		ImGuiManager::CommandsExcute(dxCommon_->GetCommandList());
		dxCommon_->PosDraw();
	}

	TextureManager::Getinstance()->Finalize();
	delete common;
	delete imgui_;
	delete input_;
	delete dxCommon_;
	winApp_->Finalize();
	delete winApp_;

	return 0;
}
