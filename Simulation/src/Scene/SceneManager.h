#pragma once
#include "TitleScene.h"
#include "SceneId.h"
#include "NameInputScene.h"
#include "StoryScene.h"
#include "EndingScene.h"

class Scene;
class Renderer;
class Input;

class SceneManager
{
public:
	SceneManager();
	void update(const Input& input);
	void draw(Renderer& renderer);
	void changeScene(SceneId id);

private:
	TitleScene titleScene;
	NameInputScene nameInputScene;
	StoryScene storyScene;
	EndingScene endingScene;
	Scene* currentScene_;
};