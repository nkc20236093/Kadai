#pragma once
#include <D3D11.h>			// DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <d3dcompiler.h>	// �V�F�[�_�[�t�@�C�����R���p�C�����邽�߂ɕK�v
#include <string>
#include <wrl/client.h>		// DirectX�̃X�}�[�g�|�C���^
#include <vector>

#pragma comment(lib, "d3d11.lib")		// DirectX11���C�u�����𗘗p���邽�߂ɕK�v
#pragma comment(lib, "d3dCompiler.lib")	// �V�F�[�_�[�R�[�h���R���p�C�����邽�߂ɕK�v

struct ShaderResources
{
	Microsoft::WRL::ComPtr<ID3D11InputLayout> pVertexLayout = nullptr;		// ���_�f�[�^�̍\�����`
	Microsoft::WRL::ComPtr<ID3D11Buffer> pVertexBuffer = nullptr;			// ���_�f�[�^��ۑ�
	Microsoft::WRL::ComPtr<ID3D11VertexShader> pVertexShader = nullptr;		// ���_�V�F�[�_
	Microsoft::WRL::ComPtr<ID3D11PixelShader> pPixelShader = nullptr;		// �s�N�Z���V�F�[�_
};

class Shader
{
public:
	static Shader* GetInstance()
	{
		static Shader instance;
		return &instance;
	}
	void Term();
	int32_t LoadShader(const std::string& vs, const std::string& ps);
	ShaderResources* GetShader(int32_t num = 0);
private:
	Shader() :cnt(0), CsoSize(0), pCsoBin(nullptr) {};
	~Shader() {};
	int32_t CreateVS(const std::string& vsStr, int32_t n);	// ���_�V�F�[�_�쐬
	int32_t CreatePS(const std::string& psStr, int32_t n);	// �s�N�Z���V�F�[�_�쐬
	std::vector<ShaderResources> pSr;
	int32_t cnt;
	int32_t CsoSize;
	uint8_t* pCsoBin;

	HRESULT CompileShaderFromFile(LPCWSTR szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
	void    ReadCSOFile(LPCWSTR szFileName);

};