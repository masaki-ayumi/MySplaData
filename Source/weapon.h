#pragma once
#include "../Library/gameObject.h"

class Weapon :public GameObject
{
public:
	Weapon(SceneBase*scene);
	~Weapon();
	void Update();
	void Draw();
	void SetPlayerPosition(VECTOR _position);//���@�̍��W���擾
	void SetPlayerMatrix(MATRIX _rotationY) { mRotationY = _rotationY; }//���@�̉�]�s����擾
	VECTOR position;
private:
	int hModel;
	VECTOR rotation;
	VECTOR velocity;
	MATRIX mRotationY;//��]�s��
};