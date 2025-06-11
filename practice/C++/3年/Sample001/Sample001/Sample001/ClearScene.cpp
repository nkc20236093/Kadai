#include <tchar.h>			// テキストや文字列を扱うために必要なヘッダーファイル
#include <Windows.h>		// Windowsプログラムで必要になるものが入っている
#include <D3D11.h>			// DirectX11SDKを使うために必要なもの
#include <d3dcompiler.h>	// シェーダーファイルをコンパイルするために必要
#include <directxcolors.h>	// DirectX::ライブラリを利用するために必要

#pragma comment(lib, "d3d11.lib")		// DirectX11ライブラリを利用するために必要
#pragma comment(lib, "d3dCompiler.lib")	// シェーダーコードをコンパイルするために必要

#include "ClearScene.h"
#include "Input.h"
#include "Camera.h"
#include "Matrix.h"
#include "Polygon.h"
#include "Shader.h"

using namespace std;
using namespace DirectX;

Matrix		clearMatrix;
Camera		clearCamera;
CPolygon	clearObj;

// プレイヤー
int32_t playerTexId;
XMMATRIX playerWld;
XMFLOAT3 playerPos;
constexpr float MOVE_SPEED = 0.1f;

// 弾用
CPolygon bulletObj;
Matrix bulletMatrix;
int32_t bulletTexId;
XMMATRIX bulletWld;
XMFLOAT3 bulletPos;
constexpr float BULLET_SPEED = 0.2f;

void ClearScene::Init()
{
	clearMatrix.Identity();
	clearCamera.SetViewPort();
	int32_t n = Shader::GetInstance()->LoadShader("VertexShader.hlsl", "PixelShader.hlsl");
	clearObj.Init(Shader::GetInstance()->GetShader(n));
	playerTexId = Texture::GetInstance()->LoadTexture("moon.png"); // 画像読み込み
	playerWld = XMMatrixIdentity(); // 単位行列で初期化
	playerPos = XMFLOAT3(0, 0, 0);  // とりあえず原点にセット

	// 弾
	bulletObj.Init(Shader::GetInstance()->GetShader(n));
	bulletMatrix.Identity();
	bulletTexId = Texture::GetInstance()->LoadTexture("hand.png");
	bulletWld = XMMatrixIdentity();
	bulletPos = XMFLOAT3(0, 0, 0);
}


SCENE ClearScene::Update()
{
	// シーン継続する場合はSCENE_MAXを返す
	SCENE rt = SCENE_MAX;

	// カメラ設定更新
	clearCamera.Update(clearMatrix.GetView(), clearMatrix.GetProjection());
	clearCamera.Update(bulletMatrix.GetView(), bulletMatrix.GetProjection());

	clearMatrix.Identity();
	playerWld = XMMatrixIdentity();

	// キー入力
	XMFLOAT3 dir = XMFLOAT3(0, 0, 0);
	auto input = Input::GetInstance();
	if (input->GetKey('W') || input->GetKey(VK_UP)) dir.y = 1.0f;
	if (input->GetKey('A') || input->GetKey(VK_LEFT)) dir.x = -1.0f;
	if (input->GetKey('D') || input->GetKey(VK_RIGHT)) dir.x = 1.0f;
	if (input->GetKey('S') || input->GetKey(VK_DOWN)) dir.y = -1.0f;

	// 正規化
	// XMVECTOR3Normalizeを使用
	// XMLoadFloat3 XMFloat3をXMFVECTOR3に変換
	// XMStoreFloat3 XMVECTOR3をXMFLOAR3に変換
	XMStoreFloat3(&dir, XMVector3Normalize(XMLoadFloat3(&dir)));

	playerPos.x += dir.x * MOVE_SPEED;
	playerPos.y += dir.y * MOVE_SPEED;
	playerWld *= XMMatrixTranslation(playerPos.x, playerPos.y, playerPos.z);
	clearMatrix.SetWorld(playerWld);

	// スペースキーで玉を発射する処理
	if (input->GetKeyDown(VK_SPACE))
	{
		// 弾の更新
		// 単位行列で初期化
		bulletMatrix.Identity();
		bulletWld = XMMatrixIdentity();

		// 弾を動かす
		bulletPos.x += BULLET_SPEED;
		bulletWld *= XMMatrixTranslation(bulletPos.x, bulletPos.y, bulletPos.z);

		// 座標変換構造体にワールド行列を渡す
		bulletMatrix.SetWorld(bulletWld);
	}

	// シーン読み込み
	if (Input::GetInstance()->GetKeyDown(VK_RETURN))
	{
		rt = START;
	}

	return rt;
}

void ClearScene::Render()
{
	App::GetInstance()->RenderBegin(0.2f, 0.2f, 0.2f, 1.0f);

	// 弾の描画
	bulletObj.Render(bulletMatrix.GetCB(), Texture::GetInstance()->GetTextureResource(bulletTexId));

	// プレイヤーの描画
	clearObj.Render(clearMatrix.GetCB(), Texture::GetInstance()->GetTextureResource(playerTexId));

	App::GetInstance()->RenderEnd();
}

void ClearScene::Term()
{
	Shader::GetInstance()->Term();
	Texture::GetInstance()->Term();
}
