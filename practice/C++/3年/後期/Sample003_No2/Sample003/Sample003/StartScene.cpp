#include <tchar.h>			// テキストや文字列を扱うために必要なヘッダーファイル
#include <Windows.h>		// Windowsプログラムで必要になるものが入っている
#include <D3D11.h>			// DirectX11SDKを使うために必要なもの
#include <d3dcompiler.h>	// シェーダーファイルをコンパイルするために必要
#include <directxcolors.h>	// DirectX::ライブラリを利用するために必要
#include <functional>

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
Float4CB	f4cb;

int32_t bgTex;
int32_t clTex;

void StartScene::Init()
{
	startMatrix.Identity();
	startCamera.SetViewPort();

	startObj.Init(Shader::GetInstance()->GetShader());
	bgTex = Texture::GetInstance()->LoadTexture("GBackTex.png");
	clTex = Texture::GetInstance()->LoadTexture("CloudTex.png");

	f4cb.float4cb = DirectX::XMFLOAT4(1, 0, 0, 0);
}

SCENE StartScene::Update()
{
	// シーン継続する場合はSCENE_MAXを返す
	SCENE rt = SCENE_MAX;

	// カメラ設定更新
	startCamera.Update(startMatrix.GetView(), startMatrix.GetProjection());

	startMatrix.Identity();

	// キー入力で明度の変更（オーバーフロー、アンダーフロー未対策）
	if(Input::GetInstance()->GetKey(VK_DOWN))
		f4cb.float4cb.x -= 0.1f;
	if (Input::GetInstance()->GetKey(VK_UP))
		f4cb.float4cb.x += 0.1f;

	startMatrix.SetScale(XMFLOAT3(4.5, 4.5, 0));

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

	// float4の定数バッファを更新
	auto cb = ConstantBuffer::GetInstance();
	cb->UpdateCB(cb->GetList().float4, &f4cb);
	startObj.PSSetCB(cb->GetList().float4, 1, cb->GetCB(cb->GetList().float4).Get());

	// 描画
	startObj.Render(startMatrix.GetCB(), Texture::GetInstance()->GetTextureResource(bgTex));
	startObj.Render(startMatrix.GetCB(), Texture::GetInstance()->GetTextureResource(clTex));

	App::GetInstance()->RenderEnd();
}

void StartScene::Term()
{
}
