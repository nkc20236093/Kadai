#include <tchar.h>			// テキストや文字列を扱うために必要なヘッダーファイル
#include <Windows.h>		// Windowsプログラムで必要になるものが入っている
#include <D3D11.h>			// DirectX11SDKを使うために必要なもの
#include <d3dcompiler.h>	// シェーダーファイルをコンパイルするために必要
#include <directxcolors.h>	// DirectX::ライブラリを利用するために必要

#pragma comment(lib, "d3d11.lib")		// DirectX11ライブラリを利用するために必要
#pragma comment(lib, "d3dCompiler.lib")	// シェーダーコードをコンパイルするために必要

#include "GameScene.h"
#include "Input.h"
#include "Matrix.h"
#include "Camera.h"
#include "Polygon.h"
#include "Shader.h"
#include "Texture.h"

using namespace std;
using namespace DirectX;

Matrix		gameMatrix;
Camera		gameCamera;
CPolygon	gameObj;
uint32_t	playerTex;	// テクスチャの管理番号
uint32_t	shader01;

void GameScene::Init()
{
	gameMatrix.Identity();
	gameCamera.SetViewPort();
	shader01 = Shader::GetInstance()->LoadShader("VertexShader.hlsl", "PixelShader.hlsl");
	gameObj.Init(Shader::GetInstance()->GetShader(shader01));
	
	playerTex = Texture::GetInstance()->LoadTexture("MyChar.png");
}

SCENE GameScene::Update()
{
	// シーン継続する場合はSCENE_MAXを返す
	SCENE rt = SCENE_MAX;

	// カメラ設定更新
	gameCamera.Update(gameMatrix.GetView(), gameMatrix.GetProjection());

	gameMatrix.Identity();


	// シーン読み込み
	if (Input::GetInstance()->GetKeyDown(VK_RETURN))
	{
		rt = CLEAR;
	}


	return rt;
}

void GameScene::Render()
{
	App::GetInstance()->RenderBegin(0.0f, 0.0f, 0.0f, 1.0f);

	gameObj.Render(gameMatrix.GetCB(), Texture::GetInstance()->GetTextureResource(playerTex));

	App::GetInstance()->RenderEnd();
}

void GameScene::Term()
{
	Shader::GetInstance()->Term();
}
