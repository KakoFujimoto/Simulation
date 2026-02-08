#include "SceneManager.h"
#include "Scene.h"
#include "UI/Input.h"

SceneManager::SceneManager()
{
	changeScene(SceneId::Title);
}

void SceneManager::update(const Input& input)
{
	currentScene_->update(input);

	if (!currentScene_->isEnd())
	{
		return;
	}
	if (currentScene_ == &titleScene)
	{
		changeScene(SceneId::Story);
	}
	else if (currentScene_ == &storyScene)
	{
		changeScene(SceneId::Ending);
	}
	else if (currentScene_ == &endingScene)
	{
		changeScene(SceneId::Title);
	}
}

void SceneManager::draw(Renderer& renderer)
{
	currentScene_->draw(renderer);
}

void SceneManager::changeScene(SceneId id)
{
	switch (id)
	{
	case SceneId::Title:
		currentScene_ = &titleScene;
		break;
	case SceneId::Story:
		currentScene_ = &storyScene;
		break;
	case SceneId::Ending:
		currentScene_ = &endingScene;
		break;
	default:
		return;
	}
	currentScene_ -> onEnter();
}
