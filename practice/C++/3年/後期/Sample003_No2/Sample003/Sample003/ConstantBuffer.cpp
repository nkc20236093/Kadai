#include "ConstantBuffer.h"
#include "App.h"

void ConstantBuffer::Term()
{
	// データを全部リセット
	for (auto cb = pCb.begin(); cb != pCb.end(); ++cb)
	{
		cb->Reset();
	}
	cnt = 0;
}

uint32_t ConstantBuffer::InitCB(uint32_t byteWidth)
{
	D3D11_BUFFER_DESC descCBuffer;
	// 初期化
	ZeroMemory(&descCBuffer, sizeof(descCBuffer));
	// バッファで想定されている読み込み及び書き込みの方法を識別
	descCBuffer.Usage = D3D11_USAGE_DEFAULT;
	// バッファのサイズ
	descCBuffer.ByteWidth = byteWidth;
	// バッファをどのようにグラフィックスパイプラインにバインドするかを識別
	descCBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	// CPUのアクセスフラグ
	descCBuffer.CPUAccessFlags = 0;

	pCb.emplace_back();
	HRESULT hr;
	// バッファの作成
	hr = App::GetInstance()->GetDevice().Get()->CreateBuffer(
		// バッファの記述へのポインタ
		&descCBuffer,
		// 初期化データへのポインタ
		nullptr,
		// 作成されるバッファへのポインタのアドレス
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
