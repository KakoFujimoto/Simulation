#include "TitleScene.h"
#include "Graphic/Renderer.h"
#include "GameConfig.h"
#include "GameMessage.h"
#include "System/Input.h"
#include "UI/GameKey.h"
#include <DxLib.h>

void TitleScene::update(const Input& input)
{
	if (input.isTriggered(GameKey::Enter))
	{
		end();
	}
}

void TitleScene::draw(Renderer& renderer)
{
	renderer.drawText(
		displayPosition_,
		displayPosition_,
		GameMessage::TitleSceneMessage::PressEnter
	);
}