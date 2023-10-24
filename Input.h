#pragma once
#include <windows.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include <wrl.h>

#include "WinApp.h"

//using namespace Microsoft::WRL;

class Input{
public:	//メンバ関数
	//初期化
	void Initialize(WinApp * winApp);
	//更新
	void Update();
	//任意のボタンを押したとき
	bool PushKey(BYTE keyNumber);
	//任意のボタンが押された瞬間
	bool TriggerKey(BYTE keyNumber);

private:

	WinApp* winApp_ = nullptr;

	// キーボードデバイスの生成
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;
	// DirectInputの初期化
	Microsoft::WRL::ComPtr<IDirectInput8> directInput;

	BYTE key[256] = {};
	//前回の全キーの状態
	BYTE keyPre[256] = {};

};

