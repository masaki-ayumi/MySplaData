#include "field.h"
#include <assert.h>

Field::Field(SceneBase* scene)
{
	//�󃂃f���̓ǂݍ���
	hSkyModel = MV1LoadModel("data\\model\\Stage\\Stage00_sky.mv1");
	assert(hSkyModel > 0);
	//�n�`���f���̓ǂݍ���
	hModel = MV1LoadModel("data\\model\\Stage\\Stage00.mv1");
	assert(hModel > 0);
}

Field::~Field()
{
	MV1DeleteModel(hSkyModel);
	MV1DeleteModel(hModel);
}

void Field::Update()
{
}

void Field::Draw()
{
	MV1DrawModel(hSkyModel);
	MV1DrawModel(hModel);
}

//�n�`�̓����蔻��
bool Field::CollisionLine(VECTOR * hit, VECTOR from, VECTOR to)
{
	MV1_COLL_RESULT_POLY col = MV1CollCheck_Line(hModel, -1, from, to);
	if (col.HitFlag == 0)
		return false;
	*hit = col.HitPosition;
	return true;
}
