#pragma once
#include "../Library/gameObject.h"

class Weapon :public GameObject
{
public:
	Weapon(SceneBase*scene);
	~Weapon();
	void Update();
	void Draw();
	void SetPlayerPosition(VECTOR _position);//�v���C���[�̍��W������
private:
	bool isShot = false;//�v���C���[���e����������true
	int hModel;
	VECTOR position;
	VECTOR rotation;
	VECTOR velocity;
};