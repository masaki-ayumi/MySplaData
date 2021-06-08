#pragma once

#include "../Library/gameObject.h"

/// <summary>
/// �n�`�N���X
/// </summary>
class  Field : public GameObject
{
public:
	Field(SceneBase* scene);
	~Field();
	void Update() override;
	void Draw() override;

	/// <summary>
	/// ���C�ƒn�`�̓����蔻�������
	/// </summary>
	/// <param name="hit">�����蔻���Ԃ�</param>
	/// <param name="from">�n�_</param>
	/// <param name="to">�I�_</param>
	/// <returns>�������Ă����true��������</returns>
	bool CollisionLine(VECTOR* hit, VECTOR from, VECTOR to);

private:
	int hModel;//�n�`�̃��f��
	int hSkyModel;//��̃��f��
};