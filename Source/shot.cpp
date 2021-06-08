#include <DxLib.h>
#include "shot.h"
#include "target.h"
#include <stdio.h>
#include "../Source/debugScreen.h"

Shot::Shot(SceneBase* scene, VECTOR pos, VECTOR vel) :GameObject(scene)
{
	position		= pos;//�e�̔��ˌ��_�̈ʒu
	velocity		= vel;//�e�̈ړ��l����
	playerPosition	= pos;//�v���C���[�̍��W����
	rotation		= VGet(0, 0, 0);//�p�x�̏�����
	vector			= VGet(0, 0, 0);//�e�̃x�N�g���̏�����
	int ir			=GetRandom(40);//�����̎擾


	//�}�E�X�̍��W���擾
	GetMousePoint(&Mx, &My);
	//�}�E�X�|�C���^�������ʍ��W�����[���h���W�ɕϊ����đ��
	worldPos = ConvScreenPosToWorldPos(VGet(Mx+ir, My, 1.0f));


	//�v���C���[�̍��W�ƃ}�E�X�̃��[���h���W�������Ēe�̃x�N�g�����擾
	vector = VSub(worldPos, playerPosition);
}

Shot::~Shot()
{

}

void Shot::Update()
{
	//�e�̃x�N�g���̐��K��
	vector = VNorm(vector);


	//�O�i����
	position.x += vector.x*velocity.x;
	position.y += vector.y*velocity.y;
	position.z += vector.z*velocity.z;
	

	//��Q���ƒe�̓����蔻��
	Target* target = GetScene()->FindGameObject<Target>();
	float r = 5.0f;
	if (target->CollisionSphere(position, r))
	{
		DestroyMe();
	}
}

void Shot::Draw()
{
	DrawSphere3D(position, 1, 16, GetColor(240, 30, 112), GetColor(240, 30, 112), true);
}

