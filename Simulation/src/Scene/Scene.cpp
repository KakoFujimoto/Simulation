#include "Scene.h"

bool Scene::isEnd() const
{
	return isEnd_;
}

void Scene::end()
{
	isEnd_ = true;
}
