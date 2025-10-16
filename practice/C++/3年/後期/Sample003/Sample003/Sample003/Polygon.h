#pragma once
#include <tchar.h>			// テキストや文字列を扱うために必要なヘッダーファイル
#include <Windows.h>		// Windowsプログラムで必要になるものが入っている
#include <D3D11.h>			// DirectX11SDKを使うために必要なもの
#include <d3dcompiler.h>	// シェーダーファイルをコンパイルするために必要
#include <directxcolors.h>	// DirectX::ライブラリを利用するために必要
#include <wrl/client.h>		// DirectXのスマートポインタ
#include <vector>
#include <string>
#include "App.h"
#include "Shader.h"
#include "Texture.h"
#include "Matrix.h"

#pragma comment(lib, "d3d11.lib")		// DirectX11ライブラリを利用するために必要
#pragma comment(lib, "d3dCompiler.lib")	// シェーダーコードをコンパイルするために必要

// 頂点データ構造体
struct vertex
{
	DirectX::XMFLOAT3 pos;		// 頂点座標	
	DirectX::XMFLOAT4 col;		// 頂点ごとの色
	DirectX::XMFLOAT2 uv;		// テクスチャ座標
	DirectX::XMFLOAT3 normal;	// 法線
};

constexpr uint32_t BOTTOM_LEFT = 0;
constexpr uint32_t TOP_LEFT = 1;
constexpr uint32_t BOTTOM_RIGHT = 2;
constexpr uint32_t TOP_RIGHT = 3;
constexpr uint32_t VERTEX_MAX = 4;

class CPolygon
{
private:
	ShaderResources* pSr;
	std::vector<ID3D11ShaderResourceView*> pTextures;

	vertex vertexList[VERTEX_MAX];
	DirectX::XMMATRIX	wld = DirectX::XMMatrixIdentity();
	DirectX::XMFLOAT3	scale = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	DirectX::XMFLOAT3	axis = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	float				angle = 0.0f;
	DirectX::XMFLOAT3	pos = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);

	MatrixCB constantBuffer;

public:
	void Init(ShaderResources* sr);
	void Render(MatrixCB cb, TextureResources* tex = Texture::GetInstance()->GetTextureResource(0));

	void Term();
	void SetColor(float r, float g, float b, float a);
	void SetColor(float r, float g, float b, float a, uint32_t v);
	void SetUV(float cx, float cy, float nx, float ny);
	void SetUV(float uv_x, float uv_y, uint32_t v);

	void PSSetCB(uint32_t startSlot, uint32_t numBuffers, Microsoft::WRL::ComPtr<ID3D11Buffer> buffer);
};