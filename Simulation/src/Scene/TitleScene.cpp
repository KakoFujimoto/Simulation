#include "TitleScene.h"
#include "Graphic/Renderer.h"
#include "GameConfig.h"
#include "GameMessage.h"
#include <DxLib.h>

void TitleScene::update()
{

}

void TitleScene::draw(Renderer& renderer)
{
	renderer.drawText(
		displayPosition_,
		displayPosition_,
		GameMessage::TitleSceneMessage::PressEnter);
}