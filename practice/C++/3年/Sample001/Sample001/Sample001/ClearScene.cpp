#include <tchar.h>   // �e�L�X�g�╶������������߂ɕK�v�ȃw�b�_�[�t�@�C��
#include <Windows.h>  // Windows�v���O�����ŕK�v�ɂȂ���̂������Ă���
#include <D3D11.h>   // DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <d3dcompiler.h> // �V�F�[�_�[�t�@�C�����R���p�C�����邽�߂ɕK�v
#include <directxcolors.h> // DirectX::���C�u�����𗘗p���邽�߂ɕK�v

#pragma comment(lib, "d3d11.lib")  // DirectX11���C�u�����𗘗p���邽�߂ɕK�v
#pragma comment(lib, "d3dCompiler.lib") // �V�F�[�_�[�R�[�h���R���p�C�����邽�߂ɕK�v

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

int32_t  playerTexId; // �v���C���[�摜�̊Ǘ�ID
XMMATRIX playerWld;  // �v���C���[�̃��[���h�ϊ��s��
XMFLOAT3 playerPos;  // �v���C���[�̍��W
constexpr float MOVE_SPEED = 0.1f; // �v���C���[�̈ړ����x

// �e�p
constexpr float BULLET_SPEED = 0.2f;
constexpr int BULLET_MAX = 20;
CPolygon bulletObj;
Matrix  bulletMatrix[BULLET_MAX];
int32_t  bulletTexId;
XMMATRIX bulletWld[BULLET_MAX];
XMFLOAT3 bulletPos[BULLET_MAX];
bool  bulletIsAlive[BULLET_MAX]; // �e�̐����t���O



void ClearScene::Init()
{
    clearMatrix.Identity();
    clearCamera.SetViewPort();
    int32_t n = Shader::GetInstance()->LoadShader("VertexShader.hlsl", "PixelShader.hlsl");
    clearObj.Init(Shader::GetInstance()->GetShader(n));
    playerTexId = Texture::GetInstance()->LoadTexture("moon.png"); // �摜�ǂݍ���
    playerWld = XMMatrixIdentity(); // �P�ʍs��ŏ�����
    playerPos = XMFLOAT3(0, 0, 0); // �Ƃ肠�������_

    // �e
    bulletObj.Init(Shader::GetInstance()->GetShader(n));// Init��Y��Ȃ��I
    bulletTexId = Texture::GetInstance()->LoadTexture("hand.png");
    for (int i = 0; i < BULLET_MAX; ++i)
    {
        bulletMatrix[i].Identity();
        bulletWld[i] = XMMatrixIdentity();
        bulletPos[i] = XMFLOAT3(0, 0, 0);
        bulletIsAlive[i] = false; // ���p���Ă��Ȃ���Ԃŏ�����
    }
}

SCENE ClearScene::Update()
{
    // �V�[���p������ꍇ��SCENE_MAX��Ԃ�
    SCENE rt = SCENE_MAX;

    // �J�����ݒ�X�V
    clearCamera.Update(clearMatrix.GetView(), clearMatrix.GetProjection());
    for (int i = 0; i < BULLET_MAX; ++i)
        clearCamera.Update(bulletMatrix[i].GetView(), bulletMatrix[i].GetProjection());

    clearMatrix.Identity();
    playerWld = XMMatrixIdentity();
    XMFLOAT3 dir = XMFLOAT3(0, 0, 0);

    // �L�[����
    auto input = Input::GetInstance();
    if (input->GetKey('W') || input->GetKey(VK_UP))  dir.y = 1.0f;
    if (input->GetKey('A') || input->GetKey(VK_LEFT)) dir.x = -1.0f;
    if (input->GetKey('D') || input->GetKey(VK_RIGHT)) dir.x = 1.0f;
    if (input->GetKey('S') || input->GetKey(VK_DOWN)) dir.y = -1.0f;
    // XMVector3Normalize�F���K��
    // XMLoadFloat3�FXMFLOAT3��XMVECTOR�ɕϊ�����
    // XMStoreFloat3�FXMVECTOR��XMFLOAT3�ɕϊ�����
    XMStoreFloat3(&dir, XMVector3Normalize(XMLoadFloat3(&dir)));

    playerPos.x += dir.x * MOVE_SPEED;
    playerPos.y += dir.y * MOVE_SPEED;
    playerWld *= XMMatrixTranslation(playerPos.x, playerPos.y, playerPos.z);
    clearMatrix.SetWorld(playerWld);

    // �e�̍X�V
    // �X�y�[�X�L�[�Œe���΂�
    if (input->GetKeyDown(VK_SPACE))
    {
        for (int i = 0; i < BULLET_MAX; ++i)
        {
            // ���g�p����������e���΂�
            if (!bulletIsAlive[i])
            {
                bulletIsAlive[i] = true;
                bulletPos[i] = playerPos; // �e�̔��ˍ��W�̓v���C���[�Ɠ���
                break;// 1�e�𔭎˂����烋�[�v�𔲂���i1�����g��Ȃ��j
            }
        }
    }
    for (int i = 0; i < BULLET_MAX; ++i)
    {
        // �P�ʍs��ŏ�����
        bulletMatrix[i].Identity();
        bulletWld[i] = XMMatrixIdentity();

        // �e�g�p���H
        if (bulletIsAlive[i])
        {
            // �e�𓮂���
            bulletPos[i].x += BULLET_SPEED;
            bulletWld[i] *= XMMatrixTranslation(bulletPos[i].x, bulletPos[i].y, bulletPos[i].z);

            // �e����ʊO�ɍs�����H
            if (bulletPos[i].x > 4.5f)
            {
                bulletIsAlive[i] = false;
            }
        }
        // ���W�ϊ��\���̂Ƀ��[���h�s���n��
        bulletMatrix[i].SetWorld(bulletWld[i]);
    }

    // �V�[���ǂݍ���
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
        // �e�𗘗p�������`�悷��
        if (bulletIsAlive[i])
        {
            // �e�̕`��
            bulletObj.Render(bulletMatrix[i].GetCB(), Texture::GetInstance()->GetTextureResource(bulletTexId));
        }
    }

    // �v���C���[�̕`��
    clearObj.Render(clearMatrix.GetCB(),
        Texture::GetInstance()->GetTextureResource(playerTexId));

    App::GetInstance()->RenderEnd();
}

void ClearScene::Term()
{
    Shader::GetInstance()->Term();
    Texture::GetInstance()->Term();
}
