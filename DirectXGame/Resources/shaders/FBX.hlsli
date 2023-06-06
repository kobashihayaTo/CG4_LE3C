cbuffer cbuff0:register(b0)
{
	matrix viewproj;
	matrix world;
	float3 cameraPos;
};

//ボーンの最大数
static const int MAX_BONES = 32;

cbuffer skinning:register(b3)//ボーンのスキニング行列
{
	matrix matSkinning[MAX_BONES];
}

//バーテックスバッファーの入力
struct VSInput
{
	float4 pos:POSITION;
	float3 normal:NORMAL;
	float2 uv :TEXCOORD;
	uint4  boneIndices:BONEINDICES;//ボーンの番号
	float4 boneWeights:BONEWEIGHTS;//ボーンのスキンウェイト
};

//頂点シェーダーからピクセルシェーダーへのやり取りに使用する構造体
struct VSOutput
{
	float4 svpos:SV_POSITION;
	float3 normal:NORMAL;
	float2 uv:TEXCOORD;
};


