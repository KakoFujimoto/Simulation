#pragma once
#include "Scene/Scene.h"
#include "GameConfig.h"


class Renderer;

class TitleScene : public Scene
{
public:
	void update() override;
	void draw(Renderer& renderer) override;

private:
	int displayPosition_ = GameConfig::TitleSceneConfig::DisplayPosition;
};
