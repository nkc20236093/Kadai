#include "Polygon.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>


void CPolygon::Init(ShaderResources* sr)
{
	pSr = sr;
	for (int32_t i = 0; i < 4; i++)
	{
		// ���_�̈ʒu
		vertexList[i].pos.x = i < 2 ? -0.5f : 0.5f;
		vertexList[i].pos.y = i % 2 == 0 ? -0.5f : 0.5f;
		vertexList[i].pos.z = 0.0f;
		// ���_�̐F
		vertexList[i].col.x = 1.0f;
		vertexList[i].col.y = 1.0f;
		vertexList[i].col.z = 1.0f;
		vertexList[i].col.w = 1.0f;
		// uv
		vertexList[i].uv.x = i < 2 ? 0.0f : 1.0f;
		vertexList[i].uv.y = i % 2 == 0 ? 1.0f : 0.0f;
		// normal
		vertexList[i].normal.x = 0.0f;
		vertexList[i].normal.y = 0.0f;
		vertexList[i].normal.z = 1.0f;
	}

	// �o�b�t�@���\�[�X�ɂ��ċL�q
	D3D11_BUFFER_DESC descBuffer;
	// ������
	ZeroMemory(&descBuffer, sizeof(descBuffer));
	// �o�b�t�@�őz�肳��Ă���ǂݍ��݋y�я������݂̕��@������
	descBuffer.Usage = D3D11_USAGE_DEFAULT;
	// �o�b�t�@�̃T�C�Y
	descBuffer.ByteWidth = sizeof(vertex) * 4;
	// �o�b�t�@���ǂ̂悤�ɃO���t�B�b�N�X�p�C�v���C���Ƀo�C���h���邩������
	descBuffer.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	// CPU�̃A�N�Z�X�t���O
	descBuffer.CPUAccessFlags = 0;

	// �T�u���\�[�X�̏������Ɏg�p�����f�[�^���w��
	D3D11_SUBRESOURCE_DATA InitData;
	// ������
	ZeroMemory(&InitData, sizeof(InitData));
	// �������f�[�^�ւ̃|�C���^
	InitData.pSysMem = vertexList;
	// �e�N�X�`���ɂ���1�{�̐��̐�[����ׂ̐��܂ł̋���
	InitData.SysMemPitch = 0;
	// 3D�e�N�X�`���Ɋ֘A����l
	InitData.SysMemSlicePitch = 0;
	// �o�b�t�@�̍쐬
	App::GetInstance()->GetDevice().Get()->CreateBuffer(
		// �o�b�t�@�̋L�q�ւ̃|�C���^
		&descBuffer,
		// �������f�[�^�ւ̃|�C���^
		&InitData,
		// �쐬�����o�b�t�@�ւ̃|�C���^�̃A�h���X
		pSr->pVertexBuffer.GetAddressOf()
	);
}

