#include <tchar.h>			// �e�L�X�g�╶������������߂ɕK�v�ȃw�b�_�[�t�@�C��
#include <Windows.h>		// Windows�v���O�����ŕK�v�ɂȂ���̂������Ă���
#include <D3D11.h>			// DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <d3dcompiler.h>	// �V�F�[�_�[�t�@�C�����R���p�C�����邽�߂ɕK�v
#include <directxcolors.h>	// DirectX::���C�u�����𗘗p���邽�߂ɕK�v

#pragma comment(lib, "d3d11.lib")		// DirectX11���C�u�����𗘗p���邽�߂ɕK�v
#pragma comment(lib, "d3dCompiler.lib")	// �V�F�[�_�[�R�[�h���R���p�C�����邽�߂ɕK�v

#include <iostream>
#include "GameScene.h"
#include "Input.h"
#include "Matrix.h"
#include "Camera.h"
#include "Polygon.h"
#include "Shader.h"

using namespace std;
using namespace DirectX;

Matrix		gameMatrix;
Camera		gameCamera;
CPolygon	gameObj;

void GameScene::Init()
{
	gameMatrix.Identity();
	gameCamera.SetViewPort();
	int32_t n = Shader::GetInstance()->LoadShader("VertexShader.hlsl", "PixelShader.hlsl");
	gameObj.Init(Shader::GetInstance()->GetShader(n));
	gameMatrix.SetFirstPos(XMFLOAT3(0, 0, 0));
}

SCENE GameScene::Update()
{
	// �V�[���p������ꍇ��SCENE_MAX��Ԃ�
	SCENE rt = SCENE_MAX;

	// �J�����ݒ�X�V
	gameCamera.Update(gameMatrix.GetView(), gameMatrix.GetProjection());
	
	// lesson01 �ړ�
	//gameMatrix.GetCB().world = XMMatrixTranslation(0.3, -0.5, 2.0);

	// lesson02 �g��
	//gameMatrix.GetCB().world = XMMatrixScaling(0.5, 2.5, 1.0);

	// lesson03 ��]
	//gameMatrix.GetCB().world = XMMatrixRotationY(45.0f * (180 * 3.14f));

	// lesson04 �g��ƈړ�
	//gameMatrix.GetCB().world = XMMatrixScaling(2.3, 1.5, 1.0), XMMatrixTranslation(-0.1, 0.5, 0.0);

	// lesson05 ��]�ƈړ�
	//gameMatrix.GetCB().world = XMMatrixRotationZ(60 * (180 * 3.14f)), XMMatrixTranslation(0.0, 0.5, 0.0);

	// lesson06 �㉺�ړ�
	//bool isUP = false;
	//XMFLOAT3  pos = gameMatrix.GetPos();
	//if (pos.y >= 1)
	//{
	//	isUP = false;
	//}
	//else if (pos.y <= -1)
	//{
	//	isUP = true;
	//}
	//gameMatrix.GetCB().world = XMMatrixTranslation(0.0, isUP ? -1 * 0.0001 : 1 * 0.0001, 0.0);

	// lesson08 ���]�ƈړ�
	float angle = gameMatrix.GetAngle();
	angle++;
	if (angle >= 360)
	{
		angle = 0;
	}
	gameMatrix.SetAxis(angle);

	// lesson09 ���]�ƈړ�(���]����)

	// lessonEX ���z�ƌ��ƒn��

	// �V�[���ǂݍ���
	if (Input::GetInstance()->GetKeyDown(VK_RETURN))
	{
		rt = CLEAR;
	}

	return rt;
}

void GameScene::Render()
{
	App::GetInstance()->RenderBegin(0.1f, 0.1f, 0.15f, 1.0f);

	gameObj.Render(gameMatrix.GetCB());

	App::GetInstance()->RenderEnd();
}

void GameScene::Term()
{
	Shader::GetInstance()->Term();
}