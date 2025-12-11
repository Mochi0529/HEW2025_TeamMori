#include "SolidObject.h"
#include<iostream>

int  SolidObject::m_objectCounter = 0;	//	現在のオブジェクトの数を代入

//	オブジェクトの数を描画
void SolidObject::SolidObjectCounter()
{
	system("cls");
	std::cout << m_objectCounter;

}
