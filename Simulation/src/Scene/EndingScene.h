#pragma once
#include "Scene/Scene.h"
#include "GameConfig.h"
#include <string>


class Renderer;
class Input;

class EndingScene : public Scene
{
public:
	void onEnter() override;
	void update(const Input& input) override;
	void draw(Renderer& renderer) override;
	void setEndingType(const std::string& type);

private:
	std::string endingType_;
};
