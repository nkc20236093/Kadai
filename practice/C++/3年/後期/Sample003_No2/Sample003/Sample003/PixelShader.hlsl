Texture2D		g_Texture : register (t0);
SamplerState	g_Sampler : register (s0);

// 頂点シェーダから受け取る値
struct PS_IN
{
	float4 pos : SV_POSITION;
	float4 col : COLOR0;
	float2 tex : TEXCOORD0;
	float3 normal : NORMAL0;
};

// 定数バッファCPUから受け取る
cbuffer Float4Buffer:register(b0)
{
	float4 f4;
}

float4 main(PS_IN input) : SV_TARGET
{
	// uvのyが0.5未満なら青、0.6以上は赤、それ以外はテクスチャ
	float4 tex = float4(1.0f, 0.0f, 1.0f, 1.0f);
    if (input.tex.y < 0.5)
    {
        tex = float4(0, 0, 1, 1);
    }
    else if (input.tex.y >= 0.6)
    {
        tex = float4(1, 0, 0, 1);
    }
    else
    {
        tex = g_Texture.Sample(g_Sampler, input.tex);
    }
    
    return tex;
	//tex = g_Texture.Sample(g_Sampler, input.tex);
	//tex.rgb = pow(tex.rgb,f4.x);
	//return tex * input.col;
}