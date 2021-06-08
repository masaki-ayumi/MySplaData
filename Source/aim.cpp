#include "aim.h"
#include "config.h"

Aim::Aim(SceneBase * scene)
{
	//�Ə��p�摜�̓ǂݍ���
	aimGraph = LoadGraph("data\\graph\\aim.png");
	//�}�E�X�̈ʒu����ʒ����t�߂ɌŒ�
	SetMousePoint(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100);
	//�}�E�X��\��
	SetMouseDispFlag(false);
}

Aim::~Aim()
{
	DeleteGraph(aimGraph);
}

void Aim::Update()
{
	//�Ə��摜�̍��W���}�E�X���W�̉��ɐݒ�
	GetMousePoint(&mouseX, &mouseY);
	graphX = mouseX - GRAPH_HALF;
	graphY = mouseY - GRAPH_HALF + 100;
}

void Aim::Draw()
{
	DrawGraph(graphX, graphY, aimGraph, true);
}
