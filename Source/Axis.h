#pragma once
#include "../Library/gameObject.h"
/// <summary>
/// ���[���h���W���̂��炷
/// </summary>
class Axis :public GameObject
{
public:
	Axis(SceneBase* scene) :GameObject(scene){}
	~Axis(){}
	void Draw() override;

};