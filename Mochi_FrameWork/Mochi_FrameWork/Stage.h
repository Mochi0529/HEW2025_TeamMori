#pragma once
#include<array>
#include "Area.h"

class Stage
{
private:
	std::array<Area, 4> Areas;
	int currentAreaIdx = 0;//現在のエリア番号

public:
	void ChangeArea();
	Area& GetCurrentArea();//現在エリアのインスタンスを取得
};