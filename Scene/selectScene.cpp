#include "selectScene.h"

selectScene::selectScene()
{
	//���\�[�X�ǂݍ���
	loadResources();

	//�p�����[�^�̃Z�b�g
	setParameter();

	thisType = gameSceneType::select;
}

selectScene::~selectScene()
{

}

void selectScene::loadResources()
{
	//�w�i
	selectBack.size = { 1280,720 };
	selectBack.generateSprite("black_color.png");
}

void selectScene::initialize()
{
	//���\�[�X�ǂݍ���
	loadResources();

	//�p�����[�^�̃Z�b�g
	setParameter();
}

void selectScene::setParameter()
{
	isNextScene = false;
}

void selectScene::updata()
{
	//�}�E�X���W�X�V
	MOUSE_POS = { (float)input->mousePoint.x,(float)input->mousePoint.y,0.0f };

	//���̃V�[���ւ̈ڍs����
	if (input->Triger(DIK_SPACE))
	{
		isNextScene = true;
	}
}

void selectScene::drawBack()
{
	sample_back->drawSprite(directx->cmdList.Get());
}

void selectScene::draw3D()
{
}

void selectScene::draw2D()
{
	
}

bool selectScene::loadStage()
{
	//�X�e�[�W�ǂݍ��ݏ���
	//CSV�ǂݍ��݂Ƃ��͂�������������Ă���

	return true;
}