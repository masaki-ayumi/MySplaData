#pragma once
#include "../Library/gameObject.h"

class Target : public GameObject
{
public:
	Target(SceneBase* scene);
	~Target();
	void Update();
	void Draw();
	//弾との当たり判定
	bool CollisionSphere(VECTOR CenterPos,float r);
private:
	int hModel;
	VECTOR position;
};