#include "playScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include "Axis.h"
#include "camera.h"
#include "player.h"
#include "field.h"
#include "weapon.h"
#include "shotManager.h"
#include "target.h"
#include "aim.h"


PlayScene::PlayScene()
{
	CreateGameObject<Axis>();
	CreateGameObject<Player>();
	Camera*pCamera = CreateGameObject<Camera>();
	SetDrawOrder(pCamera, 1);
	CreateGameObject<Field>();
	CreateGameObject<Weapon>();
	CreateGameObject<ShotManager>();
	CreateGameObject<Target>();
	Aim*pAim = CreateGameObject<Aim>();
	SetDrawOrder(pAim, 100);
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TitleScene");
	}

	SceneBase::Update();
}

void PlayScene::Draw()
{
	SceneBase::Draw();

	DrawString(0, 0, "PLAY SCENE", GetColor(0, 0, 0));

	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
	
	
	DrawString(10, 100, "�������", GetColor(0, 0, 0));
	DrawString(10, 120, "�Ə�����:�}�E�X", GetColor(0, 0, 0));
	DrawString(10, 140, "�V���b�g����:�}�E�X���N���b�N", GetColor(0, 0, 0));
	DrawString(10, 160, "�v���C���[����:W�L�[�O�i�AS�L�[��ށAA�L�[������AD�L�[�E����", GetColor(0, 0, 0));
	DrawString(10, 180, "�V���b�g���ˎ��A���s�ړ�", GetColor(0, 0, 0));
	
	
}
