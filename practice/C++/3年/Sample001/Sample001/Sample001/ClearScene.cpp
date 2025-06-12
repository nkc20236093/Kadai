#include <tchar.h>   // テキストや文字列を扱うために必要なヘッダーファイル
#include <Windows.h>  // Windowsプログラムで必要になるものが入っている
#include <D3D11.h>   // DirectX11SDKを使うために必要なもの
#include <d3dcompiler.h> // シェーダーファイルをコンパイルするために必要
#include <directxcolors.h> // DirectX::ライブラリを利用するために必要

#pragma comment(lib, "d3d11.lib")  // DirectX11ライブラリを利用するために必要
#pragma comment(lib, "d3dCompiler.lib") // シェーダーコードをコンパイルするために必要

#include "ClearScene.h"
#include "Input.h"
#include "Camera.h"
#include "Matrix.h"
#include "Polygon.h"
#include "Shader.h"

using namespace std;
using namespace DirectX;

Matrix  clearMatrix;
Camera  clearCamera;
CPolygon clearObj;

int32_t  playerTexId; // プレイヤー画像の管理ID
XMMATRIX playerWld;  // プレイヤーのワールド変換行列
XMFLOAT3 playerPos;  // プレイヤーの座標
constexpr float MOVE_SPEED = 0.1f; // プレイヤーの移動速度

// 弾用
constexpr float BULLET_SPEED = 0.2f;
constexpr int BULLET_MAX = 20;
CPolygon bulletObj;
Matrix  bulletMatrix[BULLET_MAX];
int32_t  bulletTexId;
XMMATRIX bulletWld[BULLET_MAX];
XMFLOAT3 bulletPos[BULLET_MAX];
bool  bulletIsAlive[BULLET_MAX]; // 弾の生存フラグ



void ClearScene::Init()
{
    clearMatrix.Identity();
    clearCamera.SetViewPort();
    int32_t n = Shader::GetInstance()->LoadShader("VertexShader.hlsl", "PixelShader.hlsl");
    clearObj.Init(Shader::GetInstance()->GetShader(n));
    playerTexId = Texture::GetInstance()->LoadTexture("moon.png"); // 画像読み込み
    playerWld = XMMatrixIdentity(); // 単位行列で初期化
    playerPos = XMFLOAT3(0, 0, 0); // とりあえず原点

    // 弾
    bulletObj.Init(Shader::GetInstance()->GetShader(n));// Initを忘れない！
    bulletTexId = Texture::GetInstance()->LoadTexture("hand.png");
    for (int i = 0; i < BULLET_MAX; ++i)
    {
        bulletMatrix[i].Identity();
        bulletWld[i] = XMMatrixIdentity();
        bulletPos[i] = XMFLOAT3(0, 0, 0);
        bulletIsAlive[i] = false; // 利用していない状態で初期化
    }
}

SCENE ClearScene::Update()
{
    // シーン継続する場合はSCENE_MAXを返す
    SCENE rt = SCENE_MAX;

    // カメラ設定更新
    clearCamera.Update(clearMatrix.GetView(), clearMatrix.GetProjection());
    for (int i = 0; i < BULLET_MAX; ++i)
        clearCamera.Update(bulletMatrix[i].GetView(), bulletMatrix[i].GetProjection());

    clearMatrix.Identity();
    playerWld = XMMatrixIdentity();
    XMFLOAT3 dir = XMFLOAT3(0, 0, 0);

    // キー入力
    auto input = Input::GetInstance();
    if (input->GetKey('W') || input->GetKey(VK_UP))  dir.y = 1.0f;
    if (input->GetKey('A') || input->GetKey(VK_LEFT)) dir.x = -1.0f;
    if (input->GetKey('D') || input->GetKey(VK_RIGHT)) dir.x = 1.0f;
    if (input->GetKey('S') || input->GetKey(VK_DOWN)) dir.y = -1.0f;
    // XMVector3Normalize：正規化
    // XMLoadFloat3：XMFLOAT3をXMVECTORに変換する
    // XMStoreFloat3：XMVECTORをXMFLOAT3に変換する
    XMStoreFloat3(&dir, XMVector3Normalize(XMLoadFloat3(&dir)));

    playerPos.x += dir.x * MOVE_SPEED;
    playerPos.y += dir.y * MOVE_SPEED;
    playerWld *= XMMatrixTranslation(playerPos.x, playerPos.y, playerPos.z);
    clearMatrix.SetWorld(playerWld);

    // 弾の更新
    // スペースキーで弾を飛ばす
    if (input->GetKeyDown(VK_SPACE))
    {
        for (int i = 0; i < BULLET_MAX; ++i)
        {
            // 未使用中だったら弾を飛ばす
            if (!bulletIsAlive[i])
            {
                bulletIsAlive[i] = true;
                bulletPos[i] = playerPos; // 弾の発射座標はプレイヤーと同じ
                break;// 1つ弾を発射したらループを抜ける（1つしか使わない）
            }
        }
    }
    for (int i = 0; i < BULLET_MAX; ++i)
    {
        // 単位行列で初期化
        bulletMatrix[i].Identity();
        bulletWld[i] = XMMatrixIdentity();

        // 弾使用中？
        if (bulletIsAlive[i])
        {
            // 弾を動かす
            bulletPos[i].x += BULLET_SPEED;
            bulletWld[i] *= XMMatrixTranslation(bulletPos[i].x, bulletPos[i].y, bulletPos[i].z);

            // 弾が画面外に行った？
            if (bulletPos[i].x > 4.5f)
            {
                bulletIsAlive[i] = false;
            }
        }
        // 座標変換構造体にワールド行列を渡す
        bulletMatrix[i].SetWorld(bulletWld[i]);
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

    for (int i = 0; i < BULLET_MAX; ++i)
    {
        // 弾を利用中だけ描画する
        if (bulletIsAlive[i])
        {
            // 弾の描画
            bulletObj.Render(bulletMatrix[i].GetCB(), Texture::GetInstance()->GetTextureResource(bulletTexId));
        }
    }

    // プレイヤーの描画
    clearObj.Render(clearMatrix.GetCB(),
        Texture::GetInstance()->GetTextureResource(playerTexId));

    App::GetInstance()->RenderEnd();
}

void ClearScene::Term()
{
    Shader::GetInstance()->Term();
    Texture::GetInstance()->Term();
}
