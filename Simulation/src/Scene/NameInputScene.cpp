#include "NameInputScene.h"
#include "UI/Input.h"
#include "UI/GameKey.h"
#include "Graphic/Renderer.h"
#include "GameConfig.h"
#include "GameMessage.h"
#include <DxLib.h>

NameInputScene::NameInputScene()
	: textInput_(MaxNameLength)
{
}

void NameInputScene::onEnter()
{
	textInput_.activate();
}

void NameInputScene::update(const Input& input)
{
	textInput_.update();

	if (textInput_.isDecided())
	{
		end();
	}
}

void NameInputScene::draw(Renderer& renderer)
{
	renderer.drawText(
		displayPosition_,
		displayPosition_,
		GameMessage::NameInputSceneMessage::EnterName
	);

	renderer.drawText(
		displayPosition_,
		displayPositionBelow_,
		textInput_.getText()
	);
}

const std::string& NameInputScene::getResultName() const
{
	return currentName_;
}