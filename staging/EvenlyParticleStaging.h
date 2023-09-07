#pragma once
#include"../2D/Sprite.h"
#include"../Particle/particleManagerOnTime.h"
#include"../2D/PostEffect.h"

class EvenlyParticleStaging
{
public:
	SingleSprite clearLine;
	SingleSprite nowLine;
	SingleSprite whiteBack;
	SingleSprite blackBack;

	static void setstaticdata(PostEffect* p);

	void init();

	static void ratioSet(float now, float clear)
	{

	}

	void updata();

	static void clearBufferStaging();

	void draw();

private:
	//�[�x�o�b�t�@�ύX�p�|�C���^�[
	static PostEffect* post;

	static float nowRatio;
	static float clearRatio;
};