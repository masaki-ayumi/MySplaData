#include "camera.h"
#include "../Source/debugScreen.h"

Camera::Camera(SceneBase * scene) : GameObject(scene)
{
	//position = VGet(100.0f, 150.0f, -200.0f);
	position = VGet(0,0,0);
	//target = VGet(0, 100, 0);
	rotation = VGet(0, 0, 0);
	target = VGet(0, 0, 0);
	Near = 10.0f;
	Far = 500.0f;
	vec = VGet(0, 0, 0);
	key = VGet(100.0f, 150.0f, -200.0f);
	
}

Camera::~Camera()
{
}

void Camera::Update()
{
	MATRIX rotY = MGetRotY(rotation.y);

	GetMousePoint(&Mx, &My);
	vec = ConvScreenPosToWorldPos(VGet(Mx, My, 1.0f));

	 cTarget = VTransform(vec, rotY);

	DebugSetColor(0, 0, 0);
	//DebugPrintf(0, 100, "mouseX=%d,mouseY=%d", Mx, My);
	//DebugPrintf(0, 220, "�}�E�X�̍��WX:%f,Y:%f,Z:%f", vec.x, vec.y, vec.z);
	//if (CheckHitKey(KEY_INPUT_UP))
	//	key.y += 10.0f;
	//if (CheckHitKey(KEY_INPUT_DOWN))
	//	key.y -= 10.0f;
	//if (CheckHitKey(KEY_INPUT_LEFT))
	//	key.x -= 10.0f;
	//if (CheckHitKey(KEY_INPUT_RIGHT))
	//	key.x += 10.0f;
}

void Camera::Draw()
{
	//SetCameraNearFar(Near, Far);
	//���@�̌��ɌŒ�
	//SetCameraPositionAndTarget_UpVecY(position, target);
	
	SetCameraPositionAndTarget_UpVecY(position, cTarget);

	//�}�E�X�̍��W���^�[�Q�b�g�ɐݒ�(�J�������邮��)
	//SetCameraPositionAndTarget_UpVecY(position,vec);
	//�J�����̃|�W�V��������L�[�œ�����(������Ƃ�������)
	//SetCameraPositionAndTarget_UpVecY(key,target);
}
