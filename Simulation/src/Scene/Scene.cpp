#include "Scene.h"

bool Scene::isEnd() const
{
	return isEnd_;
}

void Scene::end()
{
	isEnd_ = true;
}

void Scene::onEnter()
{
	isEnd_ = false;
};