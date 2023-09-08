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
	static void ratioSet(float now, float clear)
	{
		nowRatio = now;
		clearRatio = clear;
	}

	void updata(bool isWhite);

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
	static bool isWhite;		//���̎�Ԃ��ǂ���

	SingleSprite clearLine;
	SingleSprite nowLine;
	SingleSprite whiteBack;
	SingleSprite blackBack;


};