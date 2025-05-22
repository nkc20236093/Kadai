#include <fstream>
#include "Shader.h"
#include "App.h"


D3D11_INPUT_ELEMENT_DESC vertexDesc[]
{
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,		 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "NORMAL",	  0, DXGI_FORMAT_R32G32B32_FLOAT,	 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
};

void Shader::Term()
{
	// �v�f�ԍ�1�ȍ~�̃f�[�^��S�����Z�b�g
	for (auto sr = pSr.begin() + 1; sr != pSr.end(); ++sr)
	{
		sr->pVertexLayout.Reset();
		sr->pVertexBuffer.Reset();
		sr->pVertexShader.Reset();
		sr->pPixelShader.Reset();
	}
	cnt = 1;
}

int32_t Shader::LoadShader(const std::string& vs, const std::string& ps)
{
	pSr.emplace_back();
	CreateVS(vs, cnt);
	CreatePS(ps, cnt);
	return cnt++;
}

ShaderResources* Shader::GetShader(int32_t num)
{
	return &pSr[num];
}

// ���_�V�F�[�_�쐬
int32_t Shader::CreateVS(const std::string& vsStr, int32_t n)
{

	// ����������ɍs��ꂽ�����f����ׂɗp��
	HRESULT hr = S_OK;
	// �t�@�C���̊g���q���擾����
	size_t num = vsStr.find_last_of('.');
	std::string extension = vsStr.substr(num + 1);
	// string����const wchar_t�ɕϊ�����
	wchar_t* vs = new wchar_t[vsStr.length() + 1];
	size_t value = 0;
	mbstowcs_s(&value, vs, 20, vsStr.c_str(), vsStr.length() + 1);


	// �ǂݍ��ފg���q��hlsl?
	if (extension == "hlsl")
	{
		Microsoft::WRL::ComPtr<ID3DBlob> pVSBlob = nullptr;	// �I�u�W�F�N�g�R�[�h�ƃG���[���b�Z�[�W��Ԃ�
												
		// �V�F�[�_�[�t�@�C���ǂݍ���
		hr = CompileShaderFromFile(
			vs,						// �t�@�C���p�X
			"main",					// �G���g���[�|�C���g�̖��O
			"vs_5_0",				// �V�F�[�_�[�̃o�[�W����
			pVSBlob.GetAddressOf()	// �ۑ�����ϐ� 
		);
		if (FAILED(hr))	return false;	// �G���[�`�F�b�N

		// ���_�V�F�[�_�̍쐬
		hr = App::GetInstance()->GetDevice().Get()->CreateVertexShader(
			pVSBlob.Get()->GetBufferPointer(),	// �R���p�C���ς݃V�F�[�_�ւ̃|�C���^
			pVSBlob.Get()->GetBufferSize(),		// �R���p�C���ς݃V�F�[�_�̃T�C�Y
			nullptr,							// �N���X�����N�C���^�[�t�F�C�X�ւ̃|�C���^
			pSr[n].pVertexShader.GetAddressOf()	// ID3D11VertexShader�C���^�[�t�F�C�X�ւ̃|�C���^�̃A�h���X
		);
		if (FAILED(hr))	return false;	// �G���[�`�F�b�N

		// �C���v�b�g���C�A�E�g�̍쐬
		hr = App::GetInstance()->GetDevice().Get()->CreateInputLayout(
			vertexDesc,							// ���̓f�[�^�^�̔z��
			ARRAYSIZE(vertexDesc),				// �z����̓��̓f�[�^�^�̐�
			pVSBlob.Get()->GetBufferPointer(),	// �R���p�C���ς݃V�F�[�_�ւ̃|�C���^
			pVSBlob.Get()->GetBufferSize(),		// �R���p�C���ς݃V�F�[�_�̃T�C�Y
			pSr[n].pVertexLayout.GetAddressOf()	// �쐬�������̓��C�A�E�g�I�u�W�F�N�g�ւ̃|�C���^
		);
		pVSBlob.Reset();				// ���		
		if (FAILED(hr))	return false;	// �G���[�`�F�b�N
	}
	// �ǂݍ��ފg���q��cso?
	else if (extension == "cso")
	{
		ReadCSOFile(vs);

		// ���_�V�F�[�_�̍쐬
		hr = App::GetInstance()->GetDevice().Get()->CreateVertexShader(
			pCsoBin,							// �R���p�C���ς݃V�F�[�_�ւ̃|�C���^
			CsoSize,							// �R���p�C���ς݃V�F�[�_�̃T�C�Y
			nullptr,							// �N���X�����N�C���^�[�t�F�C�X�ւ̃|�C���^
			pSr[n].pVertexShader.GetAddressOf()	// ID3D11VertexShader�C���^�[�t�F�C�X�ւ̃|�C���^�̃A�h���X
		);
		if (FAILED(hr))	return false;	// �G���[�`�F�b�N

		// �C���v�b�g���C�A�E�g�̍쐬
		hr = App::GetInstance()->GetDevice().Get()->CreateInputLayout(
			vertexDesc,							// ���̓f�[�^�^�̔z��
			ARRAYSIZE(vertexDesc),				// �z����̓��̓f�[�^�^�̐�
			pCsoBin,							// �R���p�C���ς݃V�F�[�_�ւ̃|�C���^
			CsoSize,							// �R���p�C���ς݃V�F�[�_�̃T�C�Y
			pSr[n].pVertexLayout.GetAddressOf()	// �쐬�������̓��C�A�E�g�I�u�W�F�N�g�ւ̃|�C���^
		);
		if (FAILED(hr))	return false;	// �G���[�`�F�b�N
	}
	return true;
}

