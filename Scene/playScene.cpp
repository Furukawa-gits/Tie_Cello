#include "playScene.h"

playScene::playScene()
{
	//���\�[�X�ǂݍ���
	loadResources();

	//�p�����[�^�̃Z�b�g
	setParameter();

	thisType = gameSceneType::play;
}

playScene::~playScene()
{

}

void playScene::loadResources()
{

}

void playScene::initialize()
{
	loadResources();

	setParameter();
}

void playScene::setParameter()
{
	isNextScene = false;
}

void playScene::updata()
{
	//���C�g�X�V
	light->Update();

	//���̃V�[���ւ̈ڍs����
	if (input->Triger(DIK_SPACE))
	{
		isNextScene = true;
	}
}

void playScene::drawBack()
{
	sample_back->drawSprite(directx->cmdList.Get());
}

void playScene::draw3D()
{
}

void playScene::draw2D()
{
}

void playScene::tutorial()
{
	
}