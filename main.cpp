#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include "SpriteCommon.h"
#include "Sprite.h"

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

	SpriteCommon* spriteCommon = nullptr;
	//スプライトの共通部分の生成と初期化
	spriteCommon = new SpriteCommon;
	spriteCommon->Initialize();

	//スプライトの生成と初期化
	Sprite* sprite = new Sprite();
	sprite->Initialize();


	// ゲームループ
	while (true) {
		if (winApp_->Update() == true) {
			break;
		}
		//入力
		input_->Update();

		//更新前処理
		dxCommon_->PreDraw();

		

		//更新後処理
		dxCommon_->PosDraw();
	}

	delete input_;
	
	winApp_->Finalize();
	delete winApp_;
	
	delete dxCommon_;

	delete spriteCommon;
	delete sprite;

	return 0;
}
