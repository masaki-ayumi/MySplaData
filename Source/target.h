#pragma once
#include "../Library/gameObject.h"

class Target : public GameObject
{
public:
	Target(SceneBase* scene);
	~Target();
	void Update();
	void Draw();
	//�e�Ƃ̓����蔻��
	bool CollisionSphere(VECTOR CenterPos,float r);
private:
	int hModel;
	VECTOR position;
};