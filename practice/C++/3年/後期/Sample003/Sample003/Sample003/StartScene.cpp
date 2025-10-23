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
	//���K���

//	�ۑ�̎��O�����Ƃ���
//	�P�DStartScene.cpp���J��
//	�Q�DEnter�L�[�̃V�[���J�ڂ𖳌�������
//	�R�D�|���S���̏㉺�ړ����~������

//	��Matrix�N���X�̗��p�͂ǂ���ł��ǂ�
//	DirectX�̃N���X�����̂܂ܗ��p���Ă��ǂ����A�搶���p�ӂ���Matrix�N���X�𗘗p���Ă��ǂ�

	// �V�[���p������ꍇ��SCENE_MAX��Ԃ�
	SCENE rt = SCENE_MAX;

	// �J�����ݒ�X�V
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
			//	Lesson1 �ړ�
			//	x�F1.0f �Ay�F 0.3f �Az�F1.0f �Ɉړ�������
			startMatrix.SetPos(XMFLOAT3(1.0f, 0.3f, 1.0f));
			break;
		case 2:
			//	Lesson2 �g��
			//	x�F2.1f �Ay�F0.2f �Az�F1.0f �g��k��������
			startMatrix.SetScale(XMFLOAT3(2.1f, 0.2f, 1.0f));
			break;
		case 3:
			//	Lesson3 ��]
			//	x����60�x��]������
			startMatrix.SetRotationX(60);
			break;
		case 4:
			//	Lesson4 �g��ƈړ�
			//	x : 1.9f, y : 0.8f, z : 1.0f �Ɋg��
			//	x : -0.7f, y : 0.6f, z : -3.0f �Ɉړ�
			startMatrix.SetScale(XMFLOAT3(1.9f, 0.8f, 1.0f)),startMatrix.SetPos(XMFLOAT3(-0.7f, 0.6f, -3.0f));
			break;
		case 5:
			//	Lesson5 ��]�ƈړ�
			//	z���ŏ�ɉ�]�i���x�͎��R �T���v����constexpr float SPEED = 0.01f; �𗘗p���Ă���j
			//	x : 1.0f, y : 0.5f, z : -3.0f �Ɉړ�
			Angle++;
			if (Angle >= 360)
			{
				Angle = 0;
			}
			startMatrix.SetRotationZ(XMConvertToRadians(Angle)), startMatrix.SetPos(XMFLOAT3(1.0f, 0.5f, -3.0f));
			break;
		case 6:
			//	Lesson6 �L�[���͂ňړ�
			//	���L�[�ňړ�������i���x�͎��R �T���v����constexpr float SPEED = 0.01f; �𗘗p���Ă���j
			//	���K�����s���A�΂߈ړ��ɂ��Ή�������

			if (input->GetKey(VK_LEFT))  movePLPos.x -= 1 * Speed;
			if (input->GetKey(VK_RIGHT)) movePLPos.x += 1 * Speed;
			if (input->GetKey(VK_UP))    movePLPos.y += 1 * Speed;
			if (input->GetKey(VK_DOWN))  movePLPos.y -= 1 * Speed;

			normalizedPLPos = XMLoadFloat3(&movePLPos);
			XMStoreFloat3(&movePLPos, normalizedPLPos);

			startMatrix.SetPos(movePLPos);
		break;
		case 7:
			//	Lesson7 �|���S��2�ڕ\�� WASD�L�[�ňړ�
			//	Lesson6�̎������c�����܂ܒǉ��Ń|���S����\��������i�����ʒu��x : 1.0f, y : 0.0f, z : 0.0f�j
			//	WASD�L�[�ňړ�������i���x�͎��R �T���v����constexpr float SPEED

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
			//	Lesson8 �X�y�[�X�L�[�Ń|���S���̕���
			//	������Ɠ��������
			//	Lesson7�܂ŏo�����l�͒��킵�Ă݂悤
			//	�܂��͎���Ƒ��k�����Ɉ�l�ōl���Ă݂悤
			
			startMatrix.SetScale(XMFLOAT3(4.0f, 4.0f, 0));
			if (Input::GetInstance()->GetKeyDown(VK_SPACE))
			{

			}
		break;
		default:
			Reset();
		break;
	}

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
	if (isSecond)
	{
		auto _cb = ConstantBuffer::GetInstance();
		_cb->UpdateCB(_cb->GetList().float4, &_f4cb);
		secondObj.PSSetCB(_cb->GetList().float4, 1, _cb->GetCB(_cb->GetList().float4).Get());
	}
	// �`��
	startObj.Render(startMatrix.GetCB());
	if (isSecond) secondObj.Render(secondMatrix.GetCB());
	App::GetInstance()->RenderEnd();
}

void StartScene::Term()
{
}
