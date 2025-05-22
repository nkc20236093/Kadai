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

void ClearScene::Init()
{
	clearMatrix.Identity();
	clearCamera.SetViewPort();
	int32_t n = Shader::GetInstance()->LoadShader("VertexShader.hlsl", "PixelShader.hlsl");
	clearObj.Init(Shader::GetInstance()->GetShader(n));
}

SCENE ClearScene::Update()
{
	// �V�[���p������ꍇ��SCENE_MAX��Ԃ�
	SCENE rt = SCENE_MAX;

	// �J�����ݒ�X�V
	clearCamera.Update(clearMatrix.GetView(), clearMatrix.GetProjection());

	clearMatrix.Identity();

	static XMFLOAT3 pos;
	pos.x = 1.0f;
	clearMatrix.SetPos(pos);

	static float rot;
	rot += 0.04f;
	clearMatrix.SetRotationZ(rot);


	// �V�[���ǂݍ���
	if (Input::GetInstance()->GetKeyDown(VK_RETURN))
	{
		pos = XMFLOAT3(0, 0, 0);
		rt = START;
	}

	return rt;
}

void ClearScene::Render()
{
	App::GetInstance()->RenderBegin(0.8f, 0.8f, 0.3f, 1.0f);

	clearObj.Render(clearMatrix.GetCB());

	App::GetInstance()->RenderEnd();
}

void ClearScene::Term()
{
	Shader::GetInstance()->Term();
}
