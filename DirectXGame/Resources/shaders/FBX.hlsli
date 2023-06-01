cbuffer cbuff0:register(b0)
{
	matrix viewproj;
	matrix world;
	float3 cameraPos;
};

//�o�[�e�b�N�X�o�b�t�@�[�̓���
struct VSInput
{
	float4 pos:POSITION;
	float3 normal:NORMAL;
	float2 uv :TEXCOORD;
};

//���_�V�F�[�_�[����s�N�Z���V�F�[�_�[�ւ̂����Ɏg�p����\����
struct VSOutput
{
	float4 svpos:SV_POSITION;
	float3 normal:NORMAL;
	float2 uv:TEXCOORD;
};
