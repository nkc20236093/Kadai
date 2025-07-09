#include <tchar.h>			// �e�L�X�g�╶������������߂ɕK�v�ȃw�b�_�[�t�@�C��
#include <Windows.h>		// Windows�v���O�����ŕK�v�ɂȂ���̂������Ă���
#include <D3D11.h>			// DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <d3dcompiler.h>	// �V�F�[�_�[�t�@�C�����R���p�C�����邽�߂ɕK�v
#include <directxcolors.h>	// DirectX::���C�u�����𗘗p���邽�߂ɕK�v

#pragma comment(lib, "d3d11.lib")		// DirectX11���C�u�����𗘗p���邽�߂ɕK�v
#pragma comment(lib, "d3dCompiler.lib")	// �V�F�[�_�[�R�[�h���R���p�C�����邽�߂ɕK�v

#include "GameScene.h"
#include "Input.h"
#include "Matrix.h"
#include "Camera.h"
#include "Polygon.h"
#include "Shader.h"
#include <iostream>


using namespace std;
using namespace DirectX;

Matrix		gameMatrix;
Camera		gameCamera;
CPolygon	gameObj;
int32_t		charTexId;
XMFLOAT2	uvPos[4];
float timer = 0;
XMFLOAT2 movePos;

void GameScene::Init()
{
	gameMatrix.Identity();
	gameCamera.SetViewPort();
	int32_t n = Shader::GetInstance()->LoadShader("VertexShader.hlsl", "PixelShader.hlsl");
	gameObj.Init(Shader::GetInstance()->GetShader(n));
	charTexId = Texture::GetInstance()->LoadTexture("MyChar.png");
}

SCENE GameScene::Update()
{
	// �V�[���p������ꍇ��SCENE_MAX��Ԃ�
	SCENE rt = SCENE_MAX;

	// �J�����ݒ�X�V
	gameCamera.Update(gameMatrix.GetView(), gameMatrix.GetProjection());

	gameMatrix.Identity();
	static int num = 0;
	auto input = Input::GetInstance();
	for (int i = 1; i <= 9; ++i)
	{
		if (input->GetKeyDown('0' + i))
		{
			num = i;
			timer = 0;
			movePos = XMFLOAT2(0, 0);
			break;
		}
	}
	switch (num)
	{
		case 1:
			// ����
			uvPos[0].x = 0.0f / 1024.0f;
			uvPos[0].y = 256.0f / 1024.0f;
			// ����
			uvPos[1].x = 0.0f / 1024.0f;
			uvPos[1].y = 0.0f / 1024.0f;
			// �E��
			uvPos[2].x = 256.0f / 1024.0f;
			uvPos[2].y = 256.0f / 1024.0f;
			// �E��
			uvPos[3].x = 256.0f / 1024.0f;
			uvPos[3].y = 0.0f / 1024.0f;
			gameObj.SetUV(uvPos);
			break;
		case 2:
			timer += 0.225f;
			if (timer > 1)
			{
				timer = 0;
				movePos.x += 256.0f;
			}
			// ����
			uvPos[0].x = movePos.x / 1024.0f;
			uvPos[0].y = 256.0f / 1024.0f;
			// ����
			uvPos[1].x = movePos.x / 1024.0f;
			uvPos[1].y = 0.0f / 1024.0f;
			// �E��
			uvPos[2].x = (movePos.x + 256.0f) / 1024.0f;
			uvPos[2].y = 256.0f / 1024.0f;
			// �E��
			uvPos[3].x = (movePos.x + 256.0f) / 1024.0f;
			uvPos[3].y = 0.0f / 1024.0f;
			gameObj.SetUV(uvPos);
			break;
		case 3:			
			timer += 0.225f;
			if (timer > 1)
			{
				timer = 0;
				movePos.x += 256.0f;
			}

			if (input->GetKey('A') || input->GetKey(VK_LEFT)) movePos.y = 256.0f * 2;
			if (input->GetKey('D') || input->GetKey(VK_RIGHT)) movePos.y = 256.0f;
			if (!input->GetKey('A') && !input->GetKey(VK_LEFT) && 
				!input->GetKey('D') && !input->GetKey(VK_RIGHT))movePos.y = 0.0f;

			// ����
			uvPos[0].x = movePos.x / 1024.0f;
			uvPos[0].y = (movePos.y + 256.0f) / 1024.0f;
			// ����
			uvPos[1].x = movePos.x / 1024.0f;
			uvPos[1].y = movePos.y / 1024.0f;
			// �E��
			uvPos[2].x = (movePos.x + 256.0f) / 1024.0f;
			uvPos[2].y = (movePos.y + 256.0f) / 1024.0f;
			// �E��
			uvPos[3].x = (movePos.x + 256.0f) / 1024.0f;
			uvPos[3].y = movePos.y / 1024.0f;
			gameObj.SetUV(uvPos);
			break;
		case 4:

			break;

		default:
			// ����
			uvPos[0].x = 0.0f;
			uvPos[0].y = 1.0f;
			// ����
			uvPos[1].x = 0.0f;
			uvPos[1].y = 0.0f;
			// �E��
			uvPos[2].x = 1.0f;
			uvPos[2].y = 1.0f;
			// �E��
			uvPos[3].x = 1.0f;
			uvPos[3].y = 0.0f;
			gameObj.SetUV(uvPos);
			break;
	}


	// �V�[���ǂݍ���
	if (Input::GetInstance()->GetKeyDown(VK_RETURN))
	{
	}
	return rt;
}

void GameScene::Render()
{
	// RenderBegin�̑�1�����`��3�������w�i��RGB
	App::GetInstance()->RenderBegin(0.2f, 0.2f, 0.2f, 1.0f);

	gameObj.Render(gameMatrix.GetCB(), Texture::GetInstance()->GetTextureResource(charTexId));

	App::GetInstance()->RenderEnd();
}

void GameScene::Term()
{
	Shader::GetInstance()->Term();
}
