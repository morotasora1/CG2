#pragma once

#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>
#include <vector>
#include <string>
#include <DirectXMath.h>
using namespace DirectX;
#include <d3dcompiler.h>
#include <dinput.h>
#include "KeyboardInfo.h"
#define DIRECTINPUT_VERSION 0x0800

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")


#define DIRECTINPUT_VERSION 0x0800


class Keyboard
{
public:
	
	Keyboard();
	~Keyboard();

	void Initialize(HWND hwnd);
	/// 毎フレーム処理
	/// </summary>

	void Update(BYTE key[256], BYTE oldkey[256]);
private:
	
	//キーボードデバイスの生成
	
	IDirectInput8* directInput = nullptr;
	IDirectInputDevice8* keyboard = nullptr;
	WNDCLASSEX w{};
	HRESULT result;
	

};