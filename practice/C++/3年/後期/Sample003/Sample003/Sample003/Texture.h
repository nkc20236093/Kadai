#pragma once
#include <WICTextureLoader.h>	// テクスチャ読み込むやつ
#include <string>
#include <wrl/client.h>			// DirectXのスマートポインタ
#include <vector>


struct TextureResources
{
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> pTexture = nullptr;// テクスチャ情報
	Microsoft::WRL::ComPtr<ID3D11SamplerState> pSampler = nullptr;		// サンプラー情報
};

class Texture
{
public:
	static Texture* GetInstance()
	{
		static Texture instance;
		return &instance;
	}
	void Term();
	uint32_t LoadTexture(const std::string& path);
	TextureResources* GetTextureResource(uint32_t num = 0);
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	GetTexture(uint32_t num = 0);
	Microsoft::WRL::ComPtr<ID3D11SamplerState>			GetSampler(uint32_t num = 0);

private:
	Texture() :cnt(0) {};
	~Texture() {};
	std::vector<TextureResources> pTr;
	uint32_t cnt;
	const std::string& PATH = "tex//";// テクスチャファイル格納先
};
