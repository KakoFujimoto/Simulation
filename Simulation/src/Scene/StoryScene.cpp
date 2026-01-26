#include "StoryScene.h"
#include "UI/Input.h"
#include "UI/GameKey.h"
#include "Graphic/Renderer.h"


void StoryScene::update(const Input& input)
{

}

void StoryScene::draw(Renderer& renderer)
{
	renderer.drawText(100, 100, "NovelScene: 仮表示");
}