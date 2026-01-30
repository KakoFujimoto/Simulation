#include "StoryScene.h"
#include "UI/Input.h"
#include "UI/GameKey.h"
#include "Graphic/Renderer.h"
#include "GameConfig.h"
#include "GameMessage.h"


void StoryScene::onEnter()
{
    // 仮台本
    script_ = {
        "ここは静かな部屋だ。",
        "外から物音が聞こえる。",
        "どうする？",
        "あなたは外に出た。",
        "あなたはその場にとどまった。"
    };

    scriptIndex_ = 0;
    state_ = StoryState::ShowingText;
}

void StoryScene::update(const Input& input)
{
    switch (state_)
    {
        case StoryState::ShowingText:
            if (input.isTriggered(GameKey::Decide))
            {
                if (hasChoice())
                {
                    choices_ = {
                        Choice{ "外に出ていく", 3 },
                        Choice{ "その場にとどまる", 4 }
                    };
                    cursorIndex_ = 0;
                    state_ = StoryState::Choosing;
                }
                else
                {
                    if (scriptIndex_ == 3 || scriptIndex_ == 4)
                    {
                        end();
                    }
                    else
                    {
                        advanceStory();
                    }
                }
            }
            break;

        case StoryState::Choosing:
            updateChoosing(input);
            break;
    }
}

void StoryScene::draw(Renderer& renderer)
{
    renderer.drawText(100, 400, script_[scriptIndex_]);

    if (state_ == StoryState::Choosing)
    {
        drawChoosing(renderer);
    }

    renderer.drawText(
        GameConfig::StorySceneConfig::TextMarginLeft
        ,GameConfig::StorySceneConfig::NavigationMarginTop
        ,GameMessage::StorySceneMessage::NavigationMessage
    );
}

void StoryScene::drawChoosing(Renderer& renderer)
{
    const int x = 100;
    const int y = 450;
    const int lineHeight = 30;

    for (int i = 0; i < 2; ++i)
    {
        int drawY = y + i * lineHeight;

        if (i == cursorIndex_)
        {
            renderer.drawText(x - 20, drawY, ">");
        }

        renderer.drawText(x, drawY, choices_[i].text);
    }
}

void StoryScene::updateChoosing(const Input& input)
{
    if (input.isTriggered(GameKey::Up) ||
        input.isTriggered(GameKey::Down))
    {
        cursorIndex_ = (cursorIndex_ + 1) % 2;
    }

    if (input.isTriggered(GameKey::Decide))
    {
        scriptIndex_ = choices_[cursorIndex_].nextStoryIndex;
        state_ = StoryState::ShowingText;
    }
}

void StoryScene::advanceStory()
{
    ++scriptIndex_;

    if (scriptIndex_ >= static_cast<int>(script_.size()))
    {
        end();
    }
}

bool StoryScene::hasChoice() const
{
    return scriptIndex_ == 2;
}