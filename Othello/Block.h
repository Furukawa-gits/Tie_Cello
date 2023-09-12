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
	Block();
	~Block();

	/// <summary>
	/// �ÓI�f�[�^�Z�b�g
	/// </summary>
	/// <param name="d">directx�N���X</param>
	static void setStaticData(directX* d);

	/// <summary>
	/// ������
	/// </summary>
	void init(blockType type, XMFLOAT3 position, const XMFLOAT3& scale, int id);

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

	/// <summary>
	/// �C���f�b�N�X���擾
	/// </summary>
	/// <returns>�C���f�b�N�X</returns>
	int getIndex() { return index; }

	/// <summary>
	/// �u���b�N�̍��W���擾
	/// </summary>
	XMFLOAT3 getBlockPosition() { return blockObject->getPosition(); }

private:
	//dierctx
	static directX* dx;

	//���f���f�[�^
	static std::unique_ptr<Model> blockModel_1;
	static std::unique_ptr<Model> blockModel_2;

public:
	//�I�u�W�F�N�g
	object3dFBX* blockObject = nullptr;

	//�C�[�W���O
	easingManager startEasing;

	//�����ʒu
	XMFLOAT3 startPos;

	//�I�[�ʒu
	XMFLOAT3 endPos;

	//�}�b�v�S�̂ŉ��Ԗڂ̃C���f�b�N�X���ǂ���(�����l-1)
	int index = -1;
};