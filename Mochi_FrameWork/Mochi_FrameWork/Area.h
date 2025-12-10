#pragma once
#include "Layer.h"
class Area
{
	private:
		bool Layer_flg;//レイヤーの前後フラグ

		Layer layer1;
		Layer layer2;

	public:
		void ToggleHitDetection(const bool& Layer_flg);
};