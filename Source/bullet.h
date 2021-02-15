#pragma once
#include "../Library/gameObject.h"

class Bullet :public GameObject {
public:
	/// <summary>
	/// Bullet�̃C���X�^���X�����Ƃ��Ɏ��@�ʒu�ƈړ��l���󂯎��
	/// </summary>
	/// <param name="scene"></param>
	/// <param name="pos">���@�ʒu</param>
	/// <param name="vel">�ړ��l</param>
	Bullet(SceneBase* scene,VECTOR pos,VECTOR vel);
	~Bullet();
	void Update();
	void Draw();
	//void SetPosition(VECTOR _position);

	
	bool isShot = false;
	int Mx, My;//�}�E�X�̃X�N���[�����W
	float shotspeed = 8.0f;
	VECTOR position;
	VECTOR rotation;
	VECTOR velocity;
	VECTOR vector;//�e�̐i�ޕ����̃x�N�g���p�ϐ�
	VECTOR worldPos;//���[���h���W�p�ϐ�
	VECTOR playerPosition;//���@�̍��W
};