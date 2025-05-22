#include <tchar.h>			// テキストや文字列を扱うために必要なヘッダーファイル
#include <Windows.h>		// Windowsプログラムで必要になるものが入っている
#include <D3D11.h>			// DirectX11SDKを使うために必要なもの
#include <d3dcompiler.h>	// シェーダーファイルをコンパイルするために必要
#include <directxcolors.h>	// DirectX::ライブラリを利用するために必要

#pragma comment(lib, "d3d11.lib")		// DirectX11ライブラリを利用するために必要
#pragma comment(lib, "d3dCompiler.lib")	// シェーダーコードをコンパイルするために必要

#include "StartScene.h"
#include "Input.h"
#include "Matrix.h"
#include "Camera.h"
#include "Polygon.h"
#include "Shader.h"
#include "Texture.h"
#include "Audio.h"


using namespace std;
using namespace DirectX;

Matrix		startMatrix;
Camera		startCamera;
CPolygon	startObj;

// こんすとえくすぷれしょん
constexpr float PI = 3.14159265358979323146264f;

DirectX::XMMATRIX startWorld;

void StartScene::Init()
{
	startMatrix.Identity();
	startCamera.SetViewPort();
	startObj.Init(Shader::GetInstance()->GetShader());

	Audio::GetInstance()->Init();
	Audio::GetInstance()->LoadAudio("dummy.wav");
	Audio::GetInstance()->Play();

	// 単位行列で初期化
	startWorld = DirectX::XMMatrixIdentity();
}

SCENE StartScene::Update()
{
	// シーン継続する場合はSCENE_MAXを返す
	SCENE rt = SCENE_MAX;

	// カメラ設定更新
	startCamera.Update(startMatrix.GetView(), startMatrix.GetProjection());

	// 単位行列で初期化
	startWorld = DirectX::XMMatrixIdentity();

	//static DirectX::XMFLOAT3 pos = DirectX::XMFLOAT3(0, 0, 0);
	//pos.x += 0.01f; // 常に加算する
	//startWorld *= DirectX::XMMatrixTranslation(pos.x, 0.0f, 0.0f);

	startWorld *= XMMatrixTranslation(0, 0, 0); // 移動
	startWorld *= XMMatrixRotationZ(1.2f); // 回転

	//static XMFLOAT3 scale = XMFLOAT3(1, 1, 1);
	//// x:3.2f, y:0.145fで拡大縮小してみよう
	//scale.x = 3.2f;
	//scale.y = 0.145f;
	//startWorld *= XMMatrixScaling(scale.x, scale.y, scale.z);


	startMatrix.SetWorld(startWorld);// 座標変換構造体にワールド変換行列を渡す

	// シーン読み込み
	if (Input::GetInstance()->GetKeyDown(VK_RETURN))
	{
		rt = GAME;
	}
	return rt;
}

void StartScene::Render()
{
	App::GetInstance()->RenderBegin(0.5f, 0.8f, 1.0f, 1.0f);

	startObj.Render(startMatrix.GetCB(), Texture::GetInstance()->GetTextureResource());

	App::GetInstance()->RenderEnd();
}

void StartScene::Term()
{
}