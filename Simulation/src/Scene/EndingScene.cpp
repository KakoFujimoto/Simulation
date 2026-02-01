#include "EndingScene.h"
#include "Graphic/Renderer.h"
#include "UI/Input.h"
#include "UI/GameKey.h"

void EndingScene::onEnter()
{
	Scene::onEnter();
}

void EndingScene::update(const Input& input)
{
	if (input.isTriggered(GameKey::Decide))
	{
		end();
	}
}

void EndingScene::draw(Renderer& renderer)
{	
	// TODO:リファクタ後に座標、文言を整理する
	renderer.drawText(
		50,
		50,
		"EndingSceneに遷移しました"
	);
}