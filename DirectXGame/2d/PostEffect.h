#pragma once

#include "Sprite.h"

class PostEffect :
    public Sprite
{

protected://エイリアス
    //Microsoft::WRL::を省略
    template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;
    //DirectX::を省略
    using XMFLOAT2 = DirectX::XMFLOAT2;
    using XMFLOAT3 = DirectX::XMFLOAT3;
    using XMFLOAT4 = DirectX::XMFLOAT4;
    using XMMATRIX = DirectX::XMMATRIX;

public:
    //テクスチャバッファ
    ComPtr<ID3D12Resource>texBuff;
    //SRV用デスクリプタヒープ
    ComPtr<ID3D12DescriptorHeap>descHeapSRV;

public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    PostEffect();
    
    /// <summary>
    /// 初期化
    /// </summary>
    void Initialize();

    /// <summary>
    /// 描画コマンドの発行
    /// </summary>
    /// <param name="cmdList">コマンドリスト</param>
    void Draw(ID3D12GraphicsCommandList* cmdList);

    /// <summary>
    /// シーン描画前処理
    /// </summary>
    /// <param name="cmdList"></param>
    void PreDrawScene(ID3D12GraphicsCommandList* cmdList);

    void PostDrawScene(ID3D12GraphicsCommandList* cmdList);

    void CreateGraphicsPipelineState();
public:
    //深度バッファ
    ComPtr<ID3D12Resource>depthBuff;
    //RTV用デスクリプタヒープ
    ComPtr<ID3D12DescriptorHeap> descHeapRTV;
    //DSV用デスクリプタヒープ
    ComPtr<ID3D12DescriptorHeap> descHeapDSV;
public:
    //グラフィックスパイプライン
    ComPtr<ID3D12PipelineState>pipelineState;
    //ルートシグネチャ
    ComPtr<ID3D12RootSignature>rootSignature;
private:
    //画面クリアカラー
    static const float clearColor[4];
};

