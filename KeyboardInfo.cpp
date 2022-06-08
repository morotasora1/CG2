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
Keyboard::Keyboard() {
	
	
}

Keyboard::~Keyboard() {

}


void Keyboard::Initialize(HWND hwnd)
{
	////DirectInputの初期化
	//IDirectInput8* directInput = nullptr;
	w.hInstance = GetModuleHandle(nullptr); // ウィンドウハンドル
	result = DirectInput8Create(
		w.hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8,
		(void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	//////キーボードデバイスの生成
	//IDirectInputDevice8* keyboard = nullptr;
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	//////入力データ形式のセット
	result = keyboard->SetDataFormat(&c_dfDIKeyboard);
	assert(SUCCEEDED(result));
	
	//////排他制御レベルのセット

	result = keyboard->SetCooperativeLevel(
		hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
	
}

void Keyboard::Update()
{
	BYTE key[256] = {};
	BYTE oldkey[256] = {};
	keyboard->Acquire();
	for (int i = 0; i < 256; ++i)
	{
		oldkey[i] = key[i];
	}
	keyboard->GetDeviceState(sizeof(key), key);

	if (key[DIK_SPACE])
	{
		
	}


	

}