// �s�N�Z���V�F�[�_�쐬
int32_t Shader::CreatePS(const std::string& psStr, int32_t n)
{
	// ����������ɍs��ꂽ�����f����ׂɗp��
	HRESULT hr = S_OK;
	// �t�@�C���̊g���q���擾����
	size_t num = psStr.find_last_of('.');
	std::string extension = psStr.substr(num + 1);
	// string����const wchar_t�ɕϊ�����
	wchar_t* ps = new wchar_t[psStr.length() + 1];
	size_t value = 0;
	mbstowcs_s(&value, ps, 20, psStr.c_str(), psStr.length() + 1);


	// �ǂݍ��ފg���q��hlsl?
	if (extension == "hlsl")
	{
		Microsoft::WRL::ComPtr<ID3DBlob> pPSBlob = nullptr;	// �I�u�W�F�N�g�R�[�h�ƃG���[���b�Z�[�W��Ԃ�

		// �V�F�[�_�[�t�@�C���ǂݍ���
		hr = CompileShaderFromFile(
			ps,						// �t�@�C���p�X
			"main",					// �G���g���[�|�C���g�̖��O
			"ps_5_0",				// �V�F�[�_�[�̃o�[�W����
			pPSBlob.GetAddressOf()	// �ۑ�����ϐ� 
		);
		if (FAILED(hr))	return false;	// �G���[�`�F�b�N

		// �s�N�Z���V�F�[�_�̍쐬
		hr = App::GetInstance()->GetDevice().Get()->CreatePixelShader(
			pPSBlob.Get()->GetBufferPointer(),	// �R���p�C���ς݃V�F�[�_�ւ̃|�C���^
			pPSBlob.Get()->GetBufferSize(),		// �R���p�C���ς݃V�F�[�_�̃T�C�Y
			nullptr,							// �N���X�����N�C���^�[�t�F�C�X�ւ̃|�C���^
			pSr[n].pPixelShader.GetAddressOf()	// ID3D11PixelShader�C���^�[�t�F�C�X�ւ̃|�C���^�̃A�h���X
		);
		pPSBlob.Reset();				// ���		
		if (FAILED(hr))	return false;	// �G���[�`�F�b�N
	}
	// �ǂݍ��ފg���q��cso?
	else if (extension == "cso")
	{
		ReadCSOFile(ps);

		// �s�N�Z���V�F�[�_�̍쐬
		hr = App::GetInstance()->GetDevice().Get()->CreatePixelShader(
			pCsoBin,						// �R���p�C���ς݃V�F�[�_�ւ̃|�C���^
			CsoSize,						// �R���p�C���ς݃V�F�[�_�̃T�C�Y
			nullptr,						// �N���X�����N�C���^�[�t�F�C�X�ւ̃|�C���^
			pSr[n].pPixelShader.GetAddressOf()// ID3D11PixelShader�C���^�[�t�F�C�X�ւ̃|�C���^�̃A�h���X
		);
		if (FAILED(hr))	return false;	// �G���[�`�F�b�N
	}
	return true;
}

// �V�F�[�_�[�t�@�C���ǂݍ���
HRESULT Shader::CompileShaderFromFile(LPCWSTR szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut)
{
	HRESULT hr = S_OK;

	// �R���p�C����HLSL�R�[�h���R���p�C��������@���w��
	DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;// �����ȃR���p�C��������
#ifdef _DEBUG
	dwShaderFlags |= D3DCOMPILE_DEBUG;				// �f�o�b�O�t�@�C��/�s/�^/�V���{�������o�̓R�[�h�ɑ}������悤�ɃR���p�C���Ɏw��

	dwShaderFlags |= D3DCOMPILE_SKIP_OPTIMIZATION;	// �R�[�h�������ɍœK���X�e�b�v���X�L�b�v����悤�ɃR���p�C���Ɏw��
#endif

	Microsoft::WRL::ComPtr<ID3DBlob> pErrorBlob = nullptr;	// �R���p�C����̃o�C�i���f�[�^���擾����
													// �t�@�C������V�F�[�_���R���p�C��
	hr = D3DCompileFromFile(szFileName, nullptr, nullptr, szEntryPoint, szShaderModel,
		dwShaderFlags, 0, ppBlobOut, pErrorBlob.GetAddressOf());

	// �G���[�`�F�b�N
	if (FAILED(hr))
	{
		if (pErrorBlob.Get())
		{
			// ��������f�o�b�K�ɑ���
			OutputDebugStringA(reinterpret_cast<const char*>(pErrorBlob.Get()->GetBufferPointer()));
			pErrorBlob.Reset();
		}
		return hr;
	}
	pErrorBlob.Reset();
	return hr;
}

// CSO�t�@�C����ǂݍ���
void  Shader::ReadCSOFile(LPCWSTR szFileName)
{
	std::ifstream binfile(szFileName, std::ios::in | std::ios::binary);

	if (binfile.is_open()) {
		int32_t fsize = static_cast<int32_t>(binfile.seekg(0, std::ios::end).tellg());
		binfile.seekg(0, std::ios::beg);
		uint8_t* code(new uint8_t[fsize]);
		binfile.read((char*)code, fsize);
		CsoSize = fsize;
		pCsoBin = std::move(code);
	}
}
