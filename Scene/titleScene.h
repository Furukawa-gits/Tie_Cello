#pragma once
#include"primitiveScene.h"
#include <array>

class titleScene
	:public primitiveScene
{
public:
	//�R���X�g���N�^
	titleScene();
	~titleScene();

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
	//�}�E�X���W
	XMFLOAT3 MOUSE_POS = { 0,0,0 };
	//�w�i
	SingleSprite titleBack;
	std::array<SingleSprite, 8 * 2> titleChars;

	//�^�C�g��
	
	//�^�C�g���A�j���[�V����
	bool isTitleAnimation = false;

	//�^�C�g�����o�t���O
	bool isTitleStage = false;
	
	//���̓t���O
	bool isPushStart = false;
};