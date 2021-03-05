#pragma once
#include "../Library/gameObject.h"

class Shot :public GameObject {
public:
	/// <summary>
	/// Bullet�̃C���X�^���X�����Ƃ��Ɏ��@�ʒu�ƈړ��l���󂯎��
	/// </summary>
	/// <param name="scene"></param>
	/// <param name="pos">�v���C���[�ʒu</param>
	/// <param name="vel">�ړ��l</param>
	Shot(SceneBase* scene,VECTOR pos,VECTOR vel);
	~Shot();
	void Update();
	void Draw();
	//-n����n�܂ł̗������擾
	int GetRandom(int n) { return GetRand(2 * n) - n; };

	
	int Mx, My;//�}�E�X�̃X�N���[�����W
	VECTOR position;
	VECTOR rotation;
	VECTOR velocity;
	VECTOR vector;//�e�̐i�ޕ����̃x�N�g���p�ϐ�
	VECTOR worldPos;//���[���h���W�p�ϐ�
	VECTOR playerPosition;//���@�̍��W
};