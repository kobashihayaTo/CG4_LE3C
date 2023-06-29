#pragma once

#include "Sprite.h"

class PostEffect :
    public Sprite
{

protected://�G�C���A�X
    //Microsoft::WRL::���ȗ�
    template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;
    //DirectX::���ȗ�
    using XMFLOAT2 = DirectX::XMFLOAT2;
    using XMFLOAT3 = DirectX::XMFLOAT3;
    using XMFLOAT4 = DirectX::XMFLOAT4;
    using XMMATRIX = DirectX::XMMATRIX;

public:
    //�e�N�X�`���o�b�t�@
    ComPtr<ID3D12Resource>texBuff;
    //SRV�p�f�X�N���v�^�q�[�v
    ComPtr<ID3D12DescriptorHeap>descHeapSRV;

public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    PostEffect();
    
    /// <summary>
    /// ������
    /// </summary>
    void Initialize();

    /// <summary>
    /// �`��R�}���h�̔��s
    /// </summary>
    /// <param name="cmdList">�R�}���h���X�g</param>
    void Draw(ID3D12GraphicsCommandList* cmdList);

    /// <summary>
    /// �V�[���`��O����
    /// </summary>
    /// <param name="cmdList"></param>
    void PreDrawScene(ID3D12GraphicsCommandList* cmdList);

    void PostDrawScene(ID3D12GraphicsCommandList* cmdList);

    void CreateGraphicsPipelineState();
public:
    //�[�x�o�b�t�@
    ComPtr<ID3D12Resource>depthBuff;
    //RTV�p�f�X�N���v�^�q�[�v
    ComPtr<ID3D12DescriptorHeap> descHeapRTV;
    //DSV�p�f�X�N���v�^�q�[�v
    ComPtr<ID3D12DescriptorHeap> descHeapDSV;
public:
    //�O���t�B�b�N�X�p�C�v���C��
    ComPtr<ID3D12PipelineState>pipelineState;
    //���[�g�V�O�l�`��
    ComPtr<ID3D12RootSignature>rootSignature;
private:
    //��ʃN���A�J���[
    static const float clearColor[4];
};

