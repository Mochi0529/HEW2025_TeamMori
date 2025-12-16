#include "Area.h"

Area::Area()
{
	mLayer_flg = true;
}

Area::~Area()
{

}

void Area::ToggleHitDetection()
{
	if (mLayer_flg == true)//参照範囲Forを試す
	{
		/*for (int i = 0; i < Layer1->Objects[ObjCount]; i++)
		{
			layer1->Objects[i]->hit_flg = true;//Layer1のオブジェクトを前に
		}
		*/

		/*for(int i = 0; i < Layer2->Objects[ObjCount];i++)
		{
			layer2->Objects[i]->hit_flg = false;//Layer2のオブジェクトを後に
		}
		*/
	}
	else if (mLayer_flg == false)
	{
		/*for (int i = 0; i < Layer2->Objects[ObjCount]; i++)
		{
			layer2->Objects[i]->hit_flg = true;//Layer2のオブジェクトを前に
		}
		*/

		/*for(int i = 0; i < Layer1->Objects[ObjCount];i++)
		{
			layer1->Objects[i]->hit_flg = false;//Layer1のオブジェクトを後に
		}
		*/
	}
}

void Area::Changeflg()
{
	mLayer_flg = !mLayer_flg;
}

