#pragma once
#include <Windows.h>		// Windows�v���O�����ŕK�v�ɂȂ���̂������Ă���
#include <D3D11.h>			// DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <d3dcompiler.h>	// �V�F�[�_�[�t�@�C�����R���p�C�����邽�߂ɕK�v
#include <directxcolors.h>	// DirectX::���C�u�����𗘗p���邽�߂ɕK�v
#include "App.h"

enum STATUS
{
	INIT,		// ������
	UPDATE,		// �X�V
	TERM,		// �I��
	STATUS_MAX,
};

enum SCENE
{
	START,		// �^�C�g���V�[��
	GAME,		// �Q�[���V�[��
	CLEAR,		// �N���A�V�[��
	SCENE_MAX,
};

class SceneManager
{
public:
	SceneManager() {};
	virtual void Init() {};
	virtual SCENE Update() { return SCENE_MAX; };
	virtual void Render() {};
	virtual void Term() {};
	virtual void SetViewProj(DirectX::XMMATRIX v, DirectX::XMMATRIX p) {};// ���� view��proj���ق���

};