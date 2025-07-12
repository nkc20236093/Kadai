#include "App.h"
#include "Shader.h"
#include "Texture.h"
#include "Matrix.h"

// �R���X�g���N�^
App::App()
	:hWnd(nullptr)
	,hInstance(nullptr)
{
}

// �f�X�g���N�^
App::~App()
{
}

// �����������Ǘ�
bool App::InitApp()
{
	// �E�B���h�E������
	if (!InitWnd())	return false;

	// D3D�f�o�C�X������
	if (!InitD3D())	return false;

	// �E�B���h�E��\��.
	ShowWindow(hWnd, SW_SHOWNORMAL);

	// �E�B���h�E���X�V.
	UpdateWindow(hWnd);

	// �E�B���h�E�Ƀt�H�[�J�X��ݒ�.
	SetFocus(hWnd);

	// ����I��
	return true;
}

// �I�������Ǘ�
void App::TermApp()
{
	// D3D�f�o�C�X�I��
	TermD3D();

	// �E�B���h�E�I��
	TermWnd();
}

// �`��J�n
void App::RenderBegin(float r, float g, float b, float a)
{
	float color[4] = { r, g, b, a };
	// �w�i�̐F��ݒ� �����_�[�^�[�Q�b�g�N���A
	pImmediateContext.Get()->ClearRenderTargetView(pRenderTargetView.Get(), color);
	// �[�x/�X�e���V���o�b�t�@�N���A
	pImmediateContext.Get()->ClearDepthStencilView(pDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
}

// �`��I��
void App::RenderEnd()
{
	pSwapChain.Get()->Present(0, 0);
}

// �E�B���h�E������
bool App::InitWnd()
{
	// �E�B���h�E�N���X�o�^
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;	// �E�B���h�E�X�^�C��
	wcex.lpfnWndProc = WndProc;				// �E�B���h�E�̃��b�Z�[�W����������R�[���o�b�N�֐��ւ̃|�C���^
	wcex.cbClsExtra = 0;					// �E�B���h�E�N���X�\���̂̌��Ɋ��蓖�Ă�⑫�̃o�C�g��
	wcex.cbWndExtra = 0;					// �E�B���h�E�C���X�^���X�̌��Ɋ��蓖�Ă�⑫�̃o�C�g��
	wcex.hInstance = hInstance;				// ���̃N���X�̂��߂̃E�B���h�E�v���V�[�W��������n���h��
	wcex.hIcon = nullptr;					// �A�C�R��
	wcex.hCursor = nullptr;					// �}�E�X�J�[�\��
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);// �E�B���h�E�w�i�F
	wcex.lpszMenuName = nullptr;			// �f�t�H���g���j���[��
	wcex.lpszClassName = CLASS_NAME;		// �E�B���h�E�N���X��
	wcex.hIconSm = nullptr;					// �������A�C�R��
	RegisterClassEx(&wcex);					// �E�B���h�E�N���X�o�^

	// �E�B���h�E���� �������̓E�B���h�E�n���h���A���s����null���Ԃ�
	hWnd = CreateWindow(
		CLASS_NAME,					// RegisterClass()�œo�^�����N���X�̖��O
		WINDOW_TITLE,				// �^�C�g���o�[
		WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,// �E�B���h�E�X�^�C��
		CW_USEDEFAULT,				// �E�B���h�E����x���W
		CW_USEDEFAULT,				// �E�B���h�E����y���W
		WINDOW_W,						// �E�B���h�E��
		WINDOW_H,						// �E�B���h�E����
		nullptr,					// �e�E�B���h�E�̃n���h��
		nullptr,					// ���j���[�̃n���h��
		wcex.hInstance,				// �E�B���h�E���쐬���郂�W���[���̃n���h��
		nullptr						// WM_CREATE��LPARAM�ɓn�������l
	);

	// ����I��
	return true;
}

// �E�B���h�E�I��
void App::TermWnd()
{	
	// �E�B���h�E�̓o�^������
	if (hInstance != nullptr)
	{
		UnregisterClass(CLASS_NAME, hInstance);
	}

	hInstance = nullptr;
	hWnd = nullptr;
}

