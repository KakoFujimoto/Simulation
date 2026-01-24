#include "NameInputScene.h"
#include "System/Input.h"
#include "UI/GameKey.h"
#include "Graphic/Renderer.h"
#include "GameConfig.h"
#include "GameMessage.h"

void NameInputScene::update(const Input& input)
{

}

void NameInputScene::draw(Renderer& renderer)
{
	renderer.drawText(
		displayPosition_,
		displayPosition_,
		GameMessage::NameInputSceneMessage::EnterName
	);
}
