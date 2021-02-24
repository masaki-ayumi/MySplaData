#include "aim.h"

Aim::Aim(SceneBase * scene)
{
	aimGraph = LoadGraph("data\\graph\\aim.png");
	//�}�E�X�̈ʒu����ʒ����ɌŒ�
	SetMousePoint(400, 300);
}

Aim::~Aim()
{
	DeleteGraph(aimGraph);
}

void Aim::Update()
{
	GetMousePoint(&mouseX, &mouseY);
	graphX = mouseX - GRAPH_HALF;
	graphY = mouseY - GRAPH_HALF;
}

void Aim::Draw()
{
	DrawGraph(graphX, graphY, aimGraph, true);
}
