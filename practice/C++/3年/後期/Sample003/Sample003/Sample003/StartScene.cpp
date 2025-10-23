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
Matrix		secondMatrix;
Camera		startCamera;
Camera		secondCamera;
CPolygon	startObj;
CPolygon	secondObj;
Float4CB	f4cb;
Float4CB	_f4cb;
XMFLOAT3	movePLPos;
XMFLOAT3	moveSecondPos;
XMFLOAT3	firstPos = XMFLOAT3(1.0f, 0.0f, 0.0f);
XMVECTOR	PlayerPos;
XMVECTOR	SecondPos;
XMVECTOR	normalizedPLPos;
XMVECTOR	normalizedSecondPos;

static float Angle = 0;
static float Speed = 0.01f;
static bool  isSecond = false;

void Reset()
{
	startMatrix.Identity();
	secondMatrix.Identity();
	secondMatrix.SetPos(firstPos);
	isSecond = false;
	Angle = 0;
	movePLPos = XMFLOAT3(0, 0, 0);
	moveSecondPos = firstPos;
	PlayerPos = XMVectorZero();
	SecondPos = XMVectorZero();
	normalizedPLPos = XMVectorZero();
	normalizedSecondPos = XMLoadFloat3(&firstPos);
}

void StartScene::Init()
{
	startMatrix.Identity();
	secondMatrix.Identity();
	startCamera.SetViewPort();
	secondCamera.SetViewPort();

	startObj.Init(Shader::GetInstance()->GetShader());
	secondObj.Init(Shader::GetInstance()->GetShader());

	f4cb.float4cb = DirectX::XMFLOAT4(1, 0, 0, 0);
}

SCENE StartScene::Update()
{
	//練習問題

//	課題の事前準備として
//	１．StartScene.cppを開く
//	２．Enterキーのシーン遷移を無効化する
//	３．ポリゴンの上下移動を停止させる

//	※Matrixクラスの利用はどちらでも良い
//	DirectXのクラスをそのまま利用しても良いし、先生が用意したMatrixクラスを利用しても良い

	// シーン継続する場合はSCENE_MAXを返す
	SCENE rt = SCENE_MAX;

	// カメラ設定更新
	startCamera.Update(startMatrix.GetView(), startMatrix.GetProjection());
	if(isSecond) secondCamera.Update(secondMatrix.GetView(), secondMatrix.GetProjection());

	startMatrix.Identity();
	if (isSecond) secondMatrix.Identity();

	static int mode = 0;
	auto input = Input::GetInstance();
	for (int i = 1; i <= 9; ++i)
	{
		if (input->GetKeyDown('0' + i))
		{
			mode = i;
			Reset();
			break;
		}
	}

	switch (mode)
	{
		case 1:
			//	Lesson1 移動
			//	x：1.0f 、y： 0.3f 、z：1.0f に移動させる
			startMatrix.SetPos(XMFLOAT3(1.0f, 0.3f, 1.0f));
			break;
		case 2:
			//	Lesson2 拡大
			//	x：2.1f 、y：0.2f 、z：1.0f 拡大縮小させる
			startMatrix.SetScale(XMFLOAT3(2.1f, 0.2f, 1.0f));
			break;
		case 3:
			//	Lesson3 回転
			//	x軸で60度回転させる
			startMatrix.SetRotationX(60);
			break;
		case 4:
			//	Lesson4 拡大と移動
			//	x : 1.9f, y : 0.8f, z : 1.0f に拡大
			//	x : -0.7f, y : 0.6f, z : -3.0f に移動
			startMatrix.SetScale(XMFLOAT3(1.9f, 0.8f, 1.0f)),startMatrix.SetPos(XMFLOAT3(-0.7f, 0.6f, -3.0f));
			break;
		case 5:
			//	Lesson5 回転と移動
			//	z軸で常に回転（速度は自由 サンプルはconstexpr float SPEED = 0.01f; を利用している）
			//	x : 1.0f, y : 0.5f, z : -3.0f に移動
			Angle++;
			if (Angle >= 360)
			{
				Angle = 0;
			}
			startMatrix.SetRotationZ(XMConvertToRadians(Angle)), startMatrix.SetPos(XMFLOAT3(1.0f, 0.5f, -3.0f));
			break;
		case 6:
			//	Lesson6 キー入力で移動
			//	矢印キーで移動させる（速度は自由 サンプルはconstexpr float SPEED = 0.01f; を利用している）
			//	正規化を行い、斜め移動にも対応させる

			if (input->GetKey(VK_LEFT))  movePLPos.x -= 1 * Speed;
			if (input->GetKey(VK_RIGHT)) movePLPos.x += 1 * Speed;
			if (input->GetKey(VK_UP))    movePLPos.y += 1 * Speed;
			if (input->GetKey(VK_DOWN))  movePLPos.y -= 1 * Speed;

			normalizedPLPos = XMLoadFloat3(&movePLPos);
			XMStoreFloat3(&movePLPos, normalizedPLPos);

			startMatrix.SetPos(movePLPos);
		break;
		case 7:
			//	Lesson7 ポリゴン2つ目表示 WASDキーで移動
			//	Lesson6の実装を残したまま追加でポリゴンを表示させる（初期位置はx : 1.0f, y : 0.0f, z : 0.0f）
			//	WASDキーで移動させる（速度は自由 サンプルはconstexpr float SPEED

			isSecond = true;
			if (input->GetKey('A'))  moveSecondPos.x -= 1 * Speed;
			if (input->GetKey('D')) moveSecondPos.x += 1 * Speed;
			if (input->GetKey('W'))    moveSecondPos.y += 1 * Speed;
			if (input->GetKey('S'))  moveSecondPos.y -= 1 * Speed;

			normalizedSecondPos = XMLoadFloat3(&moveSecondPos);
			XMStoreFloat3(&moveSecondPos, normalizedSecondPos);

			secondMatrix.SetPos(moveSecondPos);

			if (input->GetKey(VK_LEFT))  movePLPos.x -= 1 * Speed;
			if (input->GetKey(VK_RIGHT)) movePLPos.x += 1 * Speed;
			if (input->GetKey(VK_UP))    movePLPos.y += 1 * Speed;
			if (input->GetKey(VK_DOWN))  movePLPos.y -= 1 * Speed;

			normalizedPLPos = XMLoadFloat3(&movePLPos);
			XMStoreFloat3(&movePLPos, normalizedPLPos);

			startMatrix.SetPos(movePLPos);
		break;
		case 8:
			//	Lesson8 スペースキーでポリゴンの崩壊
			//	ちょっと難しい挑戦問題
			//	Lesson7まで出来た人は挑戦してみよう
			//	まずは周りと相談せずに一人で考えてみよう
			
			startMatrix.SetScale(XMFLOAT3(4.0f, 4.0f, 0));
			if (Input::GetInstance()->GetKeyDown(VK_SPACE))
			{

			}
		break;
		default:
			Reset();
		break;
	}

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
	if (isSecond)
	{
		auto _cb = ConstantBuffer::GetInstance();
		_cb->UpdateCB(_cb->GetList().float4, &_f4cb);
		secondObj.PSSetCB(_cb->GetList().float4, 1, _cb->GetCB(_cb->GetList().float4).Get());
	}
	// 描画
	startObj.Render(startMatrix.GetCB());
	if (isSecond) secondObj.Render(secondMatrix.GetCB());
	App::GetInstance()->RenderEnd();
}

void StartScene::Term()
{
}
