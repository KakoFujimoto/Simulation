#pragma once
#include "TitleScene.h"

class Scene;
class Renderer;

class SceneManager
{
public:
	SceneManager();

	void update();
	void draw(Renderer& renderer);

private:
	TitleScene titleScene;
	Scene* currentScene_;
};