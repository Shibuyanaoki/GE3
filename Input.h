#pragma once
#include <windows.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include <wrl.h>

//using namespace Microsoft::WRL;

class Input{
public:	//メンバ関数
	//初期化
	void Initialize(HINSTANCE hInstance ,HWND hwnd);
	//更新
	void Update();

private:
	// キーボードデバイスの生成
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;
};

