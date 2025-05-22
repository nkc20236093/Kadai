#include <tchar.h>			// �e�L�X�g�╶������������߂ɕK�v�ȃw�b�_�[�t�@�C��
#include <Windows.h>		// Windows�v���O�����ŕK�v�ɂȂ���̂������Ă���
#include <D3D11.h>			// DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <d3dcompiler.h>	// �V�F�[�_�[�t�@�C�����R���p�C�����邽�߂ɕK�v
#include <directxcolors.h>	// DirectX::���C�u�����𗘗p���邽�߂ɕK�v

#pragma comment(lib, "d3d11.lib")		// DirectX11���C�u�����𗘗p���邽�߂ɕK�v
#pragma comment(lib, "d3dCompiler.lib")	// �V�F�[�_�[�R�[�h���R���p�C�����邽�߂ɕK�v

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

// ���񂷂Ƃ������Ղꂵ���
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

	// �P�ʍs��ŏ�����
	startWorld = DirectX::XMMatrixIdentity();
}

SCENE StartScene::Update()
{
	// �V�[���p������ꍇ��SCENE_MAX��Ԃ�
	SCENE rt = SCENE_MAX;

	// �J�����ݒ�X�V
	startCamera.Update(startMatrix.GetView(), startMatrix.GetProjection());

	// �P�ʍs��ŏ�����
	startWorld = DirectX::XMMatrixIdentity();

	//static DirectX::XMFLOAT3 pos = DirectX::XMFLOAT3(0, 0, 0);
	//pos.x += 0.01f; // ��ɉ��Z����
	//startWorld *= DirectX::XMMatrixTranslation(pos.x, 0.0f, 0.0f);

	startWorld *= XMMatrixTranslation(0, 0, 0); // �ړ�
	startWorld *= XMMatrixRotationZ(1.2f); // ��]

	//static XMFLOAT3 scale = XMFLOAT3(1, 1, 1);
	//// x:3.2f, y:0.145f�Ŋg��k�����Ă݂悤
	//scale.x = 3.2f;
	//scale.y = 0.145f;
	//startWorld *= XMMatrixScaling(scale.x, scale.y, scale.z);


	startMatrix.SetWorld(startWorld);// ���W�ϊ��\���̂Ƀ��[���h�ϊ��s���n��

	// �V�[���ǂݍ���
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