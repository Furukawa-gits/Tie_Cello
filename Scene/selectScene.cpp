#include "selectScene.h"
#include "../Othello/Othello.h"

namespace
{
const int winW = 1280, winH = 720; //�E�B���h�E�T�C�Y
}

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
	selectBack.generateSprite("Tiethello_background_tentative.png");
	//����
	for (int i = 0; i < number.size(); i++)
	{
		number[i].size = { 192.0f, 192.0f };
		number[i].position = { winW / 2.0f + ((i % 2) - 1) * number[i].size.x, winH / 2.0f - number[i].size.y / 2.0f, 0 };
		number[i].texSize = { 192.0f, 192.0f };
		number[i].generateSprite("Number_pattern01.png");
	}
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

	// �X�e�[�W�؂�ւ�
	if (input->Triger(DIK_LEFT) || input->Triger(DIK_A))
	{
		if (nowStageNumber > 1)
		{
			nowStageNumber--;
		}
	}
	if (input->Triger(DIK_RIGHT) || input->Triger(DIK_D))
	{
		if (nowStageNumber < stageCount)
		{
			nowStageNumber++;
		}
	}
	// �X�e�[�W�ǂݍ���
	if (input->Triger(DIK_SPACE))
	{
		isLoadStage = loadStage();
	}

	//���̃V�[���ւ̈ڍs����
	if (isLoadStage)
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
	selectBack.drawSprite(directx->cmdList.Get());

	char numberStr[10];
	sprintf_s(numberStr, "%02d", nowStageNumber);
	for (int i = 0; i < 2; i++)
	{
		int num = numberStr[i] - '0'; //�`�悷�鐔��
		int texX = num % 5;
		int texY = num / 5;

		number[i].texLeftTop = { texX * number[i].texSize.x, texY * number[i].texSize.y };
		number[i].spriteUpdata(true);
		number[i].drawSprite(directx->cmdList.Get());
	}
}

bool selectScene::loadStage()
{
	Othello::SetLoadStageNumber(nowStageNumber);
	return true;
}