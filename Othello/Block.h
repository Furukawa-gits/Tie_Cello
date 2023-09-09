#pragma once
#include"../FbxLoder/Object3d_FBX.h"
#include"../staging/Easing.h"
#include"../Base/DirectX_Base.h"

enum class blockType
{
	light = 0,
	dark = 1
};

class Block
{
private:
	/// <summary>
	/// ���\�[�X�ǂݍ���
	/// </summary>
	static void loadResources();

public:
	/// <summary>
	/// �ÓI�f�[�^�Z�b�g
	/// </summary>
	/// <param name="d">directx�N���X</param>
	static void setStaticData(directX* d);

	/// <summary>
	/// ������
	/// </summary>
	void init(blockType type, XMFLOAT3 position);

	/// <summary>
	/// �X�V
	/// </summary>
	void updata();

	/// <summary>
	/// �`��
	/// </summary>
	void draw3D();

	/// <summary>
	///	�}�E�X���w���Ă���u���b�N���ǂ���
	/// </summary>
	/// <param name="mousepos">�}�E�X���W</param>
	/// <returns>���茋��</returns>
	bool isThisPlayerPoint(XMFLOAT2 mousepos);

private:
	static directX* dx;
	//���f���f�[�^
	static std::unique_ptr<Model> blockModel_1;
	static std::unique_ptr<Model> blockModel_2;

	//�I�u�W�F�N�g
	std::unique_ptr<object3dFBX> blockObject;
	//�C�[�W���O
	easingManager startEasing;
	//�����ʒu
	XMFLOAT3 startPos;
	//�I�[�ʒu
	XMFLOAT3 endPos;
};