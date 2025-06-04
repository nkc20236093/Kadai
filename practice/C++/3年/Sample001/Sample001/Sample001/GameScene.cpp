#include <tchar.h>			// テキストや文字列を扱うために必要なヘッダーファイル
#include <Windows.h>		// Windowsプログラムで必要になるものが入っている
#include <D3D11.h>			// DirectX11SDKを使うために必要なもの
#include <d3dcompiler.h>	// シェーダーファイルをコンパイルするために必要
#include <directxcolors.h>	// DirectX::ライブラリを利用するために必要

#pragma comment(lib, "d3d11.lib")		// DirectX11ライブラリを利用するために必要
#pragma comment(lib, "d3dCompiler.lib")	// シェーダーコードをコンパイルするために必要

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

bool isUP = false;
static float posYUP = 0;
static float angle = 0.0f;
static float posX = 0.0f;
static float posY = 0.0f;
static float radius = 1.0f;
static float speed = 2.0f;
static XMFLOAT3 postion;


void GameScene::Init()
{
	Reset();
	gameMatrix.Identity();
	gameCamera.SetViewPort();
	int32_t n = Shader::GetInstance()->LoadShader("VertexShader.hlsl", "PixelShader.hlsl");
	gameObj.Init(Shader::GetInstance()->GetShader(n));
	gameMatrix.GetCB().world *= DirectX::XMMatrixTranslation(0, 0, 0);
}
void GameScene::Reset()
{
	posYUP = 0;
	angle = 0.0f;
	posX = 0.0f;
	posY = 0.0f;
	postion = XMFLOAT3(0, 0, 0);
}

SCENE GameScene::Update()
{
	// シーン継続する場合はSCENE_MAXを返す
	SCENE rt = SCENE_MAX;

	// カメラ設定更新
	gameCamera.Update(gameMatrix.GetView(), gameMatrix.GetProjection());
	

	static int mode = 0;
	auto input = Input::GetInstance();
	for (int i = 1; i <= 9; ++i)
	{
		if (input->GetKeyDown('0' + i))
		{
			mode = i;
			break;
		}
	}

	switch (mode)
	{
	case 1:
		 //lesson01 移動
		gameMatrix.Identity();
		gameMatrix.GetCB().world *= XMMatrixTranslation(0.3, -0.5, 2.0);
		break;
	case 2:
		// lesson02 拡大
		gameMatrix.Identity();
		gameMatrix.GetCB().world *= XMMatrixScaling(0.5, 2.5, 1.0);
		break;
	case 3:
		// lesson03 回転
		gameMatrix.Identity();
		gameMatrix.GetCB().world *= XMMatrixRotationY(XMConvertToRadians(45.0f));
		break;
	case 4:
		// lesson04 拡大と移動
		gameMatrix.Identity();
		gameMatrix.GetCB().world *= XMMatrixScaling(2.3, 1.5, 1.0), XMMatrixTranslation(-0.1, 0.5, 0.0);
		break;
	case 5:
		// lesson05 回転と移動
		gameMatrix.Identity();
		gameMatrix.GetCB().world *= XMMatrixRotationZ(XMConvertToRadians(60.0f)), XMMatrixTranslation(0.0, 0.5, 0.0);
		break;
	case 6:
		//lesson06 上下移動

		XMStoreFloat3(&postion, gameMatrix.GetCB().world.r[3]);
		posYUP = postion.y;
		if (posYUP > 1)
		{
			isUP = false;
		}
		else if (posYUP < -1)
		{
			isUP = true;
		}
		posYUP += isUP ? 0.01 : -0.01;
		gameMatrix.Identity();
		gameMatrix.GetCB().world *= XMMatrixTranslation(0.0, posYUP, 0.0);
		break;
	case 7:
		// lesson07 自転と移動
		gameMatrix.Identity();

		gameMatrix.GetCB().world = XMMatrixTranslation(1.0, 0.0, 0.0);

		angle ++;
		if (angle >= 360)
		{
			angle = 0;
		}

		XMMATRIX translationMatrix7 = XMMatrixTranslation(1.0f, 0.0f, 0.0f);

		XMMATRIX rotationMatrix7 = XMMatrixRotationZ(XMConvertToRadians(angle));

		gameMatrix.GetCB().world = rotationMatrix7 * translationMatrix7;
		break;
	case 8:
		// lesson08 公転と自転
		gameMatrix.Identity();

		angle++;
		if (angle >= 360)
		{
			angle = 0;
		}

		posX = cos(XMConvertToRadians(angle));
		posY = sin(XMConvertToRadians(angle));

		XMMATRIX translationMatrix8 = XMMatrixTranslation(posX, posY, 0.0f);

		XMMATRIX rotationMatrix8 = XMMatrixRotationZ(XMConvertToRadians(angle));

		gameMatrix.GetCB().world = rotationMatrix8 * translationMatrix8;
	break;
	case 9:
		// lesson09 公転と移動(自転無し)
		gameMatrix.Identity();

		angle++;
		if (angle >= 360)
		{
			angle = 0;
		}

		posX = cos(XMConvertToRadians(angle));
		posY = sin(XMConvertToRadians(angle));

		XMMATRIX translationMatrix9 = XMMatrixTranslation(posX, posY, 0.0f);

		gameMatrix.GetCB().world = translationMatrix9;
		break;
	default:
		gameMatrix.Identity();
		break;
	}

	// シーン読み込み
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