// D3D�f�o�C�X������
bool App::InitD3D()
{
	// ����������ɍs��ꂽ�����f����ׂɗp��
	HRESULT hr = S_OK;

	// �f�o�C�X�ƃX���b�v�`�F�C���̏������A�ݒ�
	{
		DXGI_SWAP_CHAIN_DESC desc;			// �X���b�v �`�F�[�����L�q
		ZeroMemory(&desc, sizeof(desc));	// ������
		desc.BufferCount = 1;				// �o�b�N�o�b�t�@�̐�
		desc.BufferDesc.Width = WINDOW_W;	// �o�b�N�o�b�t�@�̕�
		desc.BufferDesc.Height = WINDOW_H;	// �o�b�N�o�b�t�@�̍���
		desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;// �t�H�[�}�b�g
		desc.BufferDesc.RefreshRate.Numerator = 60;			// ���t���b�V�����[�g�i���q�j
		desc.BufferDesc.RefreshRate.Denominator = 1;		// ���t���b�V�����[�g�i����j
		desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;// �������`��
		desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;// �X�P�[�����O
		desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;		// �o�b�N�o�b�t�@�̎g�p���@
		desc.OutputWindow = hWnd;		// �o�̓E�B���h�E�ւ̊֘A�t��
		desc.SampleDesc.Count = 1;		// �s�N�Z���P�ʂ̃}���`�T���v�����O�̐�
		desc.SampleDesc.Quality = 0;	// �}���`�T���v�����O�̃N�I���e�B
		desc.Windowed = TRUE;			// TRUE:�E�B���h�E���[�h FALES:�t���X�N���[�����[�h
		desc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; // �X���b�v �`�F�[���̓���̃I�v�V����

		D3D_FEATURE_LEVEL level;
		// �f�o�C�X�ƃX���b�v�`�F�C���̍쐬
		hr = D3D11CreateDeviceAndSwapChain(
			nullptr,					// �f�o�C�X�̍쐬���Ɏg�p����r�f�I�A�_�v�^�ւ̃|�C���^
			D3D_DRIVER_TYPE_HARDWARE,	// �쐬����f�o�C�X�̎�ނ�\�� D3D_DRIVER_TYPE 
			nullptr,					// �\�t�g�E�F�A���X�^���C�U�[����������DLL�̃n���h��
			0,							// �L���ɂ��郉���^�C�����C���[
			nullptr,					// �쐬�����݂�@�\���x���̏������w��
			0,							// pFeatureLevels�̗v�f��
			D3D11_SDK_VERSION,			// SDK�̃o�[�W����
			&desc,						// �X���b�v �`�F�[���̏������p�����[�^�[���i�[����X���b�v�`�F�C���̋L�q�ւ̃|�C���^
			pSwapChain.GetAddressOf(),	// �����_�����O�Ɏg�p����X���b�v�`�F�C����\��IDXGISwapChain�I�u�W�F�N�g�ւ̃|�C���^�̃A�h���X��Ԃ�
			pDevice.GetAddressOf(),		// �쐬���ꂽ�f�o�C�X��\��ID3D11Device�I�u�W�F�N�g�ւ̃|�C���^�̃A�h���X��Ԃ�
			&level,						// ���̃f�o�C�X�ŃT�|�[�g����Ă���@�\���x���̔z��ɂ���ŏ��̗v�f��\��D3D_FEATURE_LEVEL�ւ̃|�C���^��Ԃ�
			pImmediateContext.GetAddressOf());// �f�o�C�X �R���e�L�X�g��\��ID3D11DeviceContext�I�u�W�F�N�g�ւ̃|�C���^�̃A�h���X��Ԃ�

		// �G���[�`�F�b�N
		if (FAILED(hr))	return false;
	}

	// �o�b�N�o�b�t�@��`��^�[�Q�b�g�ɐݒ�		
	{
		// �X���b�v�`�F�C������ŏ��̃o�b�N�o�b�t�@���擾����
		Microsoft::WRL::ComPtr<ID3D11Texture2D> pBackBuffer;	// �o�b�t�@�̃A�N�Z�X�Ɏg���C���^�[�t�F�C�X(�o�b�t�@��2D�e�N�X�`���Ƃ��Ĉ���)
		hr = pSwapChain.Get()->GetBuffer(
			0,									// �o�b�N�o�b�t�@�̔ԍ�
			__uuidof(ID3D11Texture2D),			// �o�b�t�@�ɃA�N�Z�X����C���^�[�t�F�C�X
			(LPVOID*)pBackBuffer.GetAddressOf()	// �o�b�t�@���󂯎��ϐ�
		);

		// �G���[�`�F�b�N
		if (FAILED(hr))	return false;

		// �o�b�N�o�b�t�@�̕`��^�[�Q�b�g�r���[�����
		hr = pDevice->CreateRenderTargetView(
			pBackBuffer.Get(),				// �r���[�ŃA�N�Z�X���郊�\�[�X
			nullptr,						// �`��^�[�Q�b�g�r���[�̒�`
			pRenderTargetView.GetAddressOf()// �`��^�[�Q�b�g�r���[���󂯎��ϐ�
		);

		// �G���[�`�F�b�N
		if (FAILED(hr))	return false;
	}

	// �[�x/�X�e���V���e�N�X�`���̍쐬
	{
		D3D11_TEXTURE2D_DESC descDepth;
		descDepth.Width = WINDOW_W;						// ��
		descDepth.Height = WINDOW_H;					// ����
		descDepth.MipLevels = 1;						// �~�b�v�}�b�v ���x����
		descDepth.ArraySize = 1;						// �z��T�C�Y
		descDepth.Format = DXGI_FORMAT_D32_FLOAT;		// �t�H�[�}�b�g(�[�x�̂�)
		descDepth.SampleDesc.Count = 1;					// �}���`�T���v�����O�̐ݒ�
		descDepth.SampleDesc.Quality = 0;				// �}���`�T���v�����O�̕i��
		descDepth.Usage = D3D11_USAGE_DEFAULT;			// �g�p���@ �f�t�H���g
		descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;	// �[�x/�X�e���V���Ƃ��Ďg�p
		descDepth.CPUAccessFlags = 0;					// CPU����A�N�Z�X���Ȃ�
		descDepth.MiscFlags = 0;						// ���̑��̐ݒ�Ȃ�

		// 2D�e�N�X�`���[�̔z����쐬
		hr = pDevice->CreateTexture2D(
			&descDepth,					// �쐬����2D�e�N�X�`��
			nullptr,					// �T�u���\�[�X�̋L�q�̔z��ւ̃|�C���^
			pDepthStencil.GetAddressOf()// �쐬�����e�N�X�`�����󂯎��
		);

		// �G���[�`�F�b�N
		if (FAILED(hr))	return false;

		// �[�x/�X�e���V���r���[�̍쐬
		D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
		descDSV.Format = descDepth.Format;	// ���\�[�X �f�[�^�̃t�H�[�}�b�g
		descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;// ���\�[�X�̃^�C�v
		descDSV.Flags = 0;					// �e�N�X�`���[���ǂݎ���p���ǂ���
		descDSV.Texture2D.MipSlice = 0;		// 2D�e�N�X�`���[�̃T�u���\�[�X���w��
		hr = pDevice->CreateDepthStencilView(
			pDepthStencil.Get(),			// �[�x/�X�e���V���r���[�����e�N�X�`��
			&descDSV,						// �[�x/�X�e���V���r���[�̐ݒ�
			pDepthStencilView.GetAddressOf()// �쐬�����r���[���󂯎��
		);

		// �G���[�`�F�b�N
		if (FAILED(hr))	return false;

		// �`��^�[�Q�b�g�r���[���o�̓}�[�W���[�̕`��^�[�Q�b�g�Ƃ��Đݒ�
		pImmediateContext.Get()->OMSetRenderTargets(
			1,									// �`��^�[�Q�b�g�̐�
			pRenderTargetView.GetAddressOf(),	// �`��^�[�Q�b�g�r���[�̔z��
			pDepthStencilView.Get()				// �[�x/�X�e���V���r���[��ݒ肵�Ȃ�
		);
	}

	// ���X�^���C�Y�X�e�[�g�I�u�W�F�N�g�̐ݒ�
	{
		D3D11_RASTERIZER_DESC descRast = {
			D3D11_FILL_SOLID,	// �����_�����O���Ɏg�p����`�惂�[�h��ݒ�
			D3D11_CULL_NONE,	// �J�����O�̐ݒ�
			FALSE,				// �O�p�`���O����������������ݒ肷��
			0,					// �w��̃s�N�Z���ɉ��Z����[�x�l
			0.0f,				// �s�N�Z���̍ő�[�x�o�C�A�X
			0.0f,				// �s�N�Z���̌X�΂Ɋ�Â��ăo�C�A�X��������
			FALSE,				// �����Ɋ�Â��ăN���b�s���O��L���ɂ���
			FALSE,				// �V�U�[��`�J�����O��L���ɂ���
			FALSE,				// �}���`�T���v�����O�̃A���`�G�C���A�V���O��L���ɂ���
			FALSE				// ���̃A���`�G�C���A�V���O��L���ɂ���
		};

		// ���X�^���C�Y�X�e�[�g�I�u�W�F�N�g�̍쐬
		pDevice.Get()->CreateRasterizerState(
			&descRast,						// ���X�^���C�U�X�e�[�g�̋L�q�ւ̃|�C���^
			pRasterizerState.GetAddressOf()	// �쐬����郉�X�^���C�U�X�e�[�g�I�u�W�F�N�g�ւ̃|�C���^�̃A�h���X
		);

		//���X�^���C�U�[���R���e�L�X�g�ɐݒ�
		pImmediateContext.Get()->RSSetState(pRasterizerState.Get());
	}

	// �u�����f�B���O�X�e�[�g�̍쐬
	{
		D3D11_BLEND_DESC descBlend;
		ZeroMemory(&descBlend, sizeof(descBlend));
		descBlend.AlphaToCoverageEnable = TRUE;		// �s�N�Z���������_�[�^�[�Q�b�g�ɐݒ肷��Ƃ��ɁA�A���t�@�g�D�J�o���b�W���}���`�T���v�����O�e�N�j�b�N�Ƃ��Ďg�p���邩�ǂ���������
		descBlend.IndependentBlendEnable = FALSE;		// ���������̃����_�[�^�[�Q�b�g�œƗ������u�����f�B���O��L���ɂ��邩�ǂ���
		descBlend.RenderTarget[0].BlendEnable = TRUE;	// �u�����f�B���O��L���ɂ���
		descBlend.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;		// �ŏ���RGB�f�[�^�\�[�X���w��
		descBlend.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;// 2�Ԗڂ�RGB�f�[�^�\�[�X���w��
		descBlend.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;			// RGB�f�[�^�\�[�X�̑g�������@���`
		descBlend.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;		// �ŏ��̃A���t�@�f�[�^�\�[�X���w��
		descBlend.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;	// 2�Ԗڂ̃A���t�@�f�[�^�\�[�X���w��
		descBlend.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;	// �A���t�@�f�[�^�\�[�X�̑g�������@���`
		descBlend.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL; // �������݃}�X�N
		pDevice.Get()->CreateBlendState(
			&descBlend,					// �u�����f�B���O�X�e�[�g�̋L�q�ւ̃|�C���^
			pBlendState.GetAddressOf()	// �쐬�����I�u�W�F�N�g�ւ̃|�C���^�̃A�h���X
		);

		// �u�����f�B���O�X�e�[�g�̐ݒ�
		float blendFactor[4] = {
			D3D11_BLEND_ZERO,
			D3D11_BLEND_ZERO,
			D3D11_BLEND_ZERO,
			D3D11_BLEND_ZERO
		};

		// �u�����f�B���O�X�e�[�g�̐ݒ�
		pImmediateContext.Get()->OMSetBlendState(
			pBlendState.Get(),	// �u�����f�B���O�X�e�[�g�ւ̃|�C���^
			blendFactor,	// �u�����f�B���O�W���̔z��
			0xffffffff		// �T���v���}�X�N
		);
	}

	// ���W�ϊ��s��
	{
		D3D11_BUFFER_DESC descCBuffer;
		// ������
		ZeroMemory(&descCBuffer, sizeof(descCBuffer));
		// �o�b�t�@�őz�肳��Ă���ǂݍ��݋y�я������݂̕��@������
		descCBuffer.Usage = D3D11_USAGE_DEFAULT;
		// �o�b�t�@�̃T�C�Y
		descCBuffer.ByteWidth = sizeof(ConstantBuffer);
		// �o�b�t�@���ǂ̂悤�ɃO���t�B�b�N�X�p�C�v���C���Ƀo�C���h���邩������
		descCBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		// CPU�̃A�N�Z�X�t���O
		descCBuffer.CPUAccessFlags = 0;

		// �o�b�t�@�̍쐬
		hr = pDevice.Get()->CreateBuffer(
			// �o�b�t�@�̋L�q�ւ̃|�C���^
			&descCBuffer,
			// �������f�[�^�ւ̃|�C���^
			nullptr,
			// �쐬�����o�b�t�@�ւ̃|�C���^�̃A�h���X
			pConstantBuffer.GetAddressOf()
		);

		// �G���[�`�F�b�N
		if (FAILED(hr))	return false;
	}

	// �Œ�p�C�v���C���p�ɃV�F�[�_�[�f�[�^�ǂݍ���
	{
		Shader::GetInstance()->LoadShader("VertexShader.cso", "PixelShader.cso");
	}
	// �_�~�[�摜�ǂݍ���
	{
		Texture::GetInstance()->LoadTexture("dummy.jpg");
	}

	// ����I��
	return true;
}

// D3D�f�o�C�X�I��
void App::TermD3D()
{
	pRasterizerState.Reset();
	pBlendState.Reset();
	pDepthStencilView.Reset();
	pDepthStencil.Reset();
	pRenderTargetView.Reset();
	pSwapChain.Reset();
	pImmediateContext.Reset();
	pDevice.Reset();
}

LRESULT CALLBACK App::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:		// ����{�^���������ꂽ�Ƃ�
		PostMessage(hWnd, WM_DESTROY, 0, 0);	// WM_DESTROY��
		break;
	case WM_DESTROY:	// �E�B���h�E���I������Ƃ�
		PostQuitMessage(0);	// WM_QUIT�𑗐M����
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)// esc�L�[�ŃE�B���h�E����
			DestroyWindow(hWnd);
		break;
	}
	// ����̃E�B���h�E�v���V�[�W�����Ăяo���ď�����Ԃ�
	return DefWindowProc(hWnd, message, wParam, lParam);
}
