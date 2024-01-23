#pragma once
#include <Windows.h>
#include <wrl.h>
#include <string>
#include <dxcapi.h>

class SpriteCommon
{
public:
	//èâä˙âª
	void Initialize();
private:

	IDxcBlob* compileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcUtils* dxcUtils,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* dxcIncludeHandler
	);

};

