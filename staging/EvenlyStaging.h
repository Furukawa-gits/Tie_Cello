#pragma once
#include"../2D/Sprite.h"
#include"../Particle/particleManagerOnTime.h"
#include"../2D/PostEffect.h"

class EvenlyStaging
{
public:

	static void setstaticdata(PostEffect* p, directX* d);

	void init();

	/// <summary>
	/// �����̐ݒ�
	/// </summary>
	/// <param name="now">���݂̊���(0�`1)</param>
	/// <param name="clear">�N���A�����̊���(0�`1)</param>
	static void ratioSet(float clear)
	{
		clearRatio = clear;

		int totalCell = whiteCount + blackCount;

		if (whiteCount == 0 && blackCount == 0)
		{
			nowRatio = 0.5f;
			return;
		}

		nowRatio = (float)(whiteCount / (float)totalCell);
	}

	static void setWhiteBlackCount(int wcount, int bcount)
	{
		whiteCount = wcount;
		blackCount = bcount;
	}

	void updata(bool iswhite);

	static void reSetBuffer();

	void draw3D();

	void draw2D();

private:

	void changeBackSprite();

	void setParticle();

	//�ÓI�����o�ϐ�
	static PostEffect* post;	//�[�x�o�b�t�@�N���A�p
	static directX* dx;			//�`�揈���p
	static float nowRatio;		//���݂̔����̊���
	static float clearRatio;	//�N���A�����̔����̊���
	static int whiteCount;		//���̐�
	static int blackCount;		//���̐�

	bool isWhite;				//���̎�Ԃ��ǂ���
	SingleSprite clearLine;
	SingleSprite nowLine;
	SingleSprite whiteBack;
	SingleSprite blackBack;

	std::list<std::unique_ptr<SingleParticle>> particleList;
};