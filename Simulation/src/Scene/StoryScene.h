#pragma once
#include "Scene/Scene.h"
#include "GameConfig.h"
#include "StoryState.h"
#include "Choice.h"
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
	StoryState state_ = StoryState::ShowingText;
	int scriptIndex_ = 0;
	std::vector<std::string> script_;
	int currentLine_ = 0;
	std::array<Choice, 2> choices_;
	int cursorIndex_ = 0;
};
