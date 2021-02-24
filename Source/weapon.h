#pragma once
#include "../Library/gameObject.h"

class Weapon :public GameObject
{
public:
	Weapon(SceneBase*scene);
	~Weapon();
	void Update();
	void Draw();
	void SetPlayerPosition(VECTOR _position);//���@�̍��W������
	VECTOR position;
private:
	bool isShot = false;//���@���e����������true
	int hModel;
	VECTOR rotation;
	VECTOR velocity;
};