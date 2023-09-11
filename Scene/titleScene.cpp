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
	titleBack.generateSprite("Tiethello_background_tentative.png");

	const size_t charCount = titleChars.size() / 2;
	const XMFLOAT3 offset = { 32.0f, 100.0f, 0 };
	for (int i = 0; i < titleChars.size(); i++)
	{
		titleChars[i].size = { 192.0f, 192.0f };
		titleChars[i].position = { (i / 2) * 128.0f, 0, 0 };
		titleChars[i].position = {
			titleChars[i].position.x + offset.x,
			titleChars[i].position.y + offset.y,
			titleChars[i].position.z + offset.z
		};

		titleChars[i].texSize = { 256.0f, 256.0f };
		//Tiethello
		int texY = 0;
		switch (i / 2)
		{
		// T
		case 0:
			texY = 0;
			break;
		// i
		case 1:
			texY = 1;
			break;
		// e
		case 2:
		case 5:
			texY = 2;
			break;
		// o
		case 8:
			texY = 3;
			break;
		// l
		case 6:
		case 7:
			texY = 4;
			break;
		// h
		case 4:
			texY = 5;
			break;
		// t
		case 3:
			texY = 6;
			break;
		default:
			break;
		}
		titleChars[i].texLeftTop = { (i % 2) * titleChars[i].texSize.x, texY * titleChars[i].texSize.y };
		titleChars[i].generateSprite("TitleChars.png", false, false, false, true);
		titleChars[i].spriteUpdata(true);
	}
	//�^�C�g��

	//Move
	//Number_pattern01
	//Number_pattern02
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
	for (auto& i : titleChars)
	{
		i.drawSprite(directx->cmdList.Get());
	}
}
