#include <tchar.h>			// �e�L�X�g�╶������������߂ɕK�v�ȃw�b�_�[�t�@�C��
#include <Windows.h>		// Windows�v���O�����ŕK�v�ɂȂ���̂������Ă���
#include <D3D11.h>			// DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <d3dcompiler.h>	// �V�F�[�_�[�t�@�C�����R���p�C�����邽�߂ɕK�v
#include <directxcolors.h>	// DirectX::���C�u�����𗘗p���邽�߂ɕK�v
#include <functional>

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
	// �V�[���p������ꍇ��SCENE_MAX��Ԃ�
	SCENE rt = SCENE_MAX;

	// �J�����ݒ�X�V
	startCamera.Update(startMatrix.GetView(), startMatrix.GetProjection());

	startMatrix.Identity();

	// �L�[���͂Ŗ��x�̕ύX�i�I�[�o�[�t���[�A�A���_�[�t���[���΍�j
	if(Input::GetInstance()->GetKey(VK_DOWN))
		f4cb.float4cb.x -= 0.1f;
	if (Input::GetInstance()->GetKey(VK_UP))
		f4cb.float4cb.x += 0.1f;

	startMatrix.SetScale(XMFLOAT3(4.5, 4.5, 0));

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

	// float4�̒萔�o�b�t�@���X�V
	auto cb = ConstantBuffer::GetInstance();
	cb->UpdateCB(cb->GetList().float4, &f4cb);
	startObj.PSSetCB(cb->GetList().float4, 1, cb->GetCB(cb->GetList().float4).Get());

	// �`��
	startObj.Render(startMatrix.GetCB(), Texture::GetInstance()->GetTextureResource(bgTex));
	startObj.Render(startMatrix.GetCB(), Texture::GetInstance()->GetTextureResource(clTex));

	App::GetInstance()->RenderEnd();
}

void StartScene::Term()
{
}
