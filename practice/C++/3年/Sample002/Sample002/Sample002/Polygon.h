#pragma once
#include <tchar.h>			// �e�L�X�g�╶������������߂ɕK�v�ȃw�b�_�[�t�@�C��
#include <Windows.h>		// Windows�v���O�����ŕK�v�ɂȂ���̂������Ă���
#include <D3D11.h>			// DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <d3dcompiler.h>	// �V�F�[�_�[�t�@�C�����R���p�C�����邽�߂ɕK�v
#include <directxcolors.h>	// DirectX::���C�u�����𗘗p���邽�߂ɕK�v
#include <wrl/client.h>		// DirectX�̃X�}�[�g�|�C���^
#include <vector>
#include <string>
#include "App.h"
#include "Shader.h"
#include "Texture.h"
#include "Matrix.h"

#pragma comment(lib, "d3d11.lib")		// DirectX11���C�u�����𗘗p���邽�߂ɕK�v
#pragma comment(lib, "d3dCompiler.lib")	// �V�F�[�_�[�R�[�h���R���p�C�����邽�߂ɕK�v

// ���_�f�[�^�\����
struct vertex
{
	DirectX::XMFLOAT3 pos;		// ���_���W	
	DirectX::XMFLOAT4 col;		// ���_���Ƃ̐F
	DirectX::XMFLOAT2 uv;		// �e�N�X�`�����W
	DirectX::XMFLOAT3 normal;	// �@��
};

class CPolygon
{
private:
	ShaderResources* pSr;
	std::vector<ID3D11ShaderResourceView*> pTextures;

	vertex vertexList[4];
	vertex vertexListEX[4];
	DirectX::XMMATRIX	wld = DirectX::XMMatrixIdentity();
	DirectX::XMFLOAT3	scale = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	DirectX::XMFLOAT3	axis = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	float				angle = 0.0f;
	DirectX::XMFLOAT3	pos = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);

	ConstantBuffer constantBuffer;

public:
	void Init(ShaderResources* sr);
	void Render(ConstantBuffer cb, TextureResources* tex = Texture::GetInstance()->GetTextureResource(0));
	void InitEX(ShaderResources* sr);
	void RenderEX(ConstantBuffer cb, TextureResources* tex = Texture::GetInstance()->GetTextureResource(0));

	void Term();
	void SetColor(float r, float g, float b, float a, int32_t v);
	void SetUV();
};