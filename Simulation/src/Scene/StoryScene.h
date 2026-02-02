#pragma once
#include "Scene/Scene.h"
#include "GameConfig.h"
#include "StoryState.h"
#include "Story/StoryData.h"
#include <string>
#include <vector>
#include <array>


class Renderer;
class Input;

class StoryScene : public Scene
{
public:
	void onEnter() override;
	void update(const Input& input) override;
	void draw(Renderer& renderer) override;

private:
	void advanceStory();
	bool hasChoice() const;

	StoryState state_ = StoryState::ShowingText;

	int scriptIndex_ = 0;
	std::vector<std::string> script_;

	std::array<Choice, 2> choices_;
	int cursorIndex_ = 0;

	void updateChoosing(const Input& input);
	void drawChoosing(Renderer& renderer);
};