void CPolygon::Render(ConstantBuffer cb, TextureResources* tex)
{
	// ���[���h���W�s���]�u
	constantBuffer.world = DirectX::XMMatrixTranspose(cb.world);
	// �r���[���W�s���]�u
	constantBuffer.view = DirectX::XMMatrixTranspose(cb.view);
	// �v���W�F�N�V�������W�s���]�u
	constantBuffer.projection = DirectX::XMMatrixTranspose(cb.projection);
	// �f�[�^���R�s�[����ConstantBuffer�̓��e������������i�X�V����j
	App::GetInstance()->GetDeviceContext()->UpdateSubresource(App::GetInstance()->GetConstantBuffer().Get(), 0, nullptr, &constantBuffer, 0, 0);


	// �T�u���\�[�X�̍X�V
	App::GetInstance()->GetDeviceContext()->UpdateSubresource(
		pSr->pVertexBuffer.Get(),
		0,
		nullptr,
		vertexList,
		0,
		0
	);
	// ���̓A�Z���u���X�e�[�W�ɓ��̓��C�A�E�g�I�u�W�F�N�g���o�C���h
	App::GetInstance()->GetDeviceContext()->IASetInputLayout(pSr->pVertexLayout.Get());
	// ���̓A�Z���u���X�e�[�W�ɒ��_�o�b�t�@�̔z����o�C���h
	UINT strides = sizeof(vertex);
	UINT offsets = 0;
	App::GetInstance()->GetDeviceContext()->IASetVertexBuffers(
		0,					// �o�C���h�Ɏg�p����ŏ��̓��̓X���b�g
		1,					// �z����̒��_�o�b�t�@�̐�
		pSr->pVertexBuffer.GetAddressOf(),	// ���_�o�b�t�@�̔z��ւ̃|�C���^
		&strides,			// �X�g���C�h�l
		&offsets			// �I�t�Z�b�g�l
	);
	// ���_�V�F�[�_���f�o�C�X�ɐݒ�
	App::GetInstance()->GetDeviceContext()->VSSetShader(
		pSr->pVertexShader.Get(),// ���_�V�F�[�_�ւ̃|�C���^
		nullptr,			// �N���X�C���X�^���X�C���^�[�t�F�C�X�̔z��ւ̃|�C���^
		0					// �z��̃N���X�C���X�^���X�C���^�[�t�F�C�X�̐�
	);
	// ���_�V�F�[�_�̃p�C�v���C���X�e�[�W�Ŏg�p�����萔�o�b�t�@��ݒ�
	App::GetInstance()->GetDeviceContext()->VSSetConstantBuffers(
		0,					// �f�o�C�X�̔z��̒��Œ萔�o�b�t�@�̐ݒ���J�n����ʒu
		1,					// �ݒ肷��o�b�t�@�̐�
		App::GetInstance()->GetConstantBuffer().GetAddressOf()	// �f�o�C�X�ɐݒ肷��萔�o�b�t�@�̔z��
	);

	// �s�N�Z���V�F�[�_���f�o�C�X�ɐݒ�
	App::GetInstance()->GetDeviceContext()->PSSetShader(
		pSr->pPixelShader.Get(),// �s�N�Z���V�F�[�_�ւ̃|�C���^
		nullptr, 				// �N���X�C���X�^���X�C���^�[�t�F�C�X�̔z��ւ̃|�C���^
		0						// �z��̃N���X�C���X�^���X�C���^�[�t�F�C�X�̐�
	);
	//�e�N�X�`���[���V�F�[�_�[�ɓn��
	App::GetInstance()->GetDeviceContext()->PSSetSamplers(
		0,
		1,
		tex->pSampler.GetAddressOf()
	);
	App::GetInstance()->GetDeviceContext()->PSSetShaderResources(
		0,
		1,
		tex->pTexture.GetAddressOf()
	);
	// ���̓A�Z���u���X�e�[�W�Ƀv���~�e�B�u�̌`����o�C���h
	App::GetInstance()->GetDeviceContext()->IASetPrimitiveTopology(
		// ���_�f�[�^���O�p�`�̃��X�g�Ƃ��ĉ���
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP
		// �����̎O�p�`���o�������Ƃ���TRIANGLESTRIP�ɂ���ƒ��_��ߖ�ł���
	);
	// �v���~�e�B�u��`��
	App::GetInstance()->GetDeviceContext()->Draw(
		4,		// �`�悷�钸�_�̐�
		0		// �ŏ��̒��_�̃C���f�b�N�X
	);

}

void CPolygon::Term()
{
}

void CPolygon::SetColor(float r, float g, float b, float a, int32_t v)
{
	vertexList[v].col.x = r;
	vertexList[v].col.y = g;
	vertexList[v].col.z = b;
	vertexList[v].col.w = a;
}


void CPolygon::SetUV(float cx, float cy, float nx, float ny)
{
	float w, h;
	// �c�����w�肵�����ɕ�������
	w = 1.0f / cx;
	h = 1.0f / cy;

	vertexList[0].uv.x = w * nx;
	vertexList[0].uv.y = h * (ny + 1);

	vertexList[1].uv.x = w * nx;
	vertexList[1].uv.y = h * ny;

	vertexList[2].uv.x = w * (nx + 1);
	vertexList[2].uv.y = h * (ny + 1);

	vertexList[3].uv.x = w * (nx + 1);
	vertexList[3].uv.y = h * ny;
}
