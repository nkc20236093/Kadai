#include <D3D11.h>			// DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <directxcolors.h>	// DirectX::���C�u�����𗘗p���邽�߂ɕK�v
#include "Camera.h"
#include "App.h"

using namespace DirectX;

void Camera::SetViewPort()
{
	{
		// �r���[�|�[�g�̐ݒ�(�`��̈�)-1.0�`1.0�͈̔͂ō��ꂽ���[���h���W���X�N���[�����W�ɕϊ����邽�߂̏��
		viewPort.TopLeftX = 0.0f;		// �r���[�|�[�g�̈�̍���X���W
		viewPort.TopLeftY = 0.0f;		// �r���[�|�[�g�̈�̍���Y���W
		viewPort.Width = WINDOW_W;	// �r���[�|�[�g�̈�̕�
		viewPort.Height = WINDOW_H;	// �r���[�|�[�g�̈�̍���
		viewPort.MinDepth = 0.0f;		// �r���[�|�[�g�̈�̐[�x�l�̍ŏ��l
		viewPort.MaxDepth = 1.0f;		// �r���[�|�[�g�̈�̐[�x�l�̍ő�l

		// ���X�^���C�U�Ƀr���[�|�[�g��ݒ�
		App::GetInstance()->GetDeviceContext().Get()->RSSetViewports(
			1,				// �ݒ肷��r���[�|�[�g�̐�
			&viewPort		// �ݒ肷��D3D11_VIEWPORT�\���̂̔z��
		);
	}
}

void Camera::Update(DirectX::XMMATRIX& view, DirectX::XMMATRIX& proj)
{
	// �J�����̈ʒu
	XMVECTOR e = XMVectorSet(eye.x, eye.y, eye.z, 0.0f);
	// �J�����̏œ_
	XMVECTOR f = XMVectorSet(focus.x, focus.y, focus.z, 0.0f);
	XMStoreFloat4(&cameraLook, XMVector4Normalize(f - e));
	// ���݂̃��[���h���W�ɂ����������̒�`
	XMVECTOR u = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	// �J�����̈ʒu�A������A����яœ_���g�p���āA������W�n�̃r���[�s����쐬
	view = XMMatrixLookAtLH(e, f, u);
	// ����p�̐ݒ�
	float    fov = XMConvertToRadians(45.0f);
	// �A�X�y�N�g��̐ݒ�
	float    aspect = viewPort.Width / viewPort.Height;
	// �j�A�i������͈͂̑O���j�̐ݒ�
	float    nearZ = 0.1f;
	// �t�@�[�i������͈͂̌���j�̐ݒ�
	float    farZ = 1000.0f;
	// ����Ɋ�Â��āA������W�n�̃p�[�X�y�N�e�B�u�ˉe�s����쐬
	proj = XMMatrixPerspectiveFovLH(fov, aspect, nearZ, farZ);

}

void Camera::MoveEye(DirectX::XMFLOAT3& move)
{
	eye.x += move.x;
	eye.y += move.y;
	eye.z += move.z;
}
void Camera::MoveFocus(DirectX::XMFLOAT3& move)
{
	focus.x += move.x;
	focus.y += move.y;
	focus.z += move.z;
}