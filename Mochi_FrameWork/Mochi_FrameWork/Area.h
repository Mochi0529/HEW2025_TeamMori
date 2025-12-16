#pragma once
#include "Layer.h"
class Area
{
private:
	bool mLayer_flg;//レイヤーの前後フラグ true時:layer1が前 false時:layer2が前

	Layer layer1;
	Layer layer2;

public:
	Area();
	~Area();
	void ToggleHitDetection();//当たり判定切り替え関数
	void Changeflg();//フラグの切り替え

};