#include "ConstantBuffer.h"
#include "App.h"

void ConstantBuffer::Term()
{
	// �f�[�^��S�����Z�b�g
	for (auto cb = pCb.begin(); cb != pCb.end(); ++cb)
	{
		cb->Reset();
	}
	cnt = 0;
}

uint32_t ConstantBuffer::InitCB(uint32_t byteWidth)
{
	D3D11_BUFFER_DESC descCBuffer;
	// ������
	ZeroMemory(&descCBuffer, sizeof(descCBuffer));
	// �o�b�t�@�őz�肳��Ă���ǂݍ��݋y�я������݂̕��@������
	descCBuffer.Usage = D3D11_USAGE_DEFAULT;
	// �o�b�t�@�̃T�C�Y
	descCBuffer.ByteWidth = byteWidth;
	// �o�b�t�@���ǂ̂悤�ɃO���t�B�b�N�X�p�C�v���C���Ƀo�C���h���邩������
	descCBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	// CPU�̃A�N�Z�X�t���O
	descCBuffer.CPUAccessFlags = 0;

	pCb.emplace_back();
	HRESULT hr;
	// �o�b�t�@�̍쐬
	hr = App::GetInstance()->GetDevice().Get()->CreateBuffer(
		// �o�b�t�@�̋L�q�ւ̃|�C���^
		&descCBuffer,
		// �������f�[�^�ւ̃|�C���^
		nullptr,
		// �쐬�����o�b�t�@�ւ̃|�C���^�̃A�h���X
		pCb[cnt].GetAddressOf()
	);

	return cnt++;
}

Microsoft::WRL::ComPtr<ID3D11Buffer> ConstantBuffer::GetCB(uint32_t num)
{
	return pCb[num].Get();
}

void ConstantBuffer::UpdateCB(uint32_t num, const void* cb)
{
	App::GetInstance()->GetDeviceContext()->UpdateSubresource(pCb[num].Get(), 0, nullptr, cb, 0, 0);
}
