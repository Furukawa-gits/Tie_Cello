#pragma once
#include"../FbxLoder/Object3d_FBX.h"
#include"../staging/Easing.h"
#include"../Base/DirectX_Base.h"

enum class cellType
{
	white = 0,
	black = 1
};

class Cell
{
private:
	/// <summary>
	/// ���\�[�X�ǂݍ���
	/// </summary>
	static void loadResources();

	/// <summary>
	/// �Ђ�����Ԃ�
	/// </summary>
	void reverseCell();

public:
	Cell();
	~Cell();

	/// <summary>
	/// �ÓI�f�[�^�Z�b�g
	/// </summary>
	/// <param name="d">directx�N���X</param>
	static void setStaticData(directX* d);

	/// <summary>
	/// �v���C���[�������Ă���u���b�N�̈ʒu���X�V
	/// </summary>
	/// <param name="playerPos">�u���b�N�̍��W</param>
	static void playerBlockPosUpdata(XMFLOAT3 blockPos);

	/// <summary>
	/// ������
	/// </summary>
	void init(XMFLOAT3 pos, cellType type, bool put);

	/// <summary>
	/// �X�V
	/// </summary>
	void updata();

	/// <summary>
	/// �Ђ�����Ԃ�����
	/// </summary>
	void setReverce();

	/// <summary>
	/// �F�ύX
	/// </summary>
	void changeColor();

	/// <summary>
	/// �`��
	/// </summary>
	void draw3D();

	bool getIsPut() { return isPut; }

	bool getIsReverse() { return isReverse; }

	void setIndex(int id) { index = id; }

	int getIndex() { return index; }

	cellType getColor() { return myType; }

private:
	static directX* dx;
	//���f���f�[�^
	static std::unique_ptr<Model> cellModel;
	//�v���C���[���w���Ă���u���b�N�̈ʒu
	static XMFLOAT3 playerPointBlockPos;
	//�΂��ړ��ł��邩�ǂ���
	static bool isMove;

	//�I�u�W�F�N�g
	object3dFBX* cellObject = nullptr;
	//�C�[�W���O
	easingManager rotEasing;
	//�E���E�I���e
	cellType myType = cellType::white;
	//�u���Ă���΂��ǂ���
	bool isPut = false;
	//�Ђ�����Ԃ��Ă���r�����ǂ���
	bool isReverse = false;
	//�}�b�v�S�̂ŉ��Ԗڂ̃C���f�b�N�X���ǂ���(�����l-1)
	int index = -1;
};