#pragma once
#include "../Library/gameObject.h"

class Player : public GameObject
{
public:
	Player(SceneBase* scene);
	~Player();
	void Update() override;
	void Draw() override;

private:
	int hModel;//���f���̃n���h���[
	VECTOR position;//�v���C���[�̍��W
	VECTOR rotation;//�v���C���[�̌���
};