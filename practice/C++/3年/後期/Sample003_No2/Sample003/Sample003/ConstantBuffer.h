#pragma once
#include <D3D11.h>			// DirectX11SDKを使うために必要なもの
#include <directxcolors.h>	// DirectX::ライブラリを利用するために必要
#include <wrl/client.h>		// DirectXのスマートポインタ
#include <vector>

#pragma comment(lib, "d3d11.lib")		// DirectX11ライブラリを利用するために必要


// 定数バッファ定義============================================================
template<class T> struct Property {
	T& r;
	operator T() { return r; }
	void operator =(const T v) { r = v; }
};
struct CBList
{
private:
	// 定数バッファを増やす際はここに追加する（01/03)
	uint32_t _float4 = 0;
	uint32_t _matrix = 0;
public:
	// 定数バッファを増やす際はここに追加する（02/03)
	Property<uint32_t> float4{ _float4 };
	Property<uint32_t> matrix{ _matrix };
};

// 定数バッファを増やす際はここに追加する（03/03)
// float4でシェーダに送りたい用
struct Float4CB
{
	DirectX::XMFLOAT4 float4cb;
};

// 座標変換構造体
struct MatrixCB
{
	DirectX::XMMATRIX world;		// ワールド変換行列
	DirectX::XMMATRIX view;			// ビュー変換行列
	DirectX::XMMATRIX projection;	// プロジェクション変換行列
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