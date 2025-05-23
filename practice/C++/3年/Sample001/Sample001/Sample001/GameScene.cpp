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
	// シーン継続する場合はSCENE_MAXを返す
	SCENE rt = SCENE_MAX;

	// カメラ設定更新
	gameCamera.Update(gameMatrix.GetView(), gameMatrix.GetProjection());
	
	// lesson01 移動
	//gameMatrix.GetCB().world = XMMatrixTranslation(0.3, -0.5, 2.0);

	// lesson02 拡大
	//gameMatrix.GetCB().world = XMMatrixScaling(0.5, 2.5, 1.0);

	// lesson03 回転
	//gameMatrix.GetCB().world = XMMatrixRotationY(45.0f * (180 * 3.14f));

	// lesson04 拡大と移動
	//gameMatrix.GetCB().world = XMMatrixScaling(2.3, 1.5, 1.0), XMMatrixTranslation(-0.1, 0.5, 0.0);

	// lesson05 回転と移動
	//gameMatrix.GetCB().world = XMMatrixRotationZ(60 * (180 * 3.14f)), XMMatrixTranslation(0.0, 0.5, 0.0);

	// lesson06 上下移動
	//XMFLOAT3 postion;
	//XMStoreFloat3(&postion, gameMatrix.GetCB().world.r[3]);
	//float posY = postion.y;
	//if (posY > 1)
	//{
	//	isUP = false;
	//}
	//else if (posY < -1)
	//{
	//	isUP = true;
	//}
	//posY += isUP ? 0.001 : -0.001;
	//gameMatrix.GetCB().world = XMMatrixTranslation(0.0, posY, 0.0);

	// lesson08 自転と移動
	//static float angle = 0.0f;
	//angle++;
	//if (angle >= 360)
	//{
	//	angle = 0;
	//}
	//XMMATRIX rotationMatrix = XMMatrixRotationZ(XMConvertToRadians(angle));

	//XMMATRIX translationMatrix = XMMatrixTranslation(0.0f, 1.0f, 0.0f);

	//XMMATRIX worldMatrix = rotationMatrix * translationMatrix;

	//gameMatrix.GetCB().world = worldMatrix;

	// lesson09 公転と移動(自転無し)
	//static float angle = 0.0f;
	//float radius = 1.0f;       
	//float speed = 0.1f;       

	//
	//angle += speed;
	//if (angle >= 360.0f)
	//{
	//	angle -= 360.0f;
	//}
	//
	//float posX = radius * cos(XMConvertToRadians(angle));
	//float posY = radius * sin(XMConvertToRadians(angle));
	//float posZ = 0.0f;

	//XMMATRIX translationMatrix = XMMatrixTranslation(posX, posY, posZ);

	//gameMatrix.GetCB().world = translationMatrix;

	// lessonEX 太陽と月と地球

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