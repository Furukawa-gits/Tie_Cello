#include "titleScene.h"

titleScene::titleScene()
{
	//���\�[�X�ǂݍ���
	loadResources();

	//�p�����[�^�̃Z�b�g
	setParameter();

	thisType = gameSceneType::title;
}

titleScene::~titleScene()
{

}

void titleScene::loadResources()
{
	//�w�i
	titleBack.size = { 1280,720 };
	titleBack.generateSprite("black_color.png");

	//�^�C�g��
	
}

void titleScene::initialize()
{
	//���\�[�X�ǂݍ���
	loadResources();

	//�p�����[�^�̃Z�b�g
	setParameter();
}

void titleScene::setParameter()
{
	//�^�C�g���A�j���[�V��������
	isPushStart = false;
	isNextScene = false;
}

void titleScene::updata()
{
	//�^�C�g����ʍX�V����
	
	//�}�E�X���W�X�V
	MOUSE_POS = { (float)input->mousePoint.x,(float)input->mousePoint.y,0.0f };

	titleBack.spriteUpdata();

	//���̃V�[���ւ̈ڍs����
	if (input->Triger(DIK_SPACE))
	{
		isNextScene = true;
	}
}

void titleScene::drawBack()
{
	sample_back->drawSprite(directx->cmdList.Get());
}

void titleScene::draw3D()
{
}

void titleScene::draw2D()
{
	titleBack.drawSprite(directx->cmdList.Get());
}
