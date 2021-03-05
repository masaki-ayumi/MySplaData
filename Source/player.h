#pragma once
#include "../Library/gameObject.h"

class Player : public GameObject
{
public:
	Player(SceneBase* scene);
	~Player();
	void Update() override;
	void Draw() override;

private:
	void TranslateMove(MATRIX rotationY);//���s�ړ��̊֐�
	void RotationMove();//��]������ړ��̊֐�
	bool isShot = false;//�v���C���[���e����������true
	int hModel;//���f���̃n���h���[
	VECTOR position;//�v���C���[�̍��W
	VECTOR rotation;//�v���C���[�̌���
};