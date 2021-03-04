#include<assert.h>
#include<DxLib.h>
#include "player.h"
#include "camera.h"
#include "field.h"
#include "weapon.h"
#include "bullet.h"
#include "bulletManager.h"

Player::Player(SceneBase * scene) :GameObject(scene)
{
	hModel = MV1LoadModel("data\\model\\MMD�p�x��Lver1.02\\���u�`�˂�.pmx");
	assert(hModel > 0);
	int center = MV1SearchFrame(hModel, "�S�Ă̐e");
	MV1SetFrameUserLocalMatrix(hModel, center, MGetRotY(DX_PI_F));

	position = VGet(0, 0, 0);
	rotation = VGet(0, 0, 0);
}

Player::~Player()
{
	MV1DeleteModel(hModel);
}

void Player::Update()
{
	isShot = false;
	if (GetMouseInput()&MOUSE_INPUT_LEFT) //�e����
	{
		isShot = true;
		BulletManager* bulletManager = GetScene()->FindGameObject<BulletManager>();
		//bulletManager->Create(position, VGet(10.0f, 10.0f, 10.0f));
		Weapon* weapon = GetScene()->FindGameObject<Weapon>();
		//����̍��W�ɒe�𐶐�
		bulletManager->Create(weapon->position, VGet(10.0f, 10.0f, 10.0f));
	}

	MATRIX rotationY = MGetRotY(rotation.y);
	if (CheckHitKey(KEY_INPUT_W))//��
	{
		VECTOR velocity = VTransform(VGet(0, 0, 3.0f), rotationY);
		position = VAdd(position, velocity);
	}
	if (CheckHitKey(KEY_INPUT_S))//��
	{
		VECTOR velocity = VTransform(VGet(0, 0, -3.0f), rotationY);
		position = VAdd(position, velocity);
	}

	//�ړ��̏�ԑJ��
	switch (isShot)//�e�𔭎˂��Ă��邩
	{
	case true://�e�𔭎˂��Ă���Ƃ����s�ړ�
		TranslateMove(rotationY);
		break;
	case false://�e�𔭎˂��Ă��Ȃ��Ƃ���]����ړ�
		RotationMove();
		break;
	}




	VECTOR upper = VAdd(position, VGet(0, 1000, 0));//10m��
	VECTOR lower = VAdd(position, VGet(0, -1000, 0));//10m��
	VECTOR hit;

	Field* pF = GetScene()->FindGameObject<Field>();
	if (pF->CollisionLine(&hit, upper, lower))
	{
		position = hit;
	}

	Camera* pCamera = GetScene()->FindGameObject<Camera>();
	////camera�N���X����}�E�X�̃��[���h���W���擾
	//VECTOR MousPos = pCamera->vec;
	////�}�E�X�̍��W���g�����X�t�H�[��
	////VECTOR cTarget = VTransform((MousPos), rotationY);


	//VECTOR cTarget = VTransform(VGet(0, 0, 100.0f), rotationY);
	//pCamera->SetTarget(VAdd(position, cTarget));
	VECTOR cPosition = VTransform(VGet(0, 40.0f, -70.0f), rotationY);
	pCamera->SetPosition(VAdd(position, cPosition));

	//����Ɏ��@�̍��W��n��
	Weapon* pWeapon = GetScene()->FindGameObject<Weapon>();
	pWeapon->SetPlayerPosition(position);

}

void Player::Draw()
{
	//MV1SetRotationXYZ(hModel, rotation);
	//MV1SetPosition(hModel, position);

	MATRIX matrix;
	//�ړ��s��
	MATRIX mTranslate = MGetTranslate(position);
	//��]�s��
	MATRIX mRotationY = MGetRotY(rotation.y);
	//��]���Ă���ړ�
	matrix = MMult(mRotationY, mTranslate);

	Weapon* weapon = GetScene()->FindGameObject<Weapon>();
	//���@�̉�]�s���n��
	weapon->SetPlayerMatrix(mRotationY);

	MV1SetMatrix(hModel, matrix);
	MV1DrawModel(hModel);
}


//���s�ړ��̊֐�
void Player::TranslateMove(MATRIX rotationY)
{
	if (CheckHitKey(KEY_INPUT_D))//�E
	{
		VECTOR velocity = VTransform(VGet(3.0f, 0, 0), rotationY);
		position = VAdd(position, velocity);
	}
	if (CheckHitKey(KEY_INPUT_A))//��
	{
		VECTOR velocity = VTransform(VGet(-3.0f, 0, 0), rotationY);
		position = VAdd(position, velocity);
	}
}


//��]������ړ��̊֐�
void Player::RotationMove()
{
	if (CheckHitKey(KEY_INPUT_D))//�E
	{
		rotation.y += 3.0*DX_PI_F / 180.0f;//����
	}
	if (CheckHitKey(KEY_INPUT_A))//��
	{
		rotation.y -= 3.0*DX_PI_F / 180.0f;
	}
}
