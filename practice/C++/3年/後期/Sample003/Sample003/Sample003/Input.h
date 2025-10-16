#pragma once
#include <Windows.h>		// Windowsプログラムで必要になるものが入っている
#include <cstdint>

constexpr uint32_t KEY_MAX = 256;

class Input
{
public:
	static Input* GetInstance()
	{
		static Input instance;
		return &instance;
	}
	void SetInputState();
	void SetInputStateOld();
	bool GetKey(uint32_t v_key);
	bool GetKeyDown(uint32_t v_key);
	bool GetKeyUp(uint32_t v_key);

private:
	Input();
	~Input();
	int8_t key[KEY_MAX];
	int8_t keyOld[KEY_MAX];
};
