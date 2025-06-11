#include <tchar.h>			// �e�L�X�g�╶������������߂ɕK�v�ȃw�b�_�[�t�@�C��
#include <Windows.h>		// Windows�v���O�����ŕK�v�ɂȂ���̂������Ă���
#include <D3D11.h>			// DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <d3dcompiler.h>	// �V�F�[�_�[�t�@�C�����R���p�C�����邽�߂ɕK�v
#include <directxcolors.h>	// DirectX::���C�u�����𗘗p���邽�߂ɕK�v

#pragma comment(lib, "d3d11.lib")		// DirectX11���C�u�����𗘗p���邽�߂ɕK�v
#pragma comment(lib, "d3dCompiler.lib")	// �V�F�[�_�[�R�[�h���R���p�C�����邽�߂ɕK�v

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

// �v���C���[
int32_t playerTexId;
XMMATRIX playerWld;
XMFLOAT3 playerPos;
constexpr float MOVE_SPEED = 0.1f;

// �e�p
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
	playerTexId = Texture::GetInstance()->LoadTexture("moon.png"); // �摜�ǂݍ���
	playerWld = XMMatrixIdentity(); // �P�ʍs��ŏ�����
	playerPos = XMFLOAT3(0, 0, 0);  // �Ƃ肠�������_�ɃZ�b�g

	// �e
	bulletObj.Init(Shader::GetInstance()->GetShader(n));
	bulletMatrix.Identity();
	bulletTexId = Texture::GetInstance()->LoadTexture("hand.png");
	bulletWld = XMMatrixIdentity();
	bulletPos = XMFLOAT3(0, 0, 0);
}


SCENE ClearScene::Update()
{
	// �V�[���p������ꍇ��SCENE_MAX��Ԃ�
	SCENE rt = SCENE_MAX;

	// �J�����ݒ�X�V
	clearCamera.Update(clearMatrix.GetView(), clearMatrix.GetProjection());
	clearCamera.Update(bulletMatrix.GetView(), bulletMatrix.GetProjection());

	clearMatrix.Identity();
	playerWld = XMMatrixIdentity();

	// �L�[����
	XMFLOAT3 dir = XMFLOAT3(0, 0, 0);
	auto input = Input::GetInstance();
	if (input->GetKey('W') || input->GetKey(VK_UP)) dir.y = 1.0f;
	if (input->GetKey('A') || input->GetKey(VK_LEFT)) dir.x = -1.0f;
	if (input->GetKey('D') || input->GetKey(VK_RIGHT)) dir.x = 1.0f;
	if (input->GetKey('S') || input->GetKey(VK_DOWN)) dir.y = -1.0f;

	// ���K��
	// XMVECTOR3Normalize���g�p
	// XMLoadFloat3 XMFloat3��XMFVECTOR3�ɕϊ�
	// XMStoreFloat3 XMVECTOR3��XMFLOAR3�ɕϊ�
	XMStoreFloat3(&dir, XMVector3Normalize(XMLoadFloat3(&dir)));

	playerPos.x += dir.x * MOVE_SPEED;
	playerPos.y += dir.y * MOVE_SPEED;
	playerWld *= XMMatrixTranslation(playerPos.x, playerPos.y, playerPos.z);
	clearMatrix.SetWorld(playerWld);

	// �X�y�[�X�L�[�ŋʂ𔭎˂��鏈��
	if (input->GetKeyDown(VK_SPACE))
	{
		// �e�̍X�V
		// �P�ʍs��ŏ�����
		bulletMatrix.Identity();
		bulletWld = XMMatrixIdentity();

		// �e�𓮂���
		bulletPos.x += BULLET_SPEED;
		bulletWld *= XMMatrixTranslation(bulletPos.x, bulletPos.y, bulletPos.z);

		// ���W�ϊ��\���̂Ƀ��[���h�s���n��
		bulletMatrix.SetWorld(bulletWld);
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

	// �e�̕`��
	bulletObj.Render(bulletMatrix.GetCB(), Texture::GetInstance()->GetTextureResource(bulletTexId));

	// �v���C���[�̕`��
	clearObj.Render(clearMatrix.GetCB(), Texture::GetInstance()->GetTextureResource(playerTexId));

	App::GetInstance()->RenderEnd();
}

void ClearScene::Term()
{
	Shader::GetInstance()->Term();
	Texture::GetInstance()->Term();
}
