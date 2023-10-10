#pragma once
#include <windows.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include <wrl.h>

//using namespace Microsoft::WRL;

class Input{
public:	//�����o�֐�
	//������
	void Initialize(HINSTANCE hInstance ,HWND hwnd);
	//�X�V
	void Update();

private:
	// �L�[�{�[�h�f�o�C�X�̐���
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;
};

