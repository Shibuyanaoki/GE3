#pragma once
#include <dxcapi.h>
#include <wrl.h>
#include <string>

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
		IDxcCompiler* dxcCompiler,
		IDxcIncludeHandler* dxcIncludeHandler
	);

};

