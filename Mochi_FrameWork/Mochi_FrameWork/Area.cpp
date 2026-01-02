#include "Area.h"
#include "SolidObject.h"

Area::Area()
{
	//layer1 = new Layer;
	mLayer_flg = true;
}

Area::~Area()
{

}

void Area::ToggleHitDetection()
{
	if (mLayer_flg == true)//参照範囲Forを試す
	{
		for (int i = 0; i < layer1.GetObjects().size(); i++)
		{
			//layer1.GetObjects()[i].GetCollision() = true;//Layer1のオブジェクトを前に
		}

		for(int i = 0; i < layer2.GetObjects().size();i++)
		{
			//layer2.GetObjects().GetCollision() = false;//Layer2のオブジェクトを後に
		}
		
	}
	else if (mLayer_flg == false)
	{
		for (int i = 0; i < layer2.GetObjects().size(); i++)
		{
			//layer2.GetObjects().GetCollision() = true;//Layer2のオブジェクトを前に
		}
		

		for(int i = 0; i < layer1.GetObjects().size();i++)
		{
			//layer1.GetObjects().GetCollision() = false;//Layer1のオブジェクトを後に
		}
		
	}
}

void Area::Changeflg()
{
	mLayer_flg = !mLayer_flg;
}

