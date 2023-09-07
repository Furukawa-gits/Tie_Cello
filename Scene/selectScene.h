#pragma once
#include"primitiveScene.h"

class selectScene
	:public primitiveScene
{
public:
	selectScene();
	~selectScene();

	//���\�[�X�̓ǂݍ���
	void loadResources() override;

	//������
	void initialize() override;

	//�p�����[�^�̃��Z�b�g
	void setParameter() override;

	//�X�V
	void updata() override;

	//�w�i�`��
	void drawBack() override;

	//�`��(3D)
	void draw3D() override;

	//�`��(2D)
	void draw2D() override;

private:
	//�X�e�[�W�ǂݍ���
	bool loadStage();

private:
	//�}�E�X���W
	XMFLOAT3 MOUSE_POS = { 0,0,0 };
	
	//�w�i
	SingleSprite selectBack;
	//�X�e�[�W�A�C�R��
	
	//�Z���N�g�A�C�R��
	
	//�v���C�X�^�[�g�{�^��
	
	
	//�X�e�[�W�A�C�R���̃C�[�W���O
	
	//�X�e�[�W�A�C�R���𓮂����Ă��邩�ǂ���
	bool isMoveStageIcon = false;
	
	//���̓t���O
	bool isPushStart = false;
	//�X�e�[�W�ǂݍ��݃t���O
	bool isLoadStage = false;
};