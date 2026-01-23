#pragma once
#include "Scene/Scene.h"
#include "GameConfig.h"


class Renderer;

class StoryScene : public Scene
{
public:
	void update() override;
	void draw(Renderer& renderer) override;

};
