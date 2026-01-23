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

void SceneManager::draw()
{
	currentScene_->draw();
}