#pragma once
#include "../Library/gameObject.h"
/// <summary>
/// ��Q���̃N���X
/// </summary>
class Target : public GameObject
{
public:
	Target(SceneBase* scene);
	~Target();
	void Update();
	void Draw();
	/// <summary>
	/// �e�Ƌ��̂̂����蔻��֐�
	/// </summary>
	/// <param name="CenterPos">���̂̒��S���W</param>
	/// <param name="r">���̂̔��a</param>
	/// <returns>�����������Q���̃��f��������</returns>
	bool CollisionSphere(VECTOR CenterPos,float r);
private:
	int hModel;
	VECTOR position;
};