#include "StoryScene.h"
#include "UI/Input.h"
#include "UI/GameKey.h"
#include "Graphic/Renderer.h"
#include "GameConfig.h"
#include "GameMessage.h"
#include "Story/StoryLoader.h"
#include "Story/StoryData.h"


void StoryScene::onEnter()
{
    Scene::onEnter();

    storyData_ = createStory();
    currentNode_ = storyData_.getNode("start");
    choiceIndex_ = 0;

    state_ = StoryState::ShowingText;
}

void StoryScene::update(const Input& input)
{
    if (!currentNode_)
    {
        return;
    }

    if (currentNode_->id != previousNodeId_)
    {
        onEnterNode(currentNode_->id);
        previousNodeId_ = currentNode_->id;
    }
    if (currentNode_->choices.empty())
    {
        // 選択肢なし→Zで次へ
        if (input.isTriggered(GameKey::Decide))
        {
            end();
        }
        return;
    }

    // 選択肢がある場合
    if (input.isTriggered(GameKey::Up))
    {
        choiceIndex_ =
            (choiceIndex_ - 1 + currentNode_->choices.size())
            % currentNode_->choices.size();
    }

    if (input.isTriggered(GameKey::Down))
    {
        choiceIndex_ =
            (choiceIndex_ + 1)
            % currentNode_->choices.size();
    }

    if (input.isTriggered(GameKey::Decide))
    {
        const auto& choice = currentNode_->choices[choiceIndex_];
        currentNode_ = storyData_.getNode(choice.nextNodeId);
        choiceIndex_ = 0;
    }
}

void StoryScene::draw(Renderer& renderer)
{
    if (!currentNode_)
    {
        return;
    }

    // textを1行ずつ描画
    // TODO:マジックナンバーはのちほど手をつける
    int y = 100;
    const int lineHeight = 20;

    for (const auto& line : currentNode_->texts)
    {
        renderer.drawText(100, y, line);
        y += lineHeight;
    }

    // 選択肢はtextsの下に描画
    y += 10;

    for (size_t i = 0; i < currentNode_->choices.size(); ++i)
    {
        std::string prefix = (i == choiceIndex_) ? ">" : "";
        renderer.drawText(
            120,
            y + static_cast<int>(i) * lineHeight,
            prefix + currentNode_->choices[i].text
        );
    }
}

void StoryScene::drawChoices(Renderer& renderer)
{
    // TODO:リファクタ後に座標、文言を整理する
    const int x = 100;
    const int y = 450;
    const int lineHeight = 30;

    const auto& choices = currentNode_->choices;

    for (size_t i = 0; i < choices.size(); ++i)
    {
        int drawY = y + static_cast<int>(i) * lineHeight;

        if (i == cursorIndex_)
        {
            renderer.drawText(x - 20, drawY, ">");
        }
        renderer.drawText(x, drawY, choices[i].text);
    }
}

void StoryScene::updateChoices(const Input& input)
{
    const auto& choices = currentNode_->choices;

    if (input.isTriggered(GameKey::Up))
        cursorIndex_ = (cursorIndex_ - 1 + choices.size()) % choices.size();

    if (input.isTriggered(GameKey::Down))
        cursorIndex_ = (cursorIndex_ + 1) % choices.size();

    if (input.isTriggered(GameKey::Decide))
    {
        const auto& choice = choices[cursorIndex_];
        currentNode_ = storyData_.getNode(choice.nextNodeId);
        cursorIndex_ = 0;
    }
}

StoryData StoryScene::createStory()
{

    return StoryLoader::LoadFromFile("data/story.story");
}

void StoryScene::onEnterNode(const std::string& nodeId)
{
    if (nodeId == "bed_check")
    {
        storyFlags_.readMemo = true;
    }
}