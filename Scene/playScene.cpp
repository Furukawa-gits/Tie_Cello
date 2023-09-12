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
	othello->~Othello();
}

void playScene::loadResources()
{
	evenry = std::make_unique<EvenlyStaging>();
	evenry->init();
}

void playScene::initialize()
{
	loadResources();

	setParameter();
}

void playScene::setParameter()
{
	Cell::setStaticData(directx);
	Block::setStaticData(directx);
	Othello::setInput(input);
	othello = std::make_unique<Othello>();
	othello->Init();
	std::string num = std::to_string(Othello::GetLoadStageNumber());
	othello->Load(("Resources/StageData/stage" + num + ".csv"));
	isNextScene = false;
}

void playScene::updata()
{
	//���C�g�X�V
	light->Update();

	/*float nowratio;

	if (white == 0 && black == 0)
	{
		nowratio = 0.5f;
	}
	else
	{
		nowratio = (float)white / (float)(white + black);
	}*/

	EvenlyStaging::setWhiteBlackCount(othello->getWhiteCount(), othello->getBlackCount());
	EvenlyStaging::ratioSet(0.3f);

	if (othello->getNowColor() == Color::WHITE)
	{
		evenry->updata(true);
	}
	else
	{
		evenry->updata(false);
	}

	othello->updata(input->mousePosition);

	//���̃V�[���ւ̈ڍs����
	if (input->Triger(DIK_SPACE))
	{
		isNextScene = true;
	}
}

void playScene::drawBack()
{
	sample_back->drawSprite(directx->cmdList.Get());
	evenry->draw2D();
}

void playScene::draw3D()
{
	evenry->draw3D();
	othello->Draw();
}

void playScene::draw2D()
{
}

void playScene::tutorial()
{

}