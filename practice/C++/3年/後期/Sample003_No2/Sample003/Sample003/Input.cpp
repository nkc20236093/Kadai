#include "Input.h"

Input::Input()
	:key()
	,keyOld()
{
}

Input::~Input()
{
}

void Input::SetInputState()
{
	GetKeyboardState((BYTE*)key);
}

void Input::SetInputStateOld()
{
	for (uint32_t i = 0; i < KEY_MAX; ++i)
	{
		keyOld[i] = key[i];
	}
}

bool Input::GetKey(uint32_t v_key)
{
	if (key[v_key] & 0x80) return true;
	else return false;
}

bool Input::GetKeyDown(uint32_t v_key)
{
	if (key[v_key] & 0x80)
	{
		if (!(keyOld[v_key] & 0x80)) return true;
	}
	return false;
}

bool Input::GetKeyUp(uint32_t v_key)
{
	if (!(key[v_key] & 0x80))
	{
		if (keyOld[v_key] & 0x80) return true;
	}
	return false;
}