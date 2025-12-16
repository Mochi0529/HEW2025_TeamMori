#include "Layer_Manager.h"
#include "Stage.h"

void Layer_Manager::ChangeLayer()
{
	stage.GetCurrentArea().Changeflg();//現在エリアのフラグの切り替え
}