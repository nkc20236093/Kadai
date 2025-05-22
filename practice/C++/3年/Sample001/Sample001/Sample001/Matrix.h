#pragma once
#include <directxcolors.h>	// DirectX::ライブラリを利用するために必要

#pragma comment(lib, "d3d11.lib")		// DirectX11ライブラリを利用するために必要


// 座標変換構造体
struct ConstantBuffer
{
	DirectX::XMMATRIX world;		// ワールド変換行列
	DirectX::XMMATRIX view;			// ビュー変換行列
	DirectX::XMMATRIX projection;	// プロジェクション変換行列
};

class Matrix
{
public:
	void Identity();
	DirectX::XMFLOAT3& GetPos() { return pos; }
	float GetAngle() { return angle; }
	DirectX::XMMATRIX& GetWorld() { return cb.world; }
	DirectX::XMMATRIX& GetView() { return cb.view; }
	DirectX::XMMATRIX& GetProjection() { return cb.projection; }
	ConstantBuffer& GetCB() { return cb; }

	void SetAxis(float Axis);
	void SetFirstPos(const DirectX::XMFLOAT3& pos);
	void SetPos(const DirectX::XMFLOAT3& pos);
	void SetRotationX(float rotX);
	void SetRotationY(float rotY);
	void SetRotationZ(float rotZ);
	void SetRotationAxis(const DirectX::XMVECTOR& axis, float rot);
	void SetScale(const DirectX::XMFLOAT3& scale);
	void SetWorld(const DirectX::XMMATRIX& world);//追加
private:
	ConstantBuffer cb;
	DirectX::XMFLOAT3 pos;
	float angle;
};