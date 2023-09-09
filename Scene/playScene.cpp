#include "playScene.h"

playScene::playScene()
{
	//リソース読み込み
	loadResources();

	//パラメータのセット
	setParameter();

	thisType = gameSceneType::play;
}

playScene::~playScene()
{

}

void playScene::loadResources()
{
	test = std::make_unique<EvenlyStaging>();
	test->init();
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
	//ライト更新
	light->Update();

	if (input->Triger(DIK_RIGHT))
	{
		white++;
	}
	if (input->Triger(DIK_LEFT))
	{
		black++;
	}

	float nowratio;

	if (white == 0 && black == 0)
	{
		nowratio = 0.5f;
	}
	else
	{
		nowratio = (float)white / (float)(white + black);
	}

	EvenlyStaging::ratioSet(nowratio, 0.3f);

	test->updata(false);

	//次のシーンへの移行条件
	if (input->Triger(DIK_SPACE))
	{
		isNextScene = true;
	}
}

void playScene::drawBack()
{
	sample_back->drawSprite(directx->cmdList.Get());
	test->draw2D();
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