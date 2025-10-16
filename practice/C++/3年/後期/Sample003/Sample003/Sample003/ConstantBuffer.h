#pragma once
#include <D3D11.h>			// DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <directxcolors.h>	// DirectX::���C�u�����𗘗p���邽�߂ɕK�v
#include <wrl/client.h>		// DirectX�̃X�}�[�g�|�C���^
#include <vector>

#pragma comment(lib, "d3d11.lib")		// DirectX11���C�u�����𗘗p���邽�߂ɕK�v


// �萔�o�b�t�@��`============================================================
template<class T> struct Property {
	T& r;
	operator T() { return r; }
	void operator =(const T v) { r = v; }
};
struct CBList
{
private:
	// �萔�o�b�t�@�𑝂₷�ۂ͂����ɒǉ�����i01/03)
	uint32_t _float4 = 0;
	uint32_t _matrix = 0;
public:
	// �萔�o�b�t�@�𑝂₷�ۂ͂����ɒǉ�����i02/03)
	Property<uint32_t> float4{ _float4 };
	Property<uint32_t> matrix{ _matrix };
};

// �萔�o�b�t�@�𑝂₷�ۂ͂����ɒǉ�����i03/03)
// float4�ŃV�F�[�_�ɑ��肽���p
struct Float4CB
{
	DirectX::XMFLOAT4 float4cb;
};

// ���W�ϊ��\����
struct MatrixCB
{
	DirectX::XMMATRIX world;		// ���[���h�ϊ��s��
	DirectX::XMMATRIX view;			// �r���[�ϊ��s��
	DirectX::XMMATRIX projection;	// �v���W�F�N�V�����ϊ��s��
};


// ----------------------------------------------------------------------------

class ConstantBuffer
{
public:
	static ConstantBuffer* GetInstance()
	{
		static ConstantBuffer instance;
		return &instance;
	}
	void Term();
	uint32_t InitCB(uint32_t byteWidth);
	Microsoft::WRL::ComPtr<ID3D11Buffer> GetCB(uint32_t num);
	CBList GetList() { return list; }
	void UpdateCB(uint32_t num, const void* cb);
private:
	ConstantBuffer() :cnt(0) {};
	~ConstantBuffer() {};
	std::vector<Microsoft::WRL::ComPtr<ID3D11Buffer>> pCb;
	uint32_t cnt;
	CBList list;
};