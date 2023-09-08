#include "Block.h"

directX* Block::dx = nullptr;
std::unique_ptr<Model> Block::blockModel_1 = std::make_unique<Model>();
std::unique_ptr<Model> Block::blockModel_2 = std::make_unique<Model>();

void Block::loadResources()
{
	blockModel_1.reset(FbxLoader::GetInstance()->LoadmodelFromFile("Board_1"));
	blockModel_2.reset(FbxLoader::GetInstance()->LoadmodelFromFile("Board_2"));
}

void Block::setStaticData(directX* d)
{
	dx = d;
	loadResources();
}

void Block::init(blockType type, XMFLOAT3 position)
{
	blockObject = std::make_unique<object3dFBX>();
	blockObject->initialize();

	if (type == blockType::light)
	{
		blockObject->SetModel(blockModel_1.get());
	}
	else
	{
		blockObject->SetModel(blockModel_2.get());
	}

	startPos = position;
	blockObject->SetPosition(position);
	blockObject->SetScale({ 1,1,1 });
}

void Block::updata()
{
	blockObject->updata();
}

void Block::draw3D()
{
	blockObject->Draw(dx->cmdList.Get());
}
