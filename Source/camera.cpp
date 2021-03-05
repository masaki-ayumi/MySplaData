#include "camera.h"
#include "../Source/debugScreen.h"

Camera::Camera(SceneBase * scene) : GameObject(scene)
{
	position	= VGet(0, 0, 0);
	rotation	= VGet(0, 0, 0);
	target		= VGet(0, 0, 0);
}

Camera::~Camera()
{
}

void Camera::Update()
{
}

void Camera::Draw()
{
	//自機の後ろに固定
	SetCameraPositionAndTarget_UpVecY(position, target);
}
