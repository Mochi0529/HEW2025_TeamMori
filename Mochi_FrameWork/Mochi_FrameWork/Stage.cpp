#include"Stage.h"

void Stage::ChangeArea()
{
	/*
	if (currentAreaIdx < 4 && //エリアの右端なら)
	{
		curenntAreaIdx++;
	}
	else if(currentAreaIdx > 0 && //エリアの左端なら)
	{
		currentAreaIdx--;
	}
	*/
}

Area& Stage::GetCurrentArea()
{
	return Areas[currentAreaIdx];
}