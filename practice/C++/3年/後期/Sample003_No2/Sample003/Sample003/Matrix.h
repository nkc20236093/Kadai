#pragma once
#include <directxcolors.h>	// DirectX::ライブラリを利用するために必要
#include "ConstantBuffer.h"

#pragma comment(lib, "d3d11.lib")		// DirectX11ライブラリを利用するために必要



class Matrix
{
public:
	void Identity();
	DirectX::XMMATRIX& GetWorld() { return cb.world; }
	DirectX::XMMATRIX& GetView() { return cb.view; }
	DirectX::XMMATRIX& GetProjection() { return cb.projection; }
	MatrixCB& GetCB() { return cb; }

	void SetPos(const DirectX::XMFLOAT3& pos);
	void SetRotationX(float rotX);
	void SetRotationY(float rotY);
	void SetRotationZ(float rotZ);
	void SetRotationAxis(const DirectX::XMVECTOR& axis, float rot);
	void SetScale(const DirectX::XMFLOAT3& scale);
	void SetWorld(const DirectX::XMMATRIX& wld);
private:
	MatrixCB cb;
};