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
    int y = 50;

    if (endingType_ == "True")
    {
        renderer.drawText(50, y, "TRUE END");
        y += 40;
        renderer.drawText(50, y, "真実への帰還");
    }
    else if (endingType_ == "Normal")
    {
        renderer.drawText(50, y, "NORMAL END");
        y += 40;
        renderer.drawText(50, y, "真実を知らぬままの脱出");
    }
    else if (endingType_ == "Bad")
    {
        renderer.drawText(50, y, "BAD END");
        y += 40;
        renderer.drawText(50, y, "軽率な脱出");
    }
    else
    {
        renderer.drawText(50, y, "UNKNOWN END");
    }
}

void EndingScene::setEndingType(const std::string& type)
{
    endingType_ = type;
}