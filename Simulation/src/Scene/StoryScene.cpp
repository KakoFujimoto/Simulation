#include "StoryScene.h"
#include "UI/Input.h"
#include "UI/GameKey.h"
#include "Graphic/Renderer.h"

void StoryScene::onEnter()
{
    // 仮台本（5行）
    script_ = {
        "……目を覚ますと、そこは見知らぬ部屋だった。",
        "カーテンの隙間から、朝日が差し込んでいる。",
        "『ここは……どこだ？』",
        "頭がぼんやりして、記憶がはっきりしない。",
        "――その時、ドアの開く音がした。"
    };

    currentLine_ = 0;
}

void StoryScene::update(const Input& input)
{
    if (input.isTriggered(GameKey::Decide))
    {
        if (currentLine_ < static_cast<int>(script_.size()) - 1)
        {
            currentLine_++;
        }
    }
}

void StoryScene::draw(Renderer& renderer)
{
	renderer.drawText(
         100
        ,400
        ,script_[currentLine_]
    );

    renderer.drawText(
         100
        ,440
        ,"Zキーで進む"
    );
}