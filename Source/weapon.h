#pragma once
#include "../Library/gameObject.h"
/// <summary>
/// ����̃N���X
/// </summary>
class Weapon :public GameObject
{
public:
	Weapon(SceneBase*scene);
	~Weapon();
	void Update();
	void Draw();
	//�v���C���[�̓���ɍ��W���Z�b�g
	void SetPlayerPosition(VECTOR _position) { position = VAdd(_position, VGet(0, 20.0f, 0.0f)); }
	//�v���C���[�̉�]�s����擾
	void SetPlayerMatrix(MATRIX _rotationY) { mRotationY = _rotationY; }
	VECTOR position;
private:
	int hModel;
	VECTOR rotation;
	VECTOR velocity;
	MATRIX mRotationY;//��]�s��
};