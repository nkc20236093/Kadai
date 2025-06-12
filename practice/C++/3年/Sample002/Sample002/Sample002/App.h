#pragma once

#include <Windows.h>		// Windows�v���O�����ŕK�v�ɂȂ���̂������Ă���
#include <D3D11.h>			// DirectX11SDK���g�����߂ɕK�v�Ȃ���
#include <d3dcompiler.h>	// �V�F�[�_�[�t�@�C�����R���p�C�����邽�߂ɕK�v
#include <directxcolors.h>	// DirectX::���C�u�����𗘗p���邽�߂ɕK�v
#include <wrl/client.h>		// DirectX�̃X�}�[�g�|�C���^

#pragma comment(lib, "d3d11.lib")		// DirectX11���C�u�����𗘗p���邽�߂ɕK�v
#pragma comment(lib, "d3dCompiler.lib")	// �V�F�[�_�[�R�[�h���R���p�C�����邽�߂ɕK�v


constexpr auto WINDOW_TITLE = L"DirectXSample";	// �E�B���h�E�^�C�g��
constexpr auto CLASS_NAME = L"DIRECTXSAMPLE";	// �E�B���h�E�N���X��
constexpr int32_t WINDOW_W = 1280;				// �E�B���h�E�T�C�Y��
constexpr int32_t WINDOW_H = 720;				// �E�B���h�E�T�C�Y����
constexpr float MIN_FRAME_TIME = 1.0f / 60.0f;	// FPS

class App
{
public:
	static App* GetInstance()
	{
		static App instance;
		return &instance;
	}
	bool InitApp();			// �����������Ǘ�
	void TermApp();			// �I�������Ǘ�
	void RenderBegin(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f);// �`��J�n
	void RenderEnd();		// �`��I��

	Microsoft::WRL::ComPtr<ID3D11Device> GetDevice() {return pDevice;}
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> GetDeviceContext() {return pImmediateContext;}
	Microsoft::WRL::ComPtr<ID3D11Buffer> GetConstantBuffer() {return pConstantBuffer;}

private:
	App();					// �R���X�g���N�^
	~App();					// �f�X�g���N�^

	HWND hWnd;				// �E�B���h�E�n���h��
	HINSTANCE hInstance;	// �C���X�^���X�n���h��

	Microsoft::WRL::ComPtr<ID3D11Device> pDevice = nullptr;						// �f�o�C�X
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> pImmediateContext = nullptr;	// �f�o�C�X�R���e�L�X�g
	Microsoft::WRL::ComPtr<IDXGISwapChain> pSwapChain = nullptr;				// �X���b�v�`�F�C��
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> pRenderTargetView = nullptr;	// �`�悷�邽�߂̃��\�[�X���쐬���A���ۂ̕`�摀����s��
	Microsoft::WRL::ComPtr<ID3D11Texture2D> pDepthStencil = nullptr;			// �[�x/�X�e���V�����\�[�X�Ƃ��Ďg�p����
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> pDepthStencilView = nullptr;	// �[�x/�X�e���V�����\�[�X�ɃA�N�Z�X����
	Microsoft::WRL::ComPtr<ID3D11BlendState> pBlendState = nullptr;				// �A���t�@�u�����f�B���O
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> pRasterizerState = nullptr;	// ���X�^���C�U
	Microsoft::WRL::ComPtr<ID3D11Buffer> pConstantBuffer = nullptr;				// ���W�n�f�[�^��ۑ�

	bool InitWnd();			// �E�B���h�E������
	void TermWnd();			// �E�B���h�E�I��
	bool InitD3D();			// D3D�f�o�C�X������
	void TermD3D();			// D3D�f�o�C�X�I��

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};