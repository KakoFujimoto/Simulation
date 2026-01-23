#include "TitleScene.h"
#include <DxLib.h>

void TitleScene::update()
{

}

void TitleScene::draw()
{
	// プロトタイプなので敢えてDxLibのメソッド直書き
	DrawString(100, 100, "Press Enter", GetColor(255, 255, 255));
}