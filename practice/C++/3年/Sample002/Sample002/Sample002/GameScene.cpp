#include <tchar.h>			// �e�L�X�g�╶������������߂ɕK�v�ȃw�b�_�[�t�@�C��
#include <Windows.h>		// Windows�v���O�����ŕK�v�ɂȂ���̂������Ă���
#include <D3D11.h>			// DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <d3dcompiler.h>	// �V�F�[�_�[�t�@�C�����R���p�C�����邽�߂ɕK�v
#include <directxcolors.h>	// DirectX::���C�u�����𗘗p���邽�߂ɕK�v

#pragma comment(lib, "d3d11.lib")		// DirectX11���C�u�����𗘗p���邽�߂ɕK�v
#pragma comment(lib, "d3dCompiler.lib")	// �V�F�[�_�[�R�[�h���R���p�C�����邽�߂ɕK�v

#include "GameScene.h"
#include "Input.h"
#include "Matrix.h"
#include "Camera.h"
#include "Polygon.h"
#include "Shader.h"
#include <iostream>


using namespace std;
using namespace DirectX;

constexpr int MAX_LENGHT = 20;
constexpr float SHOT_INTERVAL = 1.5f;
Matrix		gameMatrix;
Matrix		backMatrix;
Matrix		shotMatrix[MAX_LENGHT];
Camera		gameCamera;
CPolygon	gameObj;
CPolygon	backObj;
CPolygon	shotObj;
int32_t		charTexId;
int32_t		backTexId;
int32_t		shotTexId;
XMFLOAT2	plPos[4];
XMFLOAT2	bgPos[4];
XMFLOAT2	shPos[4];
XMFLOAT3	bgScale;
XMFLOAT2	movePLPos;
XMFLOAT2	moveSHPos;
XMFLOAT2	moveBGPos;
XMFLOAT3	PlayPos;
XMFLOAT3	ShotPos[MAX_LENGHT];
XMFLOAT3	shotScale = XMFLOAT3(0.4f, 0.4f, 1.0f);
float		animPLTimer = 0;
float		animSHTimer = 0;
float		animBGTimer = 0;
float		shotTimer = 0;
bool		bgActive = false;
bool		shotAlives[MAX_LENGHT];

void Reset()
{
	// ����
	plPos[0].x = 0.0f;
	plPos[0].y = 1.0f;
	// ����
	plPos[1].x = 0.0f;
	plPos[1].y = 0.0f;
	// �E��
	plPos[2].x = 1.0f;
	plPos[2].y = 1.0f;
	// �E��
	plPos[3].x = 1.0f;
	plPos[3].y = 0.0f;
	gameObj.SetUV(plPos);
	gameMatrix.Identity();

	shotTimer = 0;
	animPLTimer = 0;
	animSHTimer = 0;
	movePLPos = XMFLOAT2(0, 0);
	PlayPos = XMFLOAT3(0, 0, 0);
	for (int i = 0; i < MAX_LENGHT; i++)
	{
		shotMatrix[i].Identity();
		ShotPos[i] = PlayPos;
		shotAlives[i] = false;
		shotMatrix[i].SetScale(shotScale);
	}

	bgActive = false;
	backMatrix.Identity();

	backObj.SetUV(plPos);
	bgScale = XMFLOAT3(1.0f, 1.0f, 1);
	backMatrix.SetScale(bgScale);
}

void GameScene::Init()
{
	gameMatrix.Identity();
	backMatrix.Identity();
	gameCamera.SetViewPort();
	int32_t n = Shader::GetInstance()->LoadShader("VertexShader.hlsl", "PixelShader.hlsl");
	gameObj.Init(Shader::GetInstance()->GetShader(n));
	shotObj.Init(Shader::GetInstance()->GetShader(n));
	backObj.Init(Shader::GetInstance()->GetShader(n));
	charTexId = Texture::GetInstance()->LoadTexture("tex/MyChar.png");
	backTexId = Texture::GetInstance()->LoadTexture("tex/GBackTex.png");
	shotTexId = Texture::GetInstance()->LoadTexture("tex/MyShot.png");
	Reset();
}

