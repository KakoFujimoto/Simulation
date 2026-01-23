#pragma once
#include "Scene/SceneManager.h"

class GameManager
{
public:
	void initialize();
	void update();
	void draw();

private:
	SceneManager sceneManager;
};