#pragma once
#include "TitleScene.h"

class Scene;

class SceneManager
{
public:
	SceneManager();

	void update();
	void draw();

private:
	TitleScene titleScene;
	Scene* currentScene_;
};