SCENE GameScene::Update()
{
	// �V�[���p������ꍇ��SCENE_MAX��Ԃ�
	SCENE rt = SCENE_MAX;

	// �J�����ݒ�X�V
	gameCamera.Update(gameMatrix.GetView(), gameMatrix.GetProjection());
	gameCamera.Update(backMatrix.GetView(), backMatrix.GetProjection());
	for (int i = 0; i < MAX_LENGHT; ++i)
	{
		gameCamera.Update(shotMatrix[i].GetView(), shotMatrix[i].GetProjection());
	}
	gameMatrix.Identity();
	backMatrix.Identity();

	//UV�e�N�X�`����p���ăA�j���[�V�������������悤
	//�m�F�p���s�f�[�^�͐����L�[�������Ƃ��ꂼ��̖��̎������m�F�ł���
	static int num = 0;
	auto input = Input::GetInstance();
	for (int i = 1; i <= 9; ++i)
	{
		if (input->GetKeyDown('0' + i))
		{
			num = i;
			Reset();
			break;
		}
	}
	switch (num)
	{
		case 1:
			//���1
			//�L�����N�^�[�摜��1�s1��ڂ̉ӏ���UV��؂蔲���ĕ`�悵�悤
			// ����
			plPos[0].x = 0.0f / 1024.0f;
			plPos[0].y = 256.0f / 1024.0f;
			// ����
			plPos[1].x = 0.0f / 1024.0f;
			plPos[1].y = 0.0f / 1024.0f;
			// �E��
			plPos[2].x = 256.0f / 1024.0f;
			plPos[2].y = 256.0f / 1024.0f;
			// �E��
			plPos[3].x = 256.0f / 1024.0f;
			plPos[3].y = 0.0f / 1024.0f;
			gameObj.SetUV(plPos);
			break;
		case 2:
			//���2
			//�L�����N�^�[�摜��1�s�ڂ�p���ăA�C�h�����O��ԁi�R�}�A�j���[�V�����j��`�悵�悤
			//���A�j���[�V�����̕b���Ɏw��͂Ȃ�
			animPLTimer += 0.225f;
			if (animPLTimer > 1)
			{
				animPLTimer = 0;
				movePLPos.x += 256.0f;
			}
			// ����
			plPos[0].x = movePLPos.x / 1024.0f;
			plPos[0].y = 256.0f / 1024.0f;
			// ����
			plPos[1].x = movePLPos.x / 1024.0f;
			plPos[1].y = 0.0f / 1024.0f;
			// �E��
			plPos[2].x = (movePLPos.x + 256.0f) / 1024.0f;
			plPos[2].y = 256.0f / 1024.0f;
			// �E��
			plPos[3].x = (movePLPos.x + 256.0f) / 1024.0f;
			plPos[3].y = 0.0f / 1024.0f;
			gameObj.SetUV(plPos);
			break;
		case 3:
			//���3
			//���E�L�[�̓��͂ɉ����ĉ摜��2�s�ځA3�s�ڂ�p���ăL�����N�^�[�̌X���A�j���[�V������`�悵�悤
			animPLTimer += 0.225f;
			if (animPLTimer > 1)
			{
				animPLTimer = 0;
				movePLPos.x += 256.0f;
			}

			if (input->GetKey('A') || input->GetKey(VK_LEFT)) movePLPos.y = 256.0f * 2;
			if (input->GetKey('D') || input->GetKey(VK_RIGHT)) movePLPos.y = 256.0f;
			if (!input->GetKey('A') && !input->GetKey(VK_LEFT) && 
				!input->GetKey('D') && !input->GetKey(VK_RIGHT))movePLPos.y = 0.0f;

			// ����
			plPos[0].x = movePLPos.x / 1024.0f;
			plPos[0].y = (movePLPos.y + 256.0f) / 1024.0f;
			// ����
			plPos[1].x = movePLPos.x / 1024.0f;
			plPos[1].y = movePLPos.y / 1024.0f;
			// �E��
			plPos[2].x = (movePLPos.x + 256.0f) / 1024.0f;
			plPos[2].y = (movePLPos.y + 256.0f) / 1024.0f;
			// �E��
			plPos[3].x = (movePLPos.x + 256.0f) / 1024.0f;
			plPos[3].y = movePLPos.y / 1024.0f;
			gameObj.SetUV(plPos);
			break;
		case 4:
			//���4
			//�㉺���E�L�[�̓��͂ɉ����ăL�����N�^�[�̃A�j���[�V�����ƈړ����������悤
			animPLTimer += 0.225f;
			if (animPLTimer > 1)
			{
				animPLTimer = 0;
				movePLPos.x += 256.0f;
			}

			if (input->GetKey('A') || input->GetKey(VK_LEFT)) movePLPos.y = 256.0f * 2;
			if (input->GetKey('D') || input->GetKey(VK_RIGHT)) movePLPos.y = 256.0f;
			if (!input->GetKey('A') && !input->GetKey(VK_LEFT) &&
				!input->GetKey('D') && !input->GetKey(VK_RIGHT))movePLPos.y = 0.0f;

			// ����
			plPos[0].x = movePLPos.x / 1024.0f;
			plPos[0].y = (movePLPos.y + 256.0f) / 1024.0f;
			// ����
			plPos[1].x = movePLPos.x / 1024.0f;
			plPos[1].y = movePLPos.y / 1024.0f;
			// �E��
			plPos[2].x = (movePLPos.x + 256.0f) / 1024.0f;
			plPos[2].y = (movePLPos.y + 256.0f) / 1024.0f;
			// �E��
			plPos[3].x = (movePLPos.x + 256.0f) / 1024.0f;
			plPos[3].y = movePLPos.y / 1024.0f;
			gameObj.SetUV(plPos);

			if (input->GetKey('W') || input->GetKey(VK_UP))  PlayPos.y += 1.0f * 0.1f;
			if (input->GetKey('A') || input->GetKey(VK_LEFT)) PlayPos.x += -1.0f * 0.1f;
			if (input->GetKey('D') || input->GetKey(VK_RIGHT)) PlayPos.x += 1.0f * 0.1f;
			if (input->GetKey('S') || input->GetKey(VK_DOWN)) PlayPos.y += -1.0f * 0.1f;
			gameMatrix.SetPos(PlayPos);
			break;
		case 5:
			//���5
			//�w�i�摜��`�悵�悤
			bgActive = true;
			bgScale = XMFLOAT3(7.5f, 4.5f, 1.0f);
			backMatrix.SetScale(bgScale);
			// ����
			plPos[0].x = 0.0f / 1024.0f;
			plPos[0].y = 256.0f / 1024.0f;
			// ����
			plPos[1].x = 0.0f / 1024.0f;
			plPos[1].y = 0.0f / 1024.0f;
			// �E��
			plPos[2].x = 256.0f / 1024.0f;
			plPos[2].y = 256.0f / 1024.0f;
			// �E��
			plPos[3].x = 256.0f / 1024.0f;
			plPos[3].y = 0.0f / 1024.0f;
			gameObj.SetUV(plPos);
			break;
		case 6:
			//���6
			//�w�i�摜���c�X�N���[�����悤
			bgActive = true;
			bgScale = XMFLOAT3(7.5f, 4.5f, 1.0f);
			backMatrix.SetScale(bgScale);

			animPLTimer += 0.225f;
			if (animPLTimer > 1)
			{
				animPLTimer = 0;
				movePLPos.x += 256.0f;
			}

			if (input->GetKey('A') || input->GetKey(VK_LEFT)) movePLPos.y = 256.0f * 2;
			if (input->GetKey('D') || input->GetKey(VK_RIGHT)) movePLPos.y = 256.0f;
			if (!input->GetKey('A') && !input->GetKey(VK_LEFT) &&
				!input->GetKey('D') && !input->GetKey(VK_RIGHT))movePLPos.y = 0.0f;

			// ����
			plPos[0].x = movePLPos.x / 1024.0f;
			plPos[0].y = (movePLPos.y + 256.0f) / 1024.0f;
			// ����
			plPos[1].x = movePLPos.x / 1024.0f;
			plPos[1].y = movePLPos.y / 1024.0f;
			// �E��
			plPos[2].x = (movePLPos.x + 256.0f) / 1024.0f;
			plPos[2].y = (movePLPos.y + 256.0f) / 1024.0f;
			// �E��
			plPos[3].x = (movePLPos.x + 256.0f) / 1024.0f;
			plPos[3].y = movePLPos.y / 1024.0f;
			gameObj.SetUV(plPos);

			if (input->GetKey('W') || input->GetKey(VK_UP))  PlayPos.y += 1.0f * 0.1f;
			if (input->GetKey('A') || input->GetKey(VK_LEFT)) PlayPos.x += -1.0f * 0.1f;
			if (input->GetKey('D') || input->GetKey(VK_RIGHT)) PlayPos.x += 1.0f * 0.1f;
			if (input->GetKey('S') || input->GetKey(VK_DOWN)) PlayPos.y += -1.0f * 0.1f;
			gameMatrix.SetPos(PlayPos);

			// �w�i
			animBGTimer += 0.225f;
			if (animBGTimer > 1)
			{
				animBGTimer = 0;
				moveBGPos.y -= 0.02f;
			}

			// ����
			bgPos[0].x = 0.0f / 1024.0f;
			bgPos[0].y = (1024.0f / 1024.0f) + moveBGPos.y;
			// ����
			bgPos[1].x = 0.0f / 1024.0f;
			bgPos[1].y = (0.0f / 1024.0f) + moveBGPos.y;
			// �E��
			bgPos[2].x = 1024.0 / 1024.0f;
			bgPos[2].y = (1024.0f / 1024.0f) + moveBGPos.y;
			// �E��
			bgPos[3].x = 1024.0f / 1024.0f;
			bgPos[3].y = (0.0f / 1024.0f) + moveBGPos.y;

			backObj.SetUV(bgPos);
			break;
		case 7:
			//���7
			//�e���΂��������������悤

			bgActive = true;
			bgScale = XMFLOAT3(7.5f, 4.5f, 1.0f);
			backMatrix.SetScale(bgScale);

			animPLTimer += 0.225f;
			if (animPLTimer > 1)
			{
				animPLTimer = 0;
				movePLPos.x += 256.0f;
			}

			if (input->GetKey('A') || input->GetKey(VK_LEFT)) movePLPos.y = 256.0f * 2;
			if (input->GetKey('D') || input->GetKey(VK_RIGHT)) movePLPos.y = 256.0f;
			if (!input->GetKey('A') && !input->GetKey(VK_LEFT) &&
				!input->GetKey('D') && !input->GetKey(VK_RIGHT))movePLPos.y = 0.0f;

			// ����
			plPos[0].x = movePLPos.x / 1024.0f;
			plPos[0].y = (movePLPos.y + 256.0f) / 1024.0f;
			// ����
			plPos[1].x = movePLPos.x / 1024.0f;
			plPos[1].y = movePLPos.y / 1024.0f;
			// �E��
			plPos[2].x = (movePLPos.x + 256.0f) / 1024.0f;
			plPos[2].y = (movePLPos.y + 256.0f) / 1024.0f;
			// �E��
			plPos[3].x = (movePLPos.x + 256.0f) / 1024.0f;
			plPos[3].y = movePLPos.y / 1024.0f;
			gameObj.SetUV(plPos);

			if (input->GetKey('W') || input->GetKey(VK_UP))  PlayPos.y += 1.0f * 0.1f;
			if (input->GetKey('A') || input->GetKey(VK_LEFT)) PlayPos.x += -1.0f * 0.1f;
			if (input->GetKey('D') || input->GetKey(VK_RIGHT)) PlayPos.x += 1.0f * 0.1f;
			if (input->GetKey('S') || input->GetKey(VK_DOWN)) PlayPos.y += -1.0f * 0.1f;
			gameMatrix.SetPos(PlayPos);

			// �w�i
			animBGTimer += 0.225f;
			if (animBGTimer > 1)
			{
				animBGTimer = 0;
				moveBGPos.y -= 0.02f;
			}

			// ����
			bgPos[0].x = 0.0f / 1024.0f;
			bgPos[0].y = (1024.0f / 1024.0f) + moveBGPos.y;
			// ����
			bgPos[1].x = 0.0f / 1024.0f;
			bgPos[1].y = (0.0f / 1024.0f) + moveBGPos.y;
			// �E��
			bgPos[2].x = 1024.0 / 1024.0f;
			bgPos[2].y = (1024.0f / 1024.0f) + moveBGPos.y;
			// �E��
			bgPos[3].x = 1024.0f / 1024.0f;
			bgPos[3].y = (0.0f / 1024.0f) + moveBGPos.y;

			backObj.SetUV(bgPos);

			// �e
			shotTimer += 0.02f;
			if (input->GetKey(VK_SPACE) && shotTimer >= SHOT_INTERVAL)
			{
				shotTimer = 0;
				for (int i = 0; i < MAX_LENGHT; i++)
				{
					if (!shotAlives[i])
					{
						shotAlives[i] = true;
						ShotPos[i] = PlayPos;
						break;
					}
				}
			}
			for (int i = 0; i < MAX_LENGHT; i++)
			{
				shotMatrix[i].Identity();

				if (shotAlives[i])
				{
					// ����
					shPos[0].x = 0 / 1024.0f;
					shPos[0].y = 1040.0f / 1024.0f;
					// ����
					shPos[1].x = 0 / 1024.0f;
					shPos[1].y = 0 / 1024.0f;
					// �E��
					shPos[2].x = 240.0f / 1024.0f;
					shPos[2].y = 1040.0f / 1024.0f;
					// �E��
					shPos[3].x = 240.0f / 1024.0f;
					shPos[3].y = 0 / 1024.0f;
					shotObj.SetUV(shPos);

					shotMatrix[i].SetScale(shotScale);

					ShotPos[i].y += 0.02f;

					if (ShotPos[i].y > 4.5f)
					{
						shotAlives[i] = false;
					}
				}
				shotMatrix[i].SetPos(ShotPos[i]);
			}
			break;
		case 8:
			//���8
			//�e�̃A�j���[�V�������������悤
			bgActive = true;
			bgScale = XMFLOAT3(7.5f, 4.5f, 1.0f);
			backMatrix.SetScale(bgScale);

			animPLTimer += 0.225f;
			if (animPLTimer > 1)
			{
				animPLTimer = 0;
				movePLPos.x += 256.0f;
			}

			if (input->GetKey('A') || input->GetKey(VK_LEFT)) movePLPos.y = 256.0f * 2;
			if (input->GetKey('D') || input->GetKey(VK_RIGHT)) movePLPos.y = 256.0f;
			if (!input->GetKey('A') && !input->GetKey(VK_LEFT) &&
				!input->GetKey('D') && !input->GetKey(VK_RIGHT))movePLPos.y = 0.0f;

			// ����
			plPos[0].x = movePLPos.x / 1024.0f;
			plPos[0].y = (movePLPos.y + 256.0f) / 1024.0f;
			// ����
			plPos[1].x = movePLPos.x / 1024.0f;
			plPos[1].y = movePLPos.y / 1024.0f;
			// �E��
			plPos[2].x = (movePLPos.x + 256.0f) / 1024.0f;
			plPos[2].y = (movePLPos.y + 256.0f) / 1024.0f;
			// �E��
			plPos[3].x = (movePLPos.x + 256.0f) / 1024.0f;
			plPos[3].y = movePLPos.y / 1024.0f;
			gameObj.SetUV(plPos);

			if (input->GetKey('W') || input->GetKey(VK_UP))  PlayPos.y += 1.0f * 0.1f;
			if (input->GetKey('A') || input->GetKey(VK_LEFT)) PlayPos.x += -1.0f * 0.1f;
			if (input->GetKey('D') || input->GetKey(VK_RIGHT)) PlayPos.x += 1.0f * 0.1f;
			if (input->GetKey('S') || input->GetKey(VK_DOWN)) PlayPos.y += -1.0f * 0.1f;
			gameMatrix.SetPos(PlayPos);

			// �w�i
			animBGTimer += 0.225f;
			if (animBGTimer > 1)
			{
				animBGTimer = 0;
				moveBGPos.y -= 0.02f;
			}

			// ����
			bgPos[0].x = 0.0f / 1024.0f;
			bgPos[0].y = (1024.0f / 1024.0f) + moveBGPos.y;
			// ����
			bgPos[1].x = 0.0f / 1024.0f;
			bgPos[1].y = (0.0f / 1024.0f) + moveBGPos.y;
			// �E��
			bgPos[2].x = 1024.0 / 1024.0f;
			bgPos[2].y = (1024.0f / 1024.0f) + moveBGPos.y;
			// �E��
			bgPos[3].x = 1024.0f / 1024.0f;
			bgPos[3].y = (0.0f / 1024.0f) + moveBGPos.y;

			backObj.SetUV(bgPos);

			// �e
			shotTimer += 0.02f;
			if (input->GetKey(VK_SPACE) && shotTimer >= SHOT_INTERVAL)
			{
				shotTimer = 0;
				for (int i = 0; i < MAX_LENGHT; i++)
				{
					if (!shotAlives[i])
					{
						shotAlives[i] = true;
						ShotPos[i] = PlayPos;
						break;
					}
				}
			}
			for (int i = 0; i < MAX_LENGHT; i++)
			{
				shotMatrix[i].Identity();
				shotMatrix[i].SetScale(shotScale);

				if (shotAlives[i])
				{
					animSHTimer += 0.255f;
					if (animSHTimer >= 0.5f)
					{
						animSHTimer = 0;
						moveSHPos.y += 1040.0f;
					}
						
					// ����
					shPos[0].x = moveSHPos.x / 1024.0f;
					shPos[0].y = (moveSHPos.y + 1040.0f) / 1024.0f;
					// ����
					shPos[1].x = moveSHPos.x / 1024.0f;
					shPos[1].y = moveSHPos.y / 1024.0f;
					// �E��
					shPos[2].x = (moveSHPos.x + 240.0f) / 1024.0f;
					shPos[2].y = (moveSHPos.y + 1040.0f) / 1024.0f;
					// �E��
					shPos[3].x = (moveSHPos.x + 240.0f) / 1024.0f;
					shPos[3].y = moveSHPos.y / 1024.0f;
					shotObj.SetUV(shPos);


					ShotPos[i].y += 0.02f;

					if (ShotPos[i].y > 4.5f)
					{
						shotAlives[i] = false;
					}
				}
				shotMatrix[i].SetPos(ShotPos[i]);
			}

			break;
	}


	// �V�[���ǂݍ���
	if (Input::GetInstance()->GetKeyDown(VK_RETURN))
	{
	}
	return rt;
}

void GameScene::Render()
{
	// RenderBegin�̑�1�����`��3�������w�i��RGB
	App::GetInstance()->RenderBegin(0.2f, 0.2f, 0.2f, 1.0f);
	
	for (int i = 0; i < MAX_LENGHT; ++i)
	{
		if (shotAlives[i])
		{
			shotObj.Render(shotMatrix[i].GetCB(), Texture::GetInstance()->GetTextureResource(shotTexId));
		}
	}

	gameObj.Render(gameMatrix.GetCB(), Texture::GetInstance()->GetTextureResource(charTexId));

	if(bgActive)	backObj.Render(backMatrix.GetCB(), Texture::GetInstance()->GetTextureResource(backTexId));

	App::GetInstance()->RenderEnd();
}

void GameScene::Term()
{
	Shader::GetInstance()->Term();
}
