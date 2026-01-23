#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager()
{
	currentScene_ = &titleScene;
}

void SceneManager::update()
{
	currentScene_->update();
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
	case SceneId::NameInput:
		currentScene_ = &nameInputScene;
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
