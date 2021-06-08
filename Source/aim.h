#pragma once
#include "../Library/gameObject.h"

/// <summary>
/// �Ə��p�N���X
/// </summary>
class Aim : public GameObject
{
public:
	Aim(SceneBase* scene);
	~Aim();
	void Update() override;
	void Draw() override;

private:
	int aimGraph;//�Ə��p�摜�̃n���h��
	int mouseX, mouseY;//�}�E�X���W�p�ϐ�
	int graphX, graphY;//�摜�̍��W
	const int GRAPH_HALF = 32; //�摜�̔����̒l
};

