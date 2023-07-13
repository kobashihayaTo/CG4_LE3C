#include "PostEffectTest.hlsli"

Texture2D<float4> tex0 : register(t0);
Texture2D<float4> tex1 : register(t1);
SamplerState smp : register(s0);

float4 main(VSOutput input) : SV_TARGET
{
	float4 colortex0 = tex0.Sample(smp,input.uv);
	float4 colortex1 = tex1.Sample(smp,input.uv);
    float4 blur = 0.0f;

    //テクスチャのサイズを指定
    int textureWidth = 512;  // テクスチャの幅
    int textureHeight = 512; // テクスチャの高さ

    // サンプリング範囲の設定
    float2 texelSize = float2(1.0 / textureWidth, 1.0 / textureHeight);

    // サンプリング範囲内のピクセルを合計
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
           blur += tex1.Sample(smp, input.uv+float2(texelSize.x*x, texelSize.y*y));
        }
    }
    colortex1 = blur / 9.0f;
   

    float4 color = 1 - colortex0;
    if(fmod(input.uv.y,0.1f)<0.05f){

        color = lerp(colortex0, colortex1, 0.4f);
    }


	return float4(color.rgb, 1);

}

//float4 main(VSOutput input) : SV_TARGET
//{
//    // テクスチャのサイズを指定
//    int textureWidth = 512;  // テクスチャの幅
//    int textureHeight = 512; // テクスチャの高さ
//
//    // サンプリング範囲の設定
//    float2 texelSize = float2(1.0 / textureWidth, 1.0 / textureHeight);
//
//    // カーネルサイズ
//    int kernelSize = 3;
//
//    // ピクセルの初期値を設定
//    float3 color = float3(0, 0, 0);
//
//    // サンプリング範囲内のピクセルを合計
//    for (int x = -kernelSize; x <= kernelSize; x++)
//    {
//        for (int y = -kernelSize; y <= kernelSize; y++)
//        {
//            float2 offset = float2(x, y) * texelSize;
//            color += tex.Sample(smp, input.uv + offset).rgb;
//        }
//    }
//
//    // ピクセル数で割って平均化
//    color /= (kernelSize * 2 + 1) * (kernelSize * 2 + 1);
//
//    return float4(color, 1);
//}

