#pragma once
#include "Scene/Scene.h"
#include "GameConfig.h"
#include <string>
#include <vector>


class Renderer;
class Input;

class StoryScene : public Scene
{
public:
	void onEnter() override;
	void update(const Input& input) override;
	void draw(Renderer& renderer) override;

private:
	std::vector<std::string> script_;
	int currentLine_ = 0;
};
