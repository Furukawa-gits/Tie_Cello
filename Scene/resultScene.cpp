#include"resultScene.h"

resultScene::resultScene()
{
	//���\�[�X�ǂݍ���
	loadResources();

	//�p�����[�^�̃Z�b�g
	setParameter();

	thisType = gameSceneType::result;
}

resultScene::~resultScene()
{

}

void resultScene::loadResources()
{
	
}

void resultScene::initialize()
{
	//���C�g�X�V
	light->Update();

	//���\�[�X�ǂݍ���
	loadResources();

	//�p�����[�^�̃Z�b�g
	setParameter();
}

void resultScene::setParameter()
{
	isNextScene = false;
}

void resultScene::updata()
{
	//�}�E�X���W�X�V
	MOUSE_POS = { (float)input->mousePoint.x,(float)input->mousePoint.y,0.0f };

	evenry->updata();
	othello->updata(input->mousePosition);

	if (isClearOrOver)
	{
		clearScene();
	}
	else
	{
		overScene();
	}

	//���̃V�[���ւ̈ڍs����
	if (input->Triger(DIK_SPACE))
	{
		isNextScene = true;
	}
}

void resultScene::drawBack()
{
	sample_back->drawSprite(directx->cmdList.Get());
	evenry->draw2D();
}

void resultScene::draw3D()
{
	evenry->draw3D();
	othello->Draw();
}

void resultScene::draw2D()
{
	
}

void resultScene::clearScene()
{
	//

	//���̃V�[���ւ̈ڍs����
	if (input->Triger(DIK_SPACE))
	{
		isNextScene = true;
	}
}

void resultScene::overScene()
{
	//���̃V�[���ւ̈ڍs����
	if (input->Triger(DIK_SPACE))
	{
		isNextScene = true;
	}
}