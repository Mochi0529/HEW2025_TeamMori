#pragma once
#include "Stage.h"

class Layer_Manager
{
private:
	Stage& stage;
public:
	void ChangeLayer();//現在エリアのフラグの切り替え
};