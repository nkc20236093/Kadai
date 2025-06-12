// �󂯎�钸�_�f�[�^�̒l
struct VS_IN
{
	float4 pos : POSITION0;// D3D11_INPUT_ELEMENT_DESC�Œ�`�����Z�}���e�B�N�X���E�C���f�b�N�X�ԍ��̗v�f���󂯎��
	float4 col : COLOR0;
	float2 tex : TEXCOORD0;
	float3 normal : NORMAL0;
};

// �s�N�Z���V�F�[�_�[�ɑ���l
struct VS_OUT
{
	// ���ɒ��_�V�F�[�_�ŏ���������Ă���̂ŁA�V�X�e����ň������W���Ƃ���SV_POSITION�ɂȂ�
	// SV��System Value�̗��H
	float4 pos : SV_POSITION;
	float4 col : COLOR0;
	float2 tex : TEXCOORD0;
	float3 normal : NORMAL0;
};

// ���W�s��f�[�^���󂯎��
cbuffer ConstantBuffer : register(b0)
{
	matrix World;		// ���[���h���W�s��
	matrix View;		// �r���[�ϊ��s��
	matrix Projection;	// �v���W�F�N�V�����ϊ��s��
}


VS_OUT main(VS_IN input)
{
	VS_OUT output;

	output.pos = mul(input.pos, World);			// ���݂̍��W�ƃ��[���h�ϊ��s��ŏ�Z���s��
	output.pos = mul(output.pos, View);			// ��L�v�Z��̍��W�ƃr���[�ϊ��s��ŏ�Z���s��
	output.pos = mul(output.pos, Projection);	// ��L�v�Z��̍��W�ƃv���W�F�N�V�����ϊ��s��ŏ�Z���s��

	output.col = input.col;
	output.tex = input.tex;

	return output;
}