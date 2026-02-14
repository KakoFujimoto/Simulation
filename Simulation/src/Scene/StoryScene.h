#pragma once
#include "Scene/Scene.h"
#include "GameConfig.h"
#include "StoryState.h"
#include "Story/StoryData.h"
#include <string>
#include <vector>
#include <array>
#include <unordered_map>


class Renderer;
class Input;

class StoryScene : public Scene
{
public:
	void onEnter() override;
	void update(const Input& input) override;
	void draw(Renderer& renderer) override;

private:
	StoryData storyData_;
	const ScriptNode* currentNode_ = nullptr;
	std::unordered_map<std::string, bool> storyFlags_;

	int choiceIndex_ = 0;
	StoryState state_ = StoryState::ShowingText;
	int cursorIndex_ = 0;
	std::string previousNodeId_;

	void updateChoices(const Input& input);
	void drawChoices(Renderer& renderer);
	StoryData createStory();
	void onEnterNode(const ScriptNode& node);
	void end() override;
};
