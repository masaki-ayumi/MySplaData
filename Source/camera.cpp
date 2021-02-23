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
	Far = 5000.0f;
	vec = VGet(0, 0, 0);
	key = VGet(100.0f, 150.0f, -200.0f);
	//マウスの位置を画面中央に固定
	SetMousePoint(400, 300);
}

Camera::~Camera()
{
}

void Camera::Update()
{
	//MATRIX rotY = MGetRotY(rotation.y);

	GetMousePoint(&Mx, &My);
	vec = ConvScreenPosToWorldPos(VGet(Mx, My, 1.0f));
	DebugSetColor(0, 0, 0);
	DebugPrintf(0, 100, "mouseX=%d,mouseY=%d", Mx, My);
	DebugPrintf(0, 120, "マウスの座標X:%f,Y:%f,Z:%f", vec.x, vec.y, vec.z);
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
	//自機の後ろに固定
	SetCameraPositionAndTarget_UpVecY(position, target);

	//マウスの座標をターゲットに設定(カメラぐるぐる)
	//SetCameraPositionAndTarget_UpVecY(position,vec);
	//カメラのポジションを矢印キーで動かす(ちょっとだけ動く)
	//SetCameraPositionAndTarget_UpVecY(key,target);
